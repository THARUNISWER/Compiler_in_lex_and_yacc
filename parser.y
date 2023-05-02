%{
	#include <stdbool.h>
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
	#include <stdarg.h>
	#include "header.h"

    int yywrap();
	int searchf(char *);
	int searchc(char *);
    int search(char *);
	int search_obj(char *clsname, char* obj_name) ;
	int search_obj_data(int cls_index, int obj_index, char* name, int data);
	void copyobj1(char* obj_name, char* cls_name);
	void copyobj2(char* obj_name, char* cls_name, nodeType* ptr);
	void addf(char *, nodeType *);
	void add_cls_data(nodeType *);
	void add_cls_func(nodeType *);
	void addmethpara(nodeType *);
	void addobjargs(int cls_index,int obj_index, nodeType *ptr);
	nodeType *obj_funccall_action(char* p1, char* p2, char* p3, nodeType* p4);
	nodeType *obj_value_access_action(char* p1, char* p2, char* p3);
	nodeType *obj_value_upd_action(char* p1, char* p2, char* p3, nodeType* p4);
	nodeType *funccall_action(char* p1, nodeType* p2);
	void cls_action(nodeType* p1, nodeType* p2);
	nodeType *opr(int oper, int nops, ...);
	nodeType *id(char* i);
	nodeType *con(double value);
	void freeNode(nodeType *p);
	double ex(nodeType *p);
	int yylex(void);
	void yyerror(char *s);
    extern int countn; 

	// arrays storing different types of errors like lexical, syntax and semantic
	int synerrs=0;
	char syntax_errors[10][200];
	int lex_cnt=0;
	char lex_errors[10][200];
	int sem_errors=0;	
	char errors[10][200]; 
	char reserved[15][10] = {"int", "float", "char", "void", "if", "else", "for", "main", "return", "while", "switch", "case", "default", "read" ,"write"};

	// 1.symbol table list is array of symbol tables.
	// 2.symbol_table_lst[0] is main function's symbol table 
	// 3.soon after a function is called, we maintain a new symbol table for that function call inserting all the functions args into this symbol table 
	int symbol_table_lst_itr=0;
	symtab symbol_table_lst[1000]; 

	// no of function definitions
	int function_cnt=0;	
	// all function parameters 
	char* func_parem_temp[10];
	int func_parem_temp_itr=0;
	// storing info about all defined functions like name, parameters, parsetree of the function body (used for execution of function calls)
	functab function_table[10];
	int args_count=0;

	//class
	int cls_cnt=0;
	cls class_table[10];
	object_node temp_obj[10];
%}

%union {
 double iValue; /* integer value */
 char* name; /* id_name */
 nodeType *nPtr; /* node pointer */
};

%token VOID 
%token CONSTRUCTOR OBJV OBJD OBJF NEW CLASS ARROW WRITE WRITE_S READ ERROR FOR WHILE IF LE GE EQ NE RETURN MAIN PP SS PE SE ME DE DEF 
%type <nPtr> expr3 expr1 expr2 cls_paremlst cls_meth cls_funcs cls_vars cls c_list return main bodylst statement program t1 t2 t3 t4  for if_else write read while function paremlst init value expression condition body functionlst functioncall argslst 
%token <iValue> NUMBER 
%token <name> ID STR
%left GE LE EQ NE '>' '<'  
%left '+' '-' 
%left '*' '/' 
%nonassoc NEWX
%nonassoc IFX  
%nonassoc ELSE 
%nonassoc UMINUS 
%%

program: c_list functionlst main  
| main
;

main: MAIN '{' bodylst '}' 									{ if(lex_cnt + synerrs + sem_errors==0){ ex($3); freeNode($3); } } 
;

c_list:
cls c_list                             
| cls                                     
; 

cls:
CLASS ID {class_table[cls_cnt].cls_name= $2;} '{' cls_vars cls_funcs '}' { cls_action($5, $6); } 
| ID ID {
	sprintf(syntax_errors[synerrs], "syntax error in line %d , wrong declaration of the class \n", countn ); synerrs++;    
} '{' cls_vars cls_funcs '}'  								{ ; } 
|                                                			{ $$= NULL;}
;

cls_vars:
cls_vars ID ';'                         					{  $$ = opr('^', 2, $1, id($2)); }
| ID ';'                                					{  $$ = opr('^', 2, NULL, id($1)); }
| ERROR ';'													{  sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in defining an Identifier/Function\n", countn); lex_cnt++;    }
|                                       					{ ;}
;

cls_funcs: 
cls_funcs cls_meth                            				{ $$ = opr('^', 2, $1, $2); }
| cls_meth                                    				{ $$ = $1; }
;

cls_meth:
  DEF ID    '(' cls_paremlst ')' '{' bodylst return '}'  	{ $$ = opr(';', 4, id($2), $4, $7, $8); }
| ID        '(' cls_paremlst ')' '{' bodylst return '}'  	{ sprintf(syntax_errors[synerrs], "syntax error in line %d , def is missing in front of function definition\n", countn); synerrs++; }
| DEF ERROR 									       		{ sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in naming a Function\n", countn); lex_cnt++;    } '(' cls_paremlst ')' '{' bodylst return '}' { $$ =  NULL;}
|                                                      		{ $$ =  NULL;}
; 

cls_paremlst:
cls_paremlst ',' ID                      					{ $$ = opr('!', 2, $1, id($3)); } 
| ID                                  						{ $$ = opr('!', 2, NULL, id($1)); }
| ERROR								  						{ sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in defining an Identifier/Function\n", countn); lex_cnt++;    }
|                                     						{ $$ = NULL;} 
;

functionlst : function functionlst  
| function 
;

function: DEF ID '(' paremlst ')' {
															  function_table[function_cnt].func_name=strdup($2);
															  function_table[function_cnt].num_parem= func_parem_temp_itr; function_cnt++; 
							    } '{' bodylst return '}' 	{ $$ = opr(';', 2, $8, $9); addf($2, $$); } 
| ID '(' paremlst ')' '{' bodylst return '}' 				{ sprintf(syntax_errors[synerrs], "syntax error in line %d , def is missing in front of function definition\n", countn); synerrs++;    }
| DEF ERROR '(' paremlst ')' '{' bodylst return '}' 		{ sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in defining an Identifier/Function\n", countn); lex_cnt++;    }
|															{ ; }
;

paremlst: paremlst ',' ID									{ func_parem_temp[func_parem_temp_itr]= $3; func_parem_temp_itr++; }
| ID 														{ func_parem_temp[func_parem_temp_itr]= $1; func_parem_temp_itr++;	}
| ERROR 													{ sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in defining an Argument\n", countn); lex_cnt++; }
|															{ ; }
;

bodylst : bodylst body 										{ $$ = opr(';', 2, $1, $2); }
|body 
;

body: for 
| if_else 
| statement ';' 
| write 
| read 
| while 
| return  
;

for : 
  FOR statement ':' condition ':' statement '{' bodylst '}'	{ $$ = opr(FOR, 4, $2, $4, $6, $8); }
| FOR statement 	condition ':' statement '{' bodylst '}' { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining for loop : ':' missing \n", countn); synerrs++;    }
| FOR statement ':' condition 	  statement '{' bodylst '}' { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining for loop : ':' missing \n", countn); synerrs++;    }
| FOR statement 	condition 	  statement '{' bodylst '}' { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining for loop: ':' missing \n", countn); synerrs++;    }
| FOR statement ':' condition ':' statement     bodylst '}' { sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining for loop : '{' missing \n", countn); synerrs++;    }
| FOR statement ':' condition ':' statement '{' bodylst 	{ sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining for loop : '}' missing \n", countn); synerrs++;    }
| FOR statement ':' condition ':' statement  	bodylst 	{ sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining for loop : '{' and '}' missing  \n", countn); synerrs++;    }
;

while : 
  WHILE condition '{' bodylst '}' 							{ $$ = opr(WHILE, 2, $2, $4);  }
| WHILE condition     bodylst '}' 							{ sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining while loop : '{' missing \n", countn); synerrs++;    }
| WHILE condition '{' bodylst  	  							{ sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining while loop : '}' missing \n", countn); synerrs++;    }
| WHILE condition     bodylst     							{ sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining while loop : '{' and '}' missing \n", countn); synerrs++;    }
| WHILE 		  '{' bodylst '}' 							{ sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining while loop : condition missing \n", countn); synerrs++;    }
;

if_else : 
  IF condition '{' bodylst '}' %prec IFX            		{ $$ = opr(IF, 2, $2, $4); }
| IF condition '{' bodylst '}' ELSE '{' bodylst '}' 		{ $$ = opr(IF, 3, $2, $4, $8); }
| IF condition     bodylst '}' ELSE '{' bodylst '}' 		{ sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining if statement : '{' missing \n", countn); synerrs++;    }
| IF condition '{' bodylst     ELSE '{' bodylst '}' 		{ sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining if statement : '}' missing \n", countn); synerrs++;    }
| IF 		   '{' bodylst '}' ELSE '{' bodylst '}' 		{ sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining if statement : condition missing \n", countn); synerrs++;    }
| ID condition '{' bodylst '}' ELSE '{' bodylst '}' 		{ sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining if statement : \"if\" not written correctly \n", countn); synerrs++;    }
| IF condition     bodylst     ELSE '{' bodylst '}' 		{ sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining if statement : '{' and '}' missing \n", countn); synerrs++;    }
| IF condition '{' bodylst '}' ELSE     bodylst '}' 		{ sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining else statement : '{' missing \n", countn); synerrs++;    }
| IF condition '{' bodylst '}' ELSE '{' bodylst     		{ sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining else statement : '}' missing \n", countn); synerrs++;    }
| IF condition '{' bodylst '}' ELSE     bodylst     		{ sprintf(syntax_errors[synerrs], "Syntax error in line %d , error in defining else statement : '{' and '}' missing \n", countn); synerrs++;    }
;

write : 
 WRITE expression ';'										{ $$ = opr(WRITE, 1, $2); }
|WRITE STR 		  ';'										{ $$ = opr(WRITE_S, 1, id($2)); }
;

//priority in operations
expression: 
  expression '+' expr1 										{ $$ = opr('+', 2, $1, $3); }
| expression '-' expr1 										{ $$ = opr('-', 2, $1, $3); }
| expr1
| ID PE expression     										{ $$ = opr(PE, 2, id($1), $3); }
| ID SE expression     										{ $$ = opr(SE, 2, id($1), $3); }
| ID ME expression     										{ $$ = opr(ME, 2, id($1), $3); }
| ID DE expression     										{ $$ = opr(DE, 2, id($1), $3); } 
;

expr1: 
  expr1 '*' expr2 { $$ = opr('*', 2, $1, $3); }
| expr1 '/' expr2 { $$ = opr('/', 2, $1, $3); }
| expr2 
;

expr2: expr2 '^' expr3 { $$ = opr('^', 2, $1, $3);}
| expr2 '%' expr3 { $$ = opr('%', 2, $1, $3);}
| expr3
;

expr3:
 '(' expression ')' 						          		{ $$ = $2; } 
| functioncall 										  		{ $$ = $1; } 
| ID '.' ID '.' ID '(' { args_count=0;} argslst ')'		    { $$ = obj_funccall_action($1, $3, $5, $8); } 
| ID '.' ID '.' ID 									  		{ $$ = obj_value_access_action($1, $3, $5); }
| value 										      		{ $$ = $1; }
| '-' expression %prec UMINUS 						  		{ $$ = opr(UMINUS, 1, $2); }
;

value: 
  NUMBER 											  		{ $$ = con($1); }
| ID 												  		{ $$ = id($1);	}
| ERROR 											  		{ sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in defining an Identifier/Function\n", countn); lex_cnt++; }
;

read : READ ID ';' 									  		{ $$=opr(READ, 1, id($2));} 
| READ ERROR ';' 										  	{ sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in defining an Identifier/Function\n", countn); lex_cnt++; }
;

return: RETURN expression ';' 								{ $$ = opr(RETURN, 1, $2); }

condition: 
  expression '<' expression 								{ $$ = opr('<', 2, $1, $3); }
| expression '>' expression 								{ $$ = opr('>', 2, $1, $3); }
| expression LE  expression 								{ $$ = opr(LE , 2, $1, $3); }
| expression GE  expression 								{ $$ = opr(GE , 2, $1, $3); }
| expression EQ  expression 								{ $$ = opr(EQ , 2, $1, $3); }
| expression NE  expression 								{ $$ = opr(NE , 2, $1, $3); } 
| /* null */ { }
;

statement: 
  t1 
| t2 
| t3 
| t4  
| functioncall 
;

t1 :
  ID '=' NEW ID %prec NEWX		  							{ $$ = NULL; if(searchc($4)==-1){ sprintf(errors[sem_errors], "semantic error in line %d , class not defined \n", countn); sem_errors++; } else copyobj1($1, $4);     }		
| ID '=' NEW ID '(' argslst ')' 							{ $$ = $6  ; if(searchc($4)==-1){ sprintf(errors[sem_errors], "semantic error in line %d , class not defined \n", countn); sem_errors++; } else copyobj2($1, $4, $6); }
;
t2 : ID init 												{ $$ = opr('=', 2, id($1), $2); }
|ERROR 														{ sprintf(lex_errors[lex_cnt], "Lexical error in line %d , Error in defining an Identifier\n", countn); lex_cnt++; } init {;}
;
init: '=' expression  										{ $$ = $2; }
;

t3: ID '.' ID '.' ID '=' expression           				{ $$= obj_value_upd_action($1, $3, $5, $7); }
;

t4 : 
  ID PP 													{ $$= opr(PP,1,id($1)); }
| ID SS 													{ $$ = opr(SS,1,id($1)); }

functioncall : ID '(' { args_count=0; } argslst ')' 		{ $$ = funccall_action($1, $4); }
;

argslst : 
  argslst ',' expression     								{ args_count++; $$ = opr(';', 2, $1  , $3); }
| expression             									{ args_count++; $$ = opr(';', 2, NULL, $1); } 
| /* null */ 		     									{ $$=NULL;} 
%%

int main(int arg_c , char**arg_v) {
	extern FILE* yyin;
	FILE* f = fopen(arg_v[1], "r"); 
	yyin =f;
    yyparse();
	int total_error = lex_cnt + synerrs + sem_errors;
	if(total_error>0){
		printf("\t\t\t---====<<<<<[       PHASE 1: LEXICAL ANALYSIS       ]>>>>>====--- \n\n");
		if(lex_cnt>0) {
			printf("Lexical errors found during Lexical analysis\n\n");
			for(int i=0; i<lex_cnt; i++){
				printf("\t - %s \n", lex_errors[i]);
			}
		}else {
			printf("Lexical analysis completed with ZERO Errors");
			printf("\n\n");	
		}
		printf("\n\n");
		printf("\t\t\t---====<<<<<[       PHASE 2:  SYNTAX ANALYSIS       ]>>>>>====--- \n\n");
		if(synerrs>0) {
			printf("Syntax errors found during syntax analysis\n\n");
			for(int i=0; i<synerrs; i++){
				printf("\t - %s\n", syntax_errors[i]);
			}
		} else {
			printf("Syntax analysis completed with ZERO Errors");
			printf("\n\n");	
		}
		printf("\n\n\n\n");
		printf("\t\t\t---====<<<<<[      PHASE 3:  SEMANTIC ANALYSIS      ]>>>>>====--- \n\n");
		
		if(sem_errors>0) {
			printf("Semantic analysis completed with %d errors\n\n", sem_errors);
			for(int i=0; i<sem_errors; i++){
				printf("\t - %s\n", errors[i]);
			}
		} else {
			printf("Semantic analysis completed with ZERO Errors");
		}

		
		printf("\n\n");
		if(total_error!=0) return 0;
	}

	return 0;
}

void cls_action(nodeType* p1, nodeType* p2){
	class_table[cls_cnt].obj_cnt=0;
	temp_obj[cls_cnt].data_index=0;
	temp_obj[cls_cnt].func_index=0;
	add_cls_data(p1); 
	add_cls_func(p2); 
	cls_cnt++; 
}

nodeType *obj_funccall_action(char* p1, char* p2, char* p3, nodeType* p4){
	int cls_index= searchc(p1);
	int obj_index= search_obj(p1, p2);
	if(cls_index==-1){ 
		sprintf(errors[sem_errors], "semantic error in line %d , class not defined \n", countn); sem_errors++; 
	}else if(obj_index==-1){
		sprintf(errors[sem_errors], "semantic error in line %d , object not created \n", countn); sem_errors++;
	}else if(search_obj_data(cls_index, obj_index, p3, 0)==-1){
		sprintf(errors[sem_errors], "semantic error in line %d , function not declared in the class \n", countn); sem_errors++;
	}else{
		bool valid_funcname=false, valid_args_count=false;
		for(int i=0; i<class_table[cls_index].objtab[obj_index].func_index ; i++){
			if(strcmp(p3, class_table[cls_index].objtab[obj_index].obj_func[i].func_name)==0){
				valid_funcname= true; 
				if(args_count== class_table[cls_index].objtab[obj_index].obj_func[i].num_parem){
					valid_args_count=true;
					break;
				}
				
			}
		}
		if(!valid_funcname){
			sprintf(errors[sem_errors], "semantic error in line %d , function not defined \n", countn); sem_errors++;   
		}else if(!valid_args_count){
			sprintf(errors[sem_errors], "semantic error in line %d , number of arguments not matched with function definition \n", countn); sem_errors++;   
		}else{
			return opr(OBJF, 4, id(p1), id(p2), id(p3), p4);
		}
	}
	return NULL;
}

nodeType *obj_value_access_action(char* p1, char* p2, char* p3){
	int cls_index= searchc(p1);
	int obj_index= search_obj(p1, p2);
	if(cls_index==-1){ 
		sprintf(errors[sem_errors], "semantic error in line %d , class not defined \n", countn); sem_errors++; 
	}else if(obj_index==-1){
		sprintf(errors[sem_errors], "semantic error in line %d , object not created \n", countn); sem_errors++;
	}else if(search_obj_data(cls_index, obj_index, p3, 1)==-1){
		sprintf(errors[sem_errors], "semantic error in line %d , variable not declared in the class \n", countn); sem_errors++;
	}else{
		return opr(OBJV, 3, id(p1), id(p2), id(p3) );
	}
	return NULL;
}

nodeType *obj_value_upd_action(char* p1, char* p2, char* p3, nodeType* p4){
	int cls_index= searchc(p1);
	int obj_index= search_obj(p1, p2);
	if(cls_index==-1){ 
		sprintf(errors[sem_errors], "semantic error in line %d , class not defined \n", countn); sem_errors++; 
	}else if(obj_index==-1){
		sprintf(errors[sem_errors], "semantic error in line %d , object not created \n", countn); sem_errors++;
	}else if(search_obj_data(cls_index, obj_index, p3, 1)==-1){
		sprintf(errors[sem_errors], "semantic error in line %d , variable not declared in the class \n", countn); sem_errors++;
	}else{
		return opr(OBJD, 4, id(p1),id(p2),id(p3),p4);
	}
	return NULL;
}

nodeType *funccall_action(char* p1, nodeType* p2){
	
	bool valid_funcname=false, valid_args_count=false;
	for(int i=0; i<function_cnt ; i++){
        if(strcmp(p1, function_table[i].func_name)==0){
			valid_funcname= true; 
			if(args_count== function_table[i].num_parem){
				valid_args_count=true;
				break;
			}
			
		}
	}
	if(!valid_funcname){
		sprintf(errors[sem_errors], "semantic error in line %d , function not defined \n", countn); sem_errors++;   
	}else if(!valid_args_count){
		sprintf(errors[sem_errors], "semantic error in line %d , number of arguments not matched with function definition \n", countn); sem_errors++;   
	}else{
		return opr(ARROW, 2, id(p1), p2);
	}
	return NULL;
}

void add_cls_data(nodeType *ptr){
   if(!ptr) return;
   switch(ptr->opr.oper){
      case '^':
         {  
            add_cls_data(ptr->opr.op[0]);
            temp_obj[cls_cnt].obj_data[temp_obj[cls_cnt].data_index].id_name = ptr->opr.op[1]->id.i;
			temp_obj[cls_cnt].obj_data[temp_obj[cls_cnt].data_index].value=0; 
			temp_obj[cls_cnt].data_index++;
         }
   }
}

void add_cls_func (nodeType *ptr){
   if(!ptr) return;

   switch(ptr->type){
      case typeOpr:
         {
            switch(ptr->opr.oper){
               case '^':
                  {
                     add_cls_func (ptr->opr.op[0]);
                     add_cls_func (ptr->opr.op[1]);
                  }

               case ';':
                  {
					temp_obj[cls_cnt].obj_func[temp_obj[cls_cnt].func_index].func_name = ptr->opr.op[0]->id.i;
                     temp_obj[cls_cnt].obj_func[temp_obj[cls_cnt].func_index].num_parem = 0;
                     addmethpara(ptr->opr.op[1]);

                     nodeType *p = opr(';', 2, ptr->opr.op[2], ptr->opr.op[3]);
                     temp_obj[cls_cnt].obj_func[temp_obj[cls_cnt].func_index].root = p;
					 temp_obj[cls_cnt].func_index++;
                  }
            }
         }
   }
}

void addmethpara(nodeType *ptr){
if(!ptr) return;

   switch(ptr->type){
      case typeOpr:
         {
            switch(ptr->opr.oper){
               case '!':
                  {
                     addmethpara(ptr->opr.op[0]);
					 int parem_ind= temp_obj[cls_cnt].obj_func[temp_obj[cls_cnt].func_index].num_parem;
					 temp_obj[cls_cnt].obj_func[temp_obj[cls_cnt].func_index].parem_list[parem_ind]= ptr->opr.op[1]->id.i;
					 temp_obj[cls_cnt].obj_func[temp_obj[cls_cnt].func_index].num_parem++;
                     
                  }
            }
         }
   }
}
void copyobj1(char* obj_name, char* cls_name){
	int cls_index= searchc(cls_name);
	int obj_index= class_table[cls_index].obj_cnt;
	class_table[cls_index].objtab[obj_index] = temp_obj[cls_index]; 
	class_table[cls_index].objtab[obj_index].obj_name= obj_name;
	class_table[cls_index].obj_cnt++;
	return;
}
void copyobj2(char* obj_name, char* cls_name, nodeType* ptr){
	int cls_index= searchc(cls_name);
	int obj_index= class_table[cls_index].obj_cnt;
	if(args_count != temp_obj[cls_index].data_index){
		printf("%d\n", args_count);
		sprintf(errors[sem_errors], "semantic error in line %d: number of arguments given doesn't match number of member variables defined in this class \n", countn);
		sem_errors++;
	}else{
		class_table[cls_index].objtab[obj_index] = temp_obj[cls_index]; 
		class_table[cls_index].objtab[obj_index].obj_name= obj_name;
		args_count=0;
		addobjargs(cls_index, obj_index, ptr);
		class_table[cls_index].obj_cnt++;
	}
	return;
}

void addobjargs(int cls_index,int obj_index, nodeType *ptr){
if(!ptr) return;

   switch(ptr->type){
      case typeOpr:
         {
            switch(ptr->opr.oper){
               case ';':
                  {
                     addobjargs(cls_index, obj_index, ptr->opr.op[0]); 
					 class_table[cls_index].objtab[obj_index].obj_data[args_count].value= ex(ptr->opr.op[1]);
                     args_count++;
                  }
            }
         }
   }
}

int search(char *type) {
	int i;
	for(i=0;i<symbol_table_lst[symbol_table_lst_itr].symbol_table_itr ;i++) {
		if(strcmp(symbol_table_lst[symbol_table_lst_itr].symbol_table[i].id_name, strdup(type))==0) {
			return i;
		}
	}
	return -1;
}

void addf(char* func_name, nodeType *root){
		for(int i=0; i<sizeof(reserved)/sizeof(reserved[0]); i++){
			if(!strcmp(reserved[i], strdup(func_name))){
        		sprintf(errors[sem_errors], "Line %d: function name \"%s\" is a reserved keyword!\n", countn+1, func_name);
				sem_errors++;   
				return;
			}
		}	
    //int q=searchf(func_name);
	int q=-1;
	if(q==-1) {
			function_cnt--;
			for(int i=0; i<func_parem_temp_itr; i++){
				function_table[function_cnt].parem_list[i]= func_parem_temp[i];
			}
			//reset func_parem values
			func_parem_temp_itr=0;

			function_table[function_cnt].root= root;
			function_cnt++;
    }		
}

int searchf(char *type) {
	int i;
	for(i=0;i<function_cnt;i++) {
		if(strcmp(function_table[i].func_name, strdup(type))==0) { //should search for parameters also
			return i;
		}
	}
	return -1;
}

int searchc(char *type) {
	int i;
	for(i=0;i<cls_cnt;i++) {
		if(strcmp(class_table[i].cls_name, strdup(type))==0) { //should search for parameters also
			return i;
		}
	}
	return -1;
}

int search_obj(char *cls_name, char* obj_name) {
	int i;
	int x=class_table[searchc(cls_name)].obj_cnt; 
	for(i=0;i<x;i++) {
		if(strcmp(class_table[searchc(cls_name)].objtab[i].obj_name, strdup(obj_name))==0) { //should search for parameters also
			return i;
		}
	}
	return -1;
}

int search_obj_data(int cls_index, int obj_index, char* name, int data) {
	int i;
	int x;
	if(data==1){ 
		x=class_table[cls_index].objtab[obj_index].data_index; 
	}
	else {
		x= class_table[cls_index].objtab[obj_index].func_index;
	}
	for(i=0;i<x;i++) {
		char* type;
		if(data==1){ 
			type=strdup(class_table[cls_index].objtab[obj_index].obj_data[i].id_name); 
		}
		else {
			type=strdup(class_table[cls_index].objtab[obj_index].obj_func[i].func_name); 
		}
		if(strcmp(name, strdup(type))==0) { //should search for parameters also
			return i;
		}
	}
	return -1;
}
#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)
nodeType *con(double value) {
    nodeType *p;
    /* allocate node */ 
    if ((p = malloc(sizeof(nodeType))) == NULL) yyerror("out of memory");
    /* copy information */
    p->type = typeCon;
    p->con.value = value;
    return p;
}
nodeType *id(char* i) { 
    nodeType *p;
    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)  yyerror("out of memory");
    /* copy information */
    p->type = typeId;
    p->id.i = strdup(i);
    return p; 
} 
nodeType *opr(int oper, int nops, ...) {
    va_list ap; 
    nodeType *p;
    int i; 
    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)  yyerror("out of memory");
    if ((p->opr.op = malloc(nops * sizeof(nodeType))) == NULL) yyerror("out of memory");
    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++) p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
} 
void freeNode(nodeType *p) {
    int i;
    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
        free(p->opr.op);
    }
    free (p);
} 

void yyerror(char* msg) { 
		sprintf(syntax_errors[synerrs], "%s in line no: %d\n", msg, countn);
		synerrs++;   
} 
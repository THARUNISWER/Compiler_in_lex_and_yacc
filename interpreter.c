#include <stdio.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>  
#include "header.h"
#include "parser.tab.h"
bool is_return=false;
extern void freeNode(nodeType *p);
extern int search(char *); 
extern int searchf(char *);
extern int searchc(char *);
extern int search_obj(char *clsname, char* obj_name) ;
extern int search_obj_data(int cls_index, int obj_index, char* name, int data);
void addn(char *);
extern double ex(nodeType *p);
void ex1(nodeType *p);

extern int symbol_table_lst_itr;
extern symtab symbol_table_lst[10];

extern int function_cnt;
double func_args_temp[10];
int func_args_temp_itr;	
extern functab function_table[10];

extern int cls_cnt;
extern cls class_table[10];
extern object_node temp_obj[10];
int cls_index;
int obj_index;
int data_index;
int func_index;

extern char reserved[15][10];
extern char errors[10][100];
extern int sem_errors;
extern int countn;

double doub;
int in;
double zero=0;
char* str;

void addn(char* name) {  
		for(int i=0; i<sizeof(reserved)/sizeof(reserved[0]); i++){
			if(!strcmp(reserved[i], strdup(name))){
        		sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword!\n", countn+1, name);
				sem_errors++;
				return;
			}
		}
    int q=search(name);
	if(q==-1) {
			symbol_table_lst[symbol_table_lst_itr].symbol_table[symbol_table_lst[symbol_table_lst_itr].symbol_table_itr].id_name=strdup(name);
            symbol_table_lst[symbol_table_lst_itr].symbol_table[symbol_table_lst[symbol_table_lst_itr].symbol_table_itr].value= 0;
			symbol_table_lst[symbol_table_lst_itr].symbol_table_itr++;
    }
}
//for taking function args  
void ex1(nodeType *p){
    if (!p) return ;
    switch(p->type) {
        case typeCon: 
            func_args_temp[func_args_temp_itr]= p->con.value; func_args_temp_itr++; return;    
        case typeId:
            func_args_temp[func_args_temp_itr]= symbol_table_lst[symbol_table_lst_itr].symbol_table[search(p->id.i)].value; func_args_temp_itr++; return;
        case typeOpr:
            switch(p->opr.oper) { 
                case ';':  ex1(p->opr.op[0]); ex1(p->opr.op[1]);  return; 
                case UMINUS:  func_args_temp[func_args_temp_itr]= -ex(p->opr.op[0]); func_args_temp_itr++; return; 
                case '+':  func_args_temp[func_args_temp_itr]= ex(p->opr.op[0]) + ex(p->opr.op[1]);func_args_temp_itr++; return;
                case '-':  func_args_temp[func_args_temp_itr]=ex(p->opr.op[0]) - ex(p->opr.op[1]); func_args_temp_itr++;return;
                case '*':  func_args_temp[func_args_temp_itr]=ex(p->opr.op[0]) * ex(p->opr.op[1]);func_args_temp_itr++;return;
                case '/':  if(ex(p->opr.op[1])!=zero){ func_args_temp[func_args_temp_itr]=ex(p->opr.op[0]) / ex(p->opr.op[1]); func_args_temp_itr++; } else{ printf("run time error, divided by zero!!!\n"); }  return;
            }
    }
}
int z, a, b;
double ex(nodeType *p){
    if (!p) return 0;
    switch(p->type) {
        case typeCon: 
            //printf("%d\n", p->con.value); 
            return p->con.value;
        case typeId: 
            //printf("%s\n", p->id.i);
            addn(p->id.i);
            return symbol_table_lst[symbol_table_lst_itr].symbol_table[search(p->id.i)].value; 
        case typeOpr:
            //printf("%d\n", p->opr.oper);
            switch(p->opr.oper) { 
                case FOR: 
                    ex(p->opr.op[0]);
                    while (ex(p->opr.op[1])){
                        //printf("%d\n", p->opr.op[3]->opr.oper);
                        int z= ex(p->opr.op[3]);
                        if(is_return) return z;
                        ex(p->opr.op[2]);
                    }
                    return 0;
                case WHILE: while(ex(p->opr.op[0])){ 
                         int z= ex(p->opr.op[1]);
                        if(is_return) return z;
                 } return 0;
                case IF: if (ex(p->opr.op[0])) {
                            int z= ex(p->opr.op[1]);
                            if(is_return) return z;
                        }else if (p->opr.nops > 2) {
                            int z= ex(p->opr.op[2]);
                            if(is_return) return z;                          
                        }return 0;
                case WRITE: 
                    doub= ex(p->opr.op[0]);
                    in= (int)doub;
                    zero=0;
                    if(doub-in==zero){
                        printf("%d\n", in); 
                    }else{
                        printf("%lf\n", doub); 
                    }
                    return 0;
                case WRITE_S:
                    str = p->opr.op[0]->id.i;
                    printf("%s\n",str);
                    return 0;
                case READ:
                    //char* symbol_table_lst[symbol_table_lst_itr].symbol_table[search(p->opr.op[0]->id.i)].value= p->opr.op[0]->id.i;
                    ex(p->opr.op[0]);
                    scanf("%lf", &symbol_table_lst[symbol_table_lst_itr].symbol_table[search(p->opr.op[0]->id.i)].value);
                    return 0;
                case ';': 
                    z= ex(p->opr.op[0]);
                    if(is_return) return z;
                    return ex(p->opr.op[1]);
                case '=': ex(p->opr.op[0]); return symbol_table_lst[symbol_table_lst_itr].symbol_table[search(p->opr.op[0]->id.i)].value = ex(p->opr.op[1]); 
                case '+': return ex(p->opr.op[0]) + ex(p->opr.op[1]);
                case '-': return ex(p->opr.op[0]) - ex(p->opr.op[1]);
                case '*': return ex(p->opr.op[0]) * ex(p->opr.op[1]);
                case '/': if(ex(p->opr.op[1])!=zero) return ex(p->opr.op[0]) / ex(p->opr.op[1]); else{ printf("run time error, divided by zero!!!\n"); return zero; }
                case '%': a= (int)ex(p->opr.op[0])+1e-9, b= (int)ex(p->opr.op[1])+1e-9; if(b!=0) return a % b; else{ printf("run time error, divided by zero!!!\n"); return zero; }
                case '^': a= (int)ex(p->opr.op[0])+1e-9, b= (int)ex(p->opr.op[1])+1e-9; return (double)pow(a, b);
                case UMINUS: return -ex(p->opr.op[0]);
                case '<': return ex(p->opr.op[0]) < ex(p->opr.op[1]);
                case '>': return ex(p->opr.op[0]) > ex(p->opr.op[1]);
                case GE: return ex(p->opr.op[0]) >= ex(p->opr.op[1]);
                case LE: return ex(p->opr.op[0]) <= ex(p->opr.op[1]);
                case NE: return ex(p->opr.op[0]) != ex(p->opr.op[1]);
                case EQ: return ex(p->opr.op[0]) == ex(p->opr.op[1]);
                case PP: ex(p->opr.op[0]); symbol_table_lst[symbol_table_lst_itr].symbol_table[search(p->opr.op[0]->id.i)].value++; return symbol_table_lst[symbol_table_lst_itr].symbol_table[search(p->opr.op[0]->id.i)].value;
                case SS: ex(p->opr.op[0]); symbol_table_lst[symbol_table_lst_itr].symbol_table[search(p->opr.op[0]->id.i)].value--; return symbol_table_lst[symbol_table_lst_itr].symbol_table[search(p->opr.op[0]->id.i)].value;
                case PE: ex(p->opr.op[0]); return symbol_table_lst[symbol_table_lst_itr].symbol_table[search(p->opr.op[0]->id.i)].value += ex(p->opr.op[1]);
                case SE: ex(p->opr.op[0]); return symbol_table_lst[symbol_table_lst_itr].symbol_table[search(p->opr.op[0]->id.i)].value -= ex(p->opr.op[1]);
                case ME: ex(p->opr.op[0]); return symbol_table_lst[symbol_table_lst_itr].symbol_table[search(p->opr.op[0]->id.i)].value *= ex(p->opr.op[1]);
                case DE: ex(p->opr.op[0]); return symbol_table_lst[symbol_table_lst_itr].symbol_table[search(p->opr.op[0]->id.i)].value /= ex(p->opr.op[1]);
                case RETURN: is_return=true; return ex(p->opr.op[0]); 
                case ARROW:
                    for(int i=0; i<function_cnt ; i++){
                        if(strcmp(p->opr.op[0]->id.i, function_table[i].func_name)==0){
                            //storing function args in func_args_temp[] array
                            ex1(p->opr.op[1]);

                            //new symbol_table element for new function call 
                            symbol_table_lst_itr++;

                            // adding argument values to symbol table of this function call 
                            symbol_table_lst[symbol_table_lst_itr].symbol_table_itr=0;
                            for(; symbol_table_lst[symbol_table_lst_itr].symbol_table_itr <function_table[i].num_parem ; symbol_table_lst[symbol_table_lst_itr].symbol_table_itr++){
                                symbol_table_lst[symbol_table_lst_itr].symbol_table[symbol_table_lst[symbol_table_lst_itr].symbol_table_itr].id_name= function_table[i].parem_list[symbol_table_lst[symbol_table_lst_itr].symbol_table_itr];
                                symbol_table_lst[symbol_table_lst_itr].symbol_table[symbol_table_lst[symbol_table_lst_itr].symbol_table_itr].value= func_args_temp[symbol_table_lst[symbol_table_lst_itr].symbol_table_itr];
                            }

                            //reset args itr 
                            func_args_temp_itr=0;

                            //executing the func body after initialising its symbol table with given arguments 
                            int res= ex(function_table[i].root);
                            is_return=0;
                            if(symbol_table_lst_itr-1>=0) symbol_table_lst_itr--;
                            return res;
                        }
                    }
                case OBJV:
                    cls_index= searchc(p->opr.op[0]->id.i);
                    obj_index= search_obj(p->opr.op[0]->id.i, p->opr.op[1]->id.i);
                    data_index= search_obj_data(cls_index, obj_index, p->opr.op[2]->id.i, 1);
                    return class_table[cls_index].objtab[obj_index].obj_data[data_index].value; 
                case OBJD:
                    cls_index= searchc(p->opr.op[0]->id.i);
                    obj_index= search_obj(p->opr.op[0]->id.i, p->opr.op[1]->id.i);
                    data_index= search_obj_data(cls_index, obj_index, p->opr.op[2]->id.i, 1);
                    class_table[cls_index].objtab[obj_index].obj_data[data_index].value= ex(p->opr.op[3]);
                    return class_table[cls_index].objtab[obj_index].obj_data[data_index].value;
                case OBJF:
                    cls_index= searchc(p->opr.op[0]->id.i);
                    obj_index= search_obj(p->opr.op[0]->id.i, p->opr.op[1]->id.i);
                    func_index= search_obj_data(cls_index, obj_index, p->opr.op[2]->id.i, 0);

                    ex1(p->opr.op[3]);

                    symbol_table_lst_itr++;

                    // adding argument values to symbol table of this function call 
                    int i=0;
                    int parems= class_table[cls_index].objtab[obj_index].obj_func[func_index].num_parem;
                    for(;i<parems; i++){
                        symbol_table_lst[symbol_table_lst_itr].symbol_table[i].id_name= class_table[cls_index].objtab[obj_index].obj_func[func_index].parem_list[i];
                        symbol_table_lst[symbol_table_lst_itr].symbol_table[i].value= func_args_temp[i];
                        //printf("%d ", func_args_temp[i]);
                    }
                    
                    // adding class member variables to this symbol table
                    int vars= class_table[cls_index].objtab[obj_index].data_index;
                    for(; i<parems+vars;i++){
                        symbol_table_lst[symbol_table_lst_itr].symbol_table[i].id_name= class_table[cls_index].objtab[obj_index].obj_data[i-parems].id_name;
                        symbol_table_lst[symbol_table_lst_itr].symbol_table[i].value= class_table[cls_index].objtab[obj_index].obj_data[i-parems].value;
                        //printf("%d ", class_table[cls_index].objtab[obj_index].obj_data[i-parems].value);
                    }
                    //printf("\n");

                    symbol_table_lst[symbol_table_lst_itr].symbol_table_itr=i;
                    //reset args itr 
                    func_args_temp_itr=0;

                    //executing the func body after initialising its symbol table with given arguments 
                    int res= ex(class_table[cls_index].objtab[obj_index].obj_func[func_index].root);
                    is_return=0;

                    int data_cnt= class_table[cls_index].objtab[obj_index].data_index;
                    for(int j=0; j<data_cnt;j++){
                        class_table[cls_index].objtab[obj_index].obj_data[j].value= symbol_table_lst[symbol_table_lst_itr].symbol_table[parems+j].value;
                    }
                    if(symbol_table_lst_itr-1>=0) symbol_table_lst_itr--;
                    return res;   
            }
    }
    return 0;
}

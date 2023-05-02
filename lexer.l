%{
    #include <stdlib.h>
    #include "header.h"
    #include "parser.tab.h"
    void yyerror(char *);
    int countn=1;
%}
%option yylineno

alpha [a-zA-Z]
digit [0-9]

%%
"|>"                        { /* Start of a multi-line comment */ char ch = input();
                                while (ch != '<' || input() != '|') {
                                    ch = input();
                                }
                            }
"|=>"                       { /* Start of a single-line comment */
                                char ch = input();
                                while (ch != '\n') {
                                    ch = input();
                                }
                            }
"->"                        { return ARROW; }
"main"                      { return MAIN; }
"class"                     { return CLASS;}
"con"                       { return CONSTRUCTOR; }
"new"                       { return NEW; }
"write"                     { return WRITE; }
"read"                      { return READ; }
"void"                      { return VOID; }
"return"                    { return RETURN; }
"go"	                    { return FOR; }
"until"                     { return WHILE; }
"see"	                    { return IF; }
"or"	                    { return ELSE; }
"def"                       { return DEF; } 
(({digit}+){alpha}+)+       { return ERROR; }
({digit}+\.{digit}{1,6}|{digit}+)     { yylval.iValue = atof(yytext); return NUMBER; }
({alpha}|[_])({alpha}|{digit}|[_])*   {  yylval.name = strdup(yytext); return ID; }
"++"                        { return PP;}
"--"                        { return SS;}
"+="                        { return PE;}
"-="                        { return SE;}
"*="                        { return ME;}
"/="                        { return DE;}
"<="                        { return LE; }
">="                        { return GE; }
"=="                        { return EQ; }
"!="                        { return NE; }  
[ \t]*                      { ; } 
[\n]                        { countn++; }
["].*["]                    { yylval.name = strdup(yytext);return STR; } 
.                           { return *yytext;}


%%

int yywrap() {
    return 1;
}

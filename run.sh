bison -d parser.y
flex lexer.l
cc lex.yy.c parser.tab.c interpreter.c -o tap_c.out -lm

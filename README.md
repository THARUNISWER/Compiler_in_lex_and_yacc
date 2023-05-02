# Compiler_in_lex_and_yacc
A compiler made in Lex and Yacc along with an interpreter for a new language "TAP". The language "TAP" can detect lexical, syntactical, semantical errors and also execute. It supports procedural code, functions, classes and objects.
1. Download and open folder in vscode <br>
2. Run the following commands <br>
bison -d parser.y <br>
flex lexer.l <br>
gcc lex.yy.c parser.tab.c interpreter.c -o tap_c.exe <br>
type ./test_cases/fibR.tap|.\tap_c.exe <br>
3. Any input test case can be run in this type <br>
4. Lexer file can be seen for understanding C based syntax morphing

lex jac.l
yacc -d -v jac.y
gcc -g -c ast.c -o ast
clang-3.8 -Wall -Wno-unused-function -o jac ast y.tab.c lex.yy.c -g -ll -ly 
./jac $1 < $2
zip jac.zip jac.l jac.y ast.h ast.c

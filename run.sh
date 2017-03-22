lex jac.l
yacc -d -v jac.y
clang-3.8 -ll -ly -Wall -Wno-unused-function -o jac y.tab.c lex.yy.c
./jac $1 < $2
zip jac.zip jac.l jac.y

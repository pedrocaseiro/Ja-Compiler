lex jac.l
clang-3.8 -Wall -Wno-unused-function -o jac lex.yy.c
./jac $1 < $2
zip jac.zip jac.l

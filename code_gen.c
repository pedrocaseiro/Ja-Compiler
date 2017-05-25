#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include "ast.h"
#include "symbol_table.h"
#include "code_gen.h"

char* class;
//counter variaveis temporarias
//counter strings
//counter calls para igualar quando chamamos
//class.method.nome.argumentos
//

char* return_type_to_llvm(char* type){

  if(!strcmp(type, "int") || !strcmp(type, "Int")){
    return "i32";
  } else if(!strcmp(type, "double") || !strcmp(type, "Double")){
    return "double";
  } else if(!strcmp(type, "boolean") || !strcmp(type, "Boolean")){
    return "i1";
  } else if(!strcmp(type, "void") || !strcmp(type, "Void") ){
    return "void";
  } else if(!strcmp(type, "StringArray") || !strcmp(type, "String[]")){
    return "i32 %argc, i8** %argv";
  } else {
    return "undefined";
  }
}

char* parse_arguments_type(char* type){
  if(!strcmp(type, "int") || !strcmp(type, "Int")){
    return "int";
  } else if(!strcmp(type, "double") || !strcmp(type, "Double")){
    return "double";
  } else if(!strcmp(type, "boolean") || !strcmp(type, "Boolean")){
    return "boolean";
  } else if(!strcmp(type, "void") || !strcmp(type, "Void") ){
    return "void";
  } else if(!strcmp(type, "StringArray") || !strcmp(type, "String[]")){
    return "stringArray";
  } else {
    return "undefined";
  } 
}

void code_generation(node* n){
  int i;
  if(!strcmp(n->token->id, "Program")){
    class = n->childs[0]->value;
    // main do llvm
    printf("define i32 @main(i32 %%argc, i8** %%argv){\n");
    printf("    call void @%s.method.main.stringArray(i32 %%argc, i8** %%argv)\n", class);
    printf("    ret i32 0\n");
    printf("}\n");
    for(i = 0; i < n->n_children; i++){
      code_generation(n->childs[i]);
    }
  } else if(!strcmp(n->token->id, "FieldDecl")){

  } else if(!strcmp(n->token->id, "MethodDecl")){
      printf("define %s @%s.method.%s", return_type_to_llvm(n->childs[0]->childs[0]->value), class, n->childs[0]->childs[1]->value);
      for(i = 0; i < n->childs[0]->childs[2]->n_children; i++){
        printf(".");
        printf("%s", parse_arguments_type(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id));
      }
      printf("(");
      for(i = 0; i < n->childs[0]->childs[2]->n_children; i++){
        printf("%s", return_type_to_llvm(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id));
        if(i != n->childs[0]->childs[2]->n_children - 1) printf(",");
      }
      printf("){\n");
      printf("    ret %s\n", return_type_to_llvm(n->childs[0]->childs[0]->value));   
      printf("}"); 
  }
}

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
int temporary_counter;
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
  } else if(!strcmp(type, "bool") || !strcmp(type, "Bool")){
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
  } else if(!strcmp(type, "bool") || !strcmp(type, "Bool")){
    return "boolean";
  } else if(!strcmp(type, "void") || !strcmp(type, "Void") ){
    return "void";
  } else if(!strcmp(type, "StringArray") || !strcmp(type, "String[]")){
    return "stringArray";
  } else {
    return "undefined";
  } 
}

void generate_fielddecl(node* n){
  if(!strcmp(n->childs[0]->token->id, "Int")){
    printf("@%s.%s.global = common global %s 0\n", n->childs[1]->value, class, return_type_to_llvm(n->childs[0]->token->id));
  }else if(!strcmp(n->childs[0]->token->id, "Double")){
    printf("@%s.%s.global = common global %s 0.0\n", n->childs[1]->value, class, return_type_to_llvm(n->childs[0]->token->id));
  } else if(!strcmp(n->childs[0]->token->id, "Bool")){
    printf("@%s.%s.global = common global %s 0\n", n->childs[1]->value, class, return_type_to_llvm(n->childs[0]->token->id));
  }
}

void generate_vardecl(node* n){
   //TODO: GUARDAR COM NOME E ARGUMENTOS DO METODO
   if(!strcmp(n->childs[0]->token->id, "Int")){
    printf("    %%%s.%s.local = alloca %s\n", n->childs[1]->value, class, return_type_to_llvm(n->childs[0]->token->id));
  }else if(!strcmp(n->childs[0]->token->id, "Double")){
    printf("    %%%s.%s.local = alloca %s\n", n->childs[1]->value, class, return_type_to_llvm(n->childs[0]->token->id));
  } else if(!strcmp(n->childs[0]->token->id, "Bool")){
    printf("    %%%s.%s.local = alloca %s\n", n->childs[1]->value, class, return_type_to_llvm(n->childs[0]->token->id));
  }

}

void generate_methoddecl(node *n){
  int i;
  printf("define %s @%s.method.%s", return_type_to_llvm(n->childs[0]->childs[0]->value), class, n->childs[0]->childs[1]->value);
  for(i = 0; i < n->childs[0]->childs[2]->n_children; i++){
    printf(".");
    printf("%s", parse_arguments_type(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id));
  }
  printf("(");
  //print arguments
  for(i = 0; i < n->childs[0]->childs[2]->n_children; i++){
    printf("%s %s", return_type_to_llvm(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id), n->childs[0]->childs[2]->childs[i]->childs[1]->value);
    if(i != n->childs[0]->childs[2]->n_children - 1) printf(", ");
  }
  printf("){\n");
  //%argc.addr = alloca i32
  for(i = 0; i < n->childs[0]->childs[2]->n_children; i++){
    if(!strcmp(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id, "StringArray")){
      printf("    %%args.addr = alloca i32\n");
      printf("    %%argv.addr = alloca i8**\n");
    } else {
      printf("    %%%s.addr = alloca %s\n", n->childs[0]->childs[2]->childs[i]->childs[1]->value, return_type_to_llvm(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id));
    }
  }
  // TODO: %retval = alloca i32/i1...
  for(i = 0; i < n->childs[1]->n_children; i++){
    code_generation(n->childs[1]->childs[i]);
  }
  if(!strcmp(n->childs[0]->childs[0]->token->id, "Int")){
    printf("    ret %s 0\n", return_type_to_llvm(n->childs[0]->childs[0]->value));   
  }else if(!strcmp(n->childs[0]->childs[0]->token->id, "Double")){
    printf("    ret %s 0.0\n", return_type_to_llvm(n->childs[0]->childs[0]->value));   
  } else if(!strcmp(n->childs[0]->childs[0]->token->id, "Bool")){
    printf("    ret %s 0\n", return_type_to_llvm(n->childs[0]->childs[0]->value));   
  } else if(!strcmp(n->childs[0]->childs[0]->token->id, "Void")){
    printf("    ret %s\n", return_type_to_llvm(n->childs[0]->childs[0]->value));   
  }
  printf("}\n"); 
}


void generate_print(node* n){
  if(!strcmp(n->childs[0]->childs[0]->anotated_type, "int")){
    //declit
    if(!strcmp(n->childs[0]->childs[0]->token->id, "Declit")){
      printf("%%call%d = call %d (i8*, ...) @printf(i8* getelementptr inbounds ([]) )")
         /*%call1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i      32 0, i32 0), i32 5)*/
    }
    //id
    else if(!strcmp(n->childs[0]->childs[0]->token->id, "Id")){

    }
    //.length 
    else if(!strcmp(n->childs[0]->childs[0]->token->id, "Length")){

    }
    //Integer.parseInt()
    else if(!strcmp(n->childs[0]->childs[0]->token->id, "ParseArgs")){

    } 
    // unary minus
    else if(!strcmp(n->childs[0]->childs[0]->token->id, "ParseArgs")){

    }
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
      generate_fielddecl(n); 
  } else if(!strcmp(n->token->id, "MethodDecl")){
      generate_methoddecl(n);
  } else if(!strcmp(n->token->id, "VarDecl")){
      generate_vardecl(n);
  } else if(!strcmp(n->token->id, "Print")){
      generate_print(n);
  }
}

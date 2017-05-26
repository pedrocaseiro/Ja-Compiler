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

// we start at 1 because of labels
int current_scope = 1;
int current_temporary = 1;

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
    printf("@%s.%s = common global %s 0\n", class, n->childs[1]->value, return_type_to_llvm(n->childs[0]->token->id));
    n->childs[1]->pointer_table->llvm_type = return_type_to_llvm(n->childs[0]->token->id);
  }else if(!strcmp(n->childs[0]->token->id, "Double")){
    printf("@%s.%s = common global %s 0.0\n", class, n->childs[1]->value, return_type_to_llvm(n->childs[0]->token->id));
    n->childs[1]->pointer_table->llvm_type = return_type_to_llvm(n->childs[0]->token->id);
  } else if(!strcmp(n->childs[0]->token->id, "Bool")){
    printf("@%s.%s = common global %s 0\n", class, n->childs[1]->value, return_type_to_llvm(n->childs[0]->token->id));
    n->childs[1]->pointer_table->llvm_type = return_type_to_llvm(n->childs[0]->token->id);
  }
}

void generate_vardecl(node* n){
  if(!strcmp(n->childs[0]->token->id, "Int")){
    printf("    %%%s = alloca %s\n", n->childs[1]->value, return_type_to_llvm(n->childs[0]->token->id));
    n->childs[1]->pointer_table->llvm_type = return_type_to_llvm(n->childs[0]->token->id);
  }else if(!strcmp(n->childs[0]->token->id, "Double")){
    printf("    %%%s = alloca %s\n", n->childs[1]->value, return_type_to_llvm(n->childs[0]->token->id));
    n->childs[1]->pointer_table->llvm_type = return_type_to_llvm(n->childs[0]->token->id);
  } else if(!strcmp(n->childs[0]->token->id, "Bool")){
    printf("    %%%s = alloca %s\n", n->childs[1]->value, return_type_to_llvm(n->childs[0]->token->id));
    n->childs[1]->pointer_table->llvm_type = return_type_to_llvm(n->childs[0]->token->id);
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
    if(!strcmp(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id, "StringArray")){
      printf("i32 %%argc, i8** %%argv");
    } else {
      printf("%s %s", return_type_to_llvm(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id), n->childs[0]->childs[2]->childs[i]->childs[1]->value);
    }
    if(i != n->childs[0]->childs[2]->n_children - 1) printf(", ");
  }
  printf("){\n");
  //%argc.addr = alloca i32
  for(i = 0; i < n->childs[0]->childs[2]->n_children; i++){
    if(!strcmp(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id, "StringArray")){
      printf("    %%argc.addr = alloca i32\n");
      printf("    %%argv.addr = alloca i8**\n");
      //n->childs[0]->childs[2]->childs[i]->childs[0]->llvm_type = "StringArray";
    } else {
      printf("    %%%s.addr = alloca %s\n", n->childs[0]->childs[2]->childs[i]->childs[1]->value, return_type_to_llvm(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id));
      //n->childs[0]->childs[2]->childs[i]->childs[0]->llvm_type = return_type_to_llvm(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id);
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
/*
  if(!strcmp(n->childs[0]->childs[0]->pointer_table->llvm_type, "i32")){

  }else if(!strcmp(n->childs[0]->childs[0]->pointer_table->llvm_type, "double")){

  }else if(!strcmp(n->childs[0]->childs[0]->pointer_table->llvm_type, "i1")){

  }else if(!strcmp(n->childs[0]->childs[0]->pointer_table->llvm_type, "StringArray")){

  }*/
}

void generate_assign(node *n){

}

// when we find a node id, we want to load it
void generate_id(node *n){

  if(n->pointer_table != NULL){

    if(!strcmp(n->pointer_table->llvm_type, "i32")){
      printf("    %%%d = load %s, %s* %%%s\n", current_temporary, n->pointer_table->llvm_type, n->pointer_table->llvm_type, n->value);
      n->address = current_temporary;
    } else if(!strcmp(n->pointer_table->llvm_type, "double")){
      printf("    %%%d = load %s, %s* %%%s\n", current_temporary, n->pointer_table->llvm_type, n->pointer_table->llvm_type, n->value);
    } else if(!strcmp(n->pointer_table->llvm_type, "i1")){
      printf("    %%%d = load %s, %s* %%%s\n", current_temporary, n->pointer_table->llvm_type, n->pointer_table->llvm_type, n->value);
    } else if(!strcmp(n->pointer_table->llvm_type, "StringArray")){
      printf("    %%%d = load %s, %s* %%%s\n", current_temporary, n->pointer_table->llvm_type, n->pointer_table->llvm_type, n->value);

    }
    current_temporary++;
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
    current_scope++;
    current_temporary = 1;
    generate_methoddecl(n);
  } else if(!strcmp(n->token->id, "VarDecl")){
    generate_vardecl(n);
  } else if(!strcmp(n->token->id, "Print")){
    for(i = 0; i < n->n_children; i++){
      code_generation(n->childs[i]);
    }
    generate_print(n);
  } else if(!strcmp(n->token->id, "Assign")){
    generate_assign(n);
  } else if(!strcmp(n->token->id, "Id") /*&& strcmp(n->llvm_type, "undefined")*/){
    generate_id(n);
  }
}

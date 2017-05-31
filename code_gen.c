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
int print_int = 0;
char* global_string_print[1000];
int string_counter = 0;
int final_size = 0;
int assign_var;

int array_counter = 0;


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


char* parse_string(char* str){
  char* new_string = (char*) malloc(1000*sizeof(char));
  int size = strlen(str);
  int index=0;
  final_size=0;
  int i;

  for (i = 0; i < size-1; i++) {

    if(str[i] == '\\' && str[i+1] == 'n'){
      new_string[index] = '\\';
      index++;
      new_string[index] = '0';
      index++;
      new_string[index] = 'A';
      index++;
      final_size++;
      i++;
    } else if(str[i] == '\\' && str[i+1] == 'r'){
        new_string[index] = '\\';
        index++;
        new_string[index] = '0';
        index++;
        new_string[index] = 'D';
        index++;
        final_size++;
        i++;
    } else if(str[i] == '\\' && str[i+1] == 't'){
        new_string[index] = '\\';
        index++;
        new_string[index] = '0';
        index++;
        new_string[index] = '9';
        index++;
        final_size++;
        i++;
    } else if(str[i] == '\\' && str[i+1] == 'f'){
        new_string[index] = '\\';
        index++;
        new_string[index] = '0';
        index++;
        new_string[index] = 'C';
        index++;
        final_size++;
        i++;
    } else if(str[i] == '\\' && str[i+1] == '\\'){
        new_string[index] = '\\';
        index++;
        new_string[index] = '5';
        index++;
        new_string[index] = 'C';
        index++;
        final_size++;
        i++;
    } else if(str[i] == '\\' && str[i+1] == '\"'){
        new_string[index] = '\\';
        index++;
        new_string[index] = '2';
        index++;
        new_string[index] = '2';
        index++;
        final_size++;
        i++;
      } else if(str[i] == '%'){
          new_string[index] = '%';
          index++;
          new_string[index] = '%';
          index++;
          final_size+=2;
      } else{
        if(str[i] != '"'){
          new_string[index] = str[i];
          index++;
          final_size++;
        }
      }
    }

    new_string[index] = '\\';
    index++;
    new_string[index] = '0';
    index++;
    new_string[index] = 'A';
    index++;
    final_size++;
    new_string[index] = '\\';
    index++;
    new_string[index] = '0';
    index++;
    new_string[index] = '0';
    index++;
    final_size++;

    new_string[index] = '\0';

    return new_string;
}

void generate_fielddecl(node* n){
  if(!strcmp(n->childs[0]->token->id, "Int")){
    printf("@%s.%s = common global %s 0\n", class, n->childs[1]->value, return_type_to_llvm(n->childs[0]->token->id));
    n->childs[1]->pointer_table->llvm_type = return_type_to_llvm(n->childs[0]->token->id);
    n->childs[1]->pointer_table->is_global = 1;
  }else if(!strcmp(n->childs[0]->token->id, "Double")){
    printf("@%s.%s = common global %s 0.0\n", class, n->childs[1]->value, return_type_to_llvm(n->childs[0]->token->id));
    n->childs[1]->pointer_table->llvm_type = return_type_to_llvm(n->childs[0]->token->id);
    n->childs[1]->pointer_table->is_global = 1;
  } else if(!strcmp(n->childs[0]->token->id, "Bool")){
    printf("@%s.%s = common global %s 0\n", class, n->childs[1]->value, return_type_to_llvm(n->childs[0]->token->id));
    n->childs[1]->pointer_table->llvm_type = return_type_to_llvm(n->childs[0]->token->id);
    n->childs[1]->pointer_table->is_global = 1;
  }

}

void generate_vardecl(node* n){
  if(!strcmp(n->childs[0]->token->id, "Int")){
    printf("    %%%s = alloca %s\n", n->childs[1]->value, return_type_to_llvm(n->childs[0]->token->id));
    n->childs[1]->pointer_table->llvm_type = return_type_to_llvm(n->childs[0]->token->id);
    n->childs[1]->pointer_table->is_global = 0;
  }else if(!strcmp(n->childs[0]->token->id, "Double")){
    printf("    %%%s = alloca %s\n", n->childs[1]->value, return_type_to_llvm(n->childs[0]->token->id));
    n->childs[1]->pointer_table->llvm_type = return_type_to_llvm(n->childs[0]->token->id);
    n->childs[1]->pointer_table->is_global = 0;
  } else if(!strcmp(n->childs[0]->token->id, "Bool")){
    printf("    %%%s = alloca %s\n", n->childs[1]->value, return_type_to_llvm(n->childs[0]->token->id));
    n->childs[1]->pointer_table->llvm_type = return_type_to_llvm(n->childs[0]->token->id);
    n->childs[1]->pointer_table->is_global = 0;
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
      printf("    store i32 %%argc, i32* %%argc.addr\n");
      printf("    store i8** %%argv, i8*** %%argv.addr\n");

      printf("    %%%d = alloca i32\n", current_temporary);
      printf("    %%.length = alloca i32\n");

      printf("    store i32 %%argc, i32* %%%d\n", current_temporary);
      current_temporary++;
      printf("    %%%d = load i32, i32* %%%d\n", current_temporary, current_temporary-1);
      current_temporary++;
      printf("    %%%d = sub nsw i32 %%%d, 1\n", current_temporary, current_temporary-1);
      printf("    store i32 %%%d, i32* %%.length\n\n\n\n", current_temporary);
      current_temporary++;


      n->childs[0]->childs[2]->childs[i]->childs[1]->pointer_table->llvm_type = "StringArray";

    } else {

      printf("    %%%s.addr = alloca %s\n", n->childs[0]->childs[2]->childs[i]->childs[1]->value, return_type_to_llvm(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id));
      n->childs[0]->childs[2]->childs[i]->childs[1]->pointer_table->llvm_type = return_type_to_llvm(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id);
    }
  }

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

void generate_global_strings(){

  int i;

  for (i = 0; i < string_counter; i++) {
    char* str = parse_string(global_string_print[i]);
    printf("@.str.string.%d = private unnamed_addr constant [%d x i8] c\"%s\"\n", i, final_size, str);
  }

  printf("@.str.int = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\"\n");
  printf("@.str.double = private unnamed_addr constant [7 x i8] c\"%%.16E\\0A\\00\"\n");
  printf("@.str.true = private unnamed_addr constant [6 x i8] c\"true\\0A\\00\"\n");
  printf("@.str.false = private unnamed_addr constant [7 x i8] c\"false\\0A\\00\"\n");
  printf("@.str.string = private unnamed_addr constant [4 x i8] c\"%%s\\0A\\00\"\n");

}


char* fix_lit_for_conversion(node* n){
  char* str = (char*) n->value;

  char* tmp = (char*)malloc(sizeof(char)*strlen(str)*10);
  int i, j=0;

  for (i=0;i<strlen(str);i++) {
    if (str[i] != '_') {
        tmp[j] = str[i];
        j++;
    }
  }
  tmp[j] = '\0';

  return tmp;
}

void generate_boolean_print(){

  printf("define void @printBoolean(i1 %%b) {\n");
  printf("    %%1 = alloca i1\n");
  printf("    store i1 %%b, i1* %%1\n");
  printf("    %%2 = load i1, i1* %%1\n");
  printf("    %%3 = icmp eq i1 %%2, 0\n");
  printf("    br i1 %%3, label %%false, label %%true\n");
  printf("    false:\n");
  printf("    %%4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.false, i32 0, i32 0))\n");
  printf("    br label %%ret\n");
  printf("    true:\n");
  printf("    %%5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.true, i32 0, i32 0))\n");
  printf("    br label %%ret\n");
  printf("    ret:\n");
  printf("    ret void\n");
  printf("}\n");


}


void generate_print(node* n){

  if(!strcmp(n->childs[0]->anotated_type, "int")){
    printf("    %%%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.int, i32 0, i32 0), i32 %%%d)\n", current_temporary, n->childs[0]->address);
    current_temporary++;
  }else if(!strcmp(n->childs[0]->anotated_type, "double")){
    printf("    %%%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.double, i32 0, i32 0), double %%%d)\n", current_temporary,n->childs[0]->address);
    current_temporary++;
  }else if(!strcmp(n->childs[0]->anotated_type, "boolean")){
    printf("    call void @printBoolean(i1 %%%d)\n", n->childs[0]->address);
  }else if(!strcmp(n->childs[0]->anotated_type, "String")){
    printf("    %%%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([%d x i8], [%d x i8]* @.str.string.%d, i32 0, i32 0), i32 0)\n", current_temporary, final_size, final_size, string_counter-1);
    current_temporary++;
  }
}


void generate_assign(node *n){
  // a = b;
  if(!strcmp(n->childs[0]->anotated_type, "int")){
    if(n->childs[0]->pointer_table->is_global == 1){
      printf("    store i32 %%%d, i32* @%s.%s\n", assign_var, class, n->childs[0]->value);
    } else {
      printf("    store i32 %%%d, i32* %%%s\n", assign_var, n->childs[0]->value);
    }
    n->address = n->childs[1]->address;
  } else if(!strcmp(n->childs[0]->anotated_type, "double")){
    if(!strcmp(n->childs[1]->anotated_type, "double")){
      if(n->childs[0]->pointer_table->is_global == 1){
        printf("    store double %%%d, double* @%s.%s\n", assign_var, class,  n->childs[0]->value);
      }else{
        printf("    store double %%%d, double* %%%s\n", assign_var, n->childs[0]->value);
      }
      n->address = n->childs[1]->address;
    } else if(!strcmp(n->childs[1]->anotated_type, "int")){
      //printf("    %%%d = alloca double\n", current_temporary);
      //printf("    store i32 %%%d, i32* %%%d\n", n->childs[1]->address, current_temporary);
      //current_temporary++;
      //printf("    %%%d = load i32, i32* %%%d\n", current_temporary, current_temporary-1);
      //current_temporary++;
      printf("    %%%d = sitofp i32 %%%d to double\n", current_temporary, n->childs[1]->address);
      if(n->childs[0]->pointer_table->is_global == 1){
        printf("    store double %%%d, double* @%s.%s\n", current_temporary, class, n->childs[0]->value);
      } else {
        printf("    store double %%%d, double* %%%s\n", current_temporary, n->childs[0]->value);
      }
      current_temporary++;
      printf("    %%%d = sitofp i32 %%%d to double\n", current_temporary, n->childs[1]->address);
      n->address = current_temporary;
      current_temporary++;

    }
  } else if(!strcmp(n->childs[0]->anotated_type, "boolean")){
    if(n->childs[0]->pointer_table->is_global == 1){
      printf("    store i1 %%%d, i1* @%s.%s\n", assign_var, class, n->childs[0]->value);
    } else {
      printf("    store i1 %%%d, i1* %%%s\n", assign_var, n->childs[0]->value);
    }
    n->address = n->childs[1]->address;
  }
}

void generate_length(node *n){

  printf("    %%%d = load i32, i32* %%.length\n", current_temporary);
  n->address = current_temporary;
  assign_var = current_temporary;
  current_temporary++;

}

// generate code for args
void generate_parseArgs(node *n){

  printf("    %%%d = add nsw i32 %%%d, 1\n", current_temporary, n->childs[1]->address);
  current_temporary++;
  printf("    %%%d = alloca i32\n", current_temporary);
  printf("    store i32 %%%d, i32* %%%d\n", current_temporary - 1, current_temporary);
  current_temporary++;
  printf("    %%%d = load i32, i32* %%%d\n", current_temporary, current_temporary - 1);
  current_temporary++;
  printf("    %%%d = load i8**, i8*** %%argv.addr\n", current_temporary);
  printf("    %%arrayidx%d = getelementptr inbounds i8*, i8** %%%d, i32 %%%d\n", array_counter, current_temporary, current_temporary - 1);
  current_temporary++;
  printf("    %%%d = load i8*, i8** %%arrayidx%d\n", current_temporary, array_counter);
  current_temporary++;
  array_counter++;
  printf("    %%%d = call i32(i8*, ...) bitcast (i32(...)* @atoi to i32 (i8*, ...)*)(i8* %%%d)\n", current_temporary, current_temporary - 1);
  n->address = current_temporary;
  assign_var = current_temporary;
  current_temporary++;
}

void generate_strlit(node *n){

  global_string_print[string_counter]= (char*)n->value;
  parse_string(global_string_print[string_counter]);
  string_counter++;
}

void generate_declit(node *n){

  printf("    %%%d = alloca i32\n", current_temporary);
  printf("    store i32 %d, i32* %%%d\n", atoi(fix_lit_for_conversion(n)), current_temporary);
  current_temporary++;
  printf("    %%%d = load i32, i32* %%%d\n", current_temporary, current_temporary-1);
  n->address = current_temporary;
  assign_var = current_temporary;
  current_temporary++;

}


void generate_reallit(node *n){

  printf("    %%%d = alloca double\n", current_temporary);
  printf("    store double %.16E, double* %%%d\n", atof(fix_lit_for_conversion(n)), current_temporary);
  current_temporary++;
  printf("    %%%d = load double, double* %%%d\n", current_temporary, current_temporary-1);
  n->address = current_temporary;
  assign_var = current_temporary;
  current_temporary++;

}

void generate_boollit(node *n){
  int res;
  printf("    %%%d = alloca i1\n", current_temporary);
  if(!strcmp((char*)n->value, "true")){
    res = 1;
  } else {
    res = 0;
  }
  printf("    store i1 %d, i1* %%%d\n", res, current_temporary);
  current_temporary++;
  printf("    %%%d = load i1, i1* %%%d\n", current_temporary, current_temporary-1);
  n->address = current_temporary;
  assign_var = current_temporary;
  current_temporary++;

}

// when we find a node id, we want to load it
void generate_id(node *n){
  //printf("%s\n", n->value);
  if(n->pointer_table != NULL && n->pointer_table->llvm_type != NULL){
    if(!strcmp(n->pointer_table->llvm_type, "i32")){
      if(n->pointer_table->is_global == 1){
        printf("    %%%d = load %s, %s* @%s.%s\n", current_temporary, n->pointer_table->llvm_type, n->pointer_table->llvm_type, class, n->value);
      } else {
        printf("    %%%d = load %s, %s* %%%s\n", current_temporary, n->pointer_table->llvm_type, n->pointer_table->llvm_type, n->value);
      }
      n->address = current_temporary;
      assign_var = current_temporary;
      current_temporary++;
    } else if(!strcmp(n->pointer_table->llvm_type, "double")){
      if(n->pointer_table->is_global == 1){
        printf("    %%%d = load %s, %s* @%s.%s\n", current_temporary, n->pointer_table->llvm_type, n->pointer_table->llvm_type, class, n->value);
      } else {
        printf("    %%%d = load %s, %s* %%%s\n", current_temporary, n->pointer_table->llvm_type, n->pointer_table->llvm_type, n->value);
      }
      n->address = current_temporary;
      assign_var = current_temporary;
      current_temporary++;
    } else if(!strcmp(n->pointer_table->llvm_type, "i1")){
      if(n->pointer_table->is_global == 1){
        printf("    %%%d = load %s, %s* @%s.%s\n", current_temporary, n->pointer_table->llvm_type, n->pointer_table->llvm_type, class, n->value);
      } else {
        printf("    %%%d = load %s, %s* %%%s\n", current_temporary, n->pointer_table->llvm_type, n->pointer_table->llvm_type, n->value);
      }
      n->address = current_temporary;
      assign_var = current_temporary;
      current_temporary++;
    }
  }
}

void generate_minus(node* n){
  if(!strcmp(n->childs[0]->anotated_type, "int")){
    // int
    printf("    %%%d = sub nsw i32 0, %%%d\n", current_temporary, n->childs[0]->address);
    n->address = current_temporary;
    assign_var = current_temporary;
    current_temporary++;
  } else{
    // double
    printf("    %%%d = fsub double -0.000000e+00, %%%d\n",current_temporary, n->childs[0]->address);
    n->address = current_temporary;
    assign_var = current_temporary;
    current_temporary++;
  }
}
void generate_plus(node* n){
  if(!strcmp(n->childs[0]->anotated_type, "int")){

    // int
    printf("    %%%d = alloca i32\n", current_temporary);
    printf("    store i32 %%%d, i32* %%%d\n", n->childs[0]->address, current_temporary);
    current_temporary++;
    printf("    %%%d = load i32, i32* %%%d\n", current_temporary, current_temporary-1);
    n->address = current_temporary;
    assign_var = current_temporary;
    current_temporary++;

  } else if(!strcmp(n->childs[0]->anotated_type, "double")){
    // double
    printf("    %%%d = alloca double\n", current_temporary);
    printf("    store double %.16E, double* %%%d\n", atof(fix_lit_for_conversion(n->childs[0])), current_temporary);
    current_temporary++;
    printf("    %%%d = load double, double* %%%d\n", current_temporary, current_temporary-1);
    n->address = current_temporary;
    assign_var = current_temporary;
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
    printf("declare i32 @printf(i8*, ...)\n");
    printf("declare i32 @atoi(...)\n");
    generate_boolean_print();


    for(i = 0; i < n->n_children; i++){
      if(!strcmp(n->childs[i]->token->id, "FieldDecl")){
        code_generation(n->childs[i]);
      }
    }
    for(i = 0; i < n->n_children; i++){
      if(strcmp(n->childs[i]->token->id, "FieldDecl")){
        code_generation(n->childs[i]);
      }
    }
  } else if(!strcmp(n->token->id, "FieldDecl")){
    for(i = 0; i < n->n_children; i++){
      code_generation(n->childs[i]);
    }
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
    for(i = 0; i < n->n_children; i++){
      code_generation(n->childs[i]);
    }
    generate_assign(n);
    generate_id(n->childs[0]);
  } else if(!strcmp(n->token->id, "Length")){
    generate_length(n);
  } else if(!strcmp(n->token->id, "ParseArgs")){
    for(i = 0; i < n->n_children; i++){
      code_generation(n->childs[i]);
    }
    generate_parseArgs(n);
  } else if(!strcmp(n->token->id, "Id")){
    generate_id(n);
  } else if(!strcmp(n->token->id, "StrLit")){
    generate_strlit(n);
  } else if(!strcmp(n->token->id, "DecLit")){
    generate_declit(n);
  } else if(!strcmp(n->token->id, "RealLit")){
    generate_reallit(n);
  } else if(!strcmp(n->token->id, "BoolLit")){
    generate_boollit(n);
  } else if(!strcmp(n->token->id, "Minus")){
    for(i = 0; i < n->n_children; i++){
      code_generation(n->childs[i]);
    }
    generate_minus(n);
  } else if(!strcmp(n->token->id, "Plus")){
    for(i = 0; i < n->n_children; i++){
      code_generation(n->childs[i]);
    }
    generate_plus(n);
  }

}

void code_gen_ast(node* n){
  code_generation(n);
  generate_global_strings();
}

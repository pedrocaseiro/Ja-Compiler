#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include "ast.h"
#include "symbol_table.h"

symbol* new_symbol(char* name, int n_params, char** paramtypes, char* type, char* flag) {
  symbol* s = (symbol*)malloc(sizeof(symbol));
  s->name = name;
  s->type = type;
  s->n_params = n_params;
  s->paramtypes = paramtypes;
  s->flag = flag;
  s->next = NULL;
  return s;
}

symbol_table* new_symbol_table(char* type, char* name, int n_params, char** paramtypes) {
  symbol_table* st = (symbol_table*)malloc(sizeof(symbol_table));
  st->name = name;
  st->type = strdup(type);
  st->n_params = n_params;
  st->paramtypes = paramtypes;
  return st;
}

char* str_to_lower(char* str) {
  if (str == NULL)
    return NULL;
  if(!strcmp(str, "StringArray")){
    return strdup("String[]");
  }
  if(str[0] >= 'A' && str[0] <= 'Z'){
    str[0] = str[0] + 32;
  }
  return str;
}

void insert_symbol(symbol_table* st, char* name, int n_params, char** paramtypes, char* type, char* flag) {
  symbol* first = st->first;
  if (first == NULL) {
    st->first = new_symbol(name, n_params, paramtypes, type, flag);
    return;

  }
  while(first->next != NULL) {
    first = first->next;
  }
  first->next = new_symbol(name, n_params, paramtypes, type, flag);

}

void build_table(node* n) {
  int i = 0;
  if (!strcmp(n->type, "Program")) {
    table[table_index] = new_symbol_table("Class", n->childs[0]->value, 0, NULL);
    table_index++;
    for(i = 1; i < n->n_children; i++){
      build_table(n->childs[i]);
    }
  } else if(!strcmp(n->type, "MethodDecl")){
    int n_params = n->childs[0]->childs[2]->n_children; //MethodHeader->MethodParams->n_children
    printf("nº parametros: %d\n", n_params);
    char** params = (char**)malloc(sizeof(char*)*n_params);
    for(int i = 0; i < n_params; i++){
      params[i] = str_to_lower(n->childs[0]->childs[2]->childs[i]->childs[0]->value); 
    }

    insert_symbol(table[0], n->childs[0]->childs[1]->value, n_params, params, str_to_lower(n->childs[0]->childs[0]->type), NULL); 
  }
}


void print_symbol_table(symbol* s) {

  printf("%s\t", s->name);
  if(s->paramtypes != NULL){
    int i;
    printf("(");
    for(int i = 0; i < s->n_params; i++){
      printf("%s", s->paramtypes[i]);
      if(i != s->n_params - 1){
        printf(", ");
      }
    }
    printf(")");
  }
  printf("\t%s", s->type);
  if(s->flag != NULL){
    printf("\t%s", s->flag);
  }
  printf("\n");
  if(s->next != NULL){
    print_symbol_table(s->next);
  }
}

void print_table() {
  int i = 0;
  for(i = 0; i < table_index; i++){
    if(i > 0){
      printf("\n");
    }
    if(!strcmp(table[i]->type, "Class")){
      printf("===== %s %s Symbol Table =====\n", table[i]->type, table[i]->name);
    } else {
      printf("===== %s %s Symbol Table =====\n", table[i]->type, table[i]->name);
      if(table[i]->n_params > 0){
        int j;
        for(int j = 0; j < table[i]->n_params; j++){
          printf("%s", table[i]->paramtypes[j]);
          if(j != table[i]->n_params - 1){
            printf(", ");
          }
        }
      }
      printf(") Symbol Table =====\n");
    }
    if(table[i]->first != NULL){
      print_symbol_table(table[i]->first);
    }
  }
}

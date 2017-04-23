#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include "ast.h"
#include "symbol_table.h"

symbol_table** new_table(int size) {
  return (symbol_table**)malloc(sizeof(symbol_table)*size);
}

symbol* new_symbol(char* name, int n_params, char** params, char* type, char* flag) {
  symbol* s = (symbol*)malloc(sizeof(symbol));
  s->name = name;
  s->params = params;
  s->n_params = n_params;
  s->type = type;
  s->flag = flag;
  s->next = NULL;
  return s;
}

symbol_table* new_symbol_table(char* type, char* name, int n_params, char** params) {
  symbol_table* st = (symbol_table*)malloc(sizeof(symbol_table));
  st->first = NULL;
  st->name = name;
  st->type = strdup(type);
  st->n_params = n_params;
  st->params = params;
  return st;
}

char* str_to_lower(char* s) {
  char* str = strdup(s);
  if (str == NULL)
    return NULL;
  if(!strcmp(str, "StringArray")){
    return strdup("String[]");
  }
  if(!strcmp(str, "bool") || !strcmp(str, "Bool")){
    return strdup("boolean");
  }
  if(str[0] >= 'A' && str[0] <= 'Z'){
    str[0] += 32;
  }
  return str;
}

void insert_symbol(symbol_table* st, char* name, int n_params, char** params, char* type, char* flag) {
  symbol* first_symbol = st->first;
  if (first_symbol == NULL) {
    st->first = new_symbol(name, n_params, params, type, flag);
    return;
  }

  while(first_symbol->next != NULL) {
    first_symbol = first_symbol->next;
  }
  first_symbol->next = new_symbol(name, n_params, params, type, flag);

}

void second_traverse(node* n){
  int n_params = n->childs[0]->childs[2]->n_children;//MethodHeader->MethodParams->n_children
  char** params = (char**)malloc(sizeof(char*)*n_params);
  int i;

  for(i = 0; i < n_params; i++){
    //MethodDecl -> MethodHeader -> MethodParams -> ParamDecl[i] -> type
    params[i] = str_to_lower(n->childs[0]->childs[2]->childs[i]->childs[0]->type);
  }
  table[table_index] = new_symbol_table("Method", n->childs[0]->childs[1]->value, n_params, params);

  insert_symbol(table[table_index], strdup("return"), 0, NULL, str_to_lower(n->childs[0]->childs[0]->type), NULL);
  for(i = 0; i < n_params; i++){
    insert_symbol(table[table_index], n->childs[0]->childs[2]->childs[i]->childs[1]->value, 0, NULL, table[table_index]->params[i], strdup("param"));
    if(!strcmp(n->childs[0]->childs[2]->childs[i]->childs[1]->type, "Id")){
        printf("%s\n", n->childs[0]->childs[2]->childs[i]->childs[1]->value);
        n->anotated_type = strdup("int");
    }
  }
  for(i = 0; i < n->childs[1]->n_children; i++){
    if(!strcmp(n->childs[1]->childs[i]->type, "VarDecl")){
      insert_symbol(table[table_index], n->childs[1]->childs[i]->childs[1]->value, 0, NULL, str_to_lower(n->childs[1]->childs[i]->childs[0]->type), NULL);
    }
  }
  table_index++;
}

void parse_assign_node(node* n){
  // TODO: detect errors
  // check if left side variable is defined...
  // check incompatibility
  n->anotated_type = n->childs[1]->anotated_type;
}

// TODO: check if the function we're calling is the right one (there may be multiple methods with the same name, but different parameters). IMPORTANT
void parse_call_node(node* n){
  int i;
  for(i = 1; i < table_index; i++){
    if(!strcmp(table[i]->name, n->childs[0]->value)){
      n->anotated_type = table[i]->first->type;
      break;
    }
  }
}

//TODO: CHECK ERRORS
void parse_parseargs_node(node* n){
  n->anotated_type = strdup("int");
}

//TODO: it only accepts comparisons between 2 booleans
void parse_and_or_nodes(node* n){
  n->anotated_type = strdup("boolean");
}

//TODO: check types compatibility
void parse_equality_nodes(node* n){
  n->anotated_type = strdup("boolean");
}

//TODO: CHECK IF ANY ERROR IS POSSIBLE
void parse_minus_plus_nodes(node* n){
  n->anotated_type = n->childs[0]->anotated_type;
}


void parse_logic_nodes(node* n){
  if(!strcmp(n->childs[0]->anotated_type, "double") || !strcmp(n->childs[1]->anotated_type, "double")){
    if(!strcmp(n->childs[0]->anotated_type, "int") || !strcmp(n->childs[1]->anotated_type, "int")){
      n->anotated_type = strdup("double");
    }else if(!strcmp(n->childs[0]->anotated_type, "double") || !strcmp(n->childs[1]->anotated_type, "double")){
      n->anotated_type = strdup("double");
    } else {
      // ERROR
    }
  } else if(!strcmp(n->childs[0]->anotated_type, "int") && !strcmp(n->childs[1]->anotated_type, "int")){
      n->anotated_type = strdup("int");
  } else {
    // ERROR
  }
}

//TODO: ERROR TRYING TO NEGATE INT OR DOUBLE
void parse_not_node(node* n){
  if(!strcmp(n->childs[0]->anotated_type, "boolean")){
    n->anotated_type = strdup("boolean");
  } else {
    // ERROR
  }
}

// ERROS -> trying to do .length of something illegal (5.length); check annotated_type of child[0]
void parse_length_node(node* n){
  n->anotated_type = strdup("int");
}

void parse_declit_node(node* n){
  n->anotated_type = strdup("int");
}

void parse_boollit_node(node* n){
  n->anotated_type = strdup("boolean");
}

void parse_reallit_node(node* n){
  n->anotated_type = strdup("double");
}

void parse_id_node(node* n){
  n->anotated_type = strdup("int");
}

void parse_strlit_node(node* n){
  n->anotated_type = strdup("String");
}



void first_traverse(node* n) {
  int i = 0;
  if (!strcmp(n->type, "Program")) {
    table[table_index] = new_symbol_table("Class", n->childs[0]->value, 0, NULL);
    table_index++;
    for(i = 1; i < n -> n_children; i++){
      first_traverse(n->childs[i]);
    }
    for(i = 1; i < n -> n_children; i++){
      if(!strcmp(n->childs[i]->type, "MethodDecl")){
        second_traverse(n->childs[i]);
      }
    }
  } else if(!strcmp(n->type, "MethodDecl")){
    int n_params = n->childs[0]->childs[2]->n_children;//MethodHeader->MethodParams->n_children
    char** params = (char**)malloc(sizeof(char*)*n_params);
    for(i = 0; i < n_params; i++){
      //MethodDecl -> MethodHeader -> MethodParams -> ParamDecl[i] -> type
      params[i] = str_to_lower(n->childs[0]->childs[2]->childs[i]->childs[0]->type);
    }

    insert_symbol(table[0], n->childs[0]->childs[1]->value, n_params, params, str_to_lower(n->childs[0]->childs[0]->type), NULL);
  } else if(!strcmp(n->type, "FieldDecl")){
    insert_symbol(table[0], n->childs[1]->value, 0, NULL, str_to_lower(n->childs[0]->type), NULL);
  }
}

void create_an_tree(node *n){
  int i = 0;

  if(!strcmp(n->type, "Program")){
    for(i = 0; i < n->n_children; i++){
      if(strcmp(n->childs[i]->type,"Id"))
        create_an_tree(n->childs[i]);
    }
  } else if(!strcmp(n->type, "FieldDecl") || !strcmp(n->type, "MethodHeader") || !strcmp(n->type, "FormalParams") || !strcmp(n->type, "VarDecl")){

  } else if(!strcmp(n->type, "MethodDecl")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->type, "MethodBody")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->type, "If")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->type, "While")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->type, "DoWhile")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->type, "Print")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->type, "Assign")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_assign_node(n);
  } else if(!strcmp(n->type, "Call")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_call_node(n);
  } else if(!strcmp(n->type, "ParseArgs")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_parseargs_node(n);
  } else if(!strcmp(n->type, "Return")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->type, "Block")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->type, "And") || !strcmp(n->type, "Or")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_and_or_nodes(n);
  } else if(!strcmp(n->type, "Eq") || !strcmp(n->type, "Geq") || !strcmp(n->type, "Gt") || !strcmp(n->type, "Leq") || !strcmp(n->type, "Lt") || !strcmp(n->type, "Neq")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_equality_nodes(n);
  } else if(!strcmp(n->type, "Add") || !strcmp(n->type, "Sub") || !strcmp(n->type, "Mul") || !strcmp(n->type, "Div") || !strcmp(n->type, "Mod")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_logic_nodes(n);
  } else if(!strcmp(n->type, "Minus") || !strcmp(n->type, "Plus")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_minus_plus_nodes(n);
  } else if(!strcmp(n->type, "Not")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_not_node(n);
  } else if(!strcmp(n->type, "Length")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_length_node(n);
  } else if(!strcmp(n->type, "BoolLit")){
      parse_boollit_node(n);
  } else if(!strcmp(n->type, "RealLit")){
      parse_reallit_node(n);
  } else if(!strcmp(n->type, "DecLit")){
      parse_declit_node(n);
  } else if(!strcmp(n->type, "StrLit")){
      parse_strlit_node(n);
  }
}


void print_symbol_table(symbol* s) {
  printf("%s\t", s->name);
  if(s->params!= NULL){
    int i;
    printf("(");
    for(i = 0; i < s->n_params; i++){
      printf("%s", s->params[i]);
      if(i != s->n_params - 1){
        printf(",");
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
      printf("===== %s %s(", table[i]->type, table[i]->name);
      if(table[i]->n_params > 0){
        int j;
        for(j = 0; j < table[i]->n_params; j++){
          printf("%s", table[i]->params[j]);
          if(j != table[i]->n_params - 1){
            printf(",");
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

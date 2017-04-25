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
    params[i] = str_to_lower(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id);
  }
  table[table_index] = new_symbol_table("Method", n->childs[0]->childs[1]->value, n_params, params);

  insert_symbol(table[table_index], strdup("return"), 0, NULL, str_to_lower(n->childs[0]->childs[0]->token->id), NULL);
  for(i = 0; i < n_params; i++){
    insert_symbol(table[table_index], n->childs[0]->childs[2]->childs[i]->childs[1]->value, 0, NULL, table[table_index]->params[i], strdup("param"));
    parse_formalparams_node(n->childs[0]->childs[2]->childs[i]);
  }
  for(i = 0; i < n->childs[1]->n_children; i++){
    if(!strcmp(n->childs[1]->childs[i]->token->id, "VarDecl")){
      insert_symbol(table[table_index], n->childs[1]->childs[i]->childs[1]->value, 0, NULL, str_to_lower(n->childs[1]->childs[i]->childs[0]->token->id), NULL);
      // we call it with n as a VarDecl node
      parse_vardecl_node(n->childs[1]->childs[i]);
    }
  }

  iterate_tree(n->childs[1]);

  table_index++;
}

void first_traverse(node* n) {
  int i = 0, j;
  if (!strcmp(n->token->id, "Program")) {
    table[table_index] = new_symbol_table("Class", n->childs[0]->value, 0, NULL);
    table_index++;
    for(i = 0; i < n -> n_children; i++){
      first_traverse(n->childs[i]);
    }
    for(i = 0; i < n -> n_children; i++){
      if(!strcmp(n->childs[i]->token->id, "MethodDecl")){
        second_traverse(n->childs[i]);
      }
    }
  } else if(!strcmp(n->token->id, "MethodDecl")){
    int n_params = n->childs[0]->childs[2]->n_children;//MethodHeader->MethodParams->n_children
    char** params = (char**)malloc(sizeof(char*)*n_params);
    for(i = 0; i < n_params; i++){
      //MethodDecl -> MethodHeader -> MethodParams -> ParamDecl[i] -> token->id
      params[i] = str_to_lower(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id);
    }

    insert_symbol(table[0], n->childs[0]->childs[1]->value, n_params, params, str_to_lower(n->childs[0]->childs[0]->token->id), NULL);
    parse_methodheader_node(n->childs[0]);
  } else if(!strcmp(n->token->id, "FieldDecl")){
    insert_symbol(table[0], n->childs[1]->value, 0, NULL, str_to_lower(n->childs[0]->token->id), NULL);
    parse_fielddecl_node(n);
  }
}

// iterate for ID's
void iterate_tree(node *n){
  int i;
  for (i = 0; i < n->n_children; i++) {

      if(!strcmp(n->childs[i]->token->id, "Id") && strcmp(n->token->id, "VarDecl")){
        symbol* s = (symbol*)malloc(sizeof(symbol));

        s = table[table_index]->first;
        while(s != NULL){
          //printf("%s %s\n", s->token->id, s->name);
          if(!strcmp(n->childs[i]->value, s->name)){
            n->childs[i]->anotated_type = strdup(s->type);
            break;
          }
          if(n->childs[i]->anotated_type == NULL){
            symbol* g = (symbol*)malloc(sizeof(symbol));
            g = table[0]->first;
            while(g != NULL){
              //printf("%s %s\n", s->type, s->name);
              if(!strcmp(n->childs[i]->value, g->name) && g->params == NULL){
                n->childs[i]->anotated_type = strdup(g->type);
                break;
              }
              g = g->next;
            }
          }
          s = s->next;
        }
        if(n->childs[i]->anotated_type == NULL){
          n->childs[i]->anotated_type = strdup("undef");
        }
      }
      iterate_tree(n->childs[i]);
  }
}

void parse_formalparams_node(node* n){
  symbol* s = (symbol*)malloc(sizeof(symbol));
  s = table[table_index]->first;
  int i;
  int count = 0;
  while(s != NULL){
    if(s->flag != NULL){
      if(!(strcmp(n->childs[1]->value, s->name)) && !strcmp(s->flag, "param")){
        count++;
      }
    }
    s = s->next;
  }

  if(count > 1){
    printf("Line %d, col %d: Symbol %s already defined\n", n->childs[1]->token->line, n->childs[1]->token->col, n->childs[1]->value);
  }
}

// We check if the variable is not already declared as a parameter
// We check if in the local table there is a variable with the same name, and flag equal to param
void parse_vardecl_node(node* n){
  symbol* s = (symbol*)malloc(sizeof(symbol));
  s = table[table_index]->first;
  int i;
  int count = 0;
  while(s != NULL){
    if(s->flag != NULL){
      if(!(strcmp(n->childs[1]->value, s->name)) && !strcmp(s->flag, "param")){
        count++;
      }
    }
    s = s->next;
  }
  if(count > 1){
    printf("Line %d, col %d: Symbol %s already defined\n", n->childs[1]->token->line, n->childs[1]->token->col, n->childs[1]->value);
  }
}

void parse_methodheader_node(node* n){
  symbol* s = (symbol*)malloc(sizeof(symbol));
  node* methodparams = (node*)malloc(sizeof(node));
  s = table[0]->first;
  int count = 0;
  char* name = strdup(s->name);
  while(s != NULL){
    if(!strcmp(s->name, n->childs[1]->value) && !strcmp(s->type, str_to_lower(n->childs[0]->token->id))){
      //check if they have the same parameters

      // reconstruct symbol params
      char str[100]="";
      char str2[100]="";

      if(s->n_params > 0){
        int j;
        for(j = 0; j < s->n_params; j++){
          strcat(str, s->params[j]);
          if(j != s->n_params - 1){
            strcat(str, ",");
          }
        }
      }
      int i;
      // reconstruct node params
      methodparams = n->childs[2];
      for(i = 0; i < n->childs[2]->n_children; i++){
        strcat(str2,str_to_lower(n->childs[2]->childs[i]->childs[0]->token->id));
        if(i != n->childs[2]->n_children - 1){
          strcat(str2, ",");
        }
      }
      //printf("str %s\n", str);
      //printf("str2 %s\n", str2);

      if(!strcmp(str, str2)){
        count++;
      }
    }
    s = s->next;
  }

  if(count > 1){
    printf("Line %d, col %d: Symbol %s already defined\n", n->childs[1]->token->line, n->childs[1]->token->col, n->childs[1]->value);
  }
}

/*
  In case there are multiple global variable declarations that are equal,
  we need to throw an error;
  TODO: ASK THE TEACHER IN WHAT TOKENS ARE THE ERRORS SUPPOSED TO TRIGGER
*/
void parse_fielddecl_node(node* n){
  symbol* s = (symbol*)malloc(sizeof(symbol));
  s = table[0]->first;
  int count = 0;
  char* name = strdup(s->name);
  while(s != NULL){
    if(!strcmp(s->name, n->childs[1]->value) && s->params == NULL){
      count++;
    }
    s = s->next;
  }

  if(count > 1){
    printf("Line %d, col: %d Symbol %s already defined\n", n->childs[1]->token->line, n->childs[1]->token->col, name);
  }
}

void parse_assign_node(node* n){
  // TODO: detect errors
  // check if left side variable is defined...
  // check incompatibility
  /* Assign
       Id(b)
       Sub
         Id(b)
         Id(a)
  */
  n->anotated_type = n->childs[1]->anotated_type;

  // incompatibility

  int error_flag = 0;
  if(!strcmp(n->childs[0]->anotated_type, "boolean") && !strcmp(n->childs[1]->anotated_type, "int")){
    error_flag = 1;
  } else if(!strcmp(n->childs[0]->anotated_type, "int") && !strcmp(n->childs[1]->anotated_type, "boolean")){
      error_flag = 1;
  } else if(!strcmp(n->childs[0]->anotated_type, "double") && !strcmp(n->childs[1]->anotated_type, "boolean")){
      error_flag = 1;
  } else if(!strcmp(n->childs[0]->anotated_type, "boolean") && !strcmp(n->childs[1]->anotated_type, "double")){
      error_flag = 1;
  } else if(!strcmp(n->childs[0]->anotated_type, "int") && !strcmp(n->childs[1]->anotated_type, "double")){
      error_flag = 1;
  } else if(!strcmp(n->childs[0]->anotated_type, "undef")){
      printf("Line %d, col: %d Cannot find symbol %s\n", n->childs[0]->token->line, n->childs[0]->token->col, n->childs[0]->value);
      error_flag = 1;
  } else if(!strcmp(n->childs[1]->anotated_type, "undef")){
      printf("Line %d, col: %d Cannot find symbol %s\n", n->childs[1]->token->line, n->childs[1]->token->col,n->childs[1]->value);
      error_flag = 1;
  }

  if(error_flag == 1){
    n->anotated_type = "undef";
    // TODO: CHECKAR LINHAS E COLUNAS PERGUNTAR AO STOR
    printf("Line %d, col: %d Operator %s cannot be applied to types %s, %s\n", n->childs[0]->token->line, n->childs[0]->token->col, n->token->id, n->childs[0]->anotated_type, n->childs[1]->anotated_type);
  }
}

// TODO: check if the function we're calling is the right one (there may be multiple methods with the same name, but different parameters). IMPORTANT
// can be ambiguous

// percorremos tabelas até encontrar com nome igual
// se for match -> preenchemos árvore
// se for compativel -> contador++
// no fim verificar se contador > 1 - se for, ambiguous
// senão está bem
void parse_call_node(node* n){
  int i;
  int j;
  int k;
  const char *aux[100];
  int ambiguous_counter = 0;
  for(i = 1; i < table_index; i++){
    if(!strcmp(table[i]->name, n->childs[0]->value) && ((n->n_children - 1) == table[i]->n_params)){ // same name && same number of params
      // now we check if all the params match
      n->anotated_type = table[i]->first->type;

      symbol* g = (symbol*)malloc(sizeof(symbol));
      g = table[0]->first;
      while(g != NULL){
        if(!strcmp(n->childs[0]->value, g->name) && g->params != NULL){
          char str[100]="(";
          if(g->n_params > 0){
            int j;
            for(j = 0; j < g->n_params; j++){
              aux[j] = g->params[j];
              strcat(str, g->params[j]);
              if(j != g->n_params - 1){
                strcat(str, ",");
              }
            }
          }
          strcat(str, ")");
          n->childs[0]->anotated_type = strdup(str);
          break;
        }
        g = g->next;
      }

      // this counter checks if we had a perfect match
      int counter = 0;
      for(k = 1; k < n->n_children; k++){
        if(!strcmp(n->childs[k]->anotated_type, aux[k-1])){
          counter++;
        }
      }

      int h;
      int aux_counter = 0;
      if(counter != n->n_children - 1){ // we didn't have a match, we look for a close one
        for(h = 1; h < n->n_children; h++){
          if((!strcmp(n->childs[h]->anotated_type, "int") && !strcmp(aux[h-1], "double")) || (!strcmp(n->childs[h]->anotated_type, "int") && !strcmp(aux[h-1], "int")) || (!strcmp(n->childs[h]->anotated_type, "boolean") && !strcmp(aux[h-1], "boolean")) || (!strcmp(n->childs[h]->anotated_type, "double") && !strcmp(aux[h-1], "double"))){
            aux_counter++;
          }
        }
        if(aux_counter == n->n_children - 1){
          ambiguous_counter++;
        }
      }
    }
    }
    if(ambiguous_counter > 1){
      printf("Line %d, col: %d Reference to method %s is ambiguous\n", n->childs[0]->token->line, n->childs[0]->token->col, n->childs[0]->value);
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
    }else if(!strcmp(n->childs[0]->anotated_type, "double") && !strcmp(n->childs[1]->anotated_type, "double")){
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
  //printf("%s %s\n", n->value, n->type);
  //printf("%s\n", n->anotated_type);
  //n->anotated_type = strdup("INT");

}

void parse_strlit_node(node* n){
  n->anotated_type = strdup("String");
}

void create_an_tree(node *n){
  int i = 0;

  if(!strcmp(n->token->id, "Program")){
    for(i = 0; i < n->n_children; i++){
      if(strcmp(n->childs[i]->token->id, "Id"))
        create_an_tree(n->childs[i]);
    }
  } else if(!strcmp(n->token->id, "FieldDecl") || !strcmp(n->token->id, "MethodHeader") || !strcmp(n->token->id, "FormalParams") || !strcmp(n->token->id, "VarDecl")){

  } else if(!strcmp(n->token->id, "MethodDecl")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->token->id, "MethodBody")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->token->id, "If")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->token->id, "While")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->token->id, "DoWhile")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->token->id, "Print")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->token->id, "Assign")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_assign_node(n);
  } else if(!strcmp(n->token->id, "Call")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_call_node(n);
  } else if(!strcmp(n->token->id, "ParseArgs")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_parseargs_node(n);
  } else if(!strcmp(n->token->id, "Return")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->token->id, "Block")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->token->id, "And") || !strcmp(n->token->id, "Or")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_and_or_nodes(n);
  } else if(!strcmp(n->token->id, "Eq") || !strcmp(n->token->id, "Geq") || !strcmp(n->token->id, "Gt") || !strcmp(n->token->id, "Leq") || !strcmp(n->token->id, "Lt") || !strcmp(n->token->id, "Neq")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_equality_nodes(n);
  } else if(!strcmp(n->token->id, "Add") || !strcmp(n->token->id, "Sub") || !strcmp(n->token->id, "Mul") || !strcmp(n->token->id, "Div") || !strcmp(n->token->id, "Mod")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_logic_nodes(n);
  } else if(!strcmp(n->token->id, "Minus") || !strcmp(n->token->id, "Plus")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_minus_plus_nodes(n);
  } else if(!strcmp(n->token->id, "Not")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_not_node(n);
  } else if(!strcmp(n->token->id, "Length")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_length_node(n);
  } else if(!strcmp(n->token->id, "BoolLit")){
      parse_boollit_node(n);
  } else if(!strcmp(n->token->id, "RealLit")){
      parse_reallit_node(n);
  } else if(!strcmp(n->token->id, "DecLit")){
      parse_declit_node(n);
  } else if(!strcmp(n->token->id, "StrLit")){
      parse_strlit_node(n);
  } /*else if(!strcmp(n->token->id, "Id")){
      parse_id_node(n);
  }*/
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

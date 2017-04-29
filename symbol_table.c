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
    if(parse_formalparams_node(n->childs[0]->childs[2]->childs[i]))
      insert_symbol(table[table_index], n->childs[0]->childs[2]->childs[i]->childs[1]->value, 0, NULL, table[table_index]->params[i], strdup("param"));

  }
  for(i = 0; i < n->childs[1]->n_children; i++){
    if(!strcmp(n->childs[1]->childs[i]->token->id, "VarDecl")){
      insert_symbol(table[table_index], n->childs[1]->childs[i]->childs[1]->value, 0, NULL, str_to_lower(n->childs[1]->childs[i]->childs[0]->token->id), NULL);
      // we call it with n as a VarDecl node
      parse_vardecl_node(n->childs[1]->childs[i]);
    }
  }

  iterate_tree(n->childs[1]);

  for(i=0; i<n->childs[1]->n_children; i++){
    if(!strcmp(n->childs[1]->childs[i]->token->id, "Return")){
      symbol* aux = (symbol*)malloc(sizeof(symbol));
      aux = table[table_index]->first;
      parse_return_node(n->childs[1]->childs[i], aux->type);
    }
  }

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
      if(!strcmp(n->childs[i]->token->id, "MethodDecl") && !n->childs[i]->childs[0]->duplicated_method){
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

    if(parse_methodheader_node(n->childs[0]))
      insert_symbol(table[0], n->childs[0]->childs[1]->value, n_params, params, str_to_lower(n->childs[0]->childs[0]->token->id), NULL);

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

bool parse_formalparams_node(node* n){
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

  if(count >= 1){
    printf("Line %d, col %d: Symbol %s already defined\n", n->childs[1]->token->line, n->childs[1]->token->col, n->childs[1]->value);
    return false;
  }
  return true;
}

// We check if the variable is not already declared as a parameter
// We check if in the local table there is a variable with the same name, and flag equal to param
void parse_vardecl_node(node* n){
  symbol* s = (symbol*)malloc(sizeof(symbol));
  s = table[table_index]->first;
  int i;
  int count = 0;
  while(s != NULL){

    if(!strcmp(n->childs[1]->value, s->name)){
      count++;
    }

    s = s->next;
  }
  if(count > 1){
    printf("Line %d, col %d: Symbol %s already defined\n", n->childs[1]->token->line, n->childs[1]->token->col, n->childs[1]->value);
  }
}

bool parse_methodheader_node(node* n){
  symbol* s = (symbol*)malloc(sizeof(symbol));
  node* methodparams = (node*)malloc(sizeof(node));
  s = table[0]->first;
  int count = 0;
  if(s!=NULL){
    char* name = strdup(s->name);
  }
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

  if(count == 1){
    printf("Line %d, col %d: Symbol %s already defined\n", n->childs[1]->token->line, n->childs[1]->token->col, n->childs[1]->value);
    n->duplicated_method = true;

    return false;
  }
  return true;
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
  n->anotated_type = n->childs[0]->anotated_type;

  // incompatibility


  int error_flag = 0;
  int flag = 0;
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
  } else if(!strcmp(n->childs[0]->anotated_type, "int") && !strcmp(n->childs[1]->anotated_type, "double")){
      error_flag = 1;
  } else if(!strcmp(n->childs[0]->anotated_type, "undef")){
      error_flag = 1;
  } else if(!strcmp(n->childs[1]->anotated_type, "undef")){
      error_flag = 1;
  }


  if(!strcmp(n->childs[1]->token->id, "Call")){
    if(!strcmp(n->childs[0]->anotated_type, "int") && !strcmp(n->childs[1]->anotated_type, "double")){
        flag = 1;
    } else if(!strcmp(n->childs[0]->anotated_type, "int") && !strcmp(n->childs[1]->anotated_type, "boolean")){
        flag = 1;
    } else if(!strcmp(n->childs[0]->anotated_type, "int") && !strcmp(n->childs[1]->anotated_type, "void")){
        flag = 1;
    } else if(!strcmp(n->childs[0]->anotated_type, "double") && !strcmp(n->childs[1]->anotated_type, "boolean")){
        flag = 1;
    } else if(!strcmp(n->childs[0]->anotated_type, "double") && !strcmp(n->childs[1]->anotated_type, "void")){
        flag = 1;
    } else if(!strcmp(n->childs[0]->anotated_type, "boolean") && !strcmp(n->childs[1]->anotated_type, "int")){
        flag = 1;
    } else if(!strcmp(n->childs[0]->anotated_type, "boolean") && !strcmp(n->childs[1]->anotated_type, "double")){
        flag = 1;
    } else if(!strcmp(n->childs[0]->anotated_type, "boolean") && !strcmp(n->childs[1]->anotated_type, "void")){
        flag = 1;
    }
  }

  if(flag){
    n->childs[1]->anotated_type = "undef";
    printf("Line %d, col: %d Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
  }

  if(error_flag == 1){
    //n->anotated_type = "undef";
    // TODO: CHECKAR LINHAS E COLUNAS PERGUNTAR AO STOR
    printf("Line %d, col: %d Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
  }
}

// percorremos tabelas até encontrar com nome igual
// se for match -> preenchemos árvore
// se for compativel -> contador++
// no fim verificar se contador > 1 - se for, ambiguous
// senão está bem
void parse_call_node(node* n){
  int i;
  int j;
  int k;
  int counter = 0;
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
      counter = 0;
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
    } else if(ambiguous_counter == 0 && counter == 0){
      n->anotated_type = "undef";
      //printf("check %s", strcat(n->childs[0]->value, n->childs[0]->anotated_type));
      int k;
      char call_child_types[100]="(";
      char result_to_print[100]="";

      for(k = 1; k < n->n_children; k++){
        strcat(call_child_types, n->childs[k]->anotated_type);
        if(k != n->n_children - 1){
          strcat(call_child_types, ",");
        }
      }
      strcat(call_child_types, ")");
      strcat(result_to_print, n->childs[0]->value);
      printf("Line %d, col %d: Cannot find symbol %s\n", n->childs[0]->token->line, n->childs[0]->token->col, strcat(result_to_print, call_child_types));
    }
}



void parse_parseargs_node(node* n){

  n->anotated_type = strdup("int");

  if(!strcmp(n->childs[0]->anotated_type,"undef")){
    printf("Line %d, col %d: Cannot find symbol %s\n", n->childs[0]->token->line, n->childs[0]->token->col, n->childs[0]->value);
  }
  if(!strcmp(n->childs[1]->anotated_type,"undef")){
    printf("Line %d, col %d: Cannot find symbol %s\n", n->childs[1]->token->line, n->childs[1]->token->col, n->childs[1]->value);
  }
  if(strcmp(n->childs[0]->anotated_type,"String[]")){
    n->anotated_type = strdup("undef");
    printf("Line %d, col: %d Incompatible type %s in %s statement\n", n->childs[0]->token->line, n->childs[0]->token->col, n->childs[0]->anotated_type, fix(n->token->id));
  }
  if(strcmp(n->childs[1]->anotated_type,"int")){
    n->anotated_type = strdup("undef");
    printf("Line %d, col: %d Incompatible type %s in %s statement\n", n->childs[1]->token->line, n->childs[1]->token->col, n->childs[1]->anotated_type, fix(n->token->id));
  }
}


void parse_and_or_nodes(node* n){
  n->anotated_type = strdup("boolean");
  if(strcmp(n->childs[0]->anotated_type,"boolean")){
    n->anotated_type = strdup("undef");
    printf("Line %d, col: %d Incompatible type %s in %s statement\n", n->childs[0]->token->line, n->childs[0]->token->col, n->childs[0]->anotated_type, fix(n->token->id));
  }
  if(strcmp(n->childs[1]->anotated_type,"boolean")){
    n->anotated_type = strdup("undef");
    printf("Line %d, col: %d Incompatible type %s in %s statement\n", n->childs[1]->token->line, n->childs[1]->token->col, n->childs[1]->anotated_type, fix(n->token->id));
  }
}

// Equality nodes >, >=, <, >=, ==, !=
// we can only compare boolean with bool2ean, int with int, double with int, int with double and double with int
// it should throw an error when the comparison is between boolean and int, boolean and double, int and boolean, double and boolean, undef and anything, anything and undef
// TODO: this can be shortened!! Not done yet for readibility purposes
void parse_equality_nodes(node* n){

  n->anotated_type = strdup("boolean");
  if(!strcmp(n->childs[0]->anotated_type,"boolean") && !strcmp(n->childs[1]->anotated_type,"int")){
    n->anotated_type = strdup("undef");
    printf("Line %d, col: %d Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
  } else if(!strcmp(n->childs[0]->anotated_type,"int") && !strcmp(n->childs[1]->anotated_type,"boolean")){
    n->anotated_type = strdup("undef");
    printf("Line %d, col: %d Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
  } else if(!strcmp(n->childs[0]->anotated_type,"boolean") && !strcmp(n->childs[1]->anotated_type,"double")){
    n->anotated_type = strdup("undef");
    printf("Line %d, col: %d Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
  } else if(!strcmp(n->childs[0]->anotated_type,"double") && !strcmp(n->childs[1]->anotated_type,"boolean")){
    n->anotated_type = strdup("undef");
    printf("Line %d, col: %d Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
  } else if(!strcmp(n->childs[0]->anotated_type,"undef")){
    n->anotated_type = strdup("undef");
    printf("Line %d, col: %d Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
  } else if(!strcmp(n->childs[1]->anotated_type,"undef")){
    n->anotated_type = strdup("undef");
    printf("Line %d, col: %d Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
  }
}


void parse_minus_plus_nodes(node* n){
  n->anotated_type = n->childs[0]->anotated_type;

  if(!strcmp(n->childs[0]->anotated_type, "int") || !strcmp(n->childs[0]->anotated_type, "double"))
    n->anotated_type = n->childs[0]->anotated_type;
  else{
    printf("Line %d, col: %d Incompatible type %s in %s statement\n", n->token->line, n->token->col, n->childs[0]->anotated_type, fix(n->token->id));
    n->anotated_type = strdup("undef");
  }

}


void parse_logic_nodes(node* n){

  if(!strcmp(n->childs[0]->anotated_type, "undef"))
    printf("Line %d, col: %d Cannot find symbol %s\n", n->childs[0]->token->line, n->childs[0]->token->col,n->childs[0]->value);
  if(!strcmp(n->childs[1]->anotated_type, "undef"))
    printf("Line %d, col: %d Cannot find symbol %s\n", n->childs[1]->token->line, n->childs[1]->token->col,n->childs[1]->value);
  if(!strcmp(n->childs[0]->anotated_type, "double") || !strcmp(n->childs[1]->anotated_type, "double")){
    if(!strcmp(n->childs[0]->anotated_type, "int") || !strcmp(n->childs[1]->anotated_type, "int")){
      n->anotated_type = strdup("double");
    }else if(!strcmp(n->childs[0]->anotated_type, "double") && !strcmp(n->childs[1]->anotated_type, "double")){
      n->anotated_type = strdup("double");
    } else {
      printf("Line %d, col: %d Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
      n->anotated_type = strdup("undef");
    }
  } else if(!strcmp(n->childs[0]->anotated_type, "int") && !strcmp(n->childs[1]->anotated_type, "int")){
      n->anotated_type = strdup("int");
  } else {
    printf("Line %d, col: %d Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
    n->anotated_type = strdup("undef");
  }
}


void parse_not_node(node* n){
  if(!strcmp(n->childs[0]->anotated_type, "boolean")){
    n->anotated_type = strdup("boolean");
  } else {
    printf("Line %d, col: %d Incompatible type %s in %s statement\n", n->token->line, n->token->col, n->childs[0]->anotated_type,fix(n->token->id));
    n->anotated_type = strdup("undef");
  }
}


void parse_length_node(node* n){
  n->anotated_type = strdup("int");
  if(strcmp(n->childs[0]->anotated_type, "String[]")){
    printf("Line %d, col: %d Incompatible type %s in %s statement\n", n->token->line, n->token->col, n->childs[0]->anotated_type, fix(n->token->id));
  }
}

void parse_declit_node(node* n){
  if((int*)n->value >= (int*)2147483648 || (int*)n->value <= (int*)-2147483648){
    n->anotated_type = strdup("undef");
    printf("Number 2147483648 out of bounds\n");
  } else {
    n->anotated_type = strdup("int");
  }

}

void parse_boollit_node(node* n){
  n->anotated_type = strdup("boolean");
}

void parse_reallit_node(node* n){
  n->anotated_type = strdup("double");
}


void parse_strlit_node(node* n){
  n->anotated_type = strdup("String");
}

//check if function type is equal to return type
void parse_return_node(node* n, char* t){

  //caso so seja return;
  if(n->n_children == 0){

    if(strcmp("void",t)){
      printf("Line %d, col: %d Incompatible type %s in %s statement\n", n->token->line, n->token->col, "void", fix(n->token->id));
    }
  } else if(strcmp(n->childs[0]->anotated_type,t) && !strcmp(n->childs[0]->anotated_type, "undef")){
    printf("Line %d, col: %d Cannot find symbol %s\n", n->childs[0]->token->line, n->childs[0]->token->col,n->childs[0]->value);
    printf("Line %d, col: %d Incompatible type %s in %s statement\n", n->token->line, n->token->col, n->childs[0]->anotated_type, fix(n->token->id));
  }
  else if(strcmp(n->childs[0]->anotated_type,t)){
    printf("Line %d, col: %d Incompatible type %s in %s statement\n", n->childs[0]->token->line, n->childs[0]->token->col, n->childs[0]->anotated_type, fix(n->token->id));
  }
}

void check_assign_definition(node* n){
  if(!strcmp(n->childs[0]->anotated_type, "undef") && n->childs[0]->n_children == 0){
      printf("Line %d, col: %d Cannot find symbol %s\n", n->token->line, n->token->col, n->childs[0]->value);
  }
}

void check_call_definition(node* n){
  int i;
  for(i=1; i< n->n_children;i++){
    if(!strcmp(n->childs[i]->anotated_type, "undef") && (n->childs[i]->n_children == 0)){
      printf("Line %d, col: %d Cannot find symbol %s\n", n->childs[i]->token->line, n->childs[i]->token->col, n->childs[i]->value);
    }

  }
}

void check_and_or_definition(node* n){
  int i;
  for(i=0; i< n->n_children;i++){
    if(!strcmp(n->childs[i]->anotated_type, "undef") && (n->childs[i]->n_children == 0)){
      printf("Line %d, col: %d Cannot find symbol %s\n", n->childs[i]->token->line, n->childs[i]->token->col, n->childs[i]->value);
    }

  }
}

void check_minus_plus_definition(node* n){

  if(!strcmp(n->childs[0]->anotated_type, "undef") && (n->childs[0]->n_children == 0)){
    printf("Line %d, col: %d Cannot find symbol %s\n", n->childs[0]->token->line, n->childs[0]->token->col, n->childs[0]->value);
  }

}

void check_not_definition(node* n){

  if(!strcmp(n->childs[0]->anotated_type, "undef") && (n->childs[0]->n_children == 0)){
    printf("AQUI mo not\n");
    printf("Line %d, col: %d Cannot find symbol %s\n", n->childs[0]->token->line, n->childs[0]->token->col, n->childs[0]->value);
  }

}

void check_equality_nodes(node* n){
  if(!strcmp(n->childs[0]->anotated_type,"undef") && n->childs[0]->n_children == 0){
    printf("Line %d, col: %d Cannot find symbol %s\n", n->childs[0]->token->line, n->childs[0]->token->col,n->childs[0]->value);
  }
  if(!strcmp(n->childs[1]->anotated_type,"undef") && n->childs[1]->n_children == 0){
    printf("Line %d, col: %d Cannot find symbol %s\n", n->childs[1]->token->line, n->childs[1]->token->col,n->childs[1]->value);
  }
}

void check_logic_nodes(node* n){
  if(!strcmp(n->childs[0]->anotated_type,"undef") && n->childs[0]->n_children == 0){
    printf("Line %d, col: %d Cannot find symbol %s\n", n->childs[0]->token->line, n->childs[0]->token->col,n->childs[0]->value);
  }
  if(!strcmp(n->childs[1]->anotated_type,"undef") && n->childs[1]->n_children == 0){
    printf("Line %d, col: %d Cannot find symbol %s\n", n->childs[1]->token->line, n->childs[1]->token->col,n->childs[1]->value);
  }
}

void check_length_nodes(node* n){
  if(!strcmp(n->childs[0]->anotated_type,"undef") && n->childs[0]->n_children == 0){
    printf("Line %d, col: %d Cannot find symbol %s\n", n->childs[0]->token->line, n->childs[0]->token->col,n->childs[0]->value);
  }
}

void create_an_tree(node *n){
  int i = 0;

  if(!strcmp(n->token->id, "Program")){
    for(i = 0; i < n->n_children; i++){
      if(strcmp(n->childs[i]->token->id, "Id"))
        create_an_tree(n->childs[i]);
    }
  } else if(!strcmp(n->token->id, "FieldDecl") || !strcmp(n->token->id, "MethodHeader") || !strcmp(n->token->id, "FormalParams") || !strcmp(n->token->id, "VarDecl")){

  } else if(!strcmp(n->token->id, "MethodDecl") && !n->childs[0]->duplicated_method){
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

      check_assign_definition(n);
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_assign_node(n);

  } else if(!strcmp(n->token->id, "Call")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_call_node(n);
      check_call_definition(n);
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
      check_and_or_definition(n);
      parse_and_or_nodes(n);

  } else if(!strcmp(n->token->id, "Eq") || !strcmp(n->token->id, "Geq") || !strcmp(n->token->id, "Gt") || !strcmp(n->token->id, "Leq") || !strcmp(n->token->id, "Lt") || !strcmp(n->token->id, "Neq")){


      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      check_equality_nodes(n);
      parse_equality_nodes(n);
  } else if(!strcmp(n->token->id, "Add") || !strcmp(n->token->id, "Sub") || !strcmp(n->token->id, "Mul") || !strcmp(n->token->id, "Div") || !strcmp(n->token->id, "Mod")){

      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      check_logic_nodes(n);
      parse_logic_nodes(n);
  } else if(!strcmp(n->token->id, "Minus") || !strcmp(n->token->id, "Plus")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      check_minus_plus_definition(n);
      parse_minus_plus_nodes(n);
  } else if(!strcmp(n->token->id, "Not")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      check_not_definition(n);
      parse_not_node(n);
  } else if(!strcmp(n->token->id, "Length")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      check_length_nodes(n);
      parse_length_node(n);
  } else if(!strcmp(n->token->id, "BoolLit")){
      parse_boollit_node(n);
  } else if(!strcmp(n->token->id, "RealLit")){
      parse_reallit_node(n);
  } else if(!strcmp(n->token->id, "DecLit")){
      parse_declit_node(n);
  } else if(!strcmp(n->token->id, "StrLit")){
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

char* fix(char* type){
  if(!strcmp(type, "Lt")){
    return "<";
  } else if(!strcmp(type, "Gt")){
    return ">";
  } else if(!strcmp(type, "Eq")){
    return "==";
  } else if(!strcmp(type, "Neq")){
    return "!=";
  } else if(!strcmp(type, "Leq")){
    return ">";
  } else if(!strcmp(type, "Geq")){
    return ">=";
  } else if(!strcmp(type, "Plus")){
    return "+";
  } else if(!strcmp(type, "Minus")){
    return "-";
  } else if(!strcmp(type, "Div")){
    return "/";
  } else if(!strcmp(type, "Mul")){
    return "*";
  } else if(!strcmp(type, "Mod")){
    return "%";
  } else if(!strcmp(type, "Not")){
    return "!";
  } else if(!strcmp(type, "Assign")){
    return "=";
  } else if(!strcmp(type, "Comma")){
    return ";";
  } else if(!strcmp(type, "Semi")){
    return ",";
  } else if(!strcmp(type, "Add")){
    return "+";
  } else if(!strcmp(type, "Sub")){
    return "-";
  } else if(!strcmp(type, "And")){
    return "&&";
  } else if(!strcmp(type, "Or")){
    return "||";
  } else if(!strcmp(type, "Length")){
    return ".length";
  }

  return type;





}

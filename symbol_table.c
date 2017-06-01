#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include "ast.h"
#include "symbol_table.h"

int error_semantic = 0;

symbol_table** new_table(int size) {
  return (symbol_table**)malloc(sizeof(symbol_table)*size);
}

symbol* new_symbol(char* name, int n_params, char** params, char* type, char* flag, int is_method) {
  symbol* s = (symbol*)malloc(sizeof(symbol));
  s->name = name;
  s->params = params;
  s->n_params = n_params;
  s->type = type;
  s->flag = flag;
  s->next = NULL;
  s->is_method=is_method; // not a method
  s->llvm_type = NULL;
  s->is_global = -1;
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

symbol* insert_symbol(symbol_table* st, char* name, int n_params, char** params, char* type, char* flag, int is_method) {
  symbol* first_symbol = st->first;
  if (first_symbol == NULL) {
    st->first = new_symbol(name, n_params, params, type, flag, is_method);
    return st->first;
  }

  while(first_symbol->next != NULL) {
    first_symbol = first_symbol->next;
  }
  first_symbol->next = new_symbol(name, n_params, params, type, flag, is_method);
  return first_symbol->next;

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

  insert_symbol(table[table_index], strdup("return"), 0, NULL, str_to_lower(n->childs[0]->childs[0]->token->id), NULL, 0);
  for(i = 0; i < n_params; i++){
    if(parse_formalparams_node(n->childs[0]->childs[2]->childs[i])){
      symbol* aux = insert_symbol(table[table_index], n->childs[0]->childs[2]->childs[i]->childs[1]->value, 0, NULL, table[table_index]->params[i], strdup("param"), 0);
      n->childs[0]->childs[2]->childs[i]->childs[1]->pointer_table = aux;
    }
  }

  for(i = 0; i < n->childs[1]->n_children; i++){
    if(!strcmp(n->childs[1]->childs[i]->token->id, "VarDecl")){
      // we call it with n as a VarDecl node
      if(parse_vardecl_node(n->childs[1]->childs[i])){
        symbol* aux =insert_symbol(table[table_index], n->childs[1]->childs[i]->childs[1]->value, 0, NULL, str_to_lower(n->childs[1]->childs[i]->childs[0]->token->id), NULL, 0);
        n->childs[1]->childs[i]->childs[1]->pointer_table = aux;
      }
    } else {
      // we pass method body
      iterate_tree(n->childs[1]->childs[i]);
    }
  }


  for(i=0; i<n->childs[1]->n_children; i++){
    if(!strcmp(n->childs[1]->childs[i]->token->id, "Return")){
      n->childs[1]->childs[i]->table_index = table_index;
    }
  }

  table_index++;
}

void first_traverse(node* n) {
  int i = 0;
  int k = 0;
  //TODO: dá seg fault aqui sem flag!!!!!!!
  if (!strcmp(n->token->id, "Program")) {
    table[table_index] = new_symbol_table("Class", n->childs[0]->value, 0, NULL);
    table_index++;
    for(i = 0; i < n -> n_children; i++){
      first_traverse(n->childs[i]);
    }
    for(i = 0; i < n -> n_children; i++){
      if(!strcmp(n->childs[i]->token->id, "MethodDecl") && n->childs[i]->childs[0]->duplicated_method == 0){
        second_traverse(n->childs[i]);
      }
    }
  } else if(!strcmp(n->token->id, "MethodDecl")){
    int n_params = n->childs[0]->childs[2]->n_children;//MethodHeader->MethodParams->n_children
    char** params = (char**)malloc(sizeof(char*)*n_params);
    for(i = 0; i < n_params; i++){
      //MethodDecl -> MethodHeader -> MethodParams -> ParamDecl[i] -> token->id
      params[i] = str_to_lower(n->childs[0]->childs[2]->childs[i]->childs[0]->token->id);
        for(k = 0; k < i; k++){
          if(!strcmp(n->childs[0]->childs[2]->childs[i]->childs[1]->value, n->childs[0]->childs[2]->childs[k]->childs[1]->value)){
            printf("Line %d, col %d: Symbol %s already defined\n", n->childs[0]->childs[2]->childs[i]->childs[1]->token->line, n->childs[0]->childs[2]->childs[i]->childs[1]->token->col, n->childs[0]->childs[2]->childs[k]->childs[1]->value);
            error_semantic = 1;
            break;
          }
        }
    }
    // checks if method exists or not
    if(parse_methodheader_node(n->childs[0])){
      insert_symbol(table[0], n->childs[0]->childs[1]->value, n_params, params, str_to_lower(n->childs[0]->childs[0]->token->id), NULL, 1);
    }
  } else if(!strcmp(n->token->id, "FieldDecl")){
    if(parse_fielddecl_node(n)){
      symbol* aux=insert_symbol(table[0], n->childs[1]->value, 0, NULL, str_to_lower(n->childs[0]->token->id), NULL, 0);
      n->childs[1]->pointer_table = aux;
    }
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
          if(!strcmp(n->childs[i]->value, s->name)){
            n->childs[i]->anotated_type = strdup(s->type);
            n->childs[i]->pointer_table = s;
            break;
          }
          if(n->childs[i]->anotated_type == NULL){
            symbol* g = (symbol*)malloc(sizeof(symbol));
            g = table[0]->first;
            while(g != NULL){
              if(!strcmp(n->childs[i]->value, g->name) && g->params == NULL){
                n->childs[i]->anotated_type = strdup(g->type);
                n->childs[i]->pointer_table = g;
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
      } else if(!strcmp(n->childs[i]->token->id, "BoolLit")){
          n->childs[i]->anotated_type = strdup("boolean");
      } else if(!strcmp(n->childs[i]->token->id, "RealLit")){
          n->childs[i]->anotated_type = strdup("double");
      } else if(!strcmp(n->childs[i]->token->id, "DecLit")){
          n->childs[i]->anotated_type = strdup("int");
      } else if(!strcmp(n->childs[i]->token->id, "StrLit")){
          n->childs[i]->anotated_type = strdup("String");
      }
      iterate_tree(n->childs[i]);
  }
}

bool parse_formalparams_node(node* n){
  symbol* s = (symbol*)malloc(sizeof(symbol));
  s = table[table_index]->first;
  int count = 0;
  while(s != NULL){
    if(s->flag != NULL){
      if(!(strcmp(n->childs[1]->value, s->name)) && !strcmp(s->flag, "param")){
        count++;
      }
    }
    s = s->next;
  }

  if(count == 1){
    return false;
  }
  return true;
}

// We check if the variable is not already declared as a parameter
// We check if in the local table there is a variable with the same name, and flag equal to param
bool parse_vardecl_node(node* n){
  symbol* s = (symbol*)malloc(sizeof(symbol));
  s = table[table_index]->first;
  int count = 0;
  while(s != NULL){
    if(!strcmp(n->childs[1]->value, s->name)){
      count++;
    }
    s = s->next;
  }
  if(count == 1){
    error_semantic = 1;
    printf("Line %d, col %d: Symbol %s already defined\n", n->childs[1]->token->line, n->childs[1]->token->col, n->childs[1]->value);
    return false;
  }
  return true;
}

bool parse_methodheader_node(node* n){
  symbol* s = (symbol*)malloc(sizeof(symbol));
  node* methodparams = (node*)malloc(sizeof(node));
  s = table[0]->first;
  int count = 0;
  //char str[1000] = {0}; // TODO: não fazer 100 à mão!!!!!
  //char str2[1000] = {0}; // TODO: MUDAR ISTO
  char* str = (char*)malloc(1000 * sizeof(char));
  char* str2 = (char*)malloc(1000 * sizeof(char));
  while(s != NULL){
    if(!strcmp(s->name, n->childs[1]->value) && n->childs[2]->n_children == s->n_params && s->is_method == 1){
      //check if they have the same parameters

      // reconstruct symbol params
      strcpy(str, "");
      strcpy(str2, "");

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

      if(!strcmp(str, str2)){
        count++;
      }
    }
    s = s->next;
  }

  if(count == 1){
    printf("Line %d, col %d: Symbol %s(%s) already defined\n", n->childs[1]->token->line, n->childs[1]->token->col, n->childs[1]->value, str2);
    error_semantic = 1;
    n->duplicated_method = 1;
    return false;
  } else {
    n->duplicated_method = 0;
  }
  return true;
}

/*
  In case there are multiple global variable declarations that are equal,
  we need to throw an error;
*/
bool parse_fielddecl_node(node* n){

  symbol* s = (symbol*)malloc(sizeof(symbol));
  s = table[0]->first;
  int count = 0;

  while(s != NULL){
    if(!strcmp(s->name, n->childs[1]->value) && s->params == NULL){
      count++;
    }
    s = s->next;
  }

  if(count == 1){
    printf("Line %d, col %d: Symbol %s already defined\n", n->childs[1]->token->line, n->childs[1]->token->col, n->childs[1]->value);
    error_semantic = 1;
    return false;
  }
  return true;
}

void parse_assign_node(node *n){
  n->anotated_type = n->childs[0]->anotated_type;
  if((!strcmp(n->childs[0]->anotated_type, "int") && !strcmp(n->childs[1]->anotated_type, "int")) ||
     (!strcmp(n->childs[0]->anotated_type, "double") && !strcmp(n->childs[1]->anotated_type, "double")) ||
     (!strcmp(n->childs[0]->anotated_type, "double") && !strcmp(n->childs[1]->anotated_type, "int")) ||
     (!strcmp(n->childs[0]->anotated_type, "boolean") && !strcmp(n->childs[1]->anotated_type, "boolean"))){
       return;
     } else {
       printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
       error_semantic = 1;
     }
}
// percorremos tabelas até encontrar com nome igual
// se for match -> preenchemos árvore
// se for compativel -> contador++
// no fim verificar se contador > 1 - se for, ambiguous
// senão está bem


// percorres as tabelas todas e vês se há alguma com nome igual e nº parametros iguais
// na tabela local ver se parametros batem certo
// se baterem, acabou
// se não baterem, vemos se são compativeis -> se forem variavel++;
// se variavel > 1 -> ambiguous


void parse_call_node(node* n){
  int k=0;
  int counter = 0;
  int double_int_counter = 0;
  int matches = 0;
  int double_int_matches = 0;
  symbol* g = (symbol*)malloc(sizeof(symbol));
  g = table[0]->first;
  char str[1000]="(";
  char str2[1000]="(";

  while(g != NULL){
    counter = 0;
    double_int_counter = 0;
    if(!strcmp(n->childs[0]->value, g->name) && ((n->n_children - 1) == g->n_params) && g->is_method == 1){

      for(k = 0; k < g->n_params; k++){
        if(!strcmp(n->childs[k+1]->anotated_type, g->params[k]) ){
          counter++;
        } else if(!strcmp(n->childs[k+1]->anotated_type, "int") && !strcmp(g->params[k], "double")){
          double_int_counter++;
        } else {
          break;
        }
      }
      if(counter == g->n_params){
        n->anotated_type = g->type;
        matches++;
        strcpy(str,"(");
        int j;
        for(j = 0; j < g->n_params; j++){
          strcat(str, g->params[j]);
          if(j != g->n_params - 1){
            strcat(str, ",");
            }
        }

        strcat(str, ")");
        break;
      } else if(counter + double_int_counter == g->n_params){
        n->anotated_type = g->type;
        double_int_matches++;
        strcpy(str2,"(");
        int j;
        for(j = 0; j < g->n_params; j++){
          strcat(str2, g->params[j]);
          if(j != g->n_params - 1){
            strcat(str2, ",");
            }
        }

        strcat(str2, ")");

      }
    }
    g = g->next;
  }

  if(matches == 1){//one perfect match found
    n->childs[0]->anotated_type = strdup(str);
    return;
  } else if( matches == 0){//perfect match not found

    if(double_int_matches == 1){//one compatible match found
      n->childs[0]->anotated_type = strdup(str2);
      return;

    } else if(double_int_matches == 0){//0 matches found
        char call_child_types[1000]="(";
        char result_to_print[1000]="";
        int h=1;
        //mandar print correto
        for(h = 1; h < n->n_children; h++){
          strcat(call_child_types, n->childs[h]->anotated_type);
          if(h != n->n_children - 1){
            strcat(call_child_types, ",");
          }
        }
        strcat(call_child_types, ")");
        strcat(result_to_print, n->childs[0]->value);


        n->anotated_type = "undef";
        n->childs[0]->anotated_type = "undef";
        printf("Line %d, col %d: Cannot find symbol %s\n", n->childs[0]->token->line, n->childs[0]->token->col, strcat(result_to_print, call_child_types));

    } else{//ambiguous

      char call_child_types[1000]="(";
      int h=1;
      //mandar print correto
      for(h = 1; h < n->n_children; h++){
        strcat(call_child_types, n->childs[h]->anotated_type);
        if(h != n->n_children - 1){
          strcat(call_child_types, ",");
        }
      }
      strcat(call_child_types, ")");


      n->anotated_type = "undef";
      n->childs[0]->anotated_type = "undef";
      printf("Line %d, col %d: Reference to method %s%s is ambiguous\n", n->childs[0]->token->line, n->childs[0]->token->col, n->childs[0]->value, call_child_types);
    }
  }


}

void parse_parseargs_node(node* n){

  n->anotated_type = strdup("int");

  if(strcmp(n->childs[0]->anotated_type,"String[]") || strcmp(n->childs[1]->anotated_type,"int")){//TODO: alterar linhas
    printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col-17, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
  }
}


void parse_and_or_nodes(node* n){
  n->anotated_type = strdup("boolean");
  if(strcmp(n->childs[0]->anotated_type,"boolean") || strcmp(n->childs[1]->anotated_type,"boolean")){
    printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
  }
}

// Equality nodes ==, !=
void parse_equality_nodes(node* n){
  n->anotated_type = strdup("boolean");
  if((!strcmp(n->childs[0]->anotated_type,"int") && !strcmp(n->childs[1]->anotated_type,"int")) ||
     (!strcmp(n->childs[0]->anotated_type,"double") && !strcmp(n->childs[1]->anotated_type,"double")) ||
     (!strcmp(n->childs[0]->anotated_type,"double") && !strcmp(n->childs[1]->anotated_type,"int")) ||
     (!strcmp(n->childs[0]->anotated_type,"boolean") && !strcmp(n->childs[1]->anotated_type,"boolean")) ||
     (!strcmp(n->childs[0]->anotated_type,"int") && !strcmp(n->childs[1]->anotated_type,"double"))){
     return;
  }else {
    printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
  }
}

// Relational nodes > , >=, <, >=
void parse_relational_nodes(node* n){
  n->anotated_type = strdup("boolean");
  if((!strcmp(n->childs[0]->anotated_type,"int") && !strcmp(n->childs[1]->anotated_type,"int")) ||
     (!strcmp(n->childs[0]->anotated_type,"double") && !strcmp(n->childs[1]->anotated_type,"double")) ||
     (!strcmp(n->childs[0]->anotated_type,"int") && !strcmp(n->childs[1]->anotated_type,"double")) ||
     (!strcmp(n->childs[0]->anotated_type,"double") && !strcmp(n->childs[1]->anotated_type,"int"))){
     return;
  }else {
    printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
  }
}


void parse_minus_plus_nodes(node* n){
  n->anotated_type = n->childs[0]->anotated_type;

  if(!strcmp(n->childs[0]->anotated_type, "int") || !strcmp(n->childs[0]->anotated_type, "double"))
    n->anotated_type = n->childs[0]->anotated_type;
  else{
    printf("Line %d, col %d: Operator %s cannot be applied to type %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type);
    n->anotated_type = strdup("undef");
  }

}


void parse_logic_nodes(node* n){

  if(!strcmp(n->childs[0]->anotated_type, "double") || !strcmp(n->childs[1]->anotated_type, "double")){
    if(!strcmp(n->childs[0]->anotated_type, "int") || !strcmp(n->childs[1]->anotated_type, "int")){
      n->anotated_type = strdup("double");
    }else if(!strcmp(n->childs[0]->anotated_type, "double") && !strcmp(n->childs[1]->anotated_type, "double")){
      n->anotated_type = strdup("double");
    } else {
      printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
      n->anotated_type = strdup("undef");
    }
  } else if(!strcmp(n->childs[0]->anotated_type, "int") && !strcmp(n->childs[1]->anotated_type, "int")){
      n->anotated_type = strdup("int");
  } else {
    printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type, n->childs[1]->anotated_type);
    n->anotated_type = strdup("undef");
  }
}


void parse_not_node(node* n){
  n->anotated_type = strdup("boolean");
  if(strcmp(n->childs[0]->anotated_type, "boolean")){
    printf("Line %d, col %d: Operator %s cannot be applied to type %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type);
  }
}


void parse_length_node(node* n){
  n->anotated_type = strdup("int");
  if(strcmp(n->childs[0]->anotated_type, "String[]")){
    printf("Line %d, col %d: Operator %s cannot be applied to type %s\n", n->token->line, n->token->col, fix(n->token->id), n->childs[0]->anotated_type);
  }
}

void parse_declit_node(node* n){
  n->anotated_type = strdup("int");
  long int a = 2147483648;
  if(atoll((char*)n->value) >= a){
    printf("Line %d, col %d: Number %s out of bounds\n", n->token->line, n->token->col, (char*)n->value);
  }
}

// count the number of zeros until e or \n
//
void parse_reallit_node(node* n){

  double number;
  char* char_value = (char*)n->value;
  char* str = (char*)malloc(1000*sizeof(char));
  int i = 0, j=0;
  bool e_flag = false;
  bool different_zero_flag = false;
  while(char_value[i] != '\0'){
    if(char_value[i] == 'E' || char_value[i] == 'e')
      e_flag = true;

    if(char_value[i] != '.' && char_value[i] != '0' && !e_flag)
      different_zero_flag = true;
    if(char_value[i] != '_'){
      str[j] = char_value[i];
      j++;
    }
    i++;

  }
  str[j] = '\0';
  number = atof(str);

  if(different_zero_flag){
    if(number==0){
      printf("Line %d, col %d: Number %s out of bounds\n", n->token->line, n->token->col, n->value);
    } else if(number > DBL_MAX){
      printf("Line %d, col %d: Number %s out of bounds\n", n->token->line, n->token->col, n->value);
    }

  }
  free(str);
  n->anotated_type = strdup("double");
}

void parse_boollit_node(node* n){
  n->anotated_type = strdup("boolean");
}


void parse_strlit_node(node* n){
  n->anotated_type = strdup("String");
}

void parse_return_node(node* n){
  // empty return
  char* t = table[n->table_index]->first->type;
  if(n->n_children == 0){
    // if it is not void
    if(strcmp(t, "void")){
      printf("Line %d, col %d: Incompatible type %s in %s statement\n", n->token->line, n->token->col, "void", fix(n->token->id));
    }
  } else if(n->n_children > 0){
    if(!strcmp(t, "double")){
      if(strcmp(n->childs[0]->anotated_type, "int") && strcmp(n->childs[0]->anotated_type, "double")){
        printf("Line %d, col %d: Incompatible type %s in %s statement\n", n->childs[0]->token->line, n->childs[0]->token->col, n->childs[0]->anotated_type, fix(n->token->id));
      }
    } else if(!strcmp(t, "void")){
      printf("Line %d, col %d: Incompatible type %s in %s statement\n", n->childs[0]->token->line, n->childs[0]->token->col, n->childs[0]->anotated_type, fix(n->token->id));
    } else if(strcmp(n->childs[0]->anotated_type, t)){
      printf("Line %d, col %d: Incompatible type %s in %s statement\n", n->childs[0]->token->line, n->childs[0]->token->col, n->childs[0]->anotated_type, fix(n->token->id));


    }

  }
}

void parse_if_node(node* n){
  if(strcmp(n->childs[0]->anotated_type, "boolean")){
    printf("Line %d, col %d: Incompatible type %s in %s statement\n", n->childs[0]->token->line, n->childs[0]->token->col, n->childs[0]->anotated_type, fix(n->token->id));
  }
}

void parse_while_node(node* n){
  if(strcmp(n->childs[0]->anotated_type, "boolean")){
    printf("Line %d, col %d: Incompatible type %s in %s statement\n", n->childs[0]->token->line, n->childs[0]->token->col, n->childs[0]->anotated_type, fix(n->token->id));
  }
}

void parse_do_while_node(node* n){
  if(strcmp(n->childs[1]->anotated_type, "boolean")){
    printf("Line %d, col %d: Incompatible type %s in %s statement\n", n->childs[1]->token->line, n->childs[1]->token->col, n->childs[1]->anotated_type, fix(n->token->id));
  }
}

void parse_print_node(node* n){

  if(!strcmp(n->childs[0]->anotated_type, "String[]") || !strcmp(n->childs[0]->anotated_type, "undef") || !strcmp(n->childs[0]->anotated_type, "void")){
    printf("Line %d, col %d: Incompatible type %s in %s statement\n", n->childs[0]->token->line, n->childs[0]->token->col, n->childs[0]->anotated_type, fix(n->token->id));
  }
}

void check_call_definition(node* n){
  n->childs[0]->is_method = 1;
}


void create_an_tree(node *n){
  int i = 0;

  if(!strcmp(n->token->id, "Program")){
    for(i = 0; i < n->n_children; i++){
      if(strcmp(n->childs[i]->token->id, "Id"))
        create_an_tree(n->childs[i]);
    }
  } else if(!strcmp(n->token->id, "FieldDecl") || !strcmp(n->token->id, "MethodHeader") || !strcmp(n->token->id, "FormalParams") || !strcmp(n->token->id, "VarDecl")){

  } else if(!strcmp(n->token->id, "MethodDecl") && n->childs[0]->duplicated_method == 0){

      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->token->id, "MethodBody")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->token->id, "If")){
      create_an_tree(n->childs[0]);
      parse_if_node(n);
      for(i = 1; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }

  } else if(!strcmp(n->token->id, "While")){
      create_an_tree(n->childs[0]);
      parse_while_node(n);
      for(i = 1; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->token->id, "DoWhile")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_do_while_node(n);
  } else if(!strcmp(n->token->id, "Print")){

      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_print_node(n);

  } else if(!strcmp(n->token->id, "Assign")){

      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_assign_node(n);
  } else if(!strcmp(n->token->id, "Call")){
      //create_an_tree(n->childs[0]);
      check_call_definition(n);
      // TODO: a 1
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_call_node(n);
  } else if(!strcmp(n->token->id, "ParseArgs")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_parseargs_node(n);
  } else if(!strcmp(n->token->id, "Block")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
  } else if(!strcmp(n->token->id, "And") || !strcmp(n->token->id, "Or")){

      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_and_or_nodes(n);
  } else if(!strcmp(n->token->id, "Eq") || !strcmp(n->token->id, "Neq")){

      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_equality_nodes(n);
  } else if(!strcmp(n->token->id, "Geq") || !strcmp(n->token->id, "Gt") || !strcmp(n->token->id, "Leq") || !strcmp(n->token->id, "Lt")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_relational_nodes(n);
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
  } else if(!strcmp(n->token->id, "Return")){
      for(i = 0; i < n->n_children; i++){
        create_an_tree(n->childs[i]);
      }
      parse_return_node(n);
  } else if(!strcmp(n->token->id, "BoolLit")){
      parse_boollit_node(n);
  } else if(!strcmp(n->token->id, "RealLit")){
      parse_reallit_node(n);
  } else if(!strcmp(n->token->id, "DecLit")){
      parse_declit_node(n);
  } else if(!strcmp(n->token->id, "StrLit")){
      parse_strlit_node(n);
  } else if(!strcmp(n->token->id, "Id")){
      if(!strcmp(n->anotated_type,"undef") && n->is_method == 0){
        printf("Line %d, col %d: Cannot find symbol %s\n", n->token->line, n->token->col,n->value);
      }
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
    return "<=";
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
  } else if(!strcmp(type, "Return")){
    return "return";
  } else if(!strcmp(type, "If")){
    return "if";
  } else if(!strcmp(type, "While")){
    return "while";
  } else if(!strcmp(type, "DoWhile")){
    return "do";
  } else if(!strcmp(type, "Print")){
    return "System.out.println";
  } else if(!strcmp(type, "ParseArgs")){
    return "Integer.parseInt";
  }

  return type;
}

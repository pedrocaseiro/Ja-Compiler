#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct symbol {
  char* name;
  char** params;
  int n_params;
  char* type;
  char* flag;
  struct symbol* next;
} symbol;

typedef struct symbol_table {
  symbol* first;
  char* name;
  char* type;
  int n_params;
  char** params;
} symbol_table;

symbol_table** table;
int table_index;

symbol_table** new_table(int);
symbol* new_symbol(char*, int, char**, char*, char*);
symbol_table* new_symbol_table(char*, char*, int, char**);
void first_traverse(node*);
void print_table();
void print_symbol_table(symbol*);
char* str_to_lower(char*);
void insert_symbol(symbol_table*, char*, int, char**, char*, char*);

void parse_return_node(node*, char*);
bool parse_formalparams_node(node*);
void parse_vardecl_node(node*);
bool parse_methodheader_node(node*);
void parse_fielddecl_node(node*);
void iterate_tree(node*);
void parse_strlit_node(node*);
void parse_length_node(node*);
void parse_not_node(node*);
void parse_logic_nodes(node*);
void parse_equality_nodes(node*);
void parse_logic_nodes(node*);
void parse_and_or_nodes(node*);
void parse_parseargs_node(node*);
void parse_call_node(node*);
void parse_declit_node(node*);
void parse_reallit_node(node*);
void parse_boollit_node(node*);
void parse_assign_node(node*);

void check_assign_definition(node*);
void check_call_definition(node*);
void check_and_or_definition(node*);
void check_minus_plus_definition(node*);
void check_not_definition(node* n);
void check_equality_nodes(node* n);
void check_length_nodes(node* n);

void create_an_tree(node*);
char* fix(char*);

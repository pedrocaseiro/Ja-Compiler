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
  int is_method; // 0 is not method, 1 is method
  struct symbol* next;
  char* llvm_type;
  int is_global;
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
int error_semantic;

symbol_table** new_table(int);
symbol* new_symbol(char*, int, char**, char*, char*, int);
symbol_table* new_symbol_table(char*, char*, int, char**);
void first_traverse(node*);
void print_table();
void print_symbol_table(symbol*);
char* str_to_lower(char*);
symbol* insert_symbol(symbol_table*, char*, int, char**, char*, char*, int);


void parse_while_node(node*);
void parse_do_while_node(node*);
void parse_if_node(node*);
void parse_return_node(node*);
bool parse_formalparams_node(node*);
bool parse_vardecl_node(node*);
bool parse_methodheader_node(node*);
bool parse_fielddecl_node(node*);
void iterate_tree(node*);
void parse_strlit_node(node*);
void parse_length_node(node*);
void parse_not_node(node*);
void parse_logic_nodes(node*);
void parse_equality_nodes(node*);
void parse_relational_nodes(node*);
void parse_logic_nodes(node*);
void parse_and_or_nodes(node*);
void parse_parseargs_node(node*);
void parse_call_node(node*);
void parse_declit_node(node*);
void parse_reallit_node(node*);
void parse_boollit_node(node*);
void parse_assign_node(node*);
void parse_print_node(node*);

void check_call_definition(node*);



void create_an_tree(node*);
char* fix(char*);

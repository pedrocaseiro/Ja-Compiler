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

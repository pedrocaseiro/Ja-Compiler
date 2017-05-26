#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void code_generation(node*);
void generate_fielddecl(node*);
void generate_vardecl(node*);
void generate_(node*);
void generate_vardecl(node*);
void generate_assign(node*);
void generate_id(node*);
char* return_type_to_llvm(char*);
char* parse_arguments_type(char*);

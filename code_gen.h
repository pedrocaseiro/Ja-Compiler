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
void generate_add(node*);
void generate_sub(node*);
void generate_mul(node*);
void generate_div(node*);
void generate_mod(node*);
void generate_not(node*);
void generate_eq(node*);
void generate_neq(node*);
void generate_lt(node*);
void generate_leq(node*);
void generate_gt(node*);
void generate_geq(node*);
void generate_and(node*);
void generate_or(node*);
void generate_return(node* n);
void generate_if(node* n);
void generate_while(node* n);
void generate_do_while(node* n);
void generate_call(node* n);
char* return_type_to_llvm(char*);
char* parse_arguments_type(char*);
void code_gen_ast(node* n);

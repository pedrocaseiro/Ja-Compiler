#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char* type;
	char* value;
	int n_children;
	int to_be_used; // node works as aux and will be used if value = 1. Will not be used if value = 0;
	struct node** childs;
} node;

int error_flag;


node* new_node(char* nodetype, int to_be_used);
node* create_terminal_node(char* nodetype, int to_be_used, char* v);
node* create_and_insert_node(char* nodetype, int to_be_used, int n_children, ...);
void ast_decl(node *typespec, node *declarator);
void print_node(node* n);
void print_tree(node* n, int d);
void destroy_tree(node *n);

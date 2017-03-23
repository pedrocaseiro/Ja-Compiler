#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char* type;
	void* value;
	int n_children;
	int to_be_used; // node works as aux and will be used if value = 1. Will not be used if value = 0;
	struct node** children;
} node;


node* new_node(char* type, void* value);
node* create_terminal_node(char* type, int used, void* value);
node* create_and_insert_node(char* type, int used, int n_children, ...);

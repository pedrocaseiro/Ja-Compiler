#include <stdarg.h>
#include <string.h>
#include "ast.h"

/* method to create a node, of any type */
node* new_node(char* type, void* value) {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->type = strdup(type);
	new_node->value = value;
	new_node->children = 0;
  new_node->n_children = 0;
	new_node->to_be_used = 1;
	return new_node;
}

/* this method uses the new_node method that creates a "general" node, but lets us change the to_be_used parameter */
node* create_terminal_node(char* type, int to_be_used, void* value) {
	node* new_terminal_node = new_node(type, value);
	new_terminal_node->to_be_used = to_be_used;
	return new_terminal_node;
}

/* this method uses the new_node method that creates a "general" node, but allows us to add children to it ( => it can't be terminal) */
node* create_and_insert_node(char* type, int to_be_used, int n_children, ...) {
  int i = 0;

	va_list args;
	va_start(args, n_children);
	node* parent = new_node(type, NULL);

	parent->to_be_used = to_be_used;
	parent->children = (node**)malloc(sizeof(node)*n_children); // allocate space for all it's children
	parent->n_children = n_children;

	node* current_child;
  int child = 0;
	for (child = 0; child < n_children; child++) { // iterate through all childs
		current_child = va_arg(args, node*);
		if (current_child->to_be_used) { // the node is gonna be used in the AST
			parent->children[i] = current_child;
			i++;
		}else { // the node is not gonna be used, we just want his childs
			parent->children = (node**)realloc(parent->children, sizeof(node)*(parent->n_children-1+current_child->n_children)); // allocate memory for all the child childrens
			parent->n_children = (parent->n_children-1)+current_child->n_children;
      int j = 0;
			for (j = 0; j < current_child->n_children; j++) {
				parent->children[i] = current_child->children[j];
				i++;
			}
		}
	}
	va_end(args);
	return parent;
}


void print_node(node* n, int depth) {

	int i;
	char* ident = (char*)malloc(sizeof(char)*depth*2+1);

	for (i=0;i<depth*2;i++) {
		ident[i] = '.';
	}
	printf("%s", ident);

  if (!strcmp(n->type, "Id")) {
  		printf("%s(%s)\n", n->type, (char*)n->value);
  }else {
    printf("%s\n", n->type);
  }

	for (i = 0; i < n->n_children; i++) {
		print_node(n->children[i], depth+1);
	}
}

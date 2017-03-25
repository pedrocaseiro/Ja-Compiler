#include <stdarg.h>
#include <string.h>
#include "ast.h"

node *merge_nodes[2048];

node* newnode(char* nodetype, int to_be_used) {
  //printf("new_node %s", nodetype);
  node* new_node = (node*) malloc(sizeof(node));
  new_node->type = nodetype;
  new_node->value = NULL;
  new_node->to_be_used = to_be_used;
  new_node->n_children = 0;
  new_node->childs = NULL;
  return new_node;
}

node* create_terminal_node(char* nodetype, int to_be_used, char* v) {
  //printf("Inserting new terminal: %s\n", node_types[nodetype]);
  node* new_terminal_node = newnode(nodetype, to_be_used);
  new_terminal_node->value = (char *) strdup(v);

  return new_terminal_node;
}


node* create_and_insert_node(char* nodetype, int to_be_used, int n_children, ...) {
  //printf("LUL");
  node *new_node, **tmp;
  int i, nodes = 0;
  va_list args;

  new_node = newnode(nodetype, to_be_used);

  tmp = merge_nodes;

  va_start(args, n_children);

  while (n_children--) {
    node *children = va_arg(args, node *);

    if (children == NULL) {
      continue;
    } else if (!children->to_be_used) { // it is not gonna be used
      nodes += children->n_children;
      for (i = 0; i < children->n_children; i++) {
        *tmp++ = children->childs[i];
      }
    } else {
      *tmp++ = children;
      nodes++;
    }
  }

  if (nodes != 0) {
    new_node->childs = (node **) malloc (nodes * sizeof(node *));
    memcpy(new_node->childs, merge_nodes, nodes * sizeof(node *));
    new_node->n_children = nodes;
  }

  va_end(args);
  return new_node;
}

node *save_nodes[2048];

void ast_fielddecl_aux(node *type, node *field_decl) {
  node **ptr = save_nodes;

  int children;
  for (children = 0; children < field_decl->n_children; children++) {
    *ptr++ = field_decl->childs[children];
  }

  field_decl->n_children++;
  field_decl->childs = (node **) malloc (field_decl->n_children * sizeof(node*));
  field_decl->childs[0] = type;

  ptr = save_nodes;
  for (children = 1; children < field_decl->n_children; children++) {
    field_decl->childs[children] = *ptr++;
  }
}

void ast_fielddecl(node *type, node *field_decl) {
  if (strcmp(field_decl->childs[0]->type, "FieldDecl") == 0) {
    printf("filho: %s\n", field_decl->childs[0]->type);
    int i;
    for (i = 0; i < field_decl->n_children; i++) {
      ast_fielddecl_aux(type, field_decl->childs[i]);
    }
  } else {
    ast_fielddecl_aux(type, field_decl);
  }
}

void print_node(node* n) {
  if (!strcmp(n->type, "Id")) {
    printf("%s(%s)\n", n->type, (char*)n->value);
  } else {
    printf("%s\n", n->type);
  }
}


void print_tree(node* n, int d) {
  //printf("asdasd");
  int i, k;
  for (k = 0; k < d; k++)
    printf("..");

  print_node(n);

  for (i = 0; i < n->n_children; i++) {
    print_tree(n->childs[i], d + 1);
  }
}


/*
node* new_node(char* type, void* value) {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->type = strdup(type);
	new_node->value = value;
	new_node->children = 0;
  new_node->n_children = 0;
	new_node->to_be_used = 1;
	return new_node;
}

node* create_terminal_node(char* type, int to_be_used, void* value) {
	node* new_terminal_node = new_node(type, value);
	new_terminal_node->to_be_used = to_be_used;
	return new_terminal_node;
}

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

*/

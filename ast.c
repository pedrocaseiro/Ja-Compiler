#include <stdarg.h>
#include <string.h>
#include "ast.h"

node *merge_nodes[2048];

node* newnode(char* nodetype, int to_be_used) {
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
  if (strcmp(field_decl->childs[0]->type, "FieldDecl") == 0 || strcmp(field_decl->childs[0]->type, "VarDecl") == 0) {
    printf("filho: %s\n", field_decl->childs[0]->type);
    int i;
    for (i = 0; i < field_decl->n_children; i++) {
      ast_fielddecl_aux(type, field_decl->childs[i]);
    }
  } else {
    ast_fielddecl_aux(type, field_decl);
  }
}

node *ast_fix_to_null(node *target_node) {
  if (target_node == NULL) {
    return create_and_insert_node("Null", 1, 0);
  } else if (strcmp(target_node->type, "Block") == 0 && target_node->n_children == 0) {
    return create_and_insert_node("Null", 1, 0);
  }

  return target_node;
}

void print_node(node* n) {
  if (strcmp(n->type, "Id") == 0 || strcmp(n->type, "DecLit") == 0) {
    printf("%s(%s)\n", n->type, (char*)n->value);
  } else {
    printf("%s\n", n->type);
  }
}


void print_tree(node* n, int d) {

  int i, k;
  for (k = 0; k < d; k++)
    printf("..");

  print_node(n);

  for (i = 0; i < n->n_children; i++) {
    print_tree(n->childs[i], d + 1);
  }
}

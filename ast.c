#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include "ast.h"

node *transfer_nodes[2048];
node *decl_nodes[2048];

int error_flag = 0;

node* newnode(char* nodetype, int to_be_used) {
  node* new_node = (node*) malloc(sizeof(node));
  new_node->type = nodetype;
  new_node->value = NULL;
  new_node->to_be_used = to_be_used;
  new_node->n_children = 0;
  new_node->childs = NULL;
  return new_node;
}

node* create_terminal_node(char* nodetype, int to_be_used, void* v) {
  node* new_terminal_node = newnode(nodetype, to_be_used);
  new_terminal_node->value = v;

  return new_terminal_node;
}


node* create_and_insert_node(char* nodetype, int to_be_used, int n_children, ...) {

  node *new_node, **tmp;
  int i, nodes = 0;
  va_list args;
  va_start(args, n_children);

  new_node = newnode(nodetype, to_be_used);

  tmp = transfer_nodes;

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
    memcpy(new_node->childs, transfer_nodes, nodes * sizeof(node *));
    new_node->n_children = nodes;
  }

  va_end(args);
  return new_node;
}

void ast_decl_aux(node *type, node *decl) {
  node **ptr = decl_nodes;

  // save the nodes that are already children of decl in ptr
  int children;
  for (children = 0; children < decl->n_children; children++) {
    *ptr++ = decl->childs[children];
  }

  decl->n_children++;
  decl->childs = (node **) malloc (decl->n_children * sizeof(node*));
  // we add type as the first child of decl.
  // by doing this we are losing his first childs
  decl->childs[0] = type;

  // ptr points to the start of the childs list
  ptr = decl_nodes;

  // iterate through the "lost" childs and add them as childs again
  for (children = 1; children < decl->n_children; children++) {
    decl->childs[children] = *ptr++;
  }
}

void ast_decl(node *type, node *decl) {
  if (strcmp(decl->childs[0]->type, "FieldDecl") == 0 || strcmp(decl->childs[0]->type, "VarDecl") == 0 || strcmp(decl->childs[0]->type, "ParamDecl") == 0) {
    int i;
    for (i = 0; i < decl->n_children; i++) {
      ast_decl_aux(type, decl->childs[i]);
    }
  } else {
    ast_decl_aux(type, decl);
  }
}

void destroy_tree(node *n) {

  if(n != NULL){
    int i;

    for (i = 0; i < n->n_children; i++) {
      destroy_tree(n->childs[i]);
    }

    free(n->childs);
    free(n);
  }
}


void print_node(node* n) {
  if (strcmp(n->type, "Id") == 0 || strcmp(n->type, "DecLit") == 0 || strcmp(n->type, "BoolLit") == 0 || strcmp(n->type, "RealLit") == 0 || strcmp(n->type, "StrLit") == 0 || strcmp(n->type, "Reserved") == 0) {
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

bool check_if_expr(node* test_node){
  if(!strcmp(test_node->type, "Semi") || !strcmp(test_node->type, "Empty") || (strcmp(test_node->type, "Return") && test_node->n_children == 0)){
    return true;
  }
  return false;
}


bool check_if_statement(node* test_node){
  if(!strcmp(test_node->type, "Semi") || !strcmp(test_node->type, "Empty") || (strcmp(test_node->type, "Return") && test_node->n_children == 0)){
    return true;
  }
  return false;
}

bool check_while_statement(node* test_node){
  if(!strcmp(test_node->type, "Semi") || !strcmp(test_node->type, "Empty") || (strcmp(test_node->type, "Return") && test_node->n_children == 0)){
    return true;
  }
  return false;
}

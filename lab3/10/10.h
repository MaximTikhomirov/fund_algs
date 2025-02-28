#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum errors {
    zero_eror,
    input_error,
    amount_arguments_error,
    realpath_error,
    same_files_error,
    memory_error,
    open_error
} errors;

typedef struct Node {
    char value;
    struct Node** children;
    int child_count;
    int child_capacity;
} Node;

int find_error(int);
int check_expression(const char *expr);
void print_tree(Node *root, FILE *output, int x);
void free_tree(Node *root);
Node* create_node(char value);
Node* parse_expression(const char** expr);
int validate_input(int argc, char **argv);

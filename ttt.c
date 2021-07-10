#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define is_leaf(t) (t->left == NULL && t->right == NULL)

typedef struct tree_t {
    char *string;
    int length;
    struct tree_t *left, *right;
} tree_t;

typedef struct automata_t {
    int start_state;
    int alpabet_size;
    int size; // n states
    int **next_state; // state x char -> next state, if negative fail state?
    char *accepting_state; // state -> 0, if accepting, non-0, if accepting
} automata_t;

void 
sort_ptrs(void *p, int size) {
    for (int i = 0; i < size-1; ++i) {
        if (p[i] < p[i+1])
    }
}

int 
size(tree_t *t) {
    if (is_leaf(t)) {return 1;}
    else {
        return size(t->left) + size(t->right);
    }
}

void;
build_automata(tree_t *t, automata_t *a) {
    // RAAI
    automata_t *a = malloc(sizeof(automata_t));
    a->size = size(t);
    a->next_state = malloc(sizeof(int)*(a->alpabet_size)*size);
    a->accepting_state = malloc(sizeof(char)*size);
}

int 
oracle(char *str) {
    // for now, a*b
    if (!str) return 0;
    for (; *str == 'a'; ++str);
    if ((*str) != 'b') return 0;
    ++str;
    return  (*str) == '\0';
}

void 
gnos_tree(tree_t *t, int indent) {
    if (!t) return;
    for (int i = 0; i < indent; ++i) printf("\t");
    printf("%s\n", t->string);
    gnos_tree(t->left, indent+1);
    gnos_tree(t->right, indent+1);
}

tree_t *
mk_node(char *string, tree_t *left, tree_t *right) {
    tree_t *tree = malloc(sizeof(tree_t));
    tree->string = string;
    tree->length = strlen(string);
    tree->left = left;
    tree->right = right; 
    return tree;
}

tree_t *
mk_leaf(char *string) {
    tree_t *tree = malloc(sizeof(tree_t));
    tree->string = string;
    tree->length = strlen(string);
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

tree_t *
sift(tree_t *t, char *string, int slen) {
    if (is_leaf(t)) { // is a leaf
        return t;
    } else {
        int length = t->length + slen;
        char *buffer = malloc(length + 1);
        strncpy(buffer, string, slen);
        strncpy(&buffer[slen], t->string, t->length);
        buffer[length] = '\0';
        if (oracle(buffer)) {
            free(buffer);
            return sift(t->left, string, slen);
        } else {
            free(buffer);
            return sift(t->right, string, slen);
        }
    }
}

int
main(int argc, char *argv[]) {
    tree_t *t = mk_node("aaab",
        mk_node("aab",
            mk_leaf("!"),
            mk_leaf("@")
        ),
        mk_leaf("#")
    );
    printf("%d\n", size(t));
}
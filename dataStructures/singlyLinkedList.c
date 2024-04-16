#include <stdio.h>
#include <stdlib.h>

typedef struct node node, *list;

struct node {
    void* data;
    list next;
};

void initList(list* var){
    *var = NULL;
}

int allocateNode(list* var, void* data){
    list Node = malloc(sizeof(node));

    if (Node == NULL) return 1;

    *var = Node;
    Node->data = data;
    Node->next = NULL;

    return 0;
}

void freeNode(list* var){
    free(*var);
    *var = NULL;
}


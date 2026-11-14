#ifndef DEREVO_H
#define DEREVO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

const size_t MAX_LENGTH_STR = 50;


struct TREE_NODE{
    struct TREE_NODE * left;
    struct TREE_NODE * right;
    struct TREE_NODE * parent;
    char data[MAX_LENGTH_STR];
};

void Poisk(struct TREE_NODE * derevo);

void PrintTree(struct TREE_NODE * derevo, FILE * name_file);

struct TREE_NODE * InputTree(FILE * name_file);

void yes_ (char * str);

void not_ (char * str);


#endif
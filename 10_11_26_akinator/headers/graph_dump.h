#ifndef GRAFDUMP_H
#define GRAFDUMP_H

#include "C:\Users\dolzh\OneDrive\Desktop\pr\10_11_26_akinator\headers\akinator.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DFS(FILE * file_dump, FILE * file_dump_bez, struct TREE_NODE * node, int *cnt);

void GraphDump(struct TREE_NODE * node);

#endif
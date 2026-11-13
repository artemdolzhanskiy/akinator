#ifndef GRAFDUMP_H
#define GRAFDUMP_H

#include "C:\Users\dolzh\OneDrive\Desktop\pr\10_11_26_akinator\headers\derevo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(FILE * file_dump, FILE * file_dump_bez, struct TREE_NODE * derevo, int *cnt);

void GrafDump(struct TREE_NODE * derevo);

#endif
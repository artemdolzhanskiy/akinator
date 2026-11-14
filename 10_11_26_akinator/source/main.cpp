#include <stdio.h>
#include <stdlib.h>

#include "C:\Users\dolzh\OneDrive\Desktop\pr\10_11_26_akinator\headers\graph_dump.h"

int main(){
    struct TREE_NODE * akinator_tree = (struct TREE_NODE *)calloc(1, sizeof(struct TREE_NODE));
    FILE * file_input = fopen("base.txt", "r");
    akinator_tree = InputTree(file_input);
    fclose(file_input);

    //------------------------------------------------------------------------------------


    Poisk(akinator_tree->left);


    //-------------------------------------------------------------------------------------

    
    FILE * file_print = fopen("base.txt", "w");
    PrintTree(akinator_tree->left, file_print);
    fclose(file_print);

    GraphDump(akinator_tree);

    int res = system("dot -Tpng DUMP.dot -o graph.png");

    res += 1;



    return 0;
}
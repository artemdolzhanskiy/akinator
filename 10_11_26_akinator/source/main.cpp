#include <stdio.h>
#include <stdlib.h>

#include "C:\Users\dolzh\OneDrive\Desktop\pr\10_11_26_akinator\headers\graf_dump.h"

int main(){
    struct TREE_NODE * derevo = (struct TREE_NODE *)calloc(1, sizeof(struct TREE_NODE));
    FILE * file_input = fopen("base.txt", "r");
    derevo = InputTree(file_input);
    fclose(file_input);

    //------------------------------------------------------------------------------------


    poisk(derevo->left);


    //-------------------------------------------------------------------------------------

    
    FILE * file_print = fopen("base.txt", "w");
    PrintTree(derevo->left, file_print);
    fclose(file_print);

    GrafDump(derevo);



    return 0;
}
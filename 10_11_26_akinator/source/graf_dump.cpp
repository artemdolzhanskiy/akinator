#include "../headers/graf_dump.h"

void dfs(FILE * file_dump, FILE * file_dump_bez, struct TREE_NODE * derevo){
    assert(derevo);

    char vopros_da_vlevo = ' ';
    char vopros_net_vpravo = ' ';
    if (derevo->left != NULL){
        if (derevo->left->right == NULL && derevo->left->left == NULL){
            vopros_da_vlevo = ' ';
        }

        if (derevo->left->left == NULL && derevo->left->right == NULL){
            fprintf(file_dump, "%s[shape=Mrecord, style=\"filled\", fillcolor=\"lightgreen\", label=\" {data = %s | %p | {left - %p  | right - %p} }\"]\n ",
            derevo->left->data, derevo->left->data, derevo->left, derevo->left->left, derevo->left->right);
        }
        else{
            fprintf(file_dump, "%s[shape=Mrecord, style=\"filled\", fillcolor=\"lightblue\", label=\" {data = %s | %p | {left - %p  | right - %p} }\"]\n ",
            derevo->left->data, derevo->left->data, derevo->left, derevo->left->left, derevo->left->right);
        }


        fprintf(file_dump_bez, "%s[shape=Mrecord, style=\"filled\", fillcolor=\"lightblue\"]\n ", derevo->left->data);
        fprintf(file_dump_bez, " %s->%s%c[label=\" 1\", style=\"bold\", color=\"darkgreen\"]\n", derevo->data, derevo->left->data, vopros_da_vlevo);
        

        fprintf(file_dump, " %s->%s%c[label=\" 1\", style=\"bold\", color=\"darkgreen\"]\n", derevo->data, derevo->left->data, vopros_da_vlevo);
        dfs(file_dump, file_dump_bez, derevo->left);
    }

    if (derevo->right != NULL){
        if (derevo->right->right == NULL && derevo->right->left == NULL){
            vopros_net_vpravo = ' ';
        }

        if (derevo->right->left == NULL && derevo->right->right == NULL){
            fprintf(file_dump, "%s[shape=Mrecord, style=\"filled\", fillcolor=\"lightgreen\", label=\" {data = %s | %p | {left - %p  | right - %p} }\"]\n ",
            derevo->right->data, derevo->right->data, derevo->right, derevo->right->left, derevo->right->right);
        }
        else{
            fprintf(file_dump, "%s[shape=Mrecord, style=\"filled\", fillcolor=\"lightblue\", label=\" {data = %s | %p | {left - %p  | right - %p} }\"]\n ",
            derevo->right->data, derevo->right->data, derevo->right, derevo->right->left, derevo->right->right);
        }
        
        fprintf(file_dump_bez, "%s[shape=Mrecord, style=\"filled\", fillcolor=\"lightblue\"]\n ", derevo->right->data);
        fprintf(file_dump_bez, " %s->%s%c[label=\" 0\", style=\"bold\", color=\"darkred\"]\n", derevo->data, derevo->right->data, vopros_net_vpravo);

        fprintf(file_dump, " %s->%s%c[label=\" 0\", style=\"bold\", color=\"darkred\"]\n", derevo->data, derevo->right->data, vopros_net_vpravo);
        dfs(file_dump, file_dump_bez, derevo->right);
    }
    
}


void GrafDump(struct TREE_NODE * derevo){
    assert(derevo);
    
    FILE * file_dump = fopen("DUMP.dot", "w");
    FILE * file_dump_bez = fopen("DUMP_bez.dot", "w");

    fprintf(file_dump, "digraph {\n");
    fprintf(file_dump_bez, "digraph {\n");


    fprintf(file_dump, "%s[shape=Mrecord, style=\"filled\", fillcolor=\"lightblue\", label=\" {data = %s | %p | {left - %p  | right - %p} }\"]\n ", derevo->left->data, derevo->left->data, derevo->left, derevo->left->left, derevo->left->right);
    fprintf(file_dump_bez, "%s[shape=Mrecord]\n ", derevo->left->data);

    dfs(file_dump, file_dump_bez, derevo->left);
    
    
   
    fprintf(file_dump, "}");
    fprintf(file_dump_bez, "}");
    
    fclose(file_dump);
    fclose(file_dump_bez);
}
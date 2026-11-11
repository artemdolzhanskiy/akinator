#include "../headers/graf_dump.h"

void dfs(FILE * file_dump, FILE * file_dump_bez, struct TREE_NODE * derevo){

    char vopros_da_vlevo = ' ';
    char vopros_net_vpravo = ' ';
    if (derevo->left != NULL){
        if (derevo->left->right == NULL && derevo->left->left == NULL){
            vopros_da_vlevo = ' ';
        }

        fprintf(file_dump, "%s[shape=Mrecord, label=\" {data = %s | %p | {left - %p  | right - %p} }\"]\n ",
            derevo->left->data, derevo->left->data, derevo->left, derevo->left->left, derevo->left->right);
        
        fprintf(file_dump_bez, " %s->%s%c[label=\" 1\", style=\"bold\"]\n", derevo->data, derevo->left->data, vopros_da_vlevo);
        

        fprintf(file_dump, " %s->%s%c[label=\" 1\", style=\"bold\"]\n", derevo->data, derevo->left->data, vopros_da_vlevo);
        dfs(file_dump, file_dump_bez, derevo->left);
    }

    if (derevo->right != NULL){
        if (derevo->right->right == NULL && derevo->right->left == NULL){
            vopros_net_vpravo = ' ';
        }

        fprintf(file_dump, "%s[shape=Mrecord, label=\" {data = %s | %p | {left - %p  | right - %p} }\"]\n ",
             derevo->right->data, derevo->right->data, derevo->right, derevo->right->left, derevo->right->right);
        
        fprintf(file_dump_bez, " %s->%s%c[label=\" 0\", style=\"bold\"]\n", derevo->data, derevo->right->data, vopros_net_vpravo);

        fprintf(file_dump, " %s->%s%c[label=\" 0\", style=\"bold\"]\n", derevo->data, derevo->right->data, vopros_net_vpravo);
        dfs(file_dump, file_dump_bez, derevo->right);
    }
    
}


void GrafDump(struct TREE_NODE * derevo){
    FILE * file_dump = fopen("DUMP.dot", "w");
    FILE * file_dump_bez = fopen("DUMP_bez.dot", "w");

    fprintf(file_dump, "digraph {\n");
    fprintf(file_dump_bez, "digraph {\n");


    fprintf(file_dump, "%s[shape=Mrecord, label=\" {data = %s | %p | {left - %p  | right - %p} }\"]\n ", derevo->left->data, derevo->left->data, derevo->left, derevo->left->left, derevo->left->right);
    
    dfs(file_dump, file_dump_bez, derevo->left);
    
    //fprintf(file_dump, " %d [shape=record, label=\" {num = %d | data = %d | {next = %d  | prev %d} }\", fillcolor = \"%s\" ]\n");

    
    

    //fprintf(file_dump, " %d->%d[style=\"bold\"]\n", data[pos], data[next[pos]]);
   
    fprintf(file_dump, "}");
    fprintf(file_dump_bez, "}");
    
    fclose(file_dump);
    fclose(file_dump_bez);
}
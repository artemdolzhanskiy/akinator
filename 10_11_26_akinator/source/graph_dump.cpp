#include "../headers/graph_dump.h"

void DFS(FILE * file_dump, FILE * file_dump_bez, struct TREE_NODE * node, int * cnt){
    assert(node);

    if (node->left != NULL){

        if (node->left->left == NULL && node->left->right == NULL){
            *cnt += 1;
            fprintf(file_dump, "%s[shape=Mrecord, style=\"filled\", fillcolor=\"lightgreen\", label=\" {data = %s | %p | {left - %p  | right - %p} }\"]\n ",
            node->left->data, node->left->data, node->left, node->left->left, node->left->right);
        }
        else{
            fprintf(file_dump, "%s[shape=Mrecord, style=\"filled\", fillcolor=\"lightblue\", label=\" {data = %s | %p | {left - %p  | right - %p} }\"]\n ",
            node->left->data, node->left->data, node->left, node->left->left, node->left->right);
        }

        fprintf(file_dump_bez, "%s[shape=Mrecord, style=\"filled\", fillcolor=\"lightblue\"]\n ", node->left->data);
        fprintf(file_dump_bez, " %s->%s[label=\" 1\", style=\"bold\", color=\"darkgreen\"]\n", node->data, node->left->data);
        

        fprintf(file_dump, " %s->%s[label=\" yes\", style=\"bold\", color=\"darkgreen\"]\n", node->data, node->left->data);
        DFS(file_dump, file_dump_bez, node->left, cnt);
    }

    if (node->right != NULL){

        if (node->right->left == NULL && node->right->right == NULL){
            *cnt += 1;
            fprintf(file_dump, "%s[shape=Mrecord, style=\"filled\", fillcolor=\"lightgreen\", label=\" {data = %s | %p | {left - %p  | right - %p} }\"]\n ",
            node->right->data, node->right->data, node->right, node->right->left, node->right->right);
        }
        else{
            fprintf(file_dump, "%s[shape=Mrecord, style=\"filled\", fillcolor=\"lightblue\", label=\" {data = %s | %p | {left - %p  | right - %p} }\"]\n ",
            node->right->data, node->right->data, node->right, node->right->left, node->right->right);
        }
        
        fprintf(file_dump_bez, "%s[shape=Mrecord, style=\"filled\", fillcolor=\"lightblue\"]\n ", node->right->data);
        fprintf(file_dump_bez, " %s->%s[label=\" 0\", style=\"bold\", color=\"darkred\"]\n", node->data, node->right->data);

        fprintf(file_dump, " %s->%s[label=\" no\", style=\"bold\", color=\"darkred\"]\n", node->data, node->right->data);
        DFS(file_dump, file_dump_bez, node->right, cnt);
    }
    
}


void GraphDump(struct TREE_NODE * node){
    assert(node);

    int cnt = 0;
    
    FILE * file_dump = fopen("DUMP.dot", "w");
    FILE * file_dump_bez = fopen("DUMP_bez.dot", "w");

    fprintf(file_dump, "digraph {\n");
    fprintf(file_dump_bez, "digraph {\n");


    fprintf(file_dump, "%s[shape=Mrecord, style=\"filled\", fillcolor=\"lightblue\", label=\" {data = %s | %p | {left - %p  | right - %p} }\"]\n ", node->left->data, node->left->data, node->left, node->left->left, node->left->right);
    fprintf(file_dump_bez, "%s[shape=Mrecord]\n ", node->left->data);

    DFS(file_dump, file_dump_bez, node->left, &cnt);

    fprintf(file_dump, "%d[shape=Mrecord, style=\"filled\", fillcolor=\"lightgreen\"]\n ", cnt);
    
    
   
    fprintf(file_dump, "}");
    fprintf(file_dump_bez, "}");
    
    fclose(file_dump);
    fclose(file_dump_bez);
}
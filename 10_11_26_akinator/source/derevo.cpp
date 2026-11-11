#include "../headers/derevo.h"

void AddTreeNode(struct TREE_NODE * derevo, const char * value){
    assert(derevo);

    if (!strncmp(derevo->data,"", MAX_LENGTH_STR)){
        //printf("ok");
        strcpy(derevo->data, value);
        return;
    }

    if (true){
        if (derevo->right == NULL){
            derevo->right = (struct TREE_NODE *)calloc(1, sizeof(struct TREE_NODE));
            derevo->right->parent = derevo;

            strcpy(derevo->right->data, value);
            
        }
        else{
            AddTreeNode(derevo->right, value);
        }
    }

    if (  true    ){
        if (derevo->left == NULL){
            derevo->left = (struct TREE_NODE *)calloc(1, sizeof(struct TREE_NODE));
            derevo->left->parent = derevo;

            strcpy(derevo->left->data, value);
        }
        else{
            AddTreeNode(derevo->left, value);
        }
    }

}

void PrintTree(struct TREE_NODE * derevo, FILE * name_file){
    fprintf(name_file, "(");

    fprintf(name_file, "%s", derevo->data);

    if (derevo->left != NULL){
        //printf("l");
        PrintTree(derevo->left, name_file);
    }
    else if (derevo->left == NULL && derevo->right != NULL){
        fprintf(name_file, "()");
    }

    if (derevo->right != NULL){
        //printf("r");
        PrintTree(derevo->right, name_file);
    }
    else if (derevo->right == NULL && derevo->left != NULL){
        fprintf(name_file, "()");
    }

    fprintf(name_file, ")");
}

struct TREE_NODE * InputTree(FILE * name_file){
    struct TREE_NODE * derevo = (struct TREE_NODE *)calloc(1, sizeof(struct TREE_NODE));
    //printf("ok\n");
    
    struct TREE_NODE * pos = derevo;
    //strcpy(pos->data, "start");

    char c = char(fgetc(name_file));

    char res[MAX_LENGTH_STR] = {};
    int res_ind = 0;
    while (c != EOF){
        //printf("%c", c);
        if (c == '('){
            if( !strncmp(pos->data,"", MAX_LENGTH_STR)){
                strcpy(pos->data, res);
            }
            //printf("%s\n", res);
            strncpy(res, "", MAX_LENGTH_STR);
            res_ind = 0;
            if (pos->left == NULL){
                pos->left = (struct TREE_NODE *)calloc(1, sizeof(struct TREE_NODE));
                pos->left->parent = pos;

                pos = pos->left;
            }
            else if (pos->right == NULL){
                pos->right = (struct TREE_NODE *)calloc(1, sizeof(struct TREE_NODE));
                pos->right->parent = pos;

                pos = pos->right;
            }
        }
        else if (c == ')'){
            //printf("ok\n");
            if (!strncmp(pos->data,"", MAX_LENGTH_STR)){
                strcpy(pos->data, res);
            }
            strncpy(res, "", MAX_LENGTH_STR);
            res_ind = 0;
            if (!strncmp(pos->data,"", MAX_LENGTH_STR)){
                c = char(fgetc(name_file));
                break;
            }
            pos = pos->parent;
        }
        else{
            res[res_ind] = c;
            res_ind += 1;
            //printf("%s\n", res);
        }

        c = char(fgetc(name_file));

    }

    return derevo;
}
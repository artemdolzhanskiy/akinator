#include "../headers/derevo.h"


void poisk(struct TREE_NODE * derevo){
    printf("Hi! Think of a character from the game Clash Royale, and I will try to guess who it is.\n");
    printf("I will ask some questions, and you should respond with 1 for yes or 2 for no.\n");


    char c = 0;
    while (derevo->left != NULL && derevo->right != NULL){
        printf("%s ? ", derevo->data);
        
        scanf(" %c", &c);
        if (c == '0'){
            derevo = derevo->right;
        }
        if (c == '1'){
            derevo = derevo->left;
        }
    }


    printf("%s ?", derevo->data);

    scanf(" %c", &c);
    if (c == '1'){
        printf("ok, bye");
        return;
    }

    if (c == '0'){
        printf("And what is the answer then? ");
        char ans[MAX_LENGTH_STR] = "";
        scanf(" %s", ans);
        printf("What is the difference between a %s and a %s? ", derevo->data, ans);
        char pr[MAX_LENGTH_STR] = "";
        scanf(" %s", pr);
        printf("got it\n");
        
        derevo->left = (struct TREE_NODE *)calloc(1, sizeof(struct TREE_NODE));
        strncpy(derevo->left->data, ans, MAX_LENGTH_STR);
        derevo->left->parent = derevo;

        derevo->right = (struct TREE_NODE *)calloc(1, sizeof(struct TREE_NODE));
        strncpy(derevo->right->data, derevo->data, MAX_LENGTH_STR);
        derevo->right->parent = derevo;

        derevo->data[0] = '\0';
        strncpy(derevo->data, pr, 50);

        //printf("%s\n", derevo->data);
        //printf("%s\n", derevo->left->data);
        //printf("%s\n", derevo->right->data);
    }
}

void AddTreeNode(struct TREE_NODE * derevo, const char * value){
    assert(derevo);
    assert(value);
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
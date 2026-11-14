#include "../headers/akinator.h"


void Poisk(struct TREE_NODE * node){
    printf("Hi! Think of a character from the game Clash Royale, and I will try to guess who it is.\n");
    printf("I will ask some questions, and you should respond with 1 for yes or 0 for no.\n");


    char c = 0;
    while (node->left != NULL && node->right != NULL){
        not_(node->data);
        printf("%s ? ", node->data);
        yes_(node->data);
        
        scanf(" %c", &c);
        if (c == '0'){
            node = node->right;
        }
        if (c == '1'){
            node = node->left;
        }
    }

    not_(node->data);
    printf("%s ? ", node->data);
    yes_(node->data);

    scanf(" %c", &c);
    if (c == '1'){
        printf("ok, bye");
        return;
    }

    if (c == '0'){
        printf("And what is the answer then? ");

        char ans[MAX_LENGTH_STR] = "";
        scanf(" ");
        fgets(ans, MAX_LENGTH_STR, stdin);
        ans[strcspn(ans, "\n")] = '\0';
        printf("What is the difference between a %s and a %s? ", node->data, ans);
        yes_(ans);


        char pr[MAX_LENGTH_STR] = "";
        scanf(" ");
        fgets(pr, MAX_LENGTH_STR, stdin);
        pr[strcspn(pr, "\n")] = '\0';
        yes_(pr);

        printf("got it\n");
        
        node->left = (struct TREE_NODE *)calloc(1, sizeof(struct TREE_NODE));
        strncpy(node->left->data, ans, MAX_LENGTH_STR);
        node->left->parent = node;

        node->right = (struct TREE_NODE *)calloc(1, sizeof(struct TREE_NODE));
        strncpy(node->right->data, node->data, MAX_LENGTH_STR);
        node->right->parent = node;

        node->data[0] = '\0';
        strncpy(node->data, pr, 50);
    }
}


void PrintTree(struct TREE_NODE * node, FILE * name_file){
    fprintf(name_file, "(");

    fprintf(name_file, "%s", node->data);

    if (node->left != NULL){
        //printf("l");
        PrintTree(node->left, name_file);
    }
    else if (node->left == NULL && node->right != NULL){
        fprintf(name_file, "()");
    }

    if (node->right != NULL){
        //printf("r");
        PrintTree(node->right, name_file);
    }
    else if (node->right == NULL && node->left != NULL){
        fprintf(name_file, "()");
    }

    fprintf(name_file, ")");
}

struct TREE_NODE * InputTree(FILE * name_file){
    struct TREE_NODE * node = (struct TREE_NODE *)calloc(1, sizeof(struct TREE_NODE));
    
    struct TREE_NODE * pos = node;

    char c = char(fgetc(name_file));

    char res[MAX_LENGTH_STR] = {};
    int res_ind = 0;
    while (c != EOF){
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

    return node;
}

void not_ (char * str){
    int i = 0;
    while(str[i] != '\0'){
        if (str[i] == '_')
            str[i] = ' ';
        i += 1;
    }
}

void yes_ (char * str){
    int i = 0;
    while(str[i] != '\0'){
        if (str[i] == ' ')
            str[i] = '_';
        i += 1;
    }
}
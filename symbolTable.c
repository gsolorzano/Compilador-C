#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct symbolT
{
    char name[200];
    int type;
    struct symbolT* next;
};

struct symbolT* nuevoNodo(int type, char name[200])
{
    struct symbolT* symbolT = (struct symbolT*) malloc(sizeof(struct symbolT));
    strcpy(symbolT->name, name);
    symbolT->type = type;
    symbolT->next = NULL;
    return symbolT;
}

int isVacio(struct symbolT *root)
{
    return !root;
}

void insert(struct symbolT** root, int type, char name[200])
{
    struct symbolT* symbolT = nuevoNodo(type, name);
    symbolT->next = *root;
    *root = symbolT;
    printf("%s agregado a la tabla de simbolos\n", name);
}

// int pop(struct symbolT** root)
// {
//     if (isVacio(*root))
//         return INT_MIN;
//     struct symbolT* temp = *root;
//     *root = (*root)->next;
//     int popped = temp->name;
//     free(temp);
//
//     return popped;
// }
//
// int peek(struct symbolT* root)
// {
//     if (isVacio(root))
//         return INT_MIN;
//     return root->name;
// }

int lookup(struct symbolT* root, char name[200])
{
    if(isVacio(root)){
        return 2;
    }
    else{
        struct symbolT* temp = root;
        while(1){
            if(temp == NULL){
                return 2;
            }
            if(!(strcmp(temp->name,name))){
                printf("Error semántico, %s ya ha sido declarado antes.\n", name);
                exit(1);
            }
            temp = temp->next;
        }
    }
}

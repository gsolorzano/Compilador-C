#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct tableRegister
{
    struct symbolT* symbolT;
    struct tableRegister* next;
};

struct tableRegister* newSymbol(struct symbolT* symbol)
{
    struct tableRegister* tableRegister =
              (struct tableRegister*) malloc(sizeof(struct tableRegister));
    tableRegister->symbolT = symbol;
    tableRegister->next = NULL;
    return tableRegister;
}

int isEmptySymbol(struct tableRegister *root)
{
    return !root;
}

void pushSymbol(struct tableRegister** root, struct symbolT* symbol)
{
    struct tableRegister* tableRegister = newSymbol(symbol);
    tableRegister->next = *root;
    *root = tableRegister;
    // printf("Context: pushed to Symbol Stack\n");
}

struct tableRegister* popSymbol(struct tableRegister** root)
{
    if (isEmptySymbol(*root))
        return NULL;
    struct tableRegister* temp = *root;
    *root = (*root)->next;
    // printf("Context: popped\n");
    free(temp);
    return *root;
}

struct symbolT* topSymbol(struct tableRegister** root)
{
    if (isEmptySymbol(*root))
        return NULL;
    return (*root)->symbolT;
}

struct symbolT* lastSymbol(struct tableRegister* root)
{
    if(isEmptySymbol(root)){
        return NULL;
    }
    else{
        struct tableRegister* temp = root;
        while(1){
            if(temp == NULL){
                return NULL;
            }
            if(temp->next == NULL){
                return temp->symbolT;
            }
            temp = temp->next;
        }
    }
}

// void clearStack(struct tableRegister* root){
//     if (isEmpty(root))
//         return;
//     while(root != NULL){
//         struct tableRegister* temp = root;
//         root = root->next;
//         free(temp);
//     }
//     return;
// }

// void printStack(struct tableRegister* root){
//     if(isEmpty(root)){
//         printf("%s\n","Empty");
//     }
//     else{
//         struct tableRegister* temp = root;
//         while(1){
//             if(temp == NULL){
//                 return;
//             }
//             printf("\nElemento:\t name: %s", temp->name);
//             printf("\t type: %d\n", temp->type);
//             temp = temp->next;
//         }
//     }
// }

// struct tableRegister* retrieve(struct tableRegister* root, int type)
// {
//     if(isEmpty(root)){
//         return NULL;
//     }
//     else{
//         struct tableRegister* temp = root;
//         while(1){
//             if(temp == NULL){
//                 return NULL;
//             }
//             if(temp->type == type){
//                 return temp;
//             }
//             temp = temp->next;
//         }
//     }
// }

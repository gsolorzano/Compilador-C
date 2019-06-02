#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct semantic_record
{
    char name[200];
    int type;
    char eti[3][200];
    struct semantic_record* next;
};

struct semantic_record* newNode(int type, char name[200], char eti[3][200])
{
    struct semantic_record* semantic_record =
              (struct semantic_record*) malloc(sizeof(struct semantic_record));
    strcpy(semantic_record->name, name);
    semantic_record->type = type;
    semantic_record->next = NULL;
    if(eti != NULL){
        for(int i=0;i<3;i++)
            strcpy(semantic_record->eti[i], eti[i]);
    }
    else{
        for(int i=0;i<3;i++)
            strcpy(semantic_record->eti[i], "");
    }
    return semantic_record;
}

int isEmpty(struct semantic_record *root)
{
    return !root;
}

void push(struct semantic_record** root, int type,char name[200], char eti[3][200])
{
    struct semantic_record* semantic_record = newNode(type, name, eti);
    semantic_record->next = *root;
    *root = semantic_record;
    // printf("\t \t pushed to stack: %s , type: %i \n", name, type);
}

struct semantic_record* pop(struct semantic_record** root)
{
    if (isEmpty(*root))
        return NULL;
    struct semantic_record* temp = *root;
    *root = (*root)->next;
    // printf("\t \t popped: %s \n", temp->name);
    free(temp);
    return *root;
}
struct semantic_record* pop2(struct semantic_record** root)
{
    if (isEmpty(*root))
        return NULL;
    struct semantic_record* temp = *root;
    *root = (*root)->next;
    // printf("\t \t popped: %s \n", temp->name);
    //free(temp);
    return *root;
}

struct semantic_record* top(struct semantic_record* root)
{
    if (isEmpty(root))
        return NULL;
    return root;
}

struct semantic_record* clearStack(struct semantic_record* root){
    if (isEmpty(root))
        return NULL;
    struct semantic_record* temp = NULL;
    while(root != NULL){
        if(root->type == 5){
            temp = root;
            root = root->next;
        }
        else{
            root = pop(&root);
        }
    }
    if(temp == NULL){
        return root;
    }
    return temp;
}

void printStack(struct semantic_record* root){
    if(isEmpty(root)){
        printf("%s\n","Empty");
    }
    else{
        struct semantic_record* temp = root;
        while(1){
            if(temp == NULL){
                return;
            }
            printf("\nElemento:\t name: %s", temp->name);
            printf("\t type: %d\n", temp->type);
            temp = temp->next;
        }
    }
}

struct semantic_record* retrieve(struct semantic_record* root, int type)
{
    if(isEmpty(root)){
        return NULL;
    }
    else{
        struct semantic_record* temp = root;
        while(1){
            if(temp == NULL){
                return NULL;
            }
            if(temp->type == type){
                return temp;
            }
            temp = temp->next;
        }
    }
}

struct semantic_record* retrieveDelete(struct semantic_record* root, int type)
{
    if(isEmpty(root)){
        return NULL;
    }
    else{
        struct semantic_record* temp = root;
        struct semantic_record* temp2 = root;
        while(1){
            if(temp == NULL){
                return NULL;
            }
            if(temp->type == type){
                temp2->next = temp->next;
                return temp;
            }
            temp2 = temp;
            temp = temp->next;
        }
    }
}

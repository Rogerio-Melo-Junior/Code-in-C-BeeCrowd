#include <stdio.h>
#include <stdlib.h>

struct item{
   int cod; 
};
int vetor[1000];
typedef struct item Item;

struct node{
    Item item;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node *treeInicialize(){
    return NULL;
}

Item itemCreate(int cod){
    Item item;
    item.cod = cod;
    return item;
}

Node *treeInsert(Node *root, Item x){
    if(root == NULL){
        Node *aux = (Node*)malloc(sizeof(Node));
        aux->item = x;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    }
    else{
        if(x.cod > root->item.cod){
            root->right = treeInsert(root->right,x);
        }
        else if(x.cod < root->item.cod){
            root->left = treeInsert(root->left,x);
        }
    }
    return root;
}

void treePrint(Node *root){
    if(root!=NULL){
        printf("%d ",root->item.cod);
        treePrint(root->left);
        treePrint(root->right);
    }
}

void treeFree(Node *root){
    if(root!=NULL){
        treeFree(root->left);
        treeFree(root->right);
        free(root);
    }
}
int main(){
    Node *root = treeInicialize();
    root = treeInsert(root, itemCreate(10));
    root = treeInsert(root, itemCreate(0));
    root = treeInsert(root, itemCreate(15));
    root = treeInsert(root, itemCreate(1));
    root = treeInsert(root, itemCreate(16));
    root = treeInsert(root, itemCreate(6));
    treePrint(root);
    treeFree(root);
    return 0;
}
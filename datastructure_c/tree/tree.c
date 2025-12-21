#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Tree struct 
typedef struct tree_node{
    int data;
    struct tree_node *l_child;
    struct tree_node *r_child;
}node_t;


//Tree Functions Definition 
int add(int data);
int traverse();
int remove(int data);
int find(int data);

//Global pointer variable to the root 
node_t *__root = NULL;

//Function Declarations 
int add(int data){
    node_t *new_child = (node_t*)malloc(sizeof(node_t));  // take void pointer from the malloc, typecast it as node_t pointer 
    //add given data to the new child 
    new_child -> data = data ;
    //placing the newly created node 
    //Check if the root node is present 
    if (__root == NULL){
        //if root is not preset/tree not present, then initialize root and set it child pointers to NULL, as intially no value was there for the child
        __root = new_child;
        new_child -> l_child = NULL;
        new_child -> r_child = NULL;
    }

    //if the root is there then we need to see where the nodes must be fixed ?
    

    return 0;
}
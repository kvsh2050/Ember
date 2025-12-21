#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "queue4tree.h"


//Tree struct 
typedef struct tree_node{
    int data;
    struct tree_node *l_child;
    struct tree_node *r_child;
}node_t;


//Tree Functions Definition 
int add(int data);
int traverse();
int delete_node(int data);
int find(int data);

//Main to test 
int main(){
    add(0);
    add(1);
    add(2);


    return 0;
}



//Global pointer variable to the root 
static node_t *__root = NULL;

//Function Declarations 
int add(int data){
    int flag;
    printf("data adding : %d\n", data);
    node_t *new_child = (node_t*)malloc(sizeof(node_t));  // take void pointer from the malloc, typecast it as node_t pointer 
    //add given data to the new child and set the l,r childs to NULL for now
    new_child -> data = data ;
    new_child -> l_child = NULL;
    new_child -> r_child = NULL;
    //placing the newly created node 
    //Check if the root node is present 
    if (__root == NULL){
        //if root is not preset/tree not present, then initialize root and set it child pointers to NULL, as intially no value was there for the child
        printf("The root is NULL\n");
        __root = new_child;
        new_child -> l_child = NULL;
        new_child -> r_child = NULL;
    } else {
        printf("The root node/tree is present, now enqueue root\n");
        enqueue(__root);
    }

    //if the root is there then we need to see where the nodes must be fixed ?
    //CHECKING BEGINS 
    while(queue_not_empty()){               //can use do-while for this 
        node_t *node_inspect = (node_t *)dequeue();  // void pointer from dequeue is typecasted to node_t pointer
            printf("Inside while the pointer is %p \n", node_inspect);

        //address
        //printf("node inspect: %p\n", node_inspect);
        //printf("%p\n", __root);
        //printf("%p\n", node_inspect ->l_child);
        //printf("%p\n", new_child);

        printf("checking conditions in  l_child  \n");
        if(node_inspect -> l_child == NULL){
            //add the new node created here and destroy queue 
            printf("checking conditions in  l_child : Lchild is NULL \n");
            node_inspect -> l_child = new_child;
            printf("free queue \n");
            flag = destroy_queue();
            if(!flag){
                printf("Success, freeing..!, Exiting..\n");
            }
            return 1;
        }else{
            //else enqueue the child node we need to check after this one's right child 
            printf("checking conditions in  l_child : Lchild is having pointer val \n");
            enqueue(node_inspect -> l_child);
        }
        printf("checking conditions in  r_child  \n");
        if(node_inspect -> r_child == NULL){
            //add the new node created here and destroy queue 
            node_inspect -> r_child = new_child;
            printf("added %d in r child  /n", data);
            flag = destroy_queue();
            if(!flag){
                printf("Success..freeing! Exiting..\n");
            }
            return 1;
        }else{
            printf("r_child of this is also full   \n");
            //else enqueue 
            enqueue(node_inspect -> r_child);
        }
    }
    //add done then return 0 
    return 0;
}

//Next steps : need to find if the queue is adding and deleting in correct way , traverse queue
// we traverse the node 
//we add the node of tree
//we delete the node of tree
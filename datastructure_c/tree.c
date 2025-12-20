/*
TREE
tree is a type of graph 
1. has root node: starting node -> is a child to none, but has children 
2. leaf node: has parent and no children 
3. siblings share same parent 
4. has levels : generations
5. height of tree is level number 
6. connection is edge 

usually link is maintained in 1 direction from parent --> child , in some we also maintain a link from the child to parent 
depending on children has many next_node ptr

BINARY TREE
parent has atmost 2 children/ 2 children only

operations on binary tree:
1. add() : add node
2. remove() : remove node 
3. find(): node
4. traverse(); node 

if we need to add node 
1. adding root node 
2. check left node == nULL(we dont have direct access to the nodes except the __root pointer / root node)
so we need to traverse the tree and add the node (based on the designer of data structure)
3. check right null, traverse to root and check the right node of root has null 
4. else, check the 2nd generation, check left then right 
-> we need to keep level, direction of algo 
*/

#include<stdio.h>
#include<stdlib.h>

//Tree Node Struct 
typedef struct node_tree{
    int data;
    //pointer 
    struct node_tree *left_child;
    struct node_tree *right_child; 
}node_t;

//If node is there then points else points to NULL 
//Static for making things private 
static node_t *__root = NULL;

int main(){



    return 0;
}

void add(int data){
    node_t* new_node;


    //if root ==NULL , the __root points to the node else does not point 
    if (!__root){
        __root = new_node;
        return;
    }else if(__root -> left_child == NULL){
        __root -> left_child = new_node;
        //if not add it to end of queue
        //after checking condition delete from end of the queue
    }else if (__root -> right_child == NULL){
        __root -> right_child = new_node;
    }

}

/*
EXPLORATION PATH IN TREE
al, ar, bl, br, cl, (cr)->add here  (like queue)
B, C, 

1. got to left of the root path al, check if that element has null on either side , if so add if not then add B node path bl, br to exploration path 
2. go to the right node check if null, else add to exploration path 
3. both left and right are not null thus we need take bl, br path first and so on 
NOTE: We only explore one node at a time 
NODE-BY-NODE Exploration 
nodes added and consumed in a fashion of a queue!!!
stacks and queues are helpful in graphs for traversing & bookkeeping
*/
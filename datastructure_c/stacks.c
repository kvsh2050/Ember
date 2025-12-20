#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

//Stack declration 
typedef struct node{
        int data;
        struct node *next_node;    
}node_s;

//function definition
int init(int data);
int push(int data);
int pop(void);
int peek(void);
int traverse(void);
//global 
node_s *__top = NULL;

int main(){
    init(0);
    //Stacks
    printf("PUSH...\n");
    for (int i = 1; i < 7; i ++){
        push(i);
    }
    traverse();
    printf("POP...\n");
    int popy;
    for (int j = 0; j < 3; j++){
        popy = pop();
        printf("popped value is : %d\n", popy);

        traverse();
    }

    printf("PEEK...\n");
    int d = peek();
    if(d == -1){
        printf("No stack, top is empty..\n");
    }
    else {
        printf("peeked value is : %d\n", d);
    }
    traverse();

    return 0;
}
int init(int data){
    if (__top){
        return -1;
    }
    node_s *new_node = malloc(sizeof(node_s));
    if(!new_node){
        printf("Dynamic Memory allocation failed..!\n");
    }
    //node pointers
    new_node -> data = data;
    new_node -> next_node = NULL;
    __top = new_node;
    return 0;
}

int push(int data){
    node_s *new_node = malloc(sizeof(node_s));
    if(!new_node){
        printf("Dynamic Memory allocation failed..!\n");
    }
    //node pointers
    new_node -> data = data;
    new_node -> next_node = __top;

    // point the top 
    __top = new_node;
    return 0;
}

int pop(void){
    if(__top == NULL){
        printf("Cannot be poped even more..!\n");
        return -1;
    }
    node_s *temp;
    int poppy = 0;
    temp = __top;
    poppy = __top -> data;
    //printf("%p for temp, %p for __top, %d for top data, %d poppy\n", temp, __top, __top -> data, poppy);
    __top = __top -> next_node;
    //printf("%p for temp, %p for __top\n", temp, __top);
    free(temp);
    return poppy;
}

int peek(void){
    int peeking;
    // peek at the top 
    if(!__top){
        return -1;
    }
    peeking = __top -> data;
    return peeking;
}

//traverse
int traverse(void){
    //printf("head : %p, tail : %p\n",__head, __tail );
    if (!__top){
        printf("Cannot be traversed..\n");
        return -1;
    }
    node_s *index = __top;
    for(index = __top; index != NULL; index = index -> next_node){
        //printf("head : %p, tail : %p, index points to : %p \n",__head, __tail, index );
        //printf("next_data %p\n",index -> next_node );
        printf("%d\t", index -> data);
    }
    printf("\n");
    return 0; 
}

/*
STACKS 
: LIFO

1. push()
2. pop() : delete the data on top of stack 
3. peek()
4. traverse
5. find(value insode stack)

say 1-> 2->3->4 (4 is last)
then pop 4->3->2->1
Organization of stacks of plates 
-> can be represented as a linked list or other basic data structure like array / struct 
-> note linked list itself is a ADT made up of pointers and stack and dynamic allocation 


note:
we have top or head point to top element : we push before head 

stack :POINTERS:
1. top pointer 
2. last data is pointing to NULL 

*/

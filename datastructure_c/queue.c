#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//node
typedef struct node{
        int data;
        struct node *next_node;    
}node_s;

//declaration 
int init(int data);
int add (int data);
int fetch();
int delete();
int find();

//head tracks the start 
static node_s *__head =NULL;

//linked list is better in queue in a way that the memory allocation is dynamic 

int main(){
    
    //queue can be done using linked lists too, also arrays and stacks 

    return 0;
}

//improving runtime : add end tracker too __tail
// when fetched the memory must be cleared the first element is always fetched not in between and loops 
//you can only add the element at the last 
//search can also be done 


    // Queue can be anything struct arrays or any representation 
    // We can add new node/element at the end FIFO
    //First Come First Serve basis data 
    // we have 2 things : get_data(), add_data()
    // Queue can be thouh like a linked list 
    // ticket online : waiting in queue 
    // chat window , FCFS
    // scheduling queue in embedded systems : while interrupt fills up the job and these jobs fetched by the cpu 
    //API 
    /*
    add();
    fetch();
    delete();
    find();
    */
    
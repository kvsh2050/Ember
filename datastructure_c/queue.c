
//improving runtime : add end tracker too __tail
// when fetched the memory must be cleared the first element is always fetched not in between and loops 
//you can only add the element at the last 
//search can also be done 
/*
1. enqueue 
2. dequeue
*/

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
//queue can be done using linked lists too, also arrays and stacks 

//QUEUE IMPLEMENTATION USING LINKED LISTS

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
int enqueue (int data);
int dequeue();
int search();
int traverse();

//head tracks the start 
static node_s *__head =NULL;
static node_s *__tail =NULL;

//linked list is better in queue in a way that the memory allocation is dynamic 

int main(){
    //Start a queue
    printf("Initializing queue..!\n");
    init(0);
    traverse();

    printf("ENQUEUE\n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);

    printf("TRAVERSE\n");
    traverse();

    printf("DEQUEUE\n");
    int d = dequeue();
    printf("dequeud: %d\n", d);
    d = dequeue();
    printf("dequeud: %d\n", d);     
    d = dequeue();
    printf("dequeud: %d\n", d);
    //printf("DEBUG: head :%p, head val: %d\n", __head, __head->data);
    printf("SEARCH\n");
    int flag = search(5);
    if(flag){
        printf("Element found\n");
    }
    else{
        printf("Element not in queue\n");
    }
    return 0;
}

//init
int init (int data){
    node_s *new_node = malloc(sizeof(node_s));
    if(!new_node){
        printf("Dynamic Memory allocation failed..!\n");
    }
    //node pointers
    new_node -> data = data;
    new_node -> next_node = NULL;
    //Tracking pointers are set 
    __head = new_node;
    __tail = __head;
}

//enqueue
int enqueue(int data){
    //Al/ data added at end 
    node_s *new_node = malloc(sizeof(node_s));
    if(!new_node){
        printf("Dynamic Memory allocation failed..!\n");
    }
    //node pointers
    new_node -> data = data;
    new_node -> next_node = NULL;
    
    //printf("head : %p, tail : %p\n",__head, __tail );
    // now we set the pointers 
    __tail -> next_node = new_node;
    __tail  = new_node;
    //printf("head : %p, tail : %p, new_node: %p\n",__head, __tail , new_node);

    return 0;
}

//dequeue
int dequeue(){
    int data;
    // dequeue 
    node_s *track;
    track = __head;
    __head = __head -> next_node;

    //get data from track 
    data = track ->data ;
    free(track);
    return data;
}

//search 
int search(int data){
    node_s *index;
    for(index = __head; index != NULL; index = index -> next_node){
        //printf("%d\t", index -> data);
        if(index -> data == data){
            return 1;
        }
    }
    return 0;
}
//traverse
int traverse(){
    //printf("head : %p, tail : %p\n",__head, __tail );
    node_s *index = __head;
    for(index = __head; index != NULL; index = index -> next_node){
        //printf("head : %p, tail : %p, index points to : %p \n",__head, __tail, index );
        //printf("next_data %p\n",index -> next_node );
        printf("%d\t", index -> data);
    }
    printf("\n");
    return 0; 
}
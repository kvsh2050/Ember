#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//STRUCT NODE 
typedef struct node{
        int word;
        struct node *next_node;   
}node_s;
    
//GLOBAL    
static node_s *__head = NULL;

//FUNCTION DEFINITIONS
int init(int data);
int add (int data);
int traverse(void);
int add_end(int data);
int exists(int data);
int deletel(int data);
int insert (int key, int data);
int insert_nex(int key , int data);


//MAIN 
int test(){
    //INITIALIZE
    init(0);
    //TESTING 
    printf("-----------------ADD----------------\n");
    for (int i = 1; i < 10; i++){
        add_end(i);  
    }
    traverse();

    printf("---------------TRAVERSE---------------\n");
    traverse();

    printf("---------------SEARCH---------------\n");
    if(exists(9)){
        printf("Found Sucessfully in this linked list..!\n");
    }else{
        printf("There is no data like that..!\n");
    }

    printf("---------------DELETE---------------\n");
    if(deletel(9)){
        printf("Deleted Sucessfully..!\n");
    }else{
        printf("There is no data like that to be deleted..!\n");
    }
    traverse();

    printf("---------------INSERT---------------\n");
    if(insert(4, 5)){
        printf("Inserted Sucessfully..!\n");
    }
    traverse();

    printf("---------------INSERT_COUNT---------------\n");
    if(insert_nex(10, 5)){
        printf("Inserted at Node Sucessfully..!\n");
    }
    traverse();

    return 0;
}


//INIT
int init(int data){
    if (__head){
        printf("Already Initialized..!\n");
        return -1;
    }
    __head = malloc(sizeof(node_s));   
    if(__head == NULL || !__head){
        printf("Memory allocation failed!");
        return -1;
    }
    __head -> next_node = NULL;
    __head->word = data; 
    //print
    printf("size of head: %lu\n", sizeof(__head) );
    printf("size of node struct: %lu\n", sizeof(node_s) );
    printf("address of head: %p\n", __head);
    return 0;
}


//ADDING AT FRONT 
int add(int data){
    node_s *n;
    n = malloc(sizeof(node_s));
    if(!n){   //if n = NULL, this condition become true
        printf("Memory Allocation failed...!\n");
        return -1;
    }
    n->word= data;
    n -> next_node = __head;
    __head = n;  

    return 0;
}

//TRAVERSE
int traverse(void){
    for (node_s *cursor = __head ; cursor != NULL ; cursor = cursor -> next_node){
        printf("%d\t", cursor ->word);
    } 
    printf("\n");
}

//ADD AT END 
int add_end(int data){
    node_s *n;
    n = malloc(sizeof(node_s));
    if(!n){   
        printf("Memory Allocation failed...!\n");
        return -1;
    }
    n -> word = data;
    n -> next_node = NULL;

    //loop for adding at last
    node_s *loop;
    for(loop = __head; loop -> next_node != NULL; loop = loop ->next_node){
        //Do nothing
    }
    //put new node after the loop
    loop -> next_node = n;

    return 0;
}

//EXISTS/SEARCHING
int exists(int data){
    //loop for traversing the linked list 
    for (node_s *cursor = __head ; cursor != NULL ; cursor = cursor -> next_node){
       if (cursor -> word == data){
            return 1;
       }
    } 
    return 0;
}

//DELETE NODE 
int deletel(int data){
    node_s *curr;
    node_s *prev;
    //CURR : which needs to be deleted 
    //PREV : needed to track the next correct value else it will be lost 
    for (
        prev = NULL, curr = __head ; 
        curr != NULL;
        prev = curr ,curr = curr -> next_node
    ){
        if(curr -> word == data){
            prev -> next_node = curr -> next_node;
            free(curr);
            return 1;
        }
    }

    return 0;
}

int insert(int key, int data){ 
    node_s *k; 
    node_s *new;
    
    //create new node 
    new = malloc(sizeof(node_s));
    if(!new){
        printf("Memory Allocation failed..!\n");
    }
    new -> word = data;
    new -> next_node = NULL;

    for (k = __head ; k != NULL; k = k -> next_node){
        if(k -> word == key){
            new -> next_node = k -> next_node;
            k -> next_node = new;
            return 1;
        }
    }

    return 0;
}

int insert_nex(int key, int data){
    // i assume that my key is a count 
    node_s *k;
    node_s *new;
    int i;
    new = malloc(sizeof(node_s));
    new -> word = data;
    new -> next_node = NULL;

    for ( k = __head, i = 1; k != NULL; k = k -> next_node, i ++){
        if (i == key-1){
            new -> next_node = k -> next_node;
            //printf("k value at %d is %d\n", key -1, k ->word);
            k -> next_node = new;
            return 1;

        }
    }
    return 0;
}
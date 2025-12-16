#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Linked list 
/*
1. most widely used 
2. elements in order, linked by pointers
3. individual list elements are scattered in memory 
4. last element has NULL pointing 
5. also we could have pointer which points to the previous elements too : here 1st element is a NULL

--> only next element pointer/link : singly linked list 
--> previous element and next element pointer : doubly linked list 
*/

/*
1. linked list are basic of tree, queue, stack, tree, graphs



*/
    // Combining different data together: we need a node!
    // NODE : user(useful data)+metadata(pointer)

    typedef struct node{
        //useful data - a string
        char word[40];
        //pointer metadata
        //NODE : cant use the typedef renaming here !!
        struct node *next_node;    //pointer to next memory address of next node
        // since it points to next node , we make a pointer to the structure (that is next node)
    }node_s;
    
//GLOBAL    
node_s *__head = NULL;

//FUNCTION DEFINITIONS
int init(char *data);
int add (char *data);
int traverse(void);
int add_end(char *data);

int main(){

    //initialization of head pointer and pointing to NULL as there is no element in linkedlist/ no linkedlist 

    init("hello");
    //init("hello");  -> reinitializing 
    //ADDING NEXT NODES AND MAKE POINTER next_node point to that 
    add("i am kavya");
    add("thankyou");


    //CHECK if linked list in the order we want from head -> NULL
    printf("---------------TRAVERSE---------------\n");
    traverse();
    return 0;
}


//INIT
int init(char *data){


    //check if initialzation is already done ? if so terminate this code now itself
    if (__head){
        printf("Already Initialized..!\n");
        return -1;
    }



    //INIT's first data in linked list 
    //printf("un-allocated memory address before init: %p\n", __head );

    //we need to allocate a memory and put the first node in place 
    //and also make head point to that memory address
    __head = malloc(sizeof(node_s));   // and create memory space to store the struct i created 
    // check if memory allocation is sucessful, if not then return error 

    if(__head == NULL || !__head){
        printf("Memory allocation failed!");
        return -1;
    }
    //Since this is a first element add NULL to next pointer value 
    __head -> next_node = NULL;

    //Now that we have the 1st address, we need to now add out data into the 1st node 
    //  __head -> word = data;
    memcpy( __head->word ,data, strlen(data));  //assuming data is < 40 bytes
    //memcpy copies data to ptr memory
    

    //print
    printf("data in head: %s\n", __head -> word );
    printf("next node address: %p\n", __head -> next_node );
    //printf("allocated head address after init: %p\n", __head );
    return 0;

}


//ADDING 
int add(char *data){

    if(!data){
        printf("Invalid data..!\n");
        return -1;
    }

    //node/element pointer 
    node_s *n;

    //create space for the new node 
    n = malloc(sizeof(node_s));
    if(!n){   //if n = NULL, this condition become true
        printf("Memory Allocation failed...!\n");
        return -1;
    }

    //Now after space creation for the new node add or set pointers 
    //1st element/previous element pointer make it point to this n pointer 
    //next, if there is no element , and this is last , make next_node point to NULL
    //n -> next_node = NULL;
    void *s = memcpy(n->word, data, strlen(data));
    if (!s){
        printf("MEMCPY failed..!\n");
        return -1;
    }

    //adding new node at end of list : for loop 
    //adding new element at before at begining 
    n -> next_node = __head;
    __head = n;   // new element/node n is now the head 

    return 0;
}

int traverse(void){
    //loop for traversing the linked list 
    for (node_s *cursor = __head ; cursor != NULL ; cursor = cursor -> next_node){
        printf("%s\n", cursor ->word);
    } 
    /*
    NOTE: 
    1. eventhough the next_node is a part of struct, it does not mean any value 
    2. it just indicates the address to the next node so that we can add or point to memory easily 
    3. it is cool and next node address == previous node ->next_node ptr value 
    */
}

int add_end(char *data){
    

    return 0;
}
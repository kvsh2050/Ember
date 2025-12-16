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
        int word;
        //pointer metadata
        //NODE : cant use the typedef renaming here !!
        struct node *next_node;    //pointer to next memory address of next node
        // since it points to next node , we make a pointer to the structure (that is next node)
    }node_s;
    
//GLOBAL    
node_s *__head = NULL;

//FUNCTION DEFINITIONS
int init(int data);
int add (int data);
int traverse(void);
int add_end(int data);
int exists(int data);
int delete(int data);
int insert (int key, int data);
int insert_nex(int key , int data);

int main(){

    //initialization of head pointer and pointing to NULL as there is no element in linkedlist/ no linkedlist 

    init(0);
    //init("hello");  -> reinitializing 
    //ADDING NEXT NODES AND MAKE POINTER next_node point to that 

    //add(2);
    //add(3);
    //add_end(0);


    //TESTING 
    printf("-----------------TEST----------------\n");
    /*
    for (int i = 1; i < 10; i++){
        add(i);   // constant time for add
    }
 
    */


    for (int i = 1; i < 10; i++){
        add_end(i);   // linear time for adding 
    }




    //CHECK if linked list in the order we want from head -> NULL
    printf("---------------TRAVERSE---------------\n");
    traverse();

    printf("---------------SEARCH---------------\n");
    if(exists(5)){
        printf("5 Exists\n");
    }


    printf("---------------DELETE---------------\n");
    if(delete(5)){
        printf("5 Deleted\n");
    }
    traverse();

    printf("---------------INSERT---------------\n");
    if(insert(4, 5)){
        printf("5 Inserted\n");
    }
    traverse();

    printf("---------------INSERT_COUNT---------------\n");
    if(insert_nex(10, 5)){
        printf("Inserted at 10\n");
    }
    traverse();

    return 0;
}


//INIT
int init(int data){


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
    __head->word = data;  //assuming data is < 40 bytes
    //memcpy copies data to ptr memory
    

    //print
    //printf("data in head: %d\n", __head -> word );
    //printf("next node address: %p\n", __head -> next_node );
    //printf("allocated head address after init: %p\n", __head );
    return 0;

}


//ADDING 
int add(int data){

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
    n->word= data;
    //adding new node at end of list : for loop 
    //adding new element at before at begining 
    n -> next_node = __head;
    __head = n;   // new element/node n is now the head 

    return 0;
}

int traverse(void){
    //loop for traversing the linked list 
    for (node_s *cursor = __head ; cursor != NULL ; cursor = cursor -> next_node){
        printf("%d\t", cursor ->word);
    } 
    printf("\n");
    /*
    NOTE: 
    1. eventhough the next_node is a part of struct, it does not mean any value 
    2. it just indicates the address to the next node so that we can add or point to memory easily 
    3. it is cool and next node address == previous node ->next_node ptr value 
    */
}

//ADD AT END 
int add_end(int data){

    node_s *n;

    //create space for the new node 
    n = malloc(sizeof(node_s));
    if(!n){   //if n = NULL, this condition become true
        printf("Memory Allocation failed...!\n");
        return -1;
    }
    n -> word = data;
    n -> next_node = NULL;

    // create a traverse variable traverse the node : O(n) -> worst case, it takes n time unit 
    // space also increases as we add new node (here 40 bytes) increases 
    node_s *loop;
    for(loop = __head; loop -> next_node != NULL; loop = loop ->next_node){
        //just continue until loop becomes previous element of null
        //if loop != NULL then it means that the next_node address will be NULL and we loose the previous element 
        // so we stop when we see the nex_node as null itself 
    }
    // add the next_node of prev element this newly created element address
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
int delete(int data){

    //take the node to delete is current node 
    // node to prev is previous node 
    //free after it 
    node_s *curr;
    node_s *prev;

// prev -> NULL , curr -> head ; till curr not null, do prev = current node address, current node to next node addrss
//the next node address is stored in struct

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
//CHECK WHAT THE UNIVERSAL KEY IS index/data/ ..etc., ?
    //key to find the target 
    //add node next to it 
    // copy key next node to the new node 
    // and copy addres of new node to key's next_node
    // also create node to add the new data using amlloc 
    node_s *k;  // k here or key is the previous node (assumed)
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
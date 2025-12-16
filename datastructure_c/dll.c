#include<stdio.h>
#include<stdlib.h>


/*
STRUCT 
size : 8+4+8 = 20 bytes
*/
typedef struct node{
    struct node *prev_node;
    int data;
    struct node *next_node;  
}__attribute__((packed)) node_s;

/*
GLOBAL VARIABLES
*/
node_s *__head ;
node_s *__tail ;

/*
FORWARD DEFINITION OF FUNCTIONS FOR USER
*/
int init(int data);
int add_back (int data);
int add_front (int data);
int traverse(void);
int search(int data);
int delete(int data);
int insert (int key, int data);


/*
MAIN
define the required functions 
*/
int main(){

    printf("--------------------INIT----------------------------\n");
    if(!init(0)){
        printf("Initialization failed..!\n");
    }
    printf("%lu\n", sizeof(node_s));
    //traverse();
    //printf("%p\n", __tail);
    //printf("%p\n", __head);

    printf("---------------------ADD----------------------------\n");
    for (int i = 1; i <= 5 ; i++){
       add_front(i);
    }
    traverse();
    //printf("%p\n", __tail);
    //printf("%p\n", __head);
    for (int i = 1; i <= 5 ; i++){
        add_back(i);
    }
    traverse();
    //printf("%p\n", __tail);
    //printf("%p\n", __head);

    printf("------------------TRAVERSE--------------------------\n");
    traverse();
    printf("-------------------SEARCH---------------------------\n");
    if(search(2)){
        printf("Success..! The value is present..!\n");
    }else{
        printf("Value is not present..!\n");
    }
    printf("-------------------DELETE---------------------------\n");
    delete(2);
    traverse();

    printf("-------------------INSERT---------------------------\n");
    int flag = insert(3, 2);
    if (!flag){
        printf("Insert is not working properly.. or Data that you gave is not in list!\n");
    }
    traverse();

    return 0;
}

int init(int data){
    node_s *new;
    new = malloc(sizeof(node_s));
    if(!new){
        printf("Memory Allocation failed..!\n");
        return -1;
    }
    new -> prev_node = NULL;
    new -> next_node = NULL;
    new -> data = data;
    __head = new;
    __tail = new;
    return 0;
}

int add_back(int data){
    node_s *new;
    new = malloc(sizeof(node_s));
    if(!new){
        printf("Memory Allocation failed..!\n");
        return -1;
    }
    //printf("inside add_back\n");
    //printf("%p\n", __tail);
    //printf("%p\n", new);
    new -> data = data;
    new -> prev_node = __tail;
    new -> next_node = NULL;
    // make sure you change the nearby node when you make chnages 
    new -> prev_node -> next_node = new;
    __tail = new;
    //printf("inside add_back\n");
    //printf("%p\n", __tail);
    //printf("%p\n", new);
    return 0;
}

int add_front(int data){
    node_s *new;
    new = malloc(sizeof(node_s));
    if(!new){
        printf("Memory Allocation failed..!\n");
        return -1;
    }
    new -> data = data;
    new -> prev_node = NULL;
    new -> next_node = __head;
    new -> next_node -> prev_node = new;
    __head = new;
    return 0;
}

int traverse(){
    node_s *cursor;
    for (cursor = __head ; cursor != NULL; cursor = cursor -> next_node){
        printf("%d\t", cursor -> data);
    }
    printf("\n");
    return 0;
}

int search (int data){
    node_s *c_t, *c_b;
    // i am trying to create parallel process like thing, need to know if this loop is executed sequentially in binary
    for (c_t = __head, c_b = __tail; c_t != NULL, c_b != NULL; c_t = c_t -> next_node, c_b = c_b -> prev_node){
        if (c_t -> data == data){
            printf("From head\n");
            return 1;
        }
        if ( c_b -> data == data){
            printf("From tail\n");
            return 1;
        }
    }
    return 0;
}

int delete(int data){
    node_s *c_t, *c_b;
    for (c_t = __head, c_b = __tail; c_t != NULL, c_b != NULL; c_t = c_t -> next_node, c_b = c_b -> prev_node){
        if (c_t -> data == data){
            printf("From head\n");
            c_t -> prev_node -> next_node = c_t -> next_node;
            c_t -> next_node -> prev_node = c_t -> prev_node;
            free(c_t);
            return 1;
        }
        if ( c_b -> data == data){
            printf("From tail\n");
            c_b -> prev_node -> next_node = c_b ->next_node;
            c_b -> next_node -> prev_node = c_b -> prev_node;
            free(c_b);
            return 1;
        }
    }
    return 0;
}

int insert(int key, int data){
    node_s *new;
    node_s *c_t, *c_b;

    new = malloc(sizeof(node_s));
    if(!new){
        printf("Memory Allocation failed..!\n");
        return -1;
    }
    new -> data = data;
    // key is a data node after which i need to insert the new node
    for (c_t = __head, c_b = __tail; c_t != NULL, c_b != NULL; c_t = c_t -> next_node, c_b = c_b -> prev_node){
        if (c_t -> data == key){
            printf("From head\n");
            new -> next_node = c_t -> next_node;
            c_t -> next_node = new;
            new -> prev_node = c_t ;
            c_t -> next_node -> prev_node = new;
            return 1;
        }
        if ( c_b -> data == key){
            printf("From tail\n");
            new -> next_node = c_b -> next_node;
            c_b -> next_node = new;
            new -> prev_node = c_b ;
            c_b -> next_node -> prev_node = new;
            return 1;
        }
    }
    return 0;
}


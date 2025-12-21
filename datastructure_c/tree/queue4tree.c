#include<stdio.h>
#include<stdlib.h>

//function definition 
int enqueue(void* node_address);
int queue_not_empty(void);
int destroy_queue(void);
void* dequeue(void);

//queue node 
typedef struct treeq{
    void* tree_node;
    struct treeq *q_next_node;
}node_q;

//global queue variables 
static node_q *_head_ = NULL;
static node_q *_tail_ = NULL;

//functions 
int enqueue(void* node_address){
    node_q *new_node = malloc(sizeof(node_q));
    if(!_head_){
        // if head is null , iniitalize the queue
        printf("head is null at enqueue : %p, so adding new queue\n", _head_);
        new_node -> tree_node = node_address;
        new_node -> q_next_node = NULL;
        _head_ = new_node;
        _tail_ = new_node;
        return 1;
    }
    printf("head is not null and queue is already present\n");
    //if head not null, then we need to add the value to tail 
    // make the previous node address point to new node 
    new_node -> tree_node = node_address;
    new_node -> q_next_node = NULL;
    _tail_ -> q_next_node = new_node;
    _tail_ = new_node;
    return 0;
}

int queue_not_empty(void){
    if (_head_ == NULL){
        printf("There is nothing in queue\n");
        return 0; // queue is empty 
    }
    printf("There is elements in queue\n");
    return 1;  // queue has elements 
}

int destroy_queue(void){
    //go to each pointer in queue and free them 
    node_q *index = _head_ ;
    node_q *delete = _head_;

    if(index == NULL){
        printf("The queue empty\n");
        return 1;  // get out of here!
    }
    printf("The queue not empty\n");
    //if used for, the delete and index points to same mem, when the delete is freed, we cannot move to next node
    while (index != NULL)
    {
        delete = index;
        //printf("The delete: %p , the index : %p, the _head_ : %p \n", delete, index, _head_);
        index = index -> q_next_node;
        //printf("The delete: %p , the index : %p, the _head_ : %p \n", delete, index, _head_);
        free(delete);
    }
    
    //reset globals 
    _head_ = NULL;
    _tail_ = NULL;
    printf("Queue Freed..!\n");
    return 0;
}

void* dequeue(void){
    void *res;
    node_q *track ;
    // copy in once var 
    track = _head_;
    //printf("head value dequeued : %p\n", _head_);
    //printf("track value dequeued : %p\n", track);
    if(_head_ -> q_next_node == NULL || _head_ == _tail_){
        printf("After this value there is no elements in queue....\n");
        printf("Present head is %p, tail is %p\n", _head_, _tail_);
        _head_ = NULL;
        _tail_ = NULL;
    } else {
        printf("Present head is %p, tail is %p\n", _head_, _tail_);
        _head_ = _head_ -> q_next_node;
    }
    res = (void *)track -> tree_node;
    free(track);

    return res;
}
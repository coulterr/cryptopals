
#include <stdlib.h>
#include <string.h>



struct node{
	int val; 
	struct node *next;  
}; 

typedef struct{ 
	struct node *head; 
	struct node *tail; 
	int size; 
}int_queue;  

typedef struct node node;  

#ifndef INT_QUEUE_H
#define INT_QUEUE_H







void int_queue_init(int_queue *q);
void int_enqueue(int_queue *q, int val);
int int_dequeue(int_queue *q);
int int_emptyqueue(int_queue *q);


#endif

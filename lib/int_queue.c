#include "int_queue.h"

void int_queue_init(int_queue *q)
{
	q -> size = 0; 
}

void int_enqueue(int_queue *q, int val)
{
	node *next = malloc(sizeof(node)); 
	next -> val = val; 

	if(q -> size == 0){
		q -> head = next;
		q -> tail = next;
	}else{
		q -> tail -> next = next; 
		q -> tail = next; 
	}
	
	q -> size++; 
}


int int_dequeue(int_queue *q)
{
	if(q -> size == 0){
		return -1; 
	}else{ 
		node *head = q -> head; 
		int val = head -> val; 
			
		if(q -> size == 1){
			free(head);
		}else{
			q -> head = head -> next; 
			free(head); 
		}
		
		q -> size--; 
		return val; 
	}

}


int int_emtpyqueue(int_queue *q)
{
	while(q -> size > 0){
		int_dequeue(q); 
	}
}



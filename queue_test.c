#include "lib/int_queue.h"
#include "stdio.h"

int main()
{
	int_queue q; 
	int_queue_init(&q); 

	printf("Initialized q. Size is: %d\n", q.size); 

	int_enqueue(&q, 1); 
	int_enqueue(&q, 2); 
	int_enqueue(&q, 3); 
	int_enqueue(&q, 4); 
	int_enqueue(&q, 5); 
	int_enqueue(&q, 6); 
	int_enqueue(&q, 7); 
	int_enqueue(&q, 8); 
	int_enqueue(&q, 9); 
	int_enqueue(&q, 10);
	
	printf("Enqueued Items. Size of q is: %d\n", q.size); 

	int i; 
	for(i = 0; i < 10; i++)
	{
		printf("Dequeue: %d\n", int_dequeue(&q)); 
		printf("Size of q: %d\n", q.size); 
	}

	printf("Trying to dequeue more...: %d\n", int_dequeue(&q)); 

	
	int_enqueue(&q, 1); 
	int_enqueue(&q, 2); 
	int_enqueue(&q, 3); 
	int_enqueue(&q, 4); 
	int_enqueue(&q, 5); 
	int_enqueue(&q, 6); 
	int_enqueue(&q, 7); 
	int_enqueue(&q, 8); 
	int_enqueue(&q, 9); 
	int_enqueue(&q, 10);

	for(i = 0; i < 10; i++)
	{
		printf("Dequeue: %d\n", int_dequeue(&q)); 
		printf("Size of q: %d\n", q.size); 
	}

	printf("Trying to dequeue more...: %d\n", int_dequeue(&q)); 

	int_enqueue(&q, 1); 
	int_enqueue(&q, 2); 
	int_enqueue(&q, 3); 
	int_enqueue(&q, 4); 
	int_enqueue(&q, 5);
	int_dequeue(&q); 
	int_dequeue(&q); 
	int_enqueue(&q, 6); 
	int_enqueue(&q, 7); 
	int_enqueue(&q, 8); 
	int_enqueue(&q, 9); 
	int_enqueue(&q, 10);
	
	for(i = 0; i < 8; i++)
	{
		printf("Dequeue: %d\n", int_dequeue(&q)); 
		printf("Size of q: %d\n", q.size); 
	}
}

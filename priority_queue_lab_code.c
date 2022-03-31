// A C program to demonstrate linked list based implementation of Minimum Priority queue
// Here the value of data is the priority and lower value means higher priority
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
// A linked list (LL) node to store a queue entry
struct QNode {
    int key;
    struct QNode* next;
};
 
// The queue, front stores the front node of LL and rear stores the
// last node of LL
struct Queue {
    struct QNode *front, *rear;
};
 
// A utility function to create a new linked list node.
struct QNode* newNode(int k)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}
 
// A utility function to create an empty queue
struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
 
// The function to add a key k to q
void enQueue(struct Queue* q, int k)
{
    // Create a new LL node
 
    // Create a pointer to the front node
 
    // If queue is empty, then new node is front and rear both
 
 
 
    // ELSE
 
 		// Special Case: The head of list has lesser
	    // priority than new node. So insert new
	    // node before head node and change head node.
 
	        // Insert New Node before head
 
		// ELSE case
 
	        // Traverse the list and find a
	        // position to insert new node
 
 
	        // Either at the ends of the list
	        // or at required position
 
}
 
// Function to remove a key from given queue q
int deQueue(struct Queue* q)
{
    // If queue is empty, return INT_MIN.
 
    // Store previous front and move front one node ahead
 
    // If front becomes NULL, then change rear also as NULL
 
 
	// Free node
 
    // Return removed value
 
}
void display(struct Queue* q)
{
	// If queue is empty, print "Queue is Empty" in this function.
 
 
 
	// Else traverse the list and print each element
 
}
// Driver program to test above functions
int main()
{
	FILE *fptr;
   	if ((fptr = fopen("priority_queue_LL_input.txt","r")) == NULL)
   	{
	   printf("Error! opening file");
       // Program exits if the file pointer returns NULL.
       exit(1);
   	}
	int choice, data;
	// Below line may be different but variable name "queue" must be same
	struct Queue* queue = createQueue();
	do
	{
		printf("\nPress 1 to enqueue\nPress 2 to dequeue\nPress 3 to display\nPress 0 to quit");
		fscanf(fptr,"%d", &choice);
		printf("\n%d", choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter value to insert: ");
				fscanf(fptr, "%d",&data);
				printf("%d", data);
				enQueue(queue, data);
				display(queue);
				break;
			case 2:
				data = deQueue(queue);
				if(data!=INT_MIN)
				{
					printf("\n%d is dequeued", data);	
					display(queue);
				}
				else
					printf("\nQueue is empty");
				break;
			case 3:
				display(queue);
				break;
			case 0:
				printf("\nQuitting program");
				break;
			default:
				printf("\nInvalid choice");
				break;
		}
	}while(choice!=0);
	return 0;
}

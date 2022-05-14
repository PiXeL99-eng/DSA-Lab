// A C program to demonstrate linked list based implementation of circular queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// A linked list (LL) node to store a queue entry
struct QNode {
    int key;
	int priority;
    struct QNode* next;
};
 
// The queue, front stores the front node of LL and rear stores the
// last node of LL
struct Queue {
    struct QNode *front, *rear;
};
 
// A utility function to create a new linked list node.
struct QNode* newNode(int k, int p)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
	temp->priority = p;
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
void enQueue(struct Queue* q, int k, int p)
{
    // Create a new LL node
 
    // If queue is empty, then new node is front and rear both

 	// Else Add the new node at the end of queue and change rear

     struct QNode *node = newNode(k, p);

     if(q->front == NULL && q->rear == NULL){
         node->next = node;
         q->front = q->rear = node;
     }
     else{
         q->rear->next = node;
         node->next = q->front;
         q->rear = node;
     }
    
}

struct QNode* getMin(struct Queue *q){
	int prior = INT_MAX;

	struct QNode* node = q->front;
	struct QNode* res = q->front;

	do{
		if(node->priority<prior){
			prior = node->priority;
			res = node;
		}

		node = node->next;

	}while(node!=q->front);

	return res;
}
 
// Function to remove a key from given queue q
int deQueue(struct Queue* q)
{
    // If queue is empty, return INT_MIN.
    int item = 0;

    if(q->front == NULL && q->rear == NULL){
        return INT_MIN;
    }
    else if(q->front == q->rear){
        item = q->front->key;
        q->front->next = q->rear->next = NULL;
        free(q->front);
        free(q->rear);
        q->front = q->rear = NULL;
    }
    else{
        struct QNode *node = getMin(q);
		item = node->key;

		if(node == q->front){
			q->rear->next = q->front->next;
			q->front->next = NULL;
			free(q->front);
			q->front = q->rear->next;
		}
		else{
			struct QNode *cur_node = q->front;

			while(cur_node->next!=node){
				cur_node = cur_node->next;
			}

			if(node == q->rear){
				cur_node->next = node->next;
				node->next = NULL;
				free(node);
				q->rear = cur_node;
			}
			else{
				cur_node->next = node->next;
				node->next = NULL;
				free(node);
			}

		}

    }

    return item;
}
void display(struct Queue* q)
{
	// If queue is empty, printf Queue is Empty in this function.

    if(q->front == NULL && q->rear == NULL){
        printf("\nQueue is Empty!\n");
    }
    else{
        struct QNode *node = q->front;

        printf("\nQueue is: ");
        do{
            printf("(key = %d, priority = %d) ", node->key, node->priority);
            node = node->next;

        }while (node!=q->front);
        
        printf("\n");
    }
}
// Driver program to test above functions
int main()
{
	FILE *fptr;
   	if ((fptr = fopen("priority_queue_input.txt","r")) == NULL)
   	{
	   printf("Error! opening file");
       // Program exits if the file pointer returns NULL.
       exit(1);
   	}
	int choice, data, priority;
	// Below line may be different but variable name "queue" must be same
	struct Queue* queue = createQueue();
	do
	{
		printf("\nPress 1 to enqueue\nPress 2 to dequeue\nPress 3 to display\nPress 0 to quit");
		fscanf(fptr, "%d", &choice);
		printf("\n%d", choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter value and priority to insert: ");
				fscanf(fptr, " %d %d",&data, &priority);
				printf("(data = %d, priority = %d)", data, priority);
				enQueue(queue, data, priority);
				break;
			case 2:
				data = deQueue(queue);
				if(data!=INT_MIN)
					printf("\n%d is dequeued", data);
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
	fclose(fptr);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* create_node(int val){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->val = val;

    return node;
}

//Queue making
struct QNode {
    struct Node* node;
    struct QNode* next;
};
 
struct Queue {
    struct QNode *front, *rear;
};

struct QNode* newNode(struct Node* cur_node)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->node = cur_node;
    temp->next = NULL;
    return temp;
}
 
struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, struct Node* cur_node)
{
     struct QNode *node = newNode(cur_node);

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

struct Node* deQueue(struct Queue* q)
{
    if(q->front == NULL && q->rear == NULL){
        return NULL;
    }
    else if(q->front == q->rear){
        struct Node* r_node = q->front->node;
        q->front->next = q->rear->next = NULL;
        free(q->front);
        q->front = q->rear = NULL;
        return r_node;
    }
    else{
        struct Node* r_node = q->front->node;
        struct QNode *node = q->front;
        q->front = q->front->next;
        q->rear->next = q->front;
        node->next = NULL;
        free(node);
        return r_node;
    }
}
//Queue making ends

void inorder(struct Node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

void preorder(struct Node* root){
    if(root != NULL){
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->val);
    }
}

struct Node* insert(int nodes){
    struct Queue* q = createQueue();
    int val;

    printf("Enter values for nodes: \n");
    scanf("%d", &val);
    struct Node* cur_node = create_node(val);
    enQueue(q, cur_node);

    struct Node* root = cur_node;
    nodes--;

    while(nodes>0){
        cur_node = deQueue(q);

        scanf("%d", &val);
        cur_node->left = create_node(val);
        nodes--;
        enQueue(q, cur_node->left);

        if(nodes == 0){
            break;
        }
    
        scanf("%d", &val);
        cur_node->right = create_node(val);
        nodes--;

        enQueue(q, cur_node->right);
    }

    return root;
}

int main()
{
    int nodes;
    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    if(nodes>0){

        struct Node* root = insert(nodes);

        printf("\nInorder Traversal: ");
        inorder(root);
        printf("\nPreorder Traversal: ");
        preorder(root);
        printf("\nPostorder Traversal: ");
        postorder(root);
    }
    else{
        printf("Number of nodes must be greater than 0");
    }

	return EXIT_SUCCESS;
}
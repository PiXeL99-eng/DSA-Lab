#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node* next;
};

struct Node* add_start(struct Node* head, int value){
    if(head == NULL){
        head = (struct Node*)malloc(sizeof(struct Node));

        if(head == NULL){
            printf("Memory ran out");
        }
        else{
            head->next = NULL;
            head->val = value;
        }
        return head;
    }
    else{
        struct Node* new_head = (struct Node*)malloc(sizeof(struct Node));

        if(new_head == NULL){
            printf("Memory ran out");
        }
        else{
            new_head->next = head;
            new_head->val = value;
        }

        return new_head;
    }
}

struct Node* add_end(struct Node* head, int value){
    if(head == NULL){
        head = (struct Node*)malloc(sizeof(struct Node));

        if(head == NULL){
            printf("Memory ran out");
        }
        else{
            head->next = NULL;
            head->val = value;
        }
        return head;
    }
    else{
        struct Node* store_head = head;
        struct Node* store = (struct Node*)malloc(sizeof(struct Node));

        if(store == NULL){
            printf("Memory ran out");
            return store_head;
        }
        else{
            while(head->next != NULL){
                head = head->next;
            }

            store->val = value;
            store->next = NULL;
            head->next = store;
        }

        return store_head;
    }
}

struct Node* add_intermediate(struct Node* head, int pos, int value){
    if(head == NULL){
        head = (struct Node*)malloc(sizeof(struct Node));

        if(head == NULL){
            printf("Memory ran out");
        }
        else{
            head->next = NULL;
            head->val = value;
        }
        return head;
    }
    else{
        struct Node* store_head = head;
        struct Node* store = (struct Node*)malloc(sizeof(struct Node));

        if(store == NULL){
            printf("Memory ran out");
            return store_head;
        }
        else{

            store->val = value;

            if (pos == 1){
                store->next = head;
                return store;
            }
            else{

                while(head->next != NULL && pos-1>1){
                    head = head->next;
                    pos--;
                }

                store->next = head->next;
                head->next = store;
            }
        }

        return store_head;
    }
}

struct Node* node_remove(struct Node* head, int value){
    if(head != NULL && head->val == value){
        printf("\nNode found and deleted\n");
        struct Node* store = head;

        head = head->next;
        free(store);

        return head;
    }
    else if (head!= NULL){
        struct Node* store_head = head;
        struct Node* initial = head;
        head = head->next;
        
        while (head!= NULL)
        {
            if(head->val == value){
                initial->next = head->next;
                free(head);
                printf("\nNode found and deleted!\n");
                return store_head;
            }

            initial = head;
            head = head->next;
        }

        printf("\nNode was not found!\n");
        return store_head; 
    }

    else{
        printf("\nList is empty!\n");
        return head;
    }
}

void display(struct Node* head){
    if(head == NULL){
        printf("\nList is empty!\n");
    }
    else{

        printf("\nLinked List: ");
        while(head != NULL){
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    }
    
}

int main(){

    struct Node* head = NULL;
    char ch;
    int v, pos;

    do
    {
        printf("\n1. Add at the beginning of Linked List: ");
        printf("\n2. Add at the end of Linked List: ");
        printf("\n3. Add in an intermediate position of Linked List: ");
        printf("\n4. Display the Linked List: ");
        printf("\n5. Delete an element from the Linked List: ");
        printf("\n6. Exit");
        printf("\nEnter your choice(1-6): ");
        fflush(stdin);
        scanf("%c", &ch);

        switch(ch)
        {
        case '1':
            printf("\nEnter value: ");
            fflush(stdin);
            scanf("%d", &v);
            head = add_start(head, v);
            display(head);
            break;
        case '2':
            printf("\nEnter value: ");
            fflush(stdin);
            scanf("%d", &v);
            head = add_end(head, v);
            display(head);
            break;
        case '3':
            printf("\nEnter position from the start: ");
            fflush(stdin);
            scanf("%d", &pos);
            printf("Enter value: ");
            fflush(stdin);
            scanf("%d", &v);
            head = add_intermediate(head, pos, v);
            display(head);
            break;
        case '4':
            display(head);
            break;
        case '5':
            printf("\nEnter value to delete: ");
            fflush(stdin);
            scanf("%d", &v);
            head = node_remove(head, v);
            display(head);
            break;
        case '6':
            printf("\nPROGRAM TERMINATED!!");
            break;
        default :
            printf("\nWrong Entry!!\n");
            break;
        }

    }while(ch!='6');
     
    return EXIT_SUCCESS;
}
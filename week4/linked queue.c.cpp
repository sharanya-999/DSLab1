#include <stdio.h>
#include <stdlib.h>  // For malloc and free

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

struct queue *insert(struct queue *, int);
struct queue *delete_element(struct queue *);
struct queue *display(struct queue *);
int peek(struct queue *);
void create_queue(struct queue *);

int main() {
    int val, option;
    struct queue *q;

    // Allocate memory and initialize
    q = (struct queue *)malloc(sizeof(struct queue));
    create_queue(q);

    do {
        printf("\n***** MAIN MENU *****");
        printf("\n1. INSERT");
        printf("\n2. DELETE");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter the number to insert in the queue: ");
                scanf("%d", &val);
                q = insert(q, val);
                break;

            case 2:
                q = delete_element(q);
                break;

            case 3:
                val = peek(q);
                if (val != -1)
                    printf("\nThe value at front of queue is: %d", val);
                break;

            case 4:
                q = display(q);
                break;

            case 5:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid Option!");
        }
    } while (option != 5);

    return 0;
}

void create_queue(struct queue *q) {
    q->rear = NULL;
    q->front = NULL;
}

struct queue *insert(struct queue *q, int val) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;

    if (q->front == NULL) {
        q->front = ptr;
        q->rear = ptr;
    } else {
        q->rear->next = ptr;
        q->rear = ptr;
    }

    return q;
}

struct queue *display(struct queue *q) {
    struct node *ptr;
    ptr = q->front;

    if (ptr == NULL)
        printf("\nQUEUE IS EMPTY\n");
    else {
        printf("\nQueue contents:\n");
        while (ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }

    return q;
}

struct queue *delete_element(struct queue *q) {
    struct node *ptr;

    if (q->front == NULL) {
        printf("\nUNDERFLOW\n");
    } else {
        ptr = q->front;
        printf("\nThe value being deleted is: %d", ptr->data);
        q->front = q->front->next;
        free(ptr);

        // If queue becomes empty, update rear
        if (q->front == NULL)
            q->rear = NULL;
    }

    return q;
}

int peek(struct queue *q) {
    if (q->front == NULL) {
        printf("\nQUEUE IS EMPTY\n");
        return -1;
    } else {
        return q->front->data;
    }
}

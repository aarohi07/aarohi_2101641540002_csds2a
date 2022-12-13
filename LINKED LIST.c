#include <stdio.h>
#include <stdlib.h>
//node
struct Node
{
    int data;
    struct Node *address;
}


// Printing a linked list
void printLL(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->address;
    }
    printf("NULL\n");
}


// Insertion at end
void insertionatend(struct Node *head, int data)
{
    printf("Before Insertion at tail \n");
    printLL(head);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->address = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    struct Node *s = head;
    while (s->address != NULL)
    {
        s = s->address;
    }
    s->address = temp;
    printf("After Insertion at tail \n");
    printLL(head);
};


// Insert at specific position
void insertion(struct Node *head, int data, int posafter)
{
    printf("Before Insertion in between\n");
    printLL(head);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->address = NULL;
    struct Node *s = head;
    while (s->address->data != posafter)
    {
        s = s->address;
    }
    struct Node *a = s->address;
    s->address = temp;
    temp->address = a;
    printf("After Insertion in between\n");
    printLL(head);
}


// Insertion at head
struct Node *insertionathead(struct Node *head, int data)
{
    printf("Before Insertion at head \n");
    printLL(head);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->address = NULL;
    struct Node *s = head;
    head = temp;
    head->address = s;
    printf("After Insertion at head \n");
    printLL(head);
    return (head);
}


// deletion at end
void deleteend(struct Node *head)
{
    printf("Before deletion at tail \n");
    printLL(head);
    struct Node *s = head;
    while (s->address->address != NULL)
    {
        s = s->address;
    }
    struct Node *temp = s->address;
    s->address = NULL;
    free(temp);
    printf("after deletion at tail \n");
    printLL(head);
}


// deletion at head
struct Node* deletehead(struct Node *head)
{
    printf("Before deletion at head \n");
    printLL(head);
    struct Node *temp = head;
    head=head->address;
    free(temp);
    printf("after deletion at head \n");
    printLL(head);
    return (head);
}


// deletion at specific position
void deletebefore(struct Node *head,int data)
{
    printf("Before deletion at before data \n");
    printLL(head);
    struct Node *s = head;
    while (s->address->address->data != data)
    {
        s = s->address;
    }
    struct Node *temp = s->address;
    s->address=s->address->address;
    free(temp);
    printf("after deletion at before data \n");
    printLL(head);
}


// return nth 
void rthterm(struct Node* head, int n_from_last){
    struct Node* s=head;
    struct Node* temp=head;
    while(n_from_last > 0){
        s=s->address;
        n_from_last--;
    }
    while (s->address!=NULL)
    {
        temp=temp->address;
        s=s->address;
    }
    printf("%d",temp->data);
    
}

// return middle node using bunny and turtle technique
void bunnyandturtle(struct Node* head){
    printf("PRINTING middle node using bunny and turtle technique\n");
    struct Node* s=head;
    struct Node* temp=head;
    while (s->address!=NULL && s!=NULL && s->address->address!=NULL)
    {
        temp=temp->address;
        s=s->address->address;
    }
    printf("%d\n",temp->data);
    
}
// return middle node using counter
void middle(struct Node* head){
    printf("PRINTING middle node using counter\n");
    int c=0;
    struct Node* s=head;
    while (s->address!=NULL)
    {
        c++;
        s=s->address;
    }
    int mi=c/2;
    s=head;
    if (c&1==0){
        mi-=1;
    }
    while (mi>0)
    {
        s=s->address;
        mi--;
    }
    printf("%d",s->data);
    
}

// return middle node using bunny and turtle technique
void bunnyandturtle(struct Node* head){
    printf("PRINTING middle node using bunny and turtle technique\n");
    struct Node* s=head;
    struct Node* temp=head;
    while (s->address!=NULL && s!=NULL && s->address->address!=NULL)
    {
        temp=temp->address;
        s=s->address->address;
    }
    printf("%d\n",temp->data);
    
}


// Main function
void main()
{
    struct Node *headptr = NULL;
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    first->data = 100;
    if (headptr == NULL)
    {
        headptr = first;
    }
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    second->data = 200;
    second->address = NULL;
    first->address = second;
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    third->data = 300;
    third->address = NULL;
    second->address = third;
    printLL(headptr);
    insertionatend(headptr, 400);
    headptr = insertionathead(headptr, 50);
    insertion(headptr, 350, 300);
    deleteend(headptr);
    headptr = deletehead(headptr); 
    deletebefore(headptr,300);
    insertionattail(headptr, 600);
    insertionattail(headptr, 700);
    insertionattail(headptr, 800);
    insertionattail(headptr, 900);  
    printLL(headptr);
    rthterm(headptr,3);
    bunnyandturtle(headptr);
    middle(headptr);

      
}
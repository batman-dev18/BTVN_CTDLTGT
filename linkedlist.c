#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node {
     int data ; 
     struct Node *next ; 
}Node ; 

Node* init ( Node **head )
{
    *head = NULL ; 
    return *head ; 
}

int is_empty(Node* head ) 
{
    return head ==NULL ; 
}

int get_size(Node * head )
{
    int i =0; 
    while ( head != NULL) 
    {
        i++; 
        head = head->next ; 
    }
    return i ; 
}

// Bo sung thanh phan K vao dau danh sach 
Node* append ( Node **head , int val )
{
    Node* newNode = (Node*) malloc ((sizeof (Node))); 
    newNode->data = val ; 
    newNode->next = NULL ;
    
    if ( is_empty(*head)){
        *head= newNode ; 
        return *head ; 
    }
    newNode->next = *head;
    *head = newNode ; 
    return *head ;
}

//tim phan tu co data = x
Node* search_with_data ( Node * head, int x )
{
    if ( is_empty(head)){
        printf("The list is empty!\n") ; 
        return NULL;
    }
    int i =1 ; 
    while(head!=NULL){
        if ( head->data == x ){
            printf("Node->data:%d, Node->index:%d\n", head->data, i ) ;
            return head ; 
        }
        i++ ; 
        head = head->next ; 
    }
    printf("There is no Node with element: %d\n", x );
    return NULL ; 
}

Node* search_with_data1 ( Node * head, int x )
{   
    if ( is_empty(head)){
        printf("The list is empty!\n") ; 
        return NULL;
    }
    while(head!=NULL){
        if ( head->data == x ){
            return head ; 
        }
        head = head->next ; 
    }
    printf("There is no Node with element: %d\n", x ); 
    return NULL ; 
}

//bo sung phan tu K vao sau phan tu duoc tro boi P 
Node* append_after_Node(Node ** head, int k, Node *p) 
{
    if ( p==NULL ) {
        printf("The Node P doesnt pointer to any Node !\n") ; 
        return *head; 
    }
    if (is_empty(*head)){
        printf("The list is empty\n") ; 
        return *head;
    }

    Node* newNode = (Node*) malloc (sizeof(Node)) ; 
    newNode->data = k ; 
    newNode->next = p->next ;
    p->next = newNode ; 
    return *head;
}

//bo sung phan tu vao node co data = x 
Node* append_after_data(Node ** head, int k, int x ) 
{
    Node * p = search_with_data1(*head,x) ; 
    if ( p==NULL ) {
        printf("The Node P doesnt pointer to any Node !\n") ; 
        return *head;
    }
    if (is_empty(*head)){
        printf("The list is empty\n") ; 
        return *head;
    }

    Node* newNode = (Node*) malloc (sizeof(Node)) ; 
    newNode->data = k ; 
    newNode->next = p->next ;
    p->next = newNode ; 
    return *head;
}

//bo sung phan tu K vao truoc phan tu duoc tro boi P 
Node* append_before_Node(Node ** head, int k, Node *p) 
{
    if ( p==NULL ) {
        printf("The Node P doesnt pointer to any Node !\n") ; 
        return *head;
    }
    if (is_empty(*head)){
        printf("The list is empty\n") ; 
        return *head;
    }

    Node* newNode = (Node*) malloc (sizeof(Node)) ; 
    newNode->data = k ; 
    newNode->next = p->next ;
    p->next = newNode ; 

    int temp = p->data ; 
    p->data = newNode->data ; 
    newNode->data = temp ; 

    return *head;
}

//bo sung phan tu vao truoc node co data = x 
Node* append_before_data(Node ** head, int k, int x ) 
{
    Node * p = search_with_data1(*head,x) ; 
    if ( p==NULL ) {
        printf("The Node P doesnt pointer to any Node !\n") ; 
        return *head;
    }
    if (is_empty(*head)){
        printf("The list is empty\n") ; 
        return *head;
    }

    Node* newNode = (Node*) malloc (sizeof(Node)) ; 
    newNode->data = k ; 
    newNode->next = p->next ;
    p->next = newNode ; 

    int temp = p->data ; 
    p->data = newNode->data ; 
    newNode->data = temp ; 
    return *head;
}

// tinh gia tri trung binh
float average_list(Node * head)
{
    if (head == NULL) return 0;
    float sum = 0; 
    int size = get_size ( head ) ; 
    Node* temp = head;
    while ( temp != NULL )
    {
        sum = sum  + temp->data ; 
        temp= temp->next ; 
    }
    float result = sum / size ;
    return result ;  
}

// tra ve node cuoi cung 
Node* last_node ( Node * head )
{
    if (head == NULL) return NULL;
    while ( head -> next != NULL) {
        head = head->next ; 
    }
    return head ; 
}

//them phan tu vao cuoi danh sach 
Node* append_last( Node ** head, int x )
{
    Node * l = last_node ( *head ) ; 
    Node * newNode = (Node*) malloc (sizeof(Node)); 
    newNode->data = x ; 
    newNode->next = NULL ; 
    if (l == NULL) {
        *head = newNode;
        return *head;
    }
    l->next= newNode ; 
    return *head;
}

// in ra danh sach 
Node* display ( Node *head)
{
    if (is_empty(head)){
        printf ("The list is empty !\n");
        return head;
    }
    while (head != NULL){
        printf( "%d->", head->data); 
        head = head->next ; 
    }
    printf("NULL\n");
    return head;
}

int main () 
{
    Node* head ; 
    init(&head ) ;
    append(&head, 1) ; 
    append(&head, 2) ; 
    append(&head, 3) ; 
    append(&head, 4) ; 
    append(&head, 5) ; 
    append(&head, 6) ; 

    Node* p = head->next->next->next ; 
    append_after_Node (&head, 8, p) ; 
    append_after_data (&head, 9, 4) ; 
    append_before_data(&head, 100, 5) ;  
    append_after_Node (&head, 120, p) ; 
    append_last(&head,111) ; 
    display(head);
    printf("\n") ; 
    search_with_data(head, 4 ) ;  
    float result = average_list(head); 
    printf("\n The average value:%f",result) ; 
    return 0 ;  
}

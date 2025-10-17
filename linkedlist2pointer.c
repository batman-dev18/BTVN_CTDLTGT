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
void append ( Node **head , int val )
{
    //tao ra 1 mode moi 
    Node* newNode = (Node*) malloc ((sizeof (Node))); 
    newNode->data = val ; 
    newNode->next = NULL ;
    
    //noi vao dau danh sach lien ket 
    if ( is_empty(*head)){
        *head= newNode ; return ; 
    }
    newNode->next = *head;
    *head = newNode ; 




}
//tim phan tu co data = x
Node* search_with_data ( Node * head, int x )
{
    if ( is_empty(head)){
        printf("The list is empty!") ; 
    }
    int i =1 ; 
    while(head!=NULL){
    if ( head->data == x ){
        printf("Node->data:%d, Node->index:%d", head->data, i ) ;return head ; 
    }
        i++ ; head = head->next ; 
    if ( head ==NULL )
    {
        printf("There is no Node with element: %d", x ); return NULL ; 
    }
    
 }
}
 Node* search_with_data1 ( Node * head, int x )
    {   
    if ( is_empty(head)){
        printf("The list is empty!") ; 
    }
    int i =1 ; 
    while(head!=NULL){
    if ( head->data == x ){
        return head ; 
    }
        i++ ; head = head->next ; 
    if ( head ==NULL )
    {
        printf("There is no Node with element: %d", x ); return NULL ; 
    }
    
 }

}
//bo sung phan tu K vao sau phan tu duoc tro boi P 
void append_after_Node(Node ** head, int k, Node *p) 
{
    if ( p==NULL ) {
        printf("The Node P doesnt pointer to any Node !") ; return; 

    }
    if (is_empty(*head)){
        printf("The list is empty") ; 
    }
    //tao ra node moi 
    Node* newNode = (Node*) malloc (sizeof(Node)) ; 
    newNode->data = k ; 
    newNode->next = NULL ; 
    //noi vao sau Node P 
    newNode->next = p->next ;
    p->next = newNode ; 

}
//bo sung phan tu vao node co data = x 
void append_after_data(Node ** head, int k, int x ) 
{
    Node * p = search_with_data1(*head,x) ; 
    if ( p==NULL ) {
        printf("The Node P doesnt pointer to any Node !") ; return; 

    }
    if (is_empty(*head)){
        printf("The list is empty") ; 
    }
    //tao ra node moi 
    Node* newNode = (Node*) malloc (sizeof(Node)) ; 
    newNode->data = k ; 
    newNode->next = NULL ; 
    //noi vao sau Node P 
    newNode->next = p->next ;
    p->next = newNode ; 
}
//bo sung phan tu K vao truoc phan tu duoc tro boi P 
void append_before_Node(Node ** head, int k, Node *p) 
{
    if ( p==NULL ) {
        printf("The Node P doesnt pointer to any Node !") ; return; 

    }
    if (is_empty(*head)){
        printf("The list is empty") ; 
    }
    //tao ra node moi 
    Node* newNode = (Node*) malloc (sizeof(Node)) ; 
    newNode->data = k ; 
    newNode->next = NULL ; 
    //noi vao sau Node P 
    newNode->next = p->next ;
    p->next = newNode ; 
    //swap data
    int temp ; 
    temp = p->data ; 
    p->data = newNode->data ; 
    newNode->data = temp ; 

}
//bo sung phan tu vao truoc node co data = x 
void append_before_data(Node ** head, int k, int x ) 
{
    Node * p = search_with_data1(*head,x) ; 
    if ( p==NULL ) {
        printf("The Node P doesnt pointer to any Node !") ; return; 

    }
    if (is_empty(*head)){
        printf("The list is empty") ; 
    }
    //tao ra node moi 
    Node* newNode = (Node*) malloc (sizeof(Node)) ; 
    newNode->data = k ; 
    newNode->next = NULL ; 
    //noi vao sau Node P 
    newNode->next = p->next ;
    p->next = newNode ; 
    //swap
    int temp ; 
    temp = p->data ; 
    p->data = newNode->data ; 
    newNode->data = temp ; 


}
// tinh gia tri trung binh
float average_list(Node * head)
{
    float sum = 0; 
    int size = get_size ( head ) ; 
    while ( head != NULL )
    {
        sum = sum  + head->data ; 
        head= head->next ; 
    }
     float result = 0 ; 
    result += sum/size ;
    return result ;  
}
//them phan tu vao cuoi danh sach 
Node* last_node ( Node * head )
{
    while ( head -> next != NULL) {
        head = head->next ; 
    }
    return head ; 
}
void append_last( Node ** head, int x )
{
Node * l = last_node ( *head ) ; 
Node * newNode = (Node*) malloc (sizeof(Node)); 
newNode->data = x ; 
newNode->next = NULL ; 
l->next= newNode ; 
}

// in ra danh sach 
void display ( Node *head)
{
    if (is_empty(head)){
        printf ("The list is empty !");
    }
    while (head != NULL){
        printf( "%d->", head->data); 
        head = head->next ; 
    }
    printf("NULL");
    return ; 
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
    // searchwithdata(head,4) ; 
    // int size = get_size(head) ; printf ( "%d", size) ;  

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
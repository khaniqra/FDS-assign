/*A154 Assign 5
Implement any database using a doubly-linked list with the following options
a) Insert a record
b) delete a record
c) modify a record
d) Display list forward
Display list backward*/

#include <stdio.h>
#include<stdlib.h>
struct abc
{
    int data;
    struct abc *prv, *next;
};
void create(int , struct abc *);
void display(struct abc*);
void insertMiddle(int,struct abc*);
void insertEnd(struct abc*);
void insertStart(struct abc*);
void deleteStart(struct abc*);
void deleteMiddle(int,struct abc*);
void deleteEnd(struct abc*);
void reverse(struct abc*);
int main()
{
    struct abc *head;
    int n,e,a,ch;
    char p;
    head=(struct abc *)malloc(sizeof(struct abc));
    printf("enter data for head node\n");
    scanf("%d",&head->data);
    head->next=NULL;
    head->prv=NULL;
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    create(n,head);
    printf("\n Data of my doubly linked list");
    display(head);
   
    do{
      printf("\nEnter the choice:\n1.Insert in middle\n2.Insert at end\n3.Insert at start\n4.Delete at start\n5.Delete in Middle\n6.Delete at end\n7.Reverse\n8.Exit\n");
      scanf("%d",&ch);
      switch(ch){
    case 1:printf("Enter the data after which insertion takes place ");
           scanf("%d",&e);
           insertMiddle(e,head);
           break;
    case 2:printf("\nInsert at end");
          insertEnd(head);
          break;
    case 3:printf("\nInsert at start");
          insertStart(head);
          break;
    case 4:printf("\nDelete from start i.e. delete head node");
          deleteStart(head);
          break;
    case 5:printf("Enter the data after which you have to delete ");
           scanf("%d",&a);
           deleteMiddle(a,head);
           break;
    case 6: printf("\nDelete from end i.e. delete last node\n");
            deleteEnd(head);
            break;
    case 7: printf("\nThe reverse of the list is:\n");
            reverse(head);
            break;
    default:printf("\nExit\n");
      }
      printf("\nDo you want to continue(y/n):");
      scanf("%s",&p);
  }while(p=='y');
}
void create(int n, struct abc* head)
{
    struct abc *temp,*head1;
    head1=head;

    printf("enter data\n");

for(int i=0; i<n; i++)
    {
         temp=(struct abc *)malloc(sizeof(struct abc));
         scanf("%d",&temp->data);
         head->next=temp;
         temp->next=NULL;
         temp->prv=head;
         head=head->next;
    }
    
}

void display(struct abc*head){
  printf("\nThe list is:\n");
  while(head!=NULL)
  {
    printf("%d\n",head->data);
    head=head->next;
  }
}

void insertMiddle(int e, struct abc*head){
  struct abc *temp,*p,*q;
  q=head;
  temp=(struct abc*)malloc(sizeof(struct abc));
  printf("Enter data\n");
  scanf("%d",&temp->data);
  temp->next=NULL;
  temp->prv=NULL;
  while(e!=head->data){
    head = head->next;
  }
  p=head->next;
  temp->next=p;
  temp->prv=head;
  head->next=temp;
  p->prv=temp;

  printf("\n Data after inserting at middle");
  display(head);
}

void insertEnd(struct abc*head){
  struct abc *temp;
  temp=(struct abc*)malloc(sizeof(struct abc));
  printf("\nEnter data\n");
  scanf("%d",&temp->data);
  temp->next=NULL;
  temp->prv=NULL;
  while(head!=NULL && head->next!=NULL){
    head=head->next;
  }
  temp->prv=head;
  head->next=temp;

  printf("\n Data after inserting at end");
  display(head);
}

void insertStart(struct abc*head){
  struct abc *temp;
  temp=(struct abc*)malloc(sizeof(struct abc));
  printf("\nEnter data\n");
  scanf("%d",&temp->data);
  temp->next=head;
  head->prv=temp;
  temp->prv=NULL;
  head=temp;

  printf("\n Data after inserting at start");
  display(head);

}

void deleteStart(struct abc* head){
  struct abc *p;
  p=head;
  head=head->next;
  head->prv=NULL;
  free(p);

  printf("\n Data after deleting first node: ");
  display(head);
}

void deleteMiddle(int a, struct abc*head){
  struct abc *temp,*p,*q;
  q=head;
  while(a!=head->data){
    head = head->next;
  }
  p=head->next;
  p->next=q->next;
  temp=p->next;
  temp->prv=p;
  free(q);

  printf("\n Data after deleting at middle");
  display(temp);
}

void deleteEnd(struct abc* head){
  struct abc *temp;
  temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->prv->next =NULL;
  temp->prv=NULL;
  free(temp);

  printf("\n Data after deleting at end");
  display(head);
}

void reverse(struct abc*head){
  struct abc *temp,*current,*last;
   current=head;
  while(head->next==NULL){
    last=head;
  }
  while(current!=NULL){
    temp=current->next;
    current->next=current->prv;
    current->prv=temp;
    current=temp;
  }
  temp=head;
  head=last;
  last=temp;

  printf("\n Reverse list is: ");
  display(head);
}


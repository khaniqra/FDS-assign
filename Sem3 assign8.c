/*A154 Iqra Khan Assign 8
The first node is reserved for the president of the club
and the last node is reserved for the secretary of the club. Write C program to maintain club
member’s information using a singly linked list. Store student PRN and Name. Write functions to
a) Add and delete the members as well as the president or even secretary.
b) Compute the total number of members of the club
c) Display members of the club
Display list in reverse order using recursion*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct abc* create();
void addM(int,struct abc*);
void display(struct abc*);
void addS(struct abc*);
struct abc* deleteP(struct abc*);
struct abc* deleteMid(int,struct abc*);
void deleteS(struct abc*);
struct abc* reverse(struct abc*);
int total(struct abc*);

struct abc{
  int prn, rollno;
  char name[20];
  struct abc*next;
};

int main() {
  struct abc *head,*temp,*temp1,*temp2;
  int ch,m,a,n;
  char p;
  do{
    printf("Enter your choice:\n1.Add President\n2.Add members\n3.Add Secretory\n4.Display\n5.Delete President\n6.Delete member\n7.Delete secretary\n8.Total members\n9.Reverse list\n");
    scanf("%d",&ch);
      switch(ch)
      {
      case 1: head=create();
                break;
      case 2: printf("Enter number of members: ");
              scanf("%d",&m);
              addM(m,head);
              break;
      case 4:display(head);
              break;
      case 3:addS(head);
              break;
      case 6:printf("Enter the roll no you have to delete:");
            scanf("%d",&a);
            temp1=deleteMid(a,head);
            display(temp1);
            break;
      case 5:temp=deleteP(head);
           printf("\n Data after deleting first node: \n");
           display(temp);
             break;
      case 7:deleteS(head);
            break;
      case 8:n=total(head);
            printf("%d\n",n);
            break;
      case 9:head=reverse(head);
              break;
   
      default:printf("Exit");
      }
    printf("Do you want to continue(y/n): ");
    scanf("%s",&p);
  }while(p=='y');
}

struct abc* create(){
  struct abc *temp;
   char n[20];
  temp=(struct abc*)malloc(sizeof(struct abc));
  printf("Enter the PRN, roll no and name of President\n");
  scanf("%d%d%s",&temp->prn,&temp->rollno,n);
  strcpy(temp->name,n);
  return temp;
}

void display(struct abc* head){
  printf("PRN \t Roll no \t Name \n");
  while(head!=NULL)
  {
    printf("%d\t",head->prn);
     printf("%d\t",head->rollno);
      printf("%s\n",head->name);
    head=head->next;
  }
}

void addM(int m,struct abc* head){
  struct abc *temp;
  char n[20];
  for(int i=0; i<m;i++){
    temp=(struct abc*)malloc(sizeof(struct abc));
    printf("Enter the PRN, roll no and name of Member\n");
    scanf("%d%d%s",&temp->prn,&temp->rollno,n);
    strcpy(temp->name,n);
    temp->next=NULL;
    head->next=temp;
    head=head->next;
  }
}

void addS(struct abc*head){
  struct abc* temp;
  char n[20];
  temp=(struct abc*)malloc(sizeof(struct abc));
  printf("Enter the PRN, roll no and name of Secretory\n");
  scanf("%d%d%s",&temp->prn,&temp->rollno,n);
  strcpy(temp->name,n);
  while(head!=NULL && head->next!=NULL) /*head->next != NULL so that we don't go out of loop and we understand that this is the last node after which we need to add secretary*/
    {
      head=head->next;
    }
head->next=temp;
}

struct abc* deleteP(struct abc* head){
  struct abc *p;
  p=head;
  head=head->next;
  free(p);
  return head;

}

struct abc* deleteMid(int a, struct abc*head){
  struct abc *q;
  //q=head;
  while(head->rollno!=a){
    q=head;
    head = head->next;
  }
  //p=head->next;
  q->next=head->next;
  free(head);
  return q;
}

void deleteS(struct abc*head){
 struct abc *p,*q;
  /*head!=NULL, we go to empty space i.e head will go out of loop so we won't delete secreatary therefore we need head->next!=NULL i.e. we go till last node only*//*we require both the conditions bcuz using only head->next!=NULL dels the data but doesn't free the*/
  p=q=head;
  while(p->next!=NULL){
    q=p;
    p=p->next;
  }
  free(p);
  q->next=NULL;
  display(head);
}

struct abc* reverse(struct abc*head){
  struct abc *p,*q;
  p=head;
  q=head;
  p->next=NULL;
  head=head->next;
  q=head;
  while(head!=NULL){
    head=head->next;
    q->next=p;
    q=head;
    p=q;
    q=head;
  }
  //display(p);
  return p;
}

int total(struct abc*head){
  int k=0;
  while(head->next!=NULL){
    k++;
    head=head->next;
  }
  return k;
}
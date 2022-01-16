/*A154 Iqra Khan Assign 7
Implement Circular Queue using Array. Perform following operations on it. a) Insertion (Enqueue) b) Deletion (Dequeue) Display*/

#include <stdio.h>
#include <stdlib.h>

void enqueue(int* queue, int e,int s);
void dequeue(int* queue,int s);
void display(int* queue,int s);
int isempty();
int isfull(int s);

int f=-1,r=-1;

int main(void) {
  int size,n;
  printf("Enter size of Queue: ");
  scanf("%d",&size);
  int queue[size];
  printf("\nOperations on Queue\n");
  int ch=0;
  while(ch!=6){
    printf("\n\n1. Insert an element in queue \n2. Delete an element from queue\n3. Display entier queue\n4. Check wether queue is full\n5. Check wether queue is empty\n6. Exit");
    printf("\nEnter Your Choice  : ");
    scanf("%d",&ch);
    switch(ch){
      case 1:
       printf("\nEnter number: ");
       scanf("%d", &n);
       enqueue(queue, n,size);
      break;
      case 2:
        dequeue(queue,size);
      break;
      case 3:
        display(queue,size);
      break;
      case 4:
        if(isfull(size)==1)
        printf("Queue is Full");
        else 
        printf("Queue is not full");
      break;
      case 5:
        if(isempty()==1)
        printf("Queue is Empty");
        else 
        printf("Queue is not Empty");
      break;
    }

  }
  return 0;
}

int isempty(){
if(f==-1 && r==-1){
  return 1;
}
else
return 0;
}

int isfull(int s){
  if((r+1)%s==f){
    return 1;
  }
  else
  return 0;
}

void enqueue(int* queue, int e,int s){
if(isfull(s) ==1)
{
  printf("Queue is full");
}
else if(isempty()){
r++;
f++;
queue[r]=e;
printf("%d inserted successfully",e);
}

else{
  r=(r+1)%s;
  queue[r]=e;
  printf("%d inserted successfully",e);
}

}

void dequeue(int* queue,int s){

  if (isempty()==1){
    printf("Queue is empty");
  }
  else if(f==r){
    printf("\n %d is deleated",queue[f]);
    f=-1;
    r=-1;
  }
  else{
    printf("\n %d is deleated",queue[f]);
    f=(f+1)%s;
  }
}

void display(int* queue,int s){

printf("\n");
if(f>r)
{
  for(int i=0;i<s;i++){
    printf("%d ",queue[i]);
  }
  for(int i=0;i<r-1;i++){
    printf("%d ",queue[i]);
  }
}
else{
  for(int i=f; i<=r;i++){
    printf("%d ",queue[i]);
  }
}
}
/*Iqra Khan A154 Assign 2
Represent sets using one dimensional arrays and implement functions to perform 1.Union 2.Intersection 3.Difference 4.Symmetric Difference of two sets */

#include <stdio.h>

int union_set(int a[],int b[], int c[], int n1, int m1);
int intersection(int a[],int b[], int c[], int n1, int m1);
int difference(int a[],int b[], int c[], int n1, int m1);
void symmetric(int a[],int b[], int c[],int n1,int m1);
void display(int a[], int n);

int main() {

  int a[100], b[100], c[100];
  int ch, n1, m1,n;

  //create
      printf("Plz enter the no of elements in set A: ");
      scanf("%d",&n1);
      printf("Plz enter the elements in set A: ");
      for(int i = 0; i < n1; i++) {
       scanf("%d", &a[i]);
       }

      printf("Plz enter the no of elements in set B: ");
      scanf("%d",&m1);
      printf("Plz enter the elements in set B: ");
       for(int i = 0; i < m1; i++) {
         scanf("%d", &b[i]);
       }

       printf("The elements of set A are:");
       printf("{");
        for(int i = 0; i < n1; i++) {
       printf("\t  %d", a[i]);
        }
         printf("\t }");
       
        printf("\nThe elements of set B are:");
       printf("{");
        for(int i = 0; i < m1; i++) {
       printf("\t  %d", b[i]);
        }
         printf("}");

  printf("\nEnter a choice:\n 1.Union\n 2.Intersection\n 3.Difference\n 4.Symmetric Difference\n");
  scanf("%d",&ch);

  switch(ch){
    case 1: n=union_set(a,b,c,n1,m1);
            display(c,n);
      break;
    case 2: n=intersection(a,b,c,n1,m1);
            display(c,n);
      break;
    case 3: difference(a,b,c,n1,m1);
      break;
    case 4: symmetric(a,b,c,n1,m1);
      break;
    default: printf("Plz enter correct choice");
  }
  return 0;
}

int union_set(int a[],int b[], int c[],int n1, int m1){
   int k=0;
   int q;

   for(int i=0;i<n1;i++)
   {
     c[k]=a[i];
     k++;
   }
   for(int i=0; i<n1; i++)
   {
     q=1;
     for(int j=0; j<m1; j++)
     {
       if(b[i]==a[j])
       {
         q=0;
         break;
       }
     }
     if(q==1)
     {
       c[k]=b[i];
       k++;
     }
   }

    return k;
   }

int intersection(int a[],int b[], int c[], int n1, int m1)
 {
    int k=0;
    int q;

    for(int i=0; i<n1; i++)
   {
     q=0;
     for(int j=0; j<m1; j++)
     {
       if(b[i]==a[j])
       {
         q=1;
         break;
       }
     }
     if(q==1)
     {
       c[k]=b[i];
       k++;
     }
   }
  return k;
}

void display(int a[], int n){
   printf("The elements of set C are:");
       printf("{");
        for(int i = 0; i< n; i++) {
       printf("\t  %d", a[i]);
        }
         printf("\t }");
}

int difference(int a[],int b[], int c[], int n1, int m1){
   int k=0;
    int q,e=0;
    int d[10];

    for(int i=0; i<n1; i++)
   {
     q=1;
     for(int j=0; j<m1; j++)
     {
       if(a[i]==b[j])
       {
         q=0;
         break;
       }
     }
     if(q==1)
     {
       c[k]=a[i];
       k++;
     }
   }
   printf("The elements of set A-B are:");
       printf("{");
        for(int i = 0; i< k; i++) {
       printf("\t  %d", c[i]);
        }
         printf("\t }");

  for(int i=0; i<n1; i++)
   {
     q=1;
     for(int j=0; j<m1; j++)
     {
       if(b[i]==a[j])
       {
         q=0;
         break;
       }
     }
     if(q==1)
     {
       d[e]=b[i];
       e++;
     }
   }
   printf("\nThe elements of set B-A are:");
       printf("{");
        for(int i = 0; i< e; i++) {
       printf("\t  %d", d[i]);
        }
         printf("\t }");

  return k;

}
void symmetric(int a[],int b[], int c[], int n1, int m1){
  int k=0,f=0,y=0;
   int r;
   int d[10];
   int z[10];

  //union
  k=union_set(a, b, c, n1, m1);
  
    //intersection
 y= intersection(a, b, d, n1, m1);
  
    //symmetric difference
    for(int i=0; i<k; i++)
   {
     r=1;
     for(int j=0; j<y; j++)
     {
       if(c[i]==d[j])
       {
         r=0;
         break;
       }
     }
     if(r==1)
     {
       z[f]=c[i];
       f++;
     }
   }

    printf("The symmetric difference is:");
       printf("{");
        for(int i = 0; i< f; i++) {
       printf("\t  %d", z[i]);
        }
         printf("\t }");


}
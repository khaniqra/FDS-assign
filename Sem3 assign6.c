/* Iqra Khan A154 Assign 6
Implement a sparse matrix with operations like initialize empty sparse matrix, insert an element, add two matrices, transpose a matrix.
*/
#include <stdio.h>

int main() {
  void sparse();
  void addition();
  void simple_tr();
  void sparse_tr();
  int n;

do{
  printf("Enter an option:\n1.Sparse matrix.\n2.Addition\n3.Sparse Transpose\n4.Simple Transpose\n5.Exit\n");
  scanf("%d",&n);

  switch(n){
    case 1: sparse();
          break;
    case 2: addition();
          break;
    case 3: sparse_tr();
          break;
    case 4: simple_tr();
          break;
    default : printf("Plz enter valid choice.");
  }
}while(n!=5);
}

void sparse(){
  int a[50][50], b[50][50];
  int r,c,i,j,k,p;
   printf("Enter no of rows and cols: ");
   scanf("%d",&r);
   scanf("%d",&c);
   printf("Enter elements of array: ");

   for(i=0;i<r;i++)
   {
     for(j=0;j<c;j++)
     {
       scanf("%d",&a[i][j]);
     }
   }

   printf("\nThe elements of the matrix are:\n");
    for(i=0;i<r;i++)
   {
     for(j=0;j<c;j++)
     {
       printf("%d\t",a[i][j]);
     }
     printf("\n");
   }

   //Triplet representation of sparse matrix
   for(i=0;i<r;i++)
   {
     for(j=0;j<c;j++)
     {
       if(a[i][j]!=0)
       {
         k++;
       }
     }
   }
   for(i=0;i<3;i++)
  {
    for(j=0;j<k;j++)
    {
      if(a[i][j]!=0)
      {
        b[0][p]=i;
        b[1][p]=j;
        b[2][p]=a[i][j];
        p++;
      }
    }
  }
  printf("The 3 row matrix is:\n");
  for(i=0;i<r;i++)
  {
    for(j=0;j<k;j++)
    {
      printf("%d\t",b[i][j]);
    }
    printf("\n");
  }
}

void addition()
{

  int a1[50][3], a2[50][3],c[50][3];
  int r1,c1,v1,r2,c2,v2;
  int i=1,j=1,k=0;

  printf("Enter no  of r1, c1 and v1: ");
  scanf("%d %d %d",&r1,&c1,&v1);
  a1[0][0]=r1;
  a1[0][1]=c1;
  a1[0][2]=v1;
  for(int i=1;i<=v1;i++){
    scanf("%d %d %d",&a1[i][0],&a1[i][1],&a1[i][2]);
  }

  printf("Enter no  of r2, c2 and v2: ");
  scanf("%d %d %d",&r2,&c2,&v2);
  a2[0][0]=r2;
  a2[0][1]=c2;
  a2[0][2]=v2;
  for(int i=1;i<=v2;i++){
    scanf("%d %d %d",&a2[i][0],&a2[i][1],&a2[i][2]);
  }
  if((a1[0][0]!=a2[0][0])&&(a1[0][1]!=a2[0][1])){
    printf("Not allowed to add");
  }

  while(i<=v1 && j<=v2){
    if(a1[i][0]<a2[j][0]){
      c[k][0]=a1[i][0];
      c[k][1]=a1[i][1];
      c[k][2]=a1[i][2];
      i++;
      k++;
    }
    else if(a1[i][0]>a2[j][0]){
      c[k][0]=a2[j][0];
      c[k][1]=a2[j][1];
      c[k][2]=a2[j][2];
      j++;
      k++;
    }
     else if(a1[i][1]>a2[j][1]){
      c[k][0]=a2[j][0];
      c[k][1]=a2[j][1];
      c[k][2]=a2[j][2];
      j++;
      k++;
    }
     else if(a1[i][1]<a2[j][1]){
      c[k][0]=a1[i][0];
      c[k][1]=a1[i][1];
      c[k][2]=a1[i][2];
      i++;
      k++;
    }
    else
    {
      c[k][0]=a1[i][0];
      c[k][1]=a1[i][1];
      c[k][2]=a1[i][2]+a2[j][2];
      i++;
      j++;
      k++; 
    }
  }
  while(i<=v1){
     c[k][0]=a1[i][0];
      c[k][1]=a1[i][1];
      c[k][2]=a1[i][2];
      i++;
      k++;
  }  
  while(j<=v2){
      c[k][0]=a2[j][0];
      c[k][1]=a2[j][1];
      c[k][2]=a2[j][2];
      j++;
      k++;
  }
  printf("The resultant matrix is:\n");
  for(i=0;i<k;i++)
  {
    for(j=0;j<3;j++)
    {
      printf("%d\t",c[i][j]);
    }
    printf("\n");
  }
  }

void sparse_tr(){
 int A[10][10], B[10][10], total[10],index[10], m,n,v,col,p;

 printf("Enter the rows, cols and values of matrix A: ");
 scanf("%d %d %d",&m,&n,&v);
 printf("\nEnter the Triplet matrix: ");
 for(int i=1;i<=v;i++)
   {
     scanf("%d%d%d",&A[i][0],&A[i][1],&A[i][2]);
   }
 printf("Matrix A in triplet form is\n");
 printf("Rows\t Cols\t Values\n");
 for(int i=1;i<=v;i++)
   {
     printf("\n%d\t%d\t%d",A[i][0],A[i][1],A[i][2]);
   }
 for(int i=0;i<n;i++)
   {
     total[i]=0;
   }
   for(int i=1; i<n;i++)
   {
     col=A[i][1];
     total[col]++;
   }
   index[0]=1;
   for(int i=1; i<n;i++)
   {
     index[i]=index[i-1]+total[i-1];
   }
  for(int i=1;i<=v;i++){
    col=A[i][1];
    p=index[col];
    index[col]++;
    B[p][0]=A[i][1];
    B[p][1]=A[i][0];
    B[p][2]=A[i][2];
  }
printf("The Sparse Transpose is: ");
  for(int i=0;i<p;i++)
  {
    for(int j=0;j<3;j++)
    {
      printf("%d\t",B[i][j]);
    }
    printf("\n");
  }
}
void simple_tr()
{
  int A[10][10], B[10][10], total[10],index[10], m,n,v,col,p=1;

 printf("Enter the rows, cols and values of matrix A: ");
 scanf("%d %d %d",&m,&n,&v);
 printf("\nEnter the Triplet matrix: ");
 for(int i=1;i<=v;i++)
   {
     scanf("%d%d%d",&A[i][0],&A[i][1],&A[i][2]);
   }
 printf("Matrix A in triplet form is\n");
 printf("Rows\t Cols\t Values\n");
 for(int i=1;i<=v;i++)
   {
     printf("\n%d\t%d\t%d",A[i][0],A[i][1],A[i][2]);
   }
   for(int i =0; i<n;i++){
     for(int j=1;j<=v;j++){
       if(A[i][j]==i){
         B[p][0]=A[j][1];
         B[p][1]=A[j][0];
         B[p][2]=A[j][2];
         p++;
       }
     }
   }
   printf("\nThe Simple Transpose is: \n");
  for(int i=0;i<=p;i++)
  {
    for(int j=0;j<3;j++)
    {
      printf("%d\t",B[i][j]);
    }
    printf("\n");
  }
}


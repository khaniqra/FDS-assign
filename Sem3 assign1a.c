//To simulate a simple calculator that performs basic tasks such as addition, subtraction,multiplication, and division.

#include <stdio.h>


int main()
{
  char operator;
  float n1,n2;
 
  printf("Enter an operator (+,-,*,/):\n");
  scanf("%c",&operator);
  printf("Enter two operands: ");
  scanf("%f %f",&n1,&n2);

  switch(operator)
  {
    case '+':
      printf("%.1f+%.1f = %.1f",n1,n2,n1+n2);
      break;
    case '-':
      printf("%.1f-%.1f =%.1f",n1,n2,n1-n2);
      break;
    case '*':
      printf("%.1f*%.1f=%.1f",n1,n2,n1*n2);
      break;
    case '/':
      if(n2==0){
        printf("Invalid operation");
      }
      else{
      printf("%.1f/%.1f=%.1f",n1,n2,n1/n2);
      }
      break;
    default:
      printf("Invalid operator");
    
  }
   printf("\nThank You!!!");
 
 return 0;
}
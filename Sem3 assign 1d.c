/*Sem3 assign1d
Accept a string and change the case of the string.*/

#include<stdio.h>
void change(char *s);
int main()
{
    char s[100];
    printf("Enter any string:\n ");
    gets(s);
    change(s); 
    return 0;
}
void change(char *s)
{
  int i=0;
  while(s[i]!='\0')
 {
   if(s[i]>='A' && s[i]<='Z')
   {
     s[i]+=32;
   }
   else if(s[i]>='a' && s[i]<='z')
   {
     s[i]-=32;
   }
     i++;
  }
  printf("Case changed: %s",s);  
}
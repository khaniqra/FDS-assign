/*Accept the string from the user and perform the followig operations i.Calculate the length of the string ii.String reversal iii.Equality check of two string iv.Check palindrome v.Check substring(Pointer to string)*/

#include <stdio.h>
#include<string.h>
int len(char *str)
{
  int count = 0, i = 0;
  while (str[i] != '\0')
    {
       i++;
       count++;
    }
   return count;
}
void length(char *str){
  printf("Length of string: %d\n",len(str));
}
void reverse(char *str)
{
    for (int i = len(str) - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}
void substring(int a, int b, char *str)
{
    for (int i = a; i <= b; i++)
    {
        printf("%c", str[i]);
    }
}
void compare(char *str, char *str2)
{
    int f = 1;
    for (int i = 0; i < len(str); i++)
    {
        if (str[i] != str2[i])
        {
            f = 0;
        }
    }
    if (f)
    {
        printf("Strings are identical");
    }
    else
        printf("Strings are not identical");
}
void palindrome(char *str)
{
    char str2[100];
    int f = 1;
    for (int i = 0; i < len(str); i++)
    {
        if (str[i] != str[len(str) - 1 - i])
        {
            f = 0;
        }
    }
    if (f)
    {
        printf("The string is palindrome");
    }
    else
    {
        printf("Entered string is not palindrome");
    }
}
int main()
{
    int p,q,m;
    int operation;
    char str[1000], str2[1000];

    Start:
    printf("Enter a string\n");
    scanf("%s", str);
    length(str);
    printf("Choose a operation\n");
    printf("1.Substring\n2.Palindrome\n3.Compare\n4.Reverse\n");
    scanf("%d", &operation);
    switch (operation)
    {
    case 1:
        printf("Enter start and end point of substring\n");
        scanf("%d %d", &p, &q);
        substring(p, q, str);
        printf("\nDo you want to continue?: 1/0\n");
        scanf("%d",&m);
        if(m){
          goto Start;
        }
        else {
          goto End;
        }
        break;
    case 2:
        palindrome(str);
        printf("\nDo you want to continue?: 1/0\n");
        scanf("%d",&m);
        if(m){
          goto Start;
        }
        else {
          goto End;
        }
        break;
    case 3:
        printf("Enter string to be compared\n");
        scanf("%s", str2);
        compare(str, str2);
        printf("\nDo you want to continue?: 1/0\n");
        scanf("%d",&m);
        if(m){
          goto Start;
        } 
        else {
          goto End;
        }     
        break;
    case 4:
        reverse(str);
        printf("\nDo you want to continue?: 1/0\n");
        scanf("%d",&m);
        if(m){
          goto Start;
        }
        else {
          goto End;
        }
    default:
        printf("Plz Select from above operations\n");
    }
  End:
    printf("\nThank You");

    return 0;
}

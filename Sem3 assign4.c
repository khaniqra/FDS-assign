/* A154 Assign 4 
Write a Menu driven program in C for a cricket player’s display board. The information of the
cricketer can be (not limited to) Name, Age, Country, Category (Batsman, Bowler, Wicket keeper,
All-rounder), Number of ODI’s played, Number of International 20-20’s played. Display
following.
a) Number of batsman of a particular country
b) Sort the Batsman as per the average batting score(Bubble/insertion sort)
c) Batsman with highest average score (Binary search)
d) Number of bowlers of a particular country
e) The bowler that has taken a maximum no of wickets
f) Show particular players the entire “Display board information”
Delete/Modify the record
*/
#include <stdio.h>
#include <string.h>

struct cricket{
  char name[10];
  int age;
  char country[10];
  int wickets;
  int match_played;
  int avg_score;
  char type_of_player[10];
}c[25];

int main() {
  void accept(struct cricket c[25], int n);
  void display(struct cricket c[25], int n);
  void linear(struct cricket c[25], int n, char country_name[20], char category[20]);
  void info(struct cricket c[25], int n, char player_name[20]);
  void sort(struct cricket c[25], int n,int avge[]);
  void highest(struct cricket c[25], int n);
  void maxwic(struct cricket c[25], int n);

  int i,n,ch,b;
  char country_name[20];
  char category[20];
  char player_name[20];
  int avge[n];

  do{
    printf("\n1.Accept the information.\n2.Display the information.\n3.Search.\n4.Players Information.\n5.Order of batting average score.\n6.Highest score.\n7.Max Wickets\n8.Exit\n");
    printf("Enter your choice:- ");
    scanf("%d",&ch);
    switch (ch) {
    case 1:  printf("\nEnter the number of records:");
        scanf("%d", &n);
        accept(c, n);
        break;
    case 2: display(c, n);
        break;
    case 3:  printf("\nPlz enter the country name : ");
    scanf("%s",country_name);
         printf("\nPlz enter the category : ");
    scanf("%s",category);
        linear(c,n,country_name,category);
        break;
    case 4: printf("\nPlz enter the name of Player : ");
    scanf("%s",player_name);
        info(c,n,player_name);
        break;
    case 5: printf("\n Order of Batting Average is: ");
         sort(c,n,avge);
         break;
    case 6: printf("\n Batsman with highest batting average is: ");
         highest(c,n);
         break;
    case 7: printf("\nBowler with Highest Wickets is: ");
        maxwic(c,n);
    }
  }while(ch!=8);
}

  void accept(struct cricket c[5], int n)
  {
    int i;
    for(i=0;i<n;i++)
    {
      printf("\nEnter the name of the player:");
      scanf("%s",c[i].name);
      printf("\n Enter the category of player: Batsman, Bowler, wicket keeper, All rounder\n");
      scanf("%s",c[i].type_of_player);
      printf("\nEnter the country of player: ");
      scanf("%s",c[i].country);
      printf("\nEnter the age of player: ");
      scanf("%d",&c[i].age);
      printf("\nEnter the number of matches played: ");
      scanf("%d",&c[i].match_played);
      printf("\nEnter the no of wickets taken: ");
      scanf("%d",&c[i].wickets);
      printf("\nEnter the average score of player: ");
      scanf("%d",&c[i].avg_score);
      }
    
  }

  void display(struct cricket c[25], int n){
    int i;
    printf("\nSr. No. \tName\tCategory\tCountry\tAge\tTotal matches\tTotal wickets");
    for (i=0; i<n; i++) {
    printf("\n%d.\t",i+1);
    printf("%s\t",c[i].name);
    printf("%s\t",c[i].type_of_player);
    printf("%s\t",c[i].country);
    printf("%d\t",c[i].age);
    printf("%d\t",c[i].match_played);
    printf("%d\n",c[i].wickets);

    }
    
  }

  void linear(struct cricket c[25], int n, char country_name[20], char category[20]){

    int player = 0;

    for(int i=0;i<n;i++)
    {
      if(strcmp(c[i].country, country_name) ==0 && strcmp(c[i].type_of_player, category) == 0){

        printf("\n%s\n",c[i].name);
        player++;
      }
    }
    printf("\nNo. of %s in %s : %d", category,country_name,player);

    if(player==0)
    {
      printf("\nNo %s from %s",category,country_name);
    }
  }

void info(struct cricket c[25], int n, char player_name[20]){
  int player=0;

  printf("\nDisplay board information\n");
  for(int i =0;i<=n;i++){
   
    if(strcmp(c[i].name,player_name)==0){
     player=1;
    printf("Name: %s\n",c[i].name);
    printf("Type of player: %s\n",c[i].type_of_player);
    printf("Country: %s\n",c[i].country);
    printf("Age: %d\n",c[i].age);
    printf("Matches played: %d\n",c[i].match_played);
    printf("Wicket taken: %d\n",c[i].wickets);

    }
  }
  if(player==0){
  printf("There is no %s in records",player_name);
  }
}

void sort(struct cricket c[25] , int n ,int avge[]){
  int i ,j,temp,count=0;

  for(int i=0; i<n; i++){
     avge[i]=c[i].avg_score;
  }
    for (i = 1; i < n; i++) {
        temp = avge[i];
        j = i - 1;

        while (j >= 0 && avge[j] >temp) {
            avge[j + 1] = avge[j];
            j = j - 1;
        }
        avge[j + 1] = temp;
    }

for(int i=n-1; i>=0; i--){
    for(int j=0; j<n; j++){
        if(avge[i]==c[j].avg_score){
            count++;
            printf("\n %d) %s",count,c[j].name);
        }
    }
}
}

void highest(struct cricket c[25], int n){
  int highestavg=c[0].avg_score;

  for(int i=1; i<n;i++){
    if(c[i].avg_score>highestavg){
      highestavg=c[i].avg_score;
    }
  }
  for(int j=0;j<n;j++){
    if(c[j].avg_score==highestavg){
      printf("%s",c[j].name);
    }
  }
}
void maxwic(struct cricket c[25], int n){
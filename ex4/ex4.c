#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

bool c[13][4];
typedef struct card{
  int rank;
  int suit;
} card_t;

card_t makeCard(int x, int y);
card_t distributeCard();
char *cardRank(int x);
char *cardSuit(int y);
void printCard(card_t *player);
void sep();

int main(){
  card_t player1[13],player2[13],player3[13],player4[13];
  srand(time(0));
  memset(c, false, sizeof(c[0][0]) * 13 * 4);
  for (int i = 0; i < 13; i++){
    player1[i] = distributeCard();
    player2[i] = distributeCard();
    player3[i] = distributeCard();
    player4[i] = distributeCard();
  }
  printf("Nguoi choi thu 1 co: \n");
  printCard(player1);
  printf("Nguoi choi thu 2 co: \n");
  printCard(player2);
  printf("Nguoi choi thu 3 co: \n");
  printCard(player3);
  printf("Nguoi choi thu 4 co: \n");
  printCard(player4);
  return 0;
}

card_t distributeCard(){
  int n = rand() % 52;
  int x = n / 4;
  int y = n % 4;
  while (c[x][y] == true){
    if (n == 51)
      n = 0;
    else
      n++;  
    x = n / 4;
    y = n % 4;
  }
  c[x][y] = true;
  return makeCard(x,y);
}

card_t makeCard(int x, int y){
  card_t newCard;
  newCard.rank = x;
  newCard.suit = y;
  return newCard;
}

char *cardRank(int x){
  switch (x){
    case 0:
      return "A";
    case 1:
      return "2";
    case 2:
      return "3";
    case 3:
      return "4";
    case 4:
      return "5";
    case 5:
      return "6";
    case 6:
      return "7";
    case 7:
      return "8";
    case 8:
      return "9";
    case 9:
      return "10";              
    case 10:
      return "J";
    case 11:
      return "Q";
    case 12:
      return "K";      
  }
}

char *cardSuit(int y){
  switch(y){
    case 0:
      return "co";
    case 1:
      return "ro";
    case 2:
      return "bich";
    case 3:
      return "tep";      
  }
}

void printCard(card_t player[]){
  for (int i = 0; i < 13; i++){
    char *cRank = cardRank(player[i].rank);
    char *cSuit = cardSuit(player[i].suit);
    printf("%s %s, ",cRank,cSuit);
  }
  printf("\n");
  int cardCount[13];
  memset(cardCount,0,sizeof(int) * 13);
  for (int i = 0; i < 13; i++){
    cardCount[player[i].rank]++;
  }
  for (int j = 0; j < 13; j++){
    if (cardCount[j] < 4)
      continue;
    printf("Nguoi choi co tu quy %s\n",cardRank(j));  
  }  
  sep();
}

void sep(){
  for (int i = 0; i < 100; i++){
    printf("-");
  }
  printf("\n\n");
}
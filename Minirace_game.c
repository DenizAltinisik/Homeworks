#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMap(char a[15][30]){
int i,j;
for(i=0;i<15;i++){
	for(j=0;j<30;j++)  {
	
	if(a[i][j] == '1'){
	printf("\033[0;33m");
	printf("%c",a[i][j]); 	
	printf("\033[0m");
	}
	else if(a[i][j] == '2'){
	printf("\033[0;34m");
	printf("%c",a[i][j]); 	
	printf("\033[0m");
	}
	else if(a[i][j] == 'X'){
	printf("\033[0;31m");
	printf("%c",a[i][j]); 	
	printf("\033[0m");
	}
	else if(a[i][j] == '_'){
	printf("\033[0;32m");
	printf("%c",a[i][j]); 	
	printf("\033[0m");
	}
	else printf("%c",a[i][j]); 	
 }
 printf("\n");
 }	
}


int dice(){
	int k;
	k = rand() % 6 + 1;
	return k;
}

int startGame(int a, int b){
	
		if(a>b) return 1; // player 1 starts
		else if(a<b) return 2; // player 2 starts
		else if(a==b) return 0;

}

int main() {
char c; // for getchars
srand(time(NULL));
char playground[15][30];

int place_x=1,place_y=1,dice1,dice2,finish1=0,finish2=0,place_x2=3,place_y2=3;

int i,j;
for(i=0;i<15;i++){
	
	for(j=0;j<30;j++){
		if(i==0 || i==14 || ( (i==2 || i==12) && j>=2 && j<=27) || ( (i==4 || i==10) && j>=4 && j<=25)){
		playground[i][j]='-';
		}
		else if( ((j==0 || j==29) && i!=0 && i!=14 ) || ( (i>=3 && i<=11) && (j==2 || j==27) ) || ((i>=5 && i<=9) && (j==4 || j==25) ) ){
		playground[i][j]='|';
		}
		else if( (i==1 && j==14) || (i==7 && j==28 ) || (i==13 && j==14 ) || (i==13 && j==14 )|| (i==3 && j==10 )|| (i==3 && j==18 )|| (i==5 && j==26 )|| (i==10 && j==26 )|| (i==11 && j==10 ) || (i==11 && j==18 )){
		playground[i][j]='X';	// penalty point
		}
		else if( (i==2 && j==1) || (i==4 && j==3) ){ // finish line
		playground[i][j]='_';
		}
		else if(i==1 && j==1){
			playground[i][j]='1';
		}
		else if(i==3 && j==3){
			playground[i][j]='2';
		}
		else{
	    	playground[i][j]=' ';
		}
		
		}  // race track without players
}
printMap(playground);
printf("\nTo start the game, player should dice and decide who is going to start first according to it...\n");
do{
printf("\033[0;33m");
printf("Player 1... Press ENTER to dice\n");
c = getchar();
dice1=dice();
printf("DICE= %d\n",dice1);
printf("\033[0m");
printf("\033[0;34m");
printf("Player 2... Press ENTER to dice\n");
c = getchar();
dice2=dice();
printf("DICE= %d\n",dice2);
printf("\033[0m");
if(dice1 == dice2) printf("Same dice value... Please try again...\n");
else if(dice1 > dice2){
	printf("\n\nPLAYER 1 STARTS!\n");
     }
else printf("\n\nPLAYER 2 STARTS!\n");
}while(startGame(dice1,dice2)==0);
int decide = startGame(dice1,dice2);
dice1=0;
dice2=0;
while(1){ // game starts here	
int i,j;
for(i=0;i<15;i++){
	
	for(j=0;j<30;j++){
		if(i==0 || i==14 || ( (i==2 || i==12) && j>=2 && j<=27) || ( (i==4 || i==10) && j>=4 && j<=25)){
		playground[i][j]='-';
		}
		else if( ((j==0 || j==29) && i!=0 && i!=14 ) || ( (i>=3 && i<=11) && (j==2 || j==27) ) || ((i>=5 && i<=9) && (j==4 || j==25) ) ){
		playground[i][j]='|';
		}
		else if( (i==1 && j==14) || (i==7 && j==28 ) || (i==13 && j==14 ) || (i==13 && j==14 )|| (i==3 && j==10 )|| (i==3 && j==18 )|| (i==5 && j==26 )|| (i==10 && j==26 )|| (i==11 && j==10 ) || (i==11 && j==18 )){
		playground[i][j]='X';	// penalty point
		}
		else if( (i==2 && j==1) || (i==4 && j==3) ){ // finish line
		playground[i][j]='_';
		}
		else{
	    	playground[i][j]=' ';
		}
		
		}  // race track without player numbers	
}

if(place_x==1){ // for north of track, dice changes the column and at the corner, row, if necessary
	
	place_y = place_y + dice1;
	if(place_y<=28){
	
	
	playground[place_x][place_y]='1';
	
	}
	else if(place_y>28){
	place_x = place_y - 27;
	place_y = 28;
	playground[place_x][place_y]='1';	
	}
}

else if(place_x<=13 && place_y==28){ // for east way of track, changes row and at the corner, column, if necessary


place_x = place_x + dice1;
if(place_x<=13){
	playground[place_x][place_y]='1';
  }

else if(place_x>13){
	place_y = place_y - (place_x - 13);
	place_x=13;
	playground[place_x][place_y]='1';
}

}

else if(place_y >=1 && place_x==13){ // for south way of track, changes column and at the corner, row, if necessary

	place_y = place_y - dice1;
	if(place_y>=1){
		playground[place_x][place_y]='1';
	finish1++;
	}
	else if(place_y<1){
		place_x = place_x + place_y - 1;
		place_y=1;
		playground[place_x][place_y] = '1';
	} 
}
else if(place_x>=1 && place_y==1){  // for west way of track, changes row and at the corner, column, not necessarily


	place_x= place_x-dice1;
	if(place_x>=1){
		playground[place_x][place_y]='1';
	}
	else if(place_x < 1){ 
		place_y = place_y - (place_x -1);
		place_x=1;
		playground[place_x][place_y]='1';
	}	
}

if(place_x==1 && place_y==14 ){  // PENALTY POINT FOR PLAYER 1
	printf("Penalty for Player 1...\n");
	playground[place_x][place_y]='X';
	playground[place_x][place_y - 2]='1';
	place_y=place_y - 2;
}
if(place_x==7 && place_y==28 ){  // PENALTY POINT FOR PLAYER 1
	printf("Penalty for Player 1...\n");
	playground[place_x][place_y]='X';
	playground[place_x - 2][place_y]='1';
	place_x=place_x - 2;
}
if(place_x==13 && place_y==14 ){  // PENALTY POINT FOR PLAYER 1
	printf("Penalty for Player 1...\n");
	playground[place_x][place_y]='X';
	playground[place_x][place_y + 2]='1';
	place_y=place_y + 2;	
}
// indicating player 1 position

if(place_x2==3){ // PLAYER 2
	
	place_y2 = place_y2 + dice2;
	if(place_y2<=26){ // for north of track, dice changes the column and at the corner, row, if necessary
	
	
	playground[place_x2][place_y2]='2';
	
	}
	else if(place_y2>26){
	place_x2 = place_y2 - 23;
	place_y2 = 26;
	playground[place_x2][place_y2]='2';	
	}
}

else if(place_x2<=11 && place_y2==26){ // for east way of track, changes row and at the corner, column, if necessary


place_x2 = place_x2 + dice2;
if(place_x2<=11){
	playground[place_x2][place_y2]='2';
  }


else if(place_x2>11){
	place_y2 = place_y2 - (place_x2 - 11);
	place_x2=11;
	playground[place_x2][place_y2]='2';
}

}

else if(place_y2 >=3 && place_x2==11){ // for south way of track, changes column and at the corner, row, if necessary
	

	place_y2 = place_y2 - dice2;
	if(place_y2>=3){
		playground[place_x2][place_y2]='2';
	finish2++;
	}
	else if(place_y2<3){
		place_x2 = place_x2 + place_y2 - 3;
		place_y2=3;
		playground[place_x2][place_y2] = '2';
	} 
}
else if(place_x2>=3 && place_y2==3){  // for west way of track, changes row and at the corner, column, not necessarily


	place_x2= place_x2-dice2;
	if(place_x2>=3){
		playground[place_x2][place_y2]='2';
	}
	else if(place_x2 < 3){ 
		place_y2 = place_y2 - (place_x2 -3);
		place_x2=3;
		
		playground[place_x2][place_y2]='2';
	}	
}  // indicating player 2 position
if(place_x2==3 && place_y2==10 ){  // PENALTY POINT FOR PLAYER 2
	printf("Penalty for Player 2...\n");
	playground[place_x2][place_y2]='X';
	playground[place_x2][place_y2 - 2]='2';
	place_y2=place_y2 - 2;
}
if(place_x2==3 && place_y2==18 ){  // PENALTY POINT FOR PLAYER 2
	printf("Penalty for Player 2...\n");
	playground[place_x2][place_y2]='X';
	playground[place_x2][place_y2 - 2]='2';
	place_y2=place_y2 - 2;
}
if(place_x2==5 && place_y2==26 ){  // PENALTY POINT FOR PLAYER 2
	printf("Penalty for Player 2...\n");
	playground[place_x2][place_y2]='X';
	playground[place_x2 - 2][place_y2]='2';	
	place_x2=place_x2 - 2;
}
if(place_x2==10 && place_y2==26 ){  // PENALTY POINT FOR PLAYER 2
	printf("Penalty for Player 2...\n");
	playground[place_x2][place_y2]='X';
	playground[place_x2 - 2][place_y2]='2';
	place_x2=place_x2 - 2;
}
if(place_x2==11 && place_y2==10 ){  // PENALTY POINT FOR PLAYER 2
	printf("Penalty for Player 2...\n");
	playground[place_x2][place_y2]='X';
	playground[place_x2][place_y2 + 2]='2';
	place_y2=place_y2+2;	
}
if(place_x2==11 && place_y2==18 ){  // PENALTY POINT FOR PLAYER 2
	printf("Penalty for Player 2...\n");
	playground[place_x2][place_y2]='X';
	playground[place_x2][place_y2 + 2]='2';	
	place_y2=place_y2+2;
}


printMap(playground);

int check1=0;
int check2=0;
if(place_x<=2 && place_y >= 1 && finish1 != 0){
	check1=1;
}
if(place_x2<=4 && place_y2 >= 3 && finish2 != 0){
	check2=2;
}
if(check1 + check2 == 1){
	printf("\n\n\n*****Player 1 WON THE GAME!*****\n");
	return 0;
}
else if(check1 + check2 == 2){
	printf("\n\n\n*****Player 2 WON THE GAME!*****\n");
	return 0;
}
else if(check1 + check2 == 3){
	if(decide==1){
		printf("\n\n\n*****Player 1 WON THE GAME!*****\n");
		return 0;
	}
	else if(decide==2){
		printf("\n\n\n*****Player 2 WON THE GAME!*****\n");
		return 0;
	}
}

if(decide==1){
printf("\033[0;33m");
printf("Player 1... Press ENTER to dice...");
c = getchar();
dice1=dice();
printf("DICE= %d\n",dice1);
printf("\033[0m");
printf("\033[0;34m");
printf("Player 2... Press ENTER to dice...");
c = getchar();
dice2=dice();
printf("DICE= %d\n",dice2);
printf("\033[0m");
}
else{
	printf("\033[0;34m");
	printf("Player 2... Press ENTER to dice...");
	c = getchar();
	dice2=dice();
	printf("DICE= %d\n",dice2);
	printf("\033[0m");
	printf("\033[0;33m");
	printf("Player 1... Press ENTER to dice...");
	c = getchar();
	dice1=dice();
	printf("DICE= %d\n",dice1);
	printf("\033[0m");
}

}
	return 0;
}

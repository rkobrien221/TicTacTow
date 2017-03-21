/*
Kyle O'Brien
LAB Project
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NAMESIZE 20


void xPlayerTurn(char ticTacToe[][3], char *playerName, int *playerTurn, int *openSpots);//lets X player choose spot on game board
void oPlayerTurn(char ticTacToe[][3], char *playerName, int *playerTurn, int *openSpots);//lets O player choose spot on game baord
void displayGame(char ticTacToe[][3], char *xPlayerPtr, char *oPlayerPtr, int *openSpots);//displays game board
void checkWinner(char ticTacToe[][3], int *openSpots, char *playerName);//checks for win conditions
void userManual();//displays user manual


//Start main program
int main () {


	char ticTacToe[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };//game board
	
	//arrays for player names
	char firstName[NAMESIZE];//holds any name entered by user
	char secondName[NAMESIZE];//holds any name entered by user
	char xPlayer[NAMESIZE];//stores name assigned to X
	char oPlayer[NAMESIZE];//stores name assigned to O

	int openSquares = 9;//how many squares are left to fill
	int turnMarker = 1;//keeps track of who's turn it is
	int shapeChoice;//lets the user who entered name first to select X or O
	
	
	userManual();//call function
	
	system("cls");	
	system("color 0e");
	printf("\n\n\n\n");
	printf("\t%s", "$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$\n"); 
	printf("\t%s", "$~$~$                                                         $~$~$\n");
	printf("\t%s", "$~$~$                  X     VS     O                         $~$~$\n");
	printf("\t%s", "$~$~$                                                         $~$~$\n");
	printf("\t%s", "$~$~$                A Tic-Tac-Toe Game                       $~$~$\n");
	printf("\t%s", "$~$~$                  by Kyle O'Brien                        $~$~$\n");
	printf("\t%s", "$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$\n"); 
	printf("\n\n\n\n");
	sleep(1);	
	
	printf("\t%s", "Please enter a player's name: ");
	scanf("%s", firstName);
	
	printf("\t%s", "Please enter another player's name: ");	
	scanf("%s", secondName);
		
	printf("\n\n  %s, %s", firstName, "please choose to be Xs or Os (Enter 1 - X or 2 - O): ");
	scanf("%d", &shapeChoice);
	
	//allows users name to be assigned to player X or player O for personalization
	if(shapeChoice == 1){
		memcpy(xPlayer, firstName, NAMESIZE);
		memcpy(oPlayer, secondName, NAMESIZE);
	}//end if
	else{
		memcpy(oPlayer, firstName, NAMESIZE);
		memcpy(xPlayer, secondName, NAMESIZE);
	}//end else
	
	
	
while(*xPlayer != '\n' && *oPlayer != '\n'){//game starts when both players have an assigned name
	
	
	displayGame(ticTacToe, xPlayer, oPlayer, &openSquares);//display gameboard	
	
	while(turnMarker == 1){
		xPlayerTurn(ticTacToe, xPlayer, &turnMarker, &openSquares);
		displayGame(ticTacToe, xPlayer, oPlayer, &openSquares);//updates gameboard before checking for winners
		checkWinner(ticTacToe, &openSquares, xPlayer);//check win conditions
	}
	while(turnMarker == 2){
		oPlayerTurn(ticTacToe, oPlayer, &turnMarker, &openSquares);
		displayGame(ticTacToe, xPlayer, oPlayer, &openSquares);//updates gameboard before checking for winners
		checkWinner(ticTacToe, &openSquares, oPlayer);//check win conditions
		
	}
	
}


	
    
puts("\n"); 
system ("pause");
return 0;

}//end main program


 
//---------USER MANUAL-----------------------------------------------------------------

void userManual(){
	
	int displayMan;	
	
	system("color 0f");
	printf("\n\n\n\n");
	printf("\t%s", "$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$\n"); 
	printf("\t%s", "$~$~$                                                         $~$~$\n");
	printf("\t%s", "$~$~$                  X     VS     O                         $~$~$\n");
	printf("\t%s", "$~$~$                                                         $~$~$\n");
	printf("\t%s", "$~$~$                A Tic-Tac-Toe Game                       $~$~$\n");
	printf("\t%s", "$~$~$                  by Kyle O'Brien                        $~$~$\n");
	printf("\t%s", "$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$\n"); 
	printf("\n\n\n\n");
	sleep(1);
	
	printf("\t%s", "Read the user manual? (1-read, 2-skip and play): ");
	scanf("%d", &displayMan);
	
		
	while(displayMan < 1 || displayMan > 2 ){//validates users input, displays error and allows to re-entry
		system("cls");
		system("color 0f");
		printf("\n\n\n\n");
		printf("\t%s", "$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$\n"); 
		printf("\t%s", "$~$~$                                                         $~$~$\n");
		printf("\t%s", "$~$~$                  X     VS     O                         $~$~$\n");
		printf("\t%s", "$~$~$                                                         $~$~$\n");
		printf("\t%s", "$~$~$                A Tic-Tac-Toe Game                       $~$~$\n");
		printf("\t%s", "$~$~$                  by Kyle O'Brien                        $~$~$\n");
		printf("\t%s", "$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$\n"); 
		printf("\n\n\n\n");
		sleep(1);
		printf("\t%s", "View the user manual? (1-view, 2-skip and play): ");
		scanf("%d", &displayMan);
	}//end while*/
	
	
	if(displayMan == 2){//returns to main if user skips user manual
		return;
	}//end if
	
	system("cls");
	system("color 0f");
	printf("\n\n\n\n");
	printf("%s", "$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$\n"); 
	printf("%s", "$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$\n"); 
	printf("%s", "$~$~$                        X     VS     O                               $~$~$\n");
	printf("%s", "$~$~$                          How to Play                                $~$~$\n");
	printf("%s", "$~$~$                                                                     $~$~$\n");
	printf("%s", "$~$~$   The game will begin by asking for two names to be entered.        $~$~$\n");
	printf("%s", "$~$~$                                                                     $~$~$\n");
	printf("%s", "$~$~$   The user who entered their name first will choose Xs or Os.       $~$~$\n");
	printf("%s", "$~$~$                                                                     $~$~$\n");
	printf("%s", "$~$~$   Enter the number shown on the game board to place an X or O.      $~$~$\n");
	printf("%s", "$~$~$                                                                     $~$~$\n");
	printf("%s", "$~$~$   A winner is chosen when 3 of one kind is lined up vertically,     $~$~$\n");
	printf("%s", "$~$~$   horizontally, or diagonal.                                        $~$~$\n");
	printf("%s", "$~$~$                                                                     $~$~$\n");
	printf("%s", "$~$~$   If all the open squares are filled before a winner is found       $~$~$\n");
	printf("%s", "$~$~$   a draw is declared.                                               $~$~$\n");
	printf("%s", "$~$~$                                                                     $~$~$\n");
	printf("%s", "$~$~$                                                                     $~$~$\n");
	printf("%s", "$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$\n"); 
	printf("%s", "$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$~$\n"); 
	printf("\n\n");
	system("pause");
	system("cls");
}
//------------------DISPLAY GAME BOARD---------------------------------------

void displayGame(char ticTacToe[][3], char *xPlayerPtr, char *oPlayerPtr, int *openSpots){
	
		int rowCount;//counter
		int colCount;//counter
	
	system("cls");
	
	//statments display player info	
	printf("%s %s\n", "Player X is: ", xPlayerPtr);
	printf("%s %s\n", "Player O is: ", oPlayerPtr);
	printf("%s %d\n", "Open Squares:", *openSpots);
	
	//display game board
	printf("\t\t\t\t   %s", "X  vs  O");
	puts("\n");
	printf("\t\t\t\t+-----------+\n");	
	for(rowCount = 0; rowCount < 3; rowCount++){		
		printf("\t\t\t\t| %c |", ticTacToe[rowCount][0]);
		printf(" %c |", ticTacToe[rowCount][1]);
		printf(" %c |\n", ticTacToe[rowCount][2]);		
		printf("\t\t\t\t+-----------+\n");
	}//end for
	
	
}//end function


//----------------------X PLAYER'S TURN-------------------------------------------------

void xPlayerTurn(char ticTacToe[][3], char *playerName, int *playerTurn, int *openSpots){
	
	int playerInput;
	
	system("COLOR b0");
	
	
	printf("\n%s%s\'s %s\n", "It is ", playerName, "turn.");
	printf("%s", "Enter the number of a square to place an X: ");
	scanf("%d", &playerInput);
	
	while(playerInput < 1 || playerInput > 9){//validates user input into game board
		printf("%s", "Your choice was not on the game board. Choose again: ");
		scanf("%d", &playerInput);
	}//end while
	
	switch(playerInput){
		case 1:
			if( isdigit(ticTacToe[0][0]) == 0 ){
			break;
			} 
		 	ticTacToe[0][0] = 'X';//assigns X into game board
		 	*playerTurn = 2;//changes the current player's turn
		 	*openSpots -= 1;//decrements the amount of open squares
			break;
		case 2:
			if( isdigit(ticTacToe[0][1]) == 0 ){
			break;
			} 
			ticTacToe[0][1] = 'X';//assigns X into game board
			*playerTurn = 2;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		case 3:
			if( isdigit(ticTacToe[0][2]) == 0 ){
			break;
			}
			ticTacToe[0][2] = 'X';//assigns X into game board
			*playerTurn = 2;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		case 4:
			if( isdigit(ticTacToe[1][0]) == 0 ){
			break;
			}
			ticTacToe[1][0] = 'X';//assigns X into game board
			*playerTurn = 2;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		case 5:
			if( isdigit(ticTacToe[1][1]) == 0 ){
			break;
			}
			ticTacToe[1][1] = 'X';//assigns X into game board
			*playerTurn = 2;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		case 6:
			if( isdigit(ticTacToe[1][2]) == 0 ){
			break;
			}
			ticTacToe[1][2] = 'X';//assigns X into game board
			*playerTurn = 2;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		case 7:
			if( isdigit(ticTacToe[2][0]) == 0 ){
			break;
			}
			ticTacToe[2][0] = 'X';//assigns X into game board
			*playerTurn = 2;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		case 8:
			if( isdigit(ticTacToe[2][1]) == 0 ){
			break;
			}
			ticTacToe[2][1] = 'X';//assigns X into game board
			*playerTurn = 2;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		case 9:
			if( isdigit(ticTacToe[2][2]) == 0 ){
			break;
			}
			ticTacToe[2][2] = 'X';//assigns X into game board
			*playerTurn = 2;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		default:
			break;
	}//end switch
}//end function


//------------------O PLAYERS TURN---------------------------------------------------------

void oPlayerTurn(char ticTacToe[][3], char *playerName, int *playerTurn, int *openSpots){
	
	int playerInput;
	
	
	system("COLOR a0");
	
	printf("\n%s%s\'s %s\n", "It is ", playerName, "turn.");
	printf("%s", "Enter the number of a square to palce an O: ");
	scanf("%d", &playerInput);
	
	while(playerInput < 1 || playerInput > 9){//validates user input into game board
		printf("%s", "Your choice was not on the game board. Choose again: ");
		scanf("%d", &playerInput);
	}//end while
	
	switch(playerInput){
		case 1:
			if( isdigit(ticTacToe[0][0]) == 0 ){
			break;
			} 
			ticTacToe[0][0] = 'O';//assigns O into game board
			*playerTurn = 1;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		case 2:
			if( isdigit(ticTacToe[0][1]) == 0 ){
			break;
			} 
			ticTacToe[0][1] = 'O';//assigns O into game board
			*playerTurn = 1;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		case 3:
			if( isdigit(ticTacToe[0][2]) == 0 ){
			break;
			} 
			ticTacToe[0][2] = 'O';//assigns O into game board
			*playerTurn = 1;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		case 4:
			if( isdigit(ticTacToe[1][0]) == 0 ){
			break;
			} 
			ticTacToe[1][0] = 'O';//assigns O into game board
			*playerTurn = 1;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		case 5:
			if( isdigit(ticTacToe[1][1]) == 0 ){
			break;
			} 
			ticTacToe[1][1] = 'O';//assigns O into game board
			*playerTurn = 1;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		case 6:
			if( isdigit(ticTacToe[1][2]) == 0 ){
			break;
			} 
			ticTacToe[1][2] = 'O';//assigns O into game board
			*playerTurn = 1;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		case 7:
			if( isdigit(ticTacToe[2][0]) == 0 ){
			break;
			} 
			ticTacToe[2][0] = 'O';//assigns O into game board
			*playerTurn = 1;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		case 8:
			if( isdigit(ticTacToe[2][1]) == 0 ){
			break;
			} 
			ticTacToe[2][1] = 'O';//assigns O into game board
			*playerTurn = 1;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		case 9:
			if( isdigit(ticTacToe[2][2]) == 0 ){
			break;
			} 
			ticTacToe[2][2] = 'O';//assigns O into game board
			*playerTurn = 1;//changes the current player's turn
			*openSpots -= 1;//decrements the amount of open squares
			break;
		default:
			break;
	}//end switch
}//end function

//-------------CHECK WINNER----------------------------------

void checkWinner(char ticTacToe[][3], int *openSpots, char *playerName){
	
	int rowCount;//counter
	int colCount;//counter
	
	
	
	//loop checks for any matching rows
	for(rowCount = 0; rowCount < 3; rowCount++){						
		if(ticTacToe [rowCount][0] == ticTacToe [rowCount][1] && ticTacToe [rowCount][0] == ticTacToe [rowCount][2]){
			printf("\n%s%s\n", "The WINNER of this game is: ", playerName );
			system("pause");
			exit(0);
		}
	}//end for
	
	//loop checks for any matching columns
	for(colCount = 0; colCount < 3; colCount++){						
		if(ticTacToe [0][colCount] == ticTacToe [1][colCount] && ticTacToe [0][colCount] == ticTacToe [2][colCount]){
			printf("\n%s%s\n", "The WINNER of this game is: ", playerName );
			system("pause");
			exit(0);
		}
	}//end for
	
	//checks if diagonal spots match
	if(ticTacToe [0][0] == ticTacToe [1][1] && ticTacToe [0][0] == ticTacToe [2][2]){
		printf("\n%s%s\n", "The WINNER of this game is: ", playerName );
		system("pause");
		exit(0);
	}//end if
	
	//checks if opposite diagonal spots match
	if(ticTacToe [0][2] == ticTacToe [1][1] && ticTacToe [0][2] == ticTacToe [2][0]){
		printf("\n%s%s\n", "The WINNER of this game is: ", playerName );
		system("pause");
		exit(0);
	}//end if
	
	//checks if all spots are filled and declares draw
	if(*openSpots == 0){
		printf("\n%s\n\n", "This game is a DRAW!");
		system("pause");
		exit(0);
	}

 }//end function
 


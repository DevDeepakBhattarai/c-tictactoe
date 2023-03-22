#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <MMsystem.h>
#include <time.h>

int aic = 1;
char space[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char* ptr=space;
int checkWin();
void drawBoardplayer();
void drawBoardcomputer();
void computer();
void resetboard(char*);
char ai(int);
int main()
{	system("cls");
	int player = 1, i;
	char mark, choice,conti; // X,O'
	char modechoise;
top:
	system("color 10");
	printf("What mode do you want to play in?\n1.Player vs Player\n2.Player vs Computer\n");
	modechoise = _getch();
	if (modechoise == '1')
	{
		goto pvp;
	}
	else if (modechoise == '2')
	{
		computer();
		goto end;
	}
	else
	{
		printf("Invalid option \n");
		goto top;
	}
pvp:

	do
	{
		drawBoardplayer();
		player = (player % 2) ? 1 : 2;
		printf("Player %d, enter the choice : \n ", player);
		choice = _getch();
		mark = (player == 1) ? 'X' : 'O';
		if (choice == '1' && space[1] == '1')
			space[1] = mark;
		else if (choice == '2' && space[2] == '2')
			space[2] = mark;
		else if (choice == '3' && space[3] == '3')
			space[3] = mark;
		else if (choice == '4' && space[4] == '4')
			space[4] = mark;
		else if (choice == '5' && space[5] == '5')
			space[5] = mark;
		else if (choice == '6' && space[6] == '6')
			space[6] = mark;
		else if (choice == '7' && space[7] == '7')
			space[7] = mark;
		else if (choice == '8' && space[8] == '8')
			space[8] = mark;
		else if (choice == '9' && space[9] == '9')
			space[9] = mark;

		else
		{
			printf("Invalid option !\n");
			player--;
			getch();
		}
		i = checkWin();
		player++;

	} while (i == -1);

	drawBoardplayer();
	if (i == 1)
	{
		printf("==>Player %d won\n", --player);
		printf("Do you want to play again?(Y/N)\n");
		conti=_getch();
		conti=toupper(conti);
		if(conti=='Y'){
			resetboard(space);
			main();
		}
		else{
			goto end;
		}
		
	}
	else
	{
		printf("==>Game draw\n");
		printf("Do you want to play again?(Y/N)\n");
		conti=_getch();
		conti=toupper(conti);
		if(conti=='Y'){
			resetboard(space);
			main();
		}
		else{
			goto end;
		}

	}
	getch();
end:
	return 0;
}
int checkWin()
{
	if (space[1] == space[2] && space[2] == space[3])
		return 1;
	else if (space[4] == space[5] && space[5] == space[6])
		return 1;
	else if (space[7] == space[8] && space[8] == space[9])
		return 1;
	else if (space[1] == space[4] && space[4] == space[7])
		return 1;
	else if (space[2] == space[5] && space[5] == space[8])
		return 1;
	else if (space[3] == space[6] && space[6] == space[9])
		return 1;
	else if (space[1] == space[5] && space[5] == space[9])
		return 1;
	else if (space[3] == space[5] && space[5] == space[7])
		return 1;
	else if (space[1] != '1' && space[2] != '2' && space[3] != '3' && space[4] != '4' && space[5] != '5' && space[6] != '6' && space[7] != '7' && space[8] != '8' && space[9] != '9')
		return 0;
	else
		return -1;
}

void drawBoardplayer()
{
	system("cls");
	printf("\n\n\t Tic Tac Toe \n\n");
	printf("Player1 (X) - Player2 (O) \n\n\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", space[1], space[2], space[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", space[4], space[5], space[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", space[7], space[8], space[9]);
	printf("     |     |     \n");
}
void drawBoardcomputer()
{
	system("cls");
	printf("\n\n\t Tic Tac Toe \n\n");
	printf("Player (X) - Computer(O) \n\n\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", space[1], space[2], space[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", space[4], space[5], space[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", space[7], space[8], space[9]);
	printf("     |     |     \n");
}
void computer()
{
	int i, player = 1, aic = 1;
	char choise, mark,conti;
	do
	{
		drawBoardcomputer();
		player = (player % 2) ? 1 : 2;
		if (player == 1)
		{
			printf("Enter your choise");
			choise = _getch();
		}
		else
		{
			
			choise = ai(aic);
			
			aic++;
		}
		mark = (player == 1) ? 'X' : 'O';
		if (choise == '1' && space[1] == '1')
			space[1] = mark;
		else if (choise == '2' && space[2] == '2')
			space[2] = mark;
		else if (choise == '3' && space[3] == '3')
			space[3] = mark;
		else if (choise == '4' && space[4] == '4')
			space[4] = mark;
		else if (choise == '5' && space[5] == '5')
			space[5] = mark;
		else if (choise == '6' && space[6] == '6')
			space[6] = mark;
		else if (choise == '7' && space[7] == '7')
			space[7] = mark;
		else if (choise == '8' && space[8] == '8')
			space[8] = mark;
		else if (choise == '9' && space[9] == '9')
			space[9] = mark;

		else
		{
			printf("\nInvalid option !");
			player--;
			getch();
		}
		i = checkWin();
		player++;

	} while (i == -1);
	drawBoardcomputer();
	if (i == 1 && --player == 1)
	{
		printf("You won\n");
		
		printf("Do you want to play again?(Y/N)\n");
		conti=_getch();
		conti=toupper(conti);
		if(conti=='Y'){
			resetboard(space);
			main();
		}
	}
	else if (i == 1 && player != 1)
	{
		printf("I am undefeated.You Lost! \n");
		
		printf("Do you want to play again?(Y/N)\n");
		conti=_getch();
		conti=toupper(conti);
		if(conti=='Y'){
			resetboard(space);
			main();
		}
	}
	else
	{
		printf("==>Game draw\n");
		
		printf("Do you want to play again?(Y/N)\n");
		conti=_getch();
		conti=toupper(conti);
		if(conti=='Y'){
			resetboard(space);
			main();
		}
		
	}

}

char ai(int aic)
{
	int condition;
	while (aic == 1 && space[5] == 'X')
	{
		srand(time(0));
		condition = rand() % 100 + 1;
		if (condition > 25 && condition < 50)
			return '1';
		if (condition > 50 && condition < 75)
			return '3';
		if (condition > 75)
			return '7';
		if (condition < 25)
			return '9';
	}
	while (aic == 1 && space[2] == 'X')
	{
		srand(time(0));
		condition = rand() % 100 + 1;
		if (condition < 50)
			return '1';
		if (condition > 50)
			return '3';
	}
	while (aic == 1 && space[4] == 'X')
	{
		srand(time(0));
		condition = rand() % 100 + 1;
		if (condition < 50)
			return '1';
		if (condition > 50)
			return '7';
	}
	while (aic == 1 && space[6] == 'X')
	{
		srand(time(0));
		condition = rand() % 100 + 1;
		if (condition < 50)
			return '9';
		if (condition > 50)
			return '3';
	}

	while (aic == 1 && space[8] == 'X')
	{
		srand(time(0));
		condition = rand() % 100 + 1;
		if (condition < 50)
			return '7';
		if (condition > 50)
			return '9';
	}

	while (aic == 1 && (space[1] == 'X' || space[3] == 'X' || space[7] == 'X' || space[9] == 'X'))
	{
		return '5';
	}
	// while(aic==2 &&  ){

	// }

	//win test
	//first row
	if (space[1] == space[2] && space[1] == 'O' && space[3] == '3')
		return '3';
	else if (space[1] == space[3] && space[1] == 'O' && space[2] == '2')
		return '2';
	else if (space[2] == space[3] && space[2] == 'O' && space[1] == '1')
		return '1';
	//second row
	else if (space[4] == space[5] && space[4] == 'O' && space[6] == '6')
		return '6';
	else if (space[5] == space[6] && space[5] == 'O' && space[4] == '4')
		return '4';
	else if (space[4] == space[6] && space[4] == 'O' && space[5] == '5')
		return '5';
	//third row
	else if (space[7] == space[8] && space[7] == 'O' && space[9] == '9')
		return '9';
	else if (space[8] == space[9] && space[8] == 'O' && space[7] == '7')
		return '7';
	else if (space[7] == space[9] && space[7] == 'O' && space[8] == '8')
		return '8';
	//first column
	else if (space[1] == space[4] && space[1] == 'O' && space[7] == '7')
		return '7';
	else if (space[4] == space[7] && space[4] == 'O' && space[1] == '1')
		return '1';
	else if (space[1] == space[7] && space[1] == 'O' && space[4] == '4')
		return '4';
	//second column
	else if (space[2] == space[5] && space[2] == 'O' && space[8] == '8')
		return '8';
	else if (space[5] == space[8] && space[5] == 'O' && space[2] == '2')
		return '2';
	else if (space[2] == space[8] && space[2] == 'O' && space[5] == '5')
		return '5';
	//third column
	else if (space[3] == space[6] && space[6] == 'O' && space[9] == '9')
		return '9';
	else if (space[6] == space[9] && space[6] == 'O' && space[3] == '3')
		return '3';
	else if (space[3] == space[9] && space[9] == 'O' && space[6] == '6')
		return '6';
	//principle diagonal
	else if (space[1] == space[5] && space[5] == 'O' && space[9] == '9')
		return '9';
	else if (space[5] == space[9] && space[5] == 'O' && space[1] == '1')
		return '1';
	else if (space[1] == space[9] && space[9] == 'O' && space[5] == '5')
		return '5';
	//other diagonal
	else if (space[3] == space[5] && space[5] == 'O' && space[7] == '7')
		return '7';
	else if (space[5] == space[7] && space[5] == 'O' && space[3] == '3')
		return '3';
	else if (space[3] == space[7] && space[7] == 'O' && space[5] == '5')
		return '5';

	//block win
	//first row
	if (space[1] == space[2] && space[3] == '3')
		return '3';
	else if (space[1] == space[3] && space[2] == '2')
		return '2';
	else if (space[2] == space[3] && space[1] == '1')
		return '1';
	//second row
	else if (space[4] == space[5] && space[6] == '6')
		return '6';
	else if (space[5] == space[6] && space[4] == '4')
		return '4';
	else if (space[4] == space[6] && space[5] == '5')
		return '5';
	//third row
	else if (space[7] == space[8] && space[9] == '9')
		return '9';
	else if (space[8] == space[9] && space[7] == '7')
		return '7';
	else if (space[7] == space[9] && space[8] == '8')
		return '8';
	//first column
	else if (space[1] == space[4] && space[7] == '7')
		return '7';
	else if (space[4] == space[7] && space[1] == '1')
		return '1';
	else if (space[1] == space[7] && space[4] == '4')
		return '4';
	//second column
	else if (space[2] == space[5] && space[8] == '8')
		return '8';
	else if (space[5] == space[8] && space[2] == '2')
		return '2';
	else if (space[2] == space[8] && space[5] == '5')
		return '5';
	//third column
	else if (space[3] == space[6] && space[9] == '9')
		return '9';
	else if (space[6] == space[9] && space[3] == '3')
		return '3';
	else if (space[3] == space[9] && space[6] == '6')
		return '6';
	//principle diagonal
	else if (space[1] == space[5] && space[9] == '9')
		return '9';
	else if (space[5] == space[9] && space[1] == '1')
		return '1';
	else if (space[1] == space[9] && space[5] == '5')
		return '5';
	//other diagonal
	else if (space[3] == space[5] && space[7] == '7')
		return '7';
	else if (space[5] == space[7] && space[3] == '3')
		return '3';
	else if (space[3] == space[7] && space[5] == '5')
		return '5';

	//first row 
	if(space[2]=='X' && space[3]=='3')
	return '3';
	if(space[2]=='X' && space[1]=='1')
	return '1';
	if(space[4]=='X' && space[1]=='1')
	return '1';
	if(space[4]=='X' && space[7]=='7')
	return '7';
	if(space[6]=='X' && space[3]=='3')
	return '3';
	if(space[6]=='X' && space[9]=='9')
	return '9';
	if(space[8]=='X' && space[9]=='9')
	return '9';
	if(space[8]=='X' && space[7]=='7')
	return '7';


	// first row
	if (space[1] == 'X' && space[2] == '2')
		return '2';
	if (space[2] == 'X' && space[3] == '3')
		return '3';
	if (space[3] == 'X' && space[2] == '2')
		return '2';
	if (space[2] == 'X' && space[3] != '3' && space[1] == '1')
		return '1';
	if (space[1] == 'X' && space[2] != '2' && space[3] == '3')
		return '3';
	if (space[3] == 'X' && space[2] != '2' && space[1] == '1')
		return '1';
	if (space[2] == 'X' && space[3] != '3' && space[1] != '1' && space[5] == '5')
		return '5';
	if (space[1] == 'X' && space[2] != '2' && space[3] != '3' && space[4] == '4')
		return '4';
	if (space[3] == 'X' && space[2] != '2' && space[1] != '1' && space[6] == '6')
		return '6';

	//second row
	if (space[4] == 'X' && space[5] == '5')
		return '5';
	if (space[5] == 'X' && space[6] == '6')
		return '6';
	if (space[6] == 'X' && space[5] == '5')
		return '7';
	if (space[5] == 'X' && space[6] != '6' && space[4] == '4')
		return '4';
	if (space[6] == 'X' && space[5] != '5' && space[4] == '4')
		return '4';
	if (space[4] == 'X' && space[5] != '5' && space[6] == '6')
		return '6';
	if (space[4] == 'X' && space[5] != '5' && space[6] != '6' && space[7] == '7')
		return '7';
	if (space[5] == 'X' && space[6] != '6' && space[4] != '4' && space[8] == '8')
		return '8';
	if (space[6] == 'X' && space[5] != '5' && space[4] != '4' && space[9] == '9')
		return '9';
	if (space[4] == 'X' && space[5] != '5' && space[6] != '6' && space[7] != '7' && space[1] == '1')
		return '1';
	if (space[5] == 'X' && space[6] != '6' && space[4] != '4' && space[8] != '8' && space[2] == '2')
		return '2';
	if (space[6] == 'X' && space[5] != '5' && space[4] != '4' && space[9] != '9' && space[3] == '3')
		return '3';

	//third row
	if (space[7] == 'X' && space[8] == '8')
		return '8';
	if (space[8] == 'X' && space[9] == '9')
		return '9';
	if (space[9] == 'X' && space[8] == '8')
		return '8';
	if (space[7] == 'X' && space[8] != '8' && space[9] == '9')
		return '9';
	if (space[8] == 'X' && space[9] != '9' && space[7] == '7')
		return '7';
	if (space[9] == 'X' && space[8] != '8' && space[7] == '7')
		return '7';
	if (space[7] == 'X' && space[8] != '8' && space[9] != '9' && space[4] == '4')
		return '4';
	if (space[8] == 'X' && space[7] != '7' && space[9] != '9' && space[5] == '5')
		return '5';
	if (space[9] == 'X' && space[7] != '7' && space[8] != '8' && space[6] == '6')
		return '6';
	if (space[7] == 'X' && space[8] != '8' && space[9] != '9' && space[4] != '4' && space[1] == '1')
		return '1';
	if (space[8] == 'X' && space[7] != '7' && space[9] != '9' && space[5] != '5' && space[2] == '2')
		return '2';
	if (space[9] == 'X' && space[7] != '7' && space[8] != '8' && space[6] != '6' && space[3] == '3')
		return '3';
}
void resetboard(char* pt){
	(*pt)='0';
	*(pt+1)='1';
	*(pt+2)='2';
	*(pt+3)='3';
	*(pt+4)='4';
	*(pt+5)='5';
	*(pt+6)='6';
	*(pt+7)='7';
	*(pt+8)='8';
	*(pt+9)='9';
	}

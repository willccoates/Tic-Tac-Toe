#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "ticTacToe.h"

using namespace std;

Tictactoe::Tictactoe()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			board[i][j] = '-';
		}
	}
}

void Tictactoe::play()
{
	//srand(time(NULL));
	this->printBoard();
	int trigger = 0;
	//int firstPlayer = rand() % 2;			//players choose heads or tails and this decides who goes first.
	//char heads;
	//char tails;

	while (trigger < 9)
	{
		if (trigger % 2 == 0)
		{
			this->xPlay();
		}
		if (trigger % 2 == 1)
		{
			this->oPlay();
		}
		trigger++;
	}
}

void Tictactoe::xPlay()
{
	int firstCoor = 0;
	int secondCoor = 0;
	bool validPlay;
	cout << "X, it is your turn!" << endl;
	input:
		cout << "Choose a location:\n First coordinate = ";
		cin >> firstCoor;
		cout << "\nSecond coordinate = ";
		cin >> secondCoor;

		validPlay = this->playPlayerSelection(firstCoor, secondCoor, 'X');
		if (!validPlay)
			goto input;
		else
			goto checkWin;

	checkWin:
		if (this->checkWin(firstCoor, secondCoor, 'X'))
		{
			cout << "X has won!\n";
			this->printBoard();
			exit(0);
		}
		else
			goto endturn;

	endturn:
		cout << "Nice move!" << endl;
		this->printBoard();

}

void Tictactoe::oPlay()
{
	int firstCoor = 0;
	int secondCoor = 0;
	bool validPlay;
	cout << "O, it is your turn!" << endl;
	input:
		cout << "Choose a location:\n First coordinate = ";
		cin >> firstCoor;
		cout << "\nSecond coordinate = ";
		cin >> secondCoor;

		validPlay = this->playPlayerSelection(firstCoor, secondCoor, 'O');
		if (!validPlay)
			goto input;
		else
			goto checkWin;

	checkWin:
		if (this->checkWin(firstCoor, secondCoor, 'O'))
		{
			cout << "O has won!\n";
			this->printBoard();
			exit(0);
		}
		else
			goto endturn;

	endturn:
		cout << "Nice move!" << endl;
		this->printBoard();
}

bool Tictactoe::playPlayerSelection(int xCoor, int yCoor, char player)
{
	if (board[xCoor][yCoor] == 'x' || board[xCoor][yCoor] == 'X' || board[xCoor][yCoor] == 'o' || board[xCoor][yCoor] == 'O')
	{
		cout << "Space occupied choose again!" << endl;
		return false;
	}
	if (player == 'X' || player == 'x')
	{
		if (xCoor > 2 || yCoor > 2)
		{
			cout << "Invalid input! Choose a number between 0 and 2" << endl;
			return false;
		}
		else
		{
			board[xCoor][yCoor] = 'X';
			return true;
		}
	}
	if (player == 'O' || player == 'o')
	{
		if (xCoor > 2 || yCoor > 2)
		{
			cout << "Invalid input! Choose a number between 0 and 2" << endl;
			return false;
		}
		else
		{
			board[xCoor][yCoor] = 'O';
			return true;
		}
	}
	return false;
}

bool Tictactoe::checkWin(int xCoor, int yCoor, char player)
{
	if (player == 'X')
	{
		if (xCoor == 0)
		{
			if (yCoor == 0)
			{
				if (board[xCoor][yCoor + 1] == 'X')
				{
					if (board[xCoor][yCoor + 2] == 'X')
						return true;
				}
				if (board[xCoor + 1][yCoor + 1] == 'X')
				{
					if (board[xCoor + 2][yCoor + 2] == 'X')
						return true;
				}
				if (board[xCoor + 1][yCoor] == 'X')
				{
					if (board[xCoor + 2][yCoor] == 'X')
						return true;
				}
			}
			else if (yCoor == 1)
			{
				if (board[xCoor][yCoor - 1] == 'X')
				{
					if (board[xCoor][yCoor + 1] == 'X')
						return true;
				}
				if (board[xCoor + 1][yCoor + 1] == 'X')
				{
					if (board[xCoor + 2][yCoor + 1] == 'X')
						return true;
				}
			}
			else
			{
				if (board[xCoor][yCoor - 1] == 'X')
				{
					if (board[xCoor][yCoor - 2] == 'X')
						return true;
				}
				if (board[xCoor + 1][yCoor - 1] == 'X')
				{
					if (board[xCoor + 2][yCoor - 2] == 'X')
						return true;
				}
				if (board[xCoor + 1][yCoor] == 'X')
				{
					if (board[xCoor + 2][yCoor] == 'X')
						return true;
				}
			}
		}
		if (xCoor == 1)
		{
			if (yCoor == 0)
			{
				if (board[xCoor - 1][yCoor] == 'X')
				{
					if (board[xCoor + 1][yCoor] == 'X')
						return true;
				}
				if (board[xCoor][yCoor + 1] == 'X')
				{
					if (board[xCoor][yCoor + 2] == 'X')
						return true;
				}
			}
			else if (yCoor == 1)
			{
				if (board[xCoor-1][yCoor] == 'X')
				{
					if (board[xCoor + 1][yCoor] == 'X')
						return true;
				}
				if (board[xCoor][yCoor - 1] == 'X')
				{
					if (board[xCoor][yCoor + 1] == 'X')
						return true;
				}
			}
			else
			{
				if (board[xCoor][yCoor - 1] == 'X')
				{
					if (board[xCoor][yCoor - 2] == 'X')
						return true;
				}
				if (board[xCoor - 1][yCoor] == 'X')
				{
					if (board[xCoor + 1][yCoor] == 'X')
						return true;
				}
			}
		}
		if (xCoor == 2)
		{
			if (yCoor == 0)
			{
				if (board[xCoor - 1][yCoor] == 'X')
				{
					if (board[xCoor - 2][yCoor] == 'X')
						return true;
				}
				if (board[xCoor - 1][yCoor - 1] == 'X')
				{
					if (board[xCoor - 2][yCoor - 2] == 'X')
						return true;
				}
				if (board[xCoor][yCoor + 1] == 'X')
				{
					if (board[xCoor][yCoor + 2] == 'X')
						return true;
				}
			}
			else if (yCoor == 1)
			{
				if (board[xCoor][yCoor - 1] == 'X')
				{
					if (board[xCoor][yCoor + 1] == 'X')
						return true;
				}
				if (board[xCoor - 1][yCoor] == 'X')
				{
					if (board[xCoor - 2][yCoor] == 'X')
						return true;
				}
			}
			else //edit this
			{
				if (board[xCoor][yCoor - 1] == 'X')
				{
					if (board[xCoor][yCoor - 2] == 'X')
						return true;
				}
				if (board[xCoor - 1][yCoor - 1] == 'X')
				{
					if (board[xCoor - 2][yCoor - 2] == 'X')
						return true;
				}
				if (board[xCoor][yCoor - 1] == 'X')
				{
					if (board[xCoor][yCoor - 2] == 'X')
						return true;
				}
			}
		}
	}
	if(player == 'O')
	{
		if (xCoor == 0)
		{
			if (yCoor == 0)
			{
				if (board[xCoor][yCoor + 1] == 'O')
				{
					if (board[xCoor][yCoor + 2] == 'O')
						return true;
				}
				if (board[xCoor + 1][yCoor + 1] == 'O')
				{
					if (board[xCoor + 2][yCoor + 2] == 'O')
						return true;
				}
				if (board[xCoor + 1][yCoor] == 'O')
				{
					if (board[xCoor + 2][yCoor] == 'O')
						return true;
				}
			}
			else if (yCoor == 1)
			{
				if (board[xCoor][yCoor - 1] == 'O')
				{
					if (board[xCoor][yCoor + 1] == 'O')
						return true;
				}
				if (board[xCoor + 1][yCoor + 1] == 'O')
				{
					if (board[xCoor + 2][yCoor + 1] == 'O')
						return true;
				}
			}
			else
			{
				if (board[xCoor][yCoor - 1] == 'O')
				{
					if (board[xCoor][yCoor - 2] == 'O')
						return true;
				}
				if (board[xCoor + 1][yCoor - 1] == 'O')
				{
					if (board[xCoor + 2][yCoor - 2] == 'O')
						return true;
				}
				if (board[xCoor + 1][yCoor] == 'O')
				{
					if (board[xCoor + 2][yCoor] == 'O')
						return true;
				}
			}
		}
		if (xCoor == 1)
		{
			if (yCoor == 0)
			{
				if (board[xCoor - 1][yCoor] == 'O')
				{
					if (board[xCoor + 1][yCoor] == 'O')
						return true;
				}
				if (board[xCoor][yCoor + 1] == 'O')
				{
					if (board[xCoor][yCoor + 2] == 'O')
						return true;
				}
			}
			else if (yCoor == 1)
			{
				if (board[xCoor - 1][yCoor] == 'O')
				{
					if (board[xCoor + 1][yCoor] == 'O')
						return true;
				}
				if (board[xCoor][yCoor - 1] == 'O')
				{
					if (board[xCoor][yCoor + 1] == 'O')
						return true;
				}
			}
			else
			{
				if (board[xCoor][yCoor - 1] == 'O')
				{
					if (board[xCoor][yCoor - 2] == 'O')
						return true;
				}
				if (board[xCoor - 1][yCoor] == 'O')
				{
					if (board[xCoor + 1][yCoor] == 'O')
						return true;
				}
			}
		}
		if (xCoor == 2)
		{
			if (yCoor == 0)
			{
				if (board[xCoor - 1][yCoor] == 'O')
				{
					if (board[xCoor - 2][yCoor] == 'O')
						return true;
				}
				if (board[xCoor - 1][yCoor - 1] == 'O')
				{
					if (board[xCoor - 2][yCoor - 2] == 'O')
						return true;
				}
				if (board[xCoor][yCoor + 1] == 'O')
				{
					if (board[xCoor][yCoor + 2] == 'O')
						return true;
				}
			}
			else if (yCoor == 1)
			{
				if (board[xCoor][yCoor - 1] == 'O')
				{
					if (board[xCoor][yCoor + 1] == 'O')
						return true;
				}
				if (board[xCoor - 1][yCoor] == 'O')
				{
					if (board[xCoor - 2][yCoor] == 'O')
						return true;
				}
			}
			else //edit this
			{
				if (board[xCoor][yCoor - 1] == 'O')
				{
					if (board[xCoor][yCoor - 2] == 'O')
						return true;
				}
				if (board[xCoor - 1][yCoor - 1] == 'O')
				{
					if (board[xCoor - 2][yCoor - 2] == 'O')
						return true;
				}
				if (board[xCoor][yCoor - 1] == 'O')
				{
					if (board[xCoor][yCoor - 2] == 'O')
						return true;
				}
			}
		}
		
	}
	return false;
}

void Tictactoe::printBoard()
{
	cout << setw(4);
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
		
			cout << board[i][j] << setw(4);
		}
		cout << endl;
	}
}
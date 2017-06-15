#ifndef TICTACTOE_H_HAS_BEEN_INCLUDED
#define TICTACTOE_H_HAS_BEEN_INCLUDED

class Tictactoe
{
private:
	char board[3][3];
public:
	Tictactoe();

	void play();
	void Tictactoe::xPlay();
	void Tictactoe::oPlay();
	bool playPlayerSelection(int xCoor, int yCoor, char player);
	bool checkWin(int xCoor, int yCoor, char player);
	void printBoard();

};

#endif // !TICTACTOE_H

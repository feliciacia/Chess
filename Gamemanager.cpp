#include<iostream>
#include "Gamemanager.h"
#include "Board.h"
#include <string>
using namespace std;

Position GameManager::findChessman(Chessman chessman, Color color, ColeredChessman checkerboard[8][8]) 
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {//searching for the king
			if (checkerboard[i][j].chessman == chessman &&
				checkerboard[i][j].color == color)
				return Position(i, j);
		}
	}
	return Position(-1, -1);
}

bool GameManager::moveKing(ColeredChessman* thisKing, ColeredChessman* thatSpace, ColeredChessman checkerboard[8][8]) //move king //move one square only
{
	if (thisKing->color == Color::WHITE) //castling
	{
		if (thisKing->x == 7 && thisKing->y == 4 && thatSpace->x == 7 && thatSpace->y == 0 && thatSpace->chessman == Chessman::ROOK && thatSpace->color == Color::WHITE) //long castle
		{
			for (int i = 1; i < 4; i++)
			{
				if (checkerboard[7][i].color != Color::NONE)
				{
					return false;
				}
			}
			thisKing->chessman = Chessman::NONE;
			thisKing->color = Color::NONE;
			thatSpace->chessman = Chessman::NONE;
			thatSpace->color = Color::NONE;
			checkerboard[7][2].chessman = Chessman::KING;
			checkerboard[7][2].color = Color::WHITE;
			checkerboard[7][3].chessman = Chessman::ROOK;
			checkerboard[7][3].color = Color::WHITE;
			return true;
		}
		else if (thisKing->x == 7 && thisKing->y == 4 && thatSpace->x == 7 && thatSpace->y == 7 && thatSpace->chessman == Chessman::ROOK && thatSpace->color == Color::WHITE) //short castle
		{
			for (int i = 5; i < 7; i++)
			{
				if (checkerboard[7][i].color != Color::NONE)
				{
					return false;
				}
			}
			thisKing->chessman = Chessman::NONE;
			thisKing->color = Color::NONE;
			thatSpace->chessman = Chessman::NONE;
			thatSpace->color = Color::NONE;
			checkerboard[7][6].chessman = Chessman::KING;
			checkerboard[7][6].color = Color::WHITE;
			checkerboard[7][5].chessman = Chessman::ROOK;
			checkerboard[7][5].color = Color::WHITE;
			return true;
		}
	}
	else if (thisKing->color == Color::BLACK)
	{
		if (thisKing->x == 0 && thisKing->y == 4 && thatSpace->x == 0 && thatSpace->y == 0 && thatSpace->chessman == Chessman::ROOK && thatSpace->color == Color::BLACK)
		{
			for (int i = 1; i < 4; i++)
			{
				if (checkerboard[0][i].color != Color::NONE)
				{
					return false;
				}
			}
			thisKing->chessman = Chessman::NONE;
			thisKing->color = Color::NONE;
			thatSpace->chessman = Chessman::NONE;
			thatSpace->color = Color::NONE;
			checkerboard[0][2].chessman = Chessman::KING;
			checkerboard[0][2].color = Color::WHITE;
			checkerboard[0][3].chessman = Chessman::ROOK;
			checkerboard[0][3].color = Color::WHITE;
			return true;
		}
		else if (thisKing->x == 0 && thisKing->y == 4 && thatSpace->x == 0 && thatSpace->y == 7 && thatSpace->chessman == Chessman::ROOK && thatSpace->color == Color::BLACK)
		{
			for (int i = 5; i < 7; i++)
			{
				if (checkerboard[0][i].color != Color::NONE)
				{
					return false;
				}
			}
			thisKing->chessman = Chessman::NONE;
			thisKing->color = Color::NONE;
			thatSpace->chessman = Chessman::NONE;
			thatSpace->color = Color::NONE;
			checkerboard[0][6].chessman = Chessman::KING;
			checkerboard[0][6].color = Color::WHITE;
			checkerboard[0][5].chessman = Chessman::ROOK;
			checkerboard[0][5].color = Color::WHITE;
			return true;
		}
	}
	if (abs(thatSpace->x - thisKing->x) == 1 && thatSpace->color != color) //move max one move if hori not same
	{
		if (abs(thatSpace->y - thisKing->y) <= 1)
		{
			ColeredChessman* temp;
			temp = thisKing;
			thatSpace->chessman = temp->chessman;
			thatSpace->color = temp->color;
			thisKing->chessman = Chessman::NONE;
			thisKing->color = Color::NONE;
			return true;
		}
		else return false;
	}
	else if (abs(thatSpace->x - thisKing->x) == 0 && thatSpace->color != color) //move max one move if hori same
	{
		if (abs(thatSpace->y - thisKing->y) == 1)
		{
			ColeredChessman* temp;
			temp = thisKing;
			thatSpace->chessman = temp->chessman;
			thatSpace->color = temp->color;
			thisKing->chessman = Chessman::NONE;
			thisKing->color = Color::NONE;
			return true;
		}
		else return false;
	}
	else return false;
}

bool GameManager::moveQueen(ColeredChessman* thisQueen, ColeredChessman* thatSpace, ColeredChessman checkerboard[8][8]) //move queen //star (*) movement
{
	bool invalid = false;
	if ((thisQueen->x != thatSpace->x || thisQueen->y != thatSpace->y) && thatSpace->color != color) //if x and y not same //if it has moved
	{
		if (thisQueen->x == thatSpace->x)//vertical movement
		{
			int yIncrement = (thatSpace->y - thisQueen->y) / abs(thatSpace->y - thisQueen->y);
			for (int i = thisQueen->y + yIncrement; i != thatSpace->y; i += yIncrement) //if has nothing from a to b then move to b
			{
				if (checkerboard[thatSpace->x][i].color != Color::NONE)
				{
					return false;
				}
			}
		}
		else if (thatSpace->y == thisQueen->y)//horizontal movement
		{
			int xIncrement = (thatSpace->x - thisQueen->x) / abs(thatSpace->x - thisQueen->x);
			for (int i = thisQueen->x + xIncrement; i != thatSpace->x; i += xIncrement)//if has nothing from a to b then move to b
			{
				if (checkerboard[i][thatSpace->y].color != Color::NONE)
				{
					return false;
				}
			}
		}
		else if (abs(thatSpace->y - thisQueen->y) == abs(thatSpace->x - thisQueen->x))//diagonal movement
		{
			int xIncrement = (thatSpace->x - thisQueen->x) / abs(thatSpace->x - thisQueen->x);
			int yIncrement = (thatSpace->y - thisQueen->y) / abs(thatSpace->y - thisQueen->y);
			for (int i = 1; i < abs(thatSpace->x - thisQueen->x);i++) //if has nothing from a to b then move to b
			{
				if (checkerboard[thisQueen->x + xIncrement * i][thisQueen->y + yIncrement * i].color != Color::NONE)
				{
					return false;
				}
			}
		}
		else
		{
			return false; //invalid movement
		}
	}
	else
	{
		invalid = true;
	}
	
	if (invalid == false) //if valid then move
	{
		ColeredChessman* temp;
		temp = thisQueen;
		thatSpace->chessman = temp->chessman;
		thatSpace->color = temp->color;
		thisQueen->chessman = Chessman::NONE;
		thisQueen->color = Color::NONE;
		return true;
	}
	else //invalid6
	{
		return false;
	}
}

bool GameManager::moveBishop(ColeredChessman* thisBishop, ColeredChessman* thatSpace, ColeredChessman checkerboard[8][8]) //move bishop //diagonal only
{
	bool invalid = false;
	if (abs(thisBishop->x - thatSpace->x) == abs(thisBishop->y - thatSpace->y) && thatSpace->color != color)
	{
		int xIncrement = (thatSpace->x - thisBishop->x) / abs(thatSpace->x - thisBishop->x);
		int yIncrement = (thatSpace->y - thisBishop->y) / abs(thatSpace->y - thisBishop->y);
		for (int i = 1; i < abs(thatSpace->x - thisBishop->x); i++) //if has nothing from a to b then move to b
		{
			if (checkerboard[thisBishop->x + xIncrement * i][thisBishop->y + yIncrement * i].color != Color::NONE)
			{
				return false;
			}
		}
	}
	else
	{
		return false; //invalid movememt
	}

	if (invalid == false) //valid movement
	{
		ColeredChessman* temp;
		temp = thisBishop;
		thatSpace->chessman = temp->chessman;
		thatSpace->color = temp->color;
		thisBishop->chessman = Chessman::NONE;
		thisBishop->color = Color::NONE;
		return true;
	}
	else
	{
		return false; //invalid
	}
}

bool GameManager::moveKnight(ColeredChessman* thisKnight, ColeredChessman* thatSpace, ColeredChessman checkerboard[8][8]) //move knight // l movement
{
	if (((abs(thisKnight->x - thatSpace->x) == 2 && abs(thisKnight->y - thatSpace->y) == 1) || (abs(thisKnight->x - thatSpace->x) == 1 && abs(thisKnight->y - thatSpace->y) == 2)) && thatSpace->color != color) //if has nothing from a to b then move to b
	{
		ColeredChessman* temp;
		temp = thisKnight;
		thatSpace->chessman = temp->chessman;
		thatSpace->color = temp->color;
		thisKnight->chessman = Chessman::NONE;
		thisKnight->color = Color::NONE;
		return true;
	}
	else //invalid
	{
		return false;
	}
}

bool GameManager::moveRook(ColeredChessman* thisRook, ColeredChessman* thatSpace, ColeredChessman checkerboard[8][8]) //move horizontally or vertically
{
	bool invalid = false;
	if ((thisRook->x != thatSpace->x || thisRook->y != thatSpace->y) && thatSpace->color != color)
	{
		if (thisRook->x == thatSpace->x)//vertical movement
		{
			int yIncrement = (thatSpace->y - thisRook->y) / abs(thatSpace->y - thisRook->y);
			for (int i = thisRook->y + yIncrement; i != thatSpace->y; i += yIncrement) //if has nothing from a to b then move to b
			{
				if (checkerboard[thatSpace->x][i].color != Color::NONE)
				{
					return false;
				}
			}
		}
		else if (thatSpace->y == thisRook->y)//horizontal movement
		{
			int xIncrement = (thatSpace->x - thisRook->x) / abs(thatSpace->x - thisRook->x);
			for (int i = thisRook->x + xIncrement; i != thatSpace->x; i += xIncrement) //if has nothing from a to b then move to b
			{
				if (checkerboard[i][thatSpace->y].color != Color::NONE)
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		invalid = true;
	}
	if (invalid == false) //valid
	{
		ColeredChessman* temp;
		temp = thisRook;
		thatSpace->chessman = temp->chessman;
		thatSpace->color = temp->color;
		thisRook->chessman = Chessman::NONE;
		thisRook->color = Color::NONE;
		return true;
	}
	else //invalid
	{
		return false;
	}
}

bool GameManager::movePawn(ColeredChessman* thisPawn, ColeredChessman* thatSpace, ColeredChessman checkerboard[8][8]) //move pawn //included first double step, promotion, and capturing opponent's piece
{
	if (thisPawn->color == Color::WHITE)
	{
		bool move = false;
		if (thisPawn->y == thatSpace->y && thisPawn->x == 6 && thatSpace->x == thisPawn->x - 2 && thatSpace->color == Color::NONE) //first double move
		{
			ColeredChessman* temp;
			temp = thisPawn;
			thatSpace->chessman = temp->chessman;
			thatSpace->color = temp->color;
			thisPawn->chessman = Chessman::NONE;
			thisPawn->color = Color::NONE;
			move = true;
		}
		else if (thisPawn->y == thatSpace->y && thisPawn->x - 1 == thatSpace->x && thatSpace->color == Color::NONE) //if has nothing from a to b then move to b //move one step forwad
		{
			ColeredChessman* temp;
			temp = thisPawn;
			thatSpace->chessman = temp->chessman;
			thatSpace->color = temp->color;
			thisPawn->chessman = Chessman::NONE;
			thisPawn->color = Color::NONE;
			move = true;
		}
		else if ((thisPawn->y + 1 == thatSpace->y || thisPawn->y - 1 == thatSpace->y) && thisPawn->x - 1 == thatSpace->x && thatSpace->color == Color::BLACK) //capturing
		{
			ColeredChessman* temp;
			temp = thisPawn;
			thatSpace->chessman = temp->chessman;
			thatSpace->color = temp->color;
			thisPawn->chessman = Chessman::NONE;
			thisPawn->color = Color::NONE;
			move = true;
		}
		else if ((thisPawn->y + 1 == thatSpace->y || thisPawn->y - 1 == thatSpace->y) && thisPawn->x - 1 == thatSpace->x && thatSpace->color == Color::NONE) //en passant
		{
			int x1 = moveset[roundnum - 1][0] - '0';
			int y1 = moveset[roundnum - 1][1] - '0';
			int x2 = moveset[roundnum - 1][2] - '0';
			int y2 = moveset[roundnum - 1][3] - '0';
			if (abs(y2 - thisPawn->y) == 1 && x1 == 1 && x2 == x1 + 2)
			{
				ColeredChessman* temp;
				temp = thisPawn;
				thatSpace->chessman = temp->chessman;
				thatSpace->color = temp->color;
				thisPawn->chessman = Chessman::NONE;
				thisPawn->color = Color::NONE;
				Board::board.checkerboard[x2][y2].chessman = Chessman::NONE;
				Board::board.checkerboard[x2][y2].color = Color::NONE;
				move = true;
			}
		}

		if (move == true) //promotion
		{
			if (thatSpace->x == 0) //currently just promote to queen first. Change promotion types later
			{

				cout << "Input type.(Queen Rook Knight Bishop)" << endl;
				map<string, Chessman> chessman_string
				{
			{ "Queen", Chessman::QUEEN },	//皇后
			{ "Rook", Chessman::ROOK },		//城堡
			{ "Knight", Chessman::KNIGHT },	//騎士
			{ "Bishop", Chessman::BISHOP }	//主教
				};

				string type_promote;
				cin >> type_promote;
				if (type_promote == "Queen" || type_promote == "Rook" || type_promote == "Knight" || type_promote == "Bishop")
				{
					ColeredChessman* temp;
					temp = thisPawn;
					thatSpace->chessman = chessman_string[type_promote];
					thatSpace->color = color;
					thisPawn->chessman = Chessman::NONE;
					thisPawn->color = Color::NONE;
					return true;
				}
			}
				
			
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	if (thisPawn->color == Color::BLACK) //black pawn
	{
		bool move = false;
		if (thisPawn->y == thatSpace->y && thisPawn->x == 1 && thatSpace->x == thisPawn->x + 2 && thatSpace->color == Color::NONE) //double move
		{
			ColeredChessman* temp;
			temp = thisPawn;
			thatSpace->chessman = temp->chessman;
			thatSpace->color = temp->color;
			thisPawn->chessman = Chessman::NONE;
			thisPawn->color = Color::NONE;
			move = true;
		}
		else if (thisPawn->y == thatSpace->y && thisPawn->x + 1 == thatSpace->x && thatSpace->color == Color::NONE) //if has nothing from a to b then move to b
		{
			ColeredChessman* temp;
			temp = thisPawn;
			thatSpace->chessman = temp->chessman;
			thatSpace->color = temp->color;
			thisPawn->chessman = Chessman::NONE;
			thisPawn->color = Color::NONE;
			move = true;
		}
		else if ((thisPawn->y + 1 == thatSpace->y || thisPawn->y - 1 == thatSpace->y) && thisPawn->x + 1 == thatSpace->x && thatSpace->color == Color::WHITE) //white pawn
		{
			ColeredChessman* temp;
			temp = thisPawn;
			thatSpace->chessman = temp->chessman;
			thatSpace->color = temp->color;
			thisPawn->chessman = Chessman::NONE;
			thisPawn->color = Color::NONE;
			move = true;
		}
		else if ((thisPawn->y + 1 == thatSpace->y || thisPawn->y - 1 == thatSpace->y) && thisPawn->x + 1 == thatSpace->x && thatSpace->color == Color::NONE) //en passant
		{
			int x1 = moveset[roundnum - 1][0] - '0';
			int y1 = moveset[roundnum - 1][1] - '0';
			int x2 = moveset[roundnum - 1][2] - '0';
			int y2 = moveset[roundnum - 1][3] - '0';
			if (abs(y2 - thisPawn->y) == 1 && x1 == 6 && x2 == x1 - 2)
			{
				ColeredChessman* temp;
				temp = thisPawn;
				thatSpace->chessman = temp->chessman;
				thatSpace->color = temp->color;
				thisPawn->chessman = Chessman::NONE;
				thisPawn->color = Color::NONE;
				Board::board.checkerboard[x2][y2].chessman = Chessman::NONE;
				Board::board.checkerboard[x2][y2].color = Color::NONE;
				move = true;
			}
		}

		if (move == true) //promotion
		{
			if (thatSpace->x == 7) //currently just promote to queen first. Change promotion types later
			{
				map<string, Chessman> chessman_string{
			{ "Queen", Chessman::QUEEN },	//皇后
			{ "Rook", Chessman::ROOK },		//城堡
			{ "Knight", Chessman::KNIGHT },	//騎士
			{ "Bishop", Chessman::BISHOP }	//主教
				};

				string type_promote;
				cout << "Input type.(Queen Rook Knight Bishop)" << endl;
				cin >> type_promote;
				if (type_promote == "Queen" || type_promote == "Rook" || type_promote == "Knight" || type_promote == "Bishop")
				{
					ColeredChessman* temp;
					temp = thisPawn;
					thatSpace->chessman = chessman_string[type_promote];
					thatSpace->color = color;
					thisPawn->chessman = Chessman::NONE;
					thisPawn->color = Color::NONE;
					return true;
				}
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
}
bool GameManager::moveIt() //input movement
{
	bool getcheck = isCheck(Board::board.checkerboard);
	if (getcheck == true)
	{
		cout << "You are in Check!\n";
	}
	//if (isCMorSM() == true)
	//{
	//	if (getcheck ==true)
	//	{
	//		cout << "Checkmate!";
	//	}
	//	else
	//	{
	//		cout << "Stalemate!";
	//	}
	//}
	//else
	//{
	//	if (getcheck == true)
	//	{
	//		cout << "Check";
	//	}
	//}



	bool stop = false;
	char x1temp;
	int x1, y1, x2, y2;
	ColeredChessman temp;
	while (!stop) //if has done valid move
	{
		cin >> x1temp;
		if (x1temp == 'u')
		{
			bool undocheck = undo();
			if (undocheck == true)
			{
				return true;
			}
			else
			{
				cout << "no move to be undo.";
				return true;
			}
			
		}
		else if (x1temp == 'r')
		{
			bool redocheck = redo();
			if (redocheck == true)
			{
				return true;
			}
			else
			{
				cout << "no move to be redo.";
				return true;
			}
			
		}
		else if (x1temp >= '0' && x1temp <= '9')
		{
			x1 = x1temp - '0';
		}
		else
		{
			cout << "Invalid Input;\n";
			return true;
		}
		cin >> y1 >> x2 >> y2; //change later with Viewer's Input!
		if (x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>7) //out of bound
		{
			cout << "Out of Bounds, Try Again.\n";
			return true;
		}

		if (isValid(x1, y1, x2, y2) == true) //if valid movement and is not in check
		{
			temp = ColeredChessman(Board::board.checkerboard[x2][y2].chessman, Board::board.checkerboard[x2][y2].color, x2, y2);
			bool check = false;

			switch (Board::board.checkerboard[x1][y1].chessman) //valid piece movements
			{
			case Chessman::KING: check = moveKing(Board::board.getChessman(x1, y1), Board::board.getChessman(x2, y2), Board::board.checkerboard);
				break;
			case Chessman::QUEEN:check = moveQueen(Board::board.getChessman(x1, y1), Board::board.getChessman(x2, y2), Board::board.checkerboard);
				break;
			case Chessman::BISHOP: check = moveBishop(Board::board.getChessman(x1, y1), Board::board.getChessman(x2, y2), Board::board.checkerboard);
				break;
			case Chessman::KNIGHT: check = moveKnight(Board::board.getChessman(x1, y1), Board::board.getChessman(x2, y2), Board::board.checkerboard);
				break;
			case Chessman::ROOK: check = moveRook(Board::board.getChessman(x1, y1), Board::board.getChessman(x2, y2), Board::board.checkerboard);
				break;
			case Chessman::PAWN: check = movePawn(Board::board.getChessman(x1, y1), Board::board.getChessman(x2, y2), Board::board.checkerboard);
				break;
			}
			stop = check;
			if (check == false)
			{
				cout << "Invalid Move\n";
				return true;
			}
		}
		else
		{
			cout << "Invalid Move";
			return true;
		}
		string a = to_string(x1) + to_string(y1) + to_string(x2) + to_string(y2) + "\n";
		if (roundnum == moveset.size())
		{
			moveset.push_back(a);
			piecetaken.push_back(temp);
			roundnum++;
		}
		else
		{
			moveset[roundnum] = a;
			piecetaken[roundnum] = temp;
			roundnum++;
		}

		if (color == Color::BLACK)
		{
			color = Color::WHITE;
		}
		else if (color == Color::WHITE)
		{
			color = Color::BLACK;
		}
		if (current_player == 0)
		{
			current_player = 1;
		}
		else if (current_player == 1)
		{
			current_player = 0;
		}
		return true;
	}
}
	
bool GameManager::isCheck(ColeredChessman checkerboardtemp[8][8]) //is our own king in check
{
	Position kingPos = findChessman(Chessman::KING, color, checkerboardtemp); //king's x and y posiiton
	if (kingPos.x == -1 && kingPos.y == -1) return false;
	bool check = false;
	ColeredChessman checkerboard[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			checkerboard[i][j] = checkerboardtemp[i][j];
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (checkerboard[i][j].color != color && checkerboard[i][j].chessman != Chessman::NONE)
			{
				switch (checkerboard[i][j].chessman)
				{
				case Chessman::KING:
					check = moveKing(&checkerboard[i][j], &checkerboard[kingPos.x][kingPos.y], checkerboard);
					break;
				case Chessman::QUEEN:
					check = moveQueen(&checkerboard[i][j], &checkerboard[kingPos.x][kingPos.y], checkerboard);
					break;
				case Chessman::BISHOP:
					check = moveBishop(&checkerboard[i][j], &checkerboard[kingPos.x][kingPos.y], checkerboard);
					break;
				case Chessman::KNIGHT:
					check = moveKnight(&checkerboard[i][j], &checkerboard[kingPos.x][kingPos.y], checkerboard);
					break;
				case Chessman::ROOK:
					check = moveRook(&checkerboard[i][j], &checkerboard[kingPos.x][kingPos.y], checkerboard);
					break;
				case Chessman::PAWN:
					check = movePawn(&checkerboard[i][j], &checkerboard[kingPos.x][kingPos.y], checkerboard);
					break;
				}
				if (check == true) //if our King is able to be eaten in the next move, then it is in check
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool GameManager::isValid(int x1, int y1, int x2, int y2)
{
	ColeredChessman checkerboardTemp[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			checkerboardTemp[i][j] = ColeredChessman(Board::board.checkerboard[i][j].chessman, Board::board.checkerboard[i][j].color, i, j);
		}
	}
	bool check = false;
	if (checkerboardTemp[x1][y1].color == color) //if move the correct piece and destination is not the same color
	{
		switch (checkerboardTemp[x1][y1].chessman) //valid piece movements
		{
		case Chessman::KING: check = moveKing(&checkerboardTemp[x1][y1], &checkerboardTemp[x2][y2], checkerboardTemp);
			break;
		case Chessman::QUEEN:check = moveQueen(&checkerboardTemp[x1][y1], &checkerboardTemp[x2][y2], checkerboardTemp);
			break;
		case Chessman::BISHOP: check = moveBishop(&checkerboardTemp[x1][y1], &checkerboardTemp[x2][y2], checkerboardTemp);
			break;
		case Chessman::KNIGHT: check = moveKnight(&checkerboardTemp[x1][y1], &checkerboardTemp[x2][y2], checkerboardTemp);
			break;
		case Chessman::ROOK: check = moveRook(&checkerboardTemp[x1][y1], &checkerboardTemp[x2][y2], checkerboardTemp);
			break;
		case Chessman::PAWN: check = movePawn(&checkerboardTemp[x1][y1], &checkerboardTemp[x2][y2], checkerboardTemp);
			break;
		}
	}
	if (check == false)
	{
		return false;;
	}
	else if (isCheck(checkerboardTemp) == true)
	{
		return false;
	}
	else
	{	
		return true;
	}
}

bool GameManager::isCMorSM() //Not Yet Perfect because only check the Checkmate by no King Moves.
{
	Position kingPos = findChessman(Chessman::KING, color, Board::board.checkerboard); //king's x and y posiiton
	if (kingPos.x == -1 && kingPos.y == -1) return false;
	bool check = false;
	for (int x = kingPos.x - 1; x <= kingPos.x + 1; x++) //all 9 squares surrounding the King, including the King's current position, is considered as possible King Position
	{
		for (int y = kingPos.y - 1; y <= kingPos.y + 1; y++)
		{
			if (x < 0 || x>7 || y < 0 || y>7) //out of bound
			{
				continue;
			}
			if (x == kingPos.x && y == kingPos.y) //if the real current position, continue
			{
				continue;
			}
			if (isValid(kingPos.x, kingPos.y, x, y) == true)
			{
				return false;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Board::board.checkerboard[i][j].chessman == Chessman::ROOK && Board::board.checkerboard[i][j].color == color)
			{
				int x = i, y = j;
				for (int k = x - 7; k < 14; k++) //horizontal movement of Rook
				{
					if (k < 0 || k>7)
					{
						continue;
					}
					if (isValid(x, y, k, y) == true)
					{
						return false;
					}
				}

				for (int k = y - 7; k < 14; k++) //vertical movement of rook
				{
					if (k < 0 || k>7)
					{
						continue;
					}
					if (isValid(x, y, x, k) == true)
					{
						return false;
					}
				}
			}
			else if (Board::board.checkerboard[i][j].chessman == Chessman::BISHOP && Board::board.checkerboard[i][j].color == color)
			{
				int x = i, y = j;
				for (int k = x - 7; k < 14; k++)
				{
					if (x - k < 0 || x - k>7 || y + k < 0 || y + k>7 || k == 0)
					{
						continue;
					}
					if (isValid(x, y, x - k, y + k) == true)
					{
						return false;
					}
				}
				for (int k = x - 7; k < 14; k++)
				{
					if (x + k < 0 || x + k>7 || y + k < 0 || y + k>7 || k == 0)
					{
						continue;
					}
					if (isValid(x, y, x + k, y + k) == true)
					{
						return false;
					}
				}
			}
			else if (Board::board.checkerboard[i][j].chessman == Chessman::KNIGHT && Board::board.checkerboard[i][j].color == color)
			{
				if (i + 2 <= 7 && j + 1 <= 7 && i + 2 >= 0 && j + 1 >= 0)
				{
					if (isValid(i, j, i + 2, j + 1) == true)
					{
						return false;
					}
				}
				if (i + 2 <= 7 && j - 1 <= 7 && i + 2 >= 0 && j - 1 >= 0)
				{
					if (isValid(i, j, i + 2, j - 1) == true)
					{
						return false;
					}
				}
				if (i - 2 <= 7 && j + 1 <= 7 && i - 2 >= 0 && j + 1 >= 0)
				{
					if (isValid(i, j, i - 2, j + 1) == true)
					{
						return false;
					}
				}
				if (i - 2 <= 7 && j - 1 <= 7 && i - 2 >= 0 && j - 1 >= 0)
				{
					if (isValid(i, j, i - 2, j - 1) == true)
					{
						return false;
					}
				}
				if (i - 1 <= 7 && j + 2 <= 7 && i - 1 >= 0 && j + 2 >= 0)
				{
					if (isValid(i, j, i - 1, j + 2) == true)
					{
						return false;
					}
				}
				if (i - 1 <= 7 && j - 2 <= 7 && i - 1 >= 0 && j - 2 >= 0)
				{
					if (isValid( i, j, i - 1, j - 2) == true)
					{
						return false;
					}
				}
				if (i + 2 <= 7 && j + 1 <= 7 && i + 2 >= 0 && j + 1 >= 0)
				{
					if (isValid(i, j, i + 2, j + 1) == true)
					{
						return false;
					}
				}
				if (i + 2 <= 7 && j - 1 <= 7 && i + 2 >= 0 && j - 1 >= 0)
				{
					if (isValid(i, j, i + 2, j - 1) == true)
					{
						return false;
					}
				}
			}
			else if (Board::board.checkerboard[i][j].chessman == Chessman::QUEEN && Board::board.checkerboard[i][j].color == color)
			{
				int x = i, y = j;
				for (int k = x - 7; k < 14; k++)
				{
					if (k < 0 || k>7)
					{
						continue;
					}
					if (isValid( x, y, k, y) == true)
					{
						return false;
					}
				}

				for (int k = y - 7; k < 14; k++)
				{
					if (k < 0 || k>7)
					{
						continue;
					}
					if (isValid( x, y, x, k) == true)
					{
						return false;
					}
				}
				for (int k = x - 7; k < 14; k++)
				{
					if (x - k < 0 || x - k>7 || y + k < 0 || y + k>7 || k == 0)
					{
						continue;
					}
					if (isValid( x, y, x - k, y + k) == true)
					{
						return false;
					}
				}
				for (int k = x - 7; k < 14; k++)
				{
					if (x + k < 0 || x + k>7 || y + k < 0 || y + k>7 || k == 0)
					{
						continue;
					}
					if (isValid( x, y, x + k, y + k) == true)
					{
						return false;
					}
				}
			}
			else if (Board::board.checkerboard[i][j].chessman == Chessman::PAWN && Board::board.checkerboard[i][j].color == color)
			{
				if (color == Color::WHITE)
				{
					if (i - 1 >= 0 && j - 1 >= 0)
					{
						if (isValid( i, j, i - 1, j - 1) == true)
						{
							return false;
						}
					}
					if (i + 1 <= 7 && j - 1 >= 0)
					{
						if (isValid(i, j, i + 1, j - 1) == true)
						{
							return false;
						}
					}
					if (j - 1 >= 0)
					{
						if (isValid(i, j, i, j - 1) == true)
						{
							return false;
						}
					}
					if (j - 2 >= 0)
					{
						if (isValid(i, j, i, j - 2) == true)
						{
							return false;
						}
					}
				}
				else if (color == Color::BLACK)
				{
					if (i - 1 >= 0 && j + 1 <= 7)
					{
						if (isValid(i, j, i - 1, j + 1) == true)
						{
							return false;
						}
					}
					if (i + 1 <= 7 && j + 1 <= 7)
					{
						if (isValid(i, j, i + 1, j + 1) == true)
						{
							return false;
						}
					}
					if (j + 1 <= 7)
					{
						if (isValid(i, j, i, j + 1) == true)
						{
							return false;
						}
					}
					if (j + 2 <= 7)
					{
						if (isValid( i, j, i, j + 2) == true)
						{
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

bool GameManager::undo()
{
	if (roundnum > 0)
	{
		int x1 = moveset[roundnum-1][0] - 48;
		int y1 = moveset[roundnum-1][1] - 48;
		int x2 = moveset[roundnum-1][2] - 48;
		int y2 = moveset[roundnum-1][3] - 48;
		
	
		ColeredChessman* temp;
		temp = Board::board.getChessman(x2,y2);
		Board::board.checkerboard[x1][y1].chessman = temp->chessman;
		Board::board.checkerboard[x1][y1].color = temp->color;;
		Board::board.checkerboard[x2][y2] = piecetaken[roundnum - 1];
		roundnum--;
	
			if (color == Color::BLACK)
			{
				color = Color::WHITE;
			}
			else if (color == Color::WHITE)
			{
				color = Color::BLACK;
			}
			if (current_player == 0)
			{
				current_player = 1;
			}
			else if (current_player == 1)
			{
				current_player = 0;
			}
	}
	else
	{
		return false;
	}
}
bool GameManager::redo()
{
	if (roundnum < moveset.size())
	{
		int x1 = moveset[roundnum][0] - 48;
		int y1 = moveset[roundnum][1] - 48;
		int x2 = moveset[roundnum][2] - 48;
		int y2 = moveset[roundnum][3] - 48;
		
		ColeredChessman* temp;
		temp = Board::board.getChessman(x1, y1);
		Board::board.checkerboard[x2][y2].chessman = temp->chessman;
		Board::board.checkerboard[x2][y2].color = temp->color;
		if (roundnum != 0)
		{
			Board::board.checkerboard[x1][y1] = piecetaken[roundnum - 1];
		}
		else
		{
			Board::board.checkerboard[x1][y1].chessman = Chessman::NONE;
			Board::board.checkerboard[x1][y1].color = Color::NONE;
		}
		roundnum++;

		if (color == Color::BLACK)
		{
			color = Color::WHITE;
		}
		else if (color == Color::WHITE)
		{
			color = Color::BLACK;
		}
		if (current_player == 0)
		{
			current_player = 1;
		}
		else if (current_player == 1)
		{
			current_player = 0;
		}
		return true;
	}
	else
	{
		return false;
	}
}
//HumanPlayer.cpp
#include "HumanPlayer.h"
#include "Board.h"
#include "Gamemanager.h"
void HumanPlayer::OnMove(/* parameters */) 
{
	bool stop = false;
	while (!stop) //if has done valid move
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2; //change later with Viewer's Input!
		if (x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>7) //out of bound
		{
			cout << "Out of Bounds, Try Again.";
			continue;
		}
		
		//if (GM.isValid(GM.color, x1, y1, x2, y2) == true) //if valid movement and is not in check
		//{

			bool check = false;
			if (GM.moveset.size() == GM.roundnum)
			{
				string a = x1 + y1 + x2 + y2 + "\n";
				GM.moveset.push_back(a);
				GM.piecetaken.push_back(ColeredChessman(Board::board.checkerboard[x2][y2].chessman, Board::board.checkerboard[x2][y2].color, x2, y2));
				GM.roundnum++;
			}
			else
			{
				string a = x1 + y1 + x2 + y2 + "\n";
				GM.moveset[GM.roundnum] = (a);
				GM.piecetaken[GM.roundnum] = (ColeredChessman(Board::board.checkerboard[x2][y2].chessman, Board::board.checkerboard[x2][y2].color, x2, y2));
				GM.roundnum++;
			}
			switch (Board::board.checkerboard[x1][y1].chessman) //valid piece movements
			{
			case Chessman::KING: check = GM.moveKing(Board::board.getChessman(x1, y1), Board::board.getChessman(x2, y2), Board::board.checkerboard);
				break;
			case Chessman::QUEEN:check = GM.moveQueen(Board::board.getChessman(x1, y1), Board::board.getChessman(x2, y2), Board::board.checkerboard);
				break;
			case Chessman::BISHOP: check = GM.moveBishop(Board::board.getChessman(x1, y1), Board::board.getChessman(x2, y2), Board::board.checkerboard);
				break;
			case Chessman::KNIGHT: check = GM.moveKnight(Board::board.getChessman(x1, y1), Board::board.getChessman(x2, y2), Board::board.checkerboard);
				break;
			case Chessman::ROOK: check = GM.moveRook(Board::board.getChessman(x1, y1), Board::board.getChessman(x2, y2), Board::board.checkerboard);
				break;
			case Chessman::PAWN: check = GM.movePawn(Board::board.getChessman(x1, y1), Board::board.getChessman(x2, y2), Board::board.checkerboard);
				break;
			}
			stop = check;
		/*}
		else
		{
			cout << "Invalid Move";
		}*/
	}
}

void HumanPlayer::OnPromote(Position p) {
	map<string, Chessman> chessman_string{
			{ "Queen", Chessman::QUEEN },	//¬Ó¦Z
			{ "Rook", Chessman::ROOK },		//«°³ù
			{ "Knight", Chessman::KNIGHT },	//ÃM¤h
			{ "Bishop", Chessman::BISHOP },	//¥D±Ð
	};
	auto chessType{ Board::board.checkerboard[p.x][p.y].chessman };
	auto chessColor{ Board::board.checkerboard[p.x][p.y].color };
	if (chessType == Chessman::PAWN) {
		string type_promote;
		cout << "Input type.(Queen Rook Knight Bishop)" << endl;
		cin >> type_promote;
		switch (chessColor)
		{
		case Color::NONE:
			break;
		case Color::BLACK:
			if (p.y == 7) {
				Board::board.checkerboard[p.x][p.y].chessman = chessman_string[type_promote];
			}
			break;
		case Color::WHITE:
			if (p.y == 0) {
				Board::board.checkerboard[p.x][p.y].chessman = chessman_string[type_promote];
			}
			break;
		default:
			break;
		}
	}
	else {
		cout << "Cannot promote." << endl;
	}
}
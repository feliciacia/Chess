#include <iostream>
using namespace std;
#include "Gamemanager.h"
#include <Windows.h>
#include <conio.h>

void gotoxy(int x, int y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x,y };
	SetConsoleCursorPosition(h, position);
}

int main()
{
	bool numnum = true;
	GameManager GM;
	while (numnum)
	{
		system("cls");
		for (int i = 0; i < 8; i++)
		{
			cout << i << " ";
			for (int j = 0; j < 8; j++)
			{
				if (Board::board.checkerboard[i][j].color == Color::WHITE)
				{
					switch (Board::board.checkerboard[i][j].chessman)
					{
					case Chessman::KING: cout << "|K"; break;
					case Chessman::QUEEN:cout << "|Q"; break;
					case Chessman::BISHOP: cout << "|B"; break;
					case Chessman::KNIGHT: cout << "|N"; break;
					case Chessman::ROOK: cout << "|R"; break;
					case Chessman::PAWN: cout << "|P"; break;
					}
				}
				else if (Board::board.checkerboard[i][j].color == Color::BLACK)
				{
					switch (Board::board.checkerboard[i][j].chessman)
					{
					case Chessman::KING: cout << "|k"; break;
					case Chessman::QUEEN:cout << "|q"; break;
					case Chessman::BISHOP: cout << "|b"; break;
					case Chessman::KNIGHT: cout << "|n"; break;
					case Chessman::ROOK: cout << "|r"; break;
					case Chessman::PAWN: cout << "|p"; break;
					}
				}
				else
				{
					cout << "| ";
				}
			}
			cout << "|\n";
		}
		gotoxy(30, 0);
		cout << "Move Done";
		for (int i = 0; i < GM.roundnum; i++)
		{
			if (i % 2 == 0)
			{
				gotoxy(25, 1 + i / 2);
				cout << GM.moveset[i];
			}
			else
			{
				gotoxy(35, 1 + i / 2);
				cout << GM.moveset[i];
			}			
		}
		gotoxy(0, 10);
		bool KingFound = false;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++) //searching for the king
			{
				if (Board::board.checkerboard[i][j].chessman == Chessman::KING)
				{
					if (Board::board.checkerboard[i][j].color == GM.color)
					{
						KingFound = true;
						break;
					}
				}
			}
			if (KingFound == true)
			{
				break;
			}
		}

		if (KingFound == false)
		{
			if (GM.color == Color::WHITE)
			{
				cout << "White";
			}
			else
			{
				cout << "Black";
			}
			cout << " Lose!\n";
			break;
		}
		numnum = GM.moveIt();
		Sleep(1000);
	}
}
#include <iostream>
#include <vector>
#include "Color.h"
#include "Board.h"
#include "Player.h"

int main()
{
    std::cout << "Hello Candy Land!\n";
}

static void PrintBoard(const std::vector<Player>& players, const Board& brd) 
{
	const int MAX_COLS = 20;
	int cols = 0;

	for (int index = 0; index < brd.GetTotalSpaces(); index++) 
	{
		bool playerFound = false;

		for (const Player& player : players)
		{
			if (player.GetSpaceIndex() == index) 
			{
				std::cout << player.GetPlayerNumber();
				playerFound = true;
			}
		}

		if (!playerFound) 
		{
			if (brd.IsShortcutAt(index))
			{
				std::cout << "S";
			}
			else if (brd.IsTurnLostAt(index))
			{
				std::cout << "X";
			}
			else 
			{
				switch (brd.GetColorAt(index))
				{
					case Color::TileColor::Mint:
						std::cout << "M";
						break;
					case Color::TileColor::IceCream:
						std::cout << "I";
						break;
					case Color::TileColor::Lollypop:
						std::cout << "L";
						break;
					case Color::TileColor::Peanut:
						std::cout << "P";
						break;
					case Color::TileColor::Empty:
						std::cout << "K";
						break;
					default:
						std::cout << "_";
						break;
				}
			}
		}

		cols++;

		if (cols >= MAX_COLS) 
		{
			std::cout << "\n";
			cols = 0;
		}
	}

	if (cols == 0) 
	{
		std::cout << "\n";
	}
	else 
	{
		std::cout << "\n\n";
	}
}
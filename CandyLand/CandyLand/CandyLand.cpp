/*
	Project Statement 3: Candy Land
	Jonathan Muniz
	Brian Izquierdo

	Code similates a game of Candy Land both standard rules and rules for older
	players. The application will run several games with both rulsets and compare
	the average turns and runtimes
*/
#include <iostream>
#include <vector>
#include "Color.h"
#include "Board.h"
#include "Player.h"
#include <chrono>

/*
	Prints a given board in reference to given Players

	no return
*/
void PrintBoard(const std::vector<Player>& players, const Board& brd)
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
				break;
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

/*
	Creates a Board in the traditional format of Candy Land

	returns a Board
*/
Board CreateCandyLandBoard()
{
	const int SHORTCUT_1_BEGIN = 3;
	const int SHORTCUT_1_END = 35;
	const int SHORTCUT_2_BEGIN = 17;
	const int SHORTCUT_2_END = 24;

	Board brd;
	brd.AddSpace(Color::TileColor::Red);
	brd.AddSpace(Color::TileColor::Purple);
	brd.AddSpace(Color::TileColor::Yellow);
	brd.AddSpace(Color::TileColor::Blue);
	brd.AddSpace(Color::TileColor::Orange);
	brd.AddSpace(Color::TileColor::Green);
	brd.AddSpace(Color::TileColor::Red);
	brd.AddSpace(Color::TileColor::Purple);
	brd.AddSpace(Color::TileColor::Yellow);
	brd.AddSpace(Color::TileColor::Blue);
	brd.AddSpace(Color::TileColor::Orange);
	brd.AddSpace(Color::TileColor::Green);
	brd.AddSpace(Color::TileColor::Red);
	brd.AddSpace(Color::TileColor::Purple);
	brd.AddSpace(Color::TileColor::Yellow);
	brd.AddSpace(Color::TileColor::Blue);
	brd.AddSpace(Color::TileColor::Orange);
	brd.AddSpace(Color::TileColor::Green);
	brd.AddSpace(Color::TileColor::Red);
	brd.AddSpace(Color::TileColor::Purple);
	brd.AddSpace(Color::TileColor::Mint);
	brd.AddSpace(Color::TileColor::Yellow);
	brd.AddSpace(Color::TileColor::Blue);
	brd.AddSpace(Color::TileColor::Orange);
	brd.AddSpace(Color::TileColor::Green);
	brd.AddSpace(Color::TileColor::Red);
	brd.AddLoseTurnSpace(Color::TileColor::Purple);
	brd.AddSpace(Color::TileColor::Yellow);
	brd.AddSpace(Color::TileColor::Blue);
	brd.AddSpace(Color::TileColor::Orange);
	brd.AddSpace(Color::TileColor::Green);
	brd.AddSpace(Color::TileColor::Red);
	brd.AddSpace(Color::TileColor::Peanut);
	brd.AddSpace(Color::TileColor::Purple);
	brd.AddSpace(Color::TileColor::Yellow);
	brd.AddSpace(Color::TileColor::Blue);
	brd.AddSpace(Color::TileColor::Orange);
	brd.AddSpace(Color::TileColor::Green);
	brd.AddSpace(Color::TileColor::Red);
	brd.AddSpace(Color::TileColor::Purple);
	brd.AddSpace(Color::TileColor::Yellow);
	brd.AddSpace(Color::TileColor::Blue);
	brd.AddSpace(Color::TileColor::Orange);
	brd.AddSpace(Color::TileColor::Green);
	brd.AddSpace(Color::TileColor::Red);
	brd.AddSpace(Color::TileColor::Purple);
	brd.AddSpace(Color::TileColor::Yellow);
	brd.AddSpace(Color::TileColor::Blue);
	brd.AddSpace(Color::TileColor::Orange);
	brd.AddSpace(Color::TileColor::Lollypop);
	brd.AddSpace(Color::TileColor::Green);
	brd.AddSpace(Color::TileColor::Red);
	brd.AddSpace(Color::TileColor::Purple);
	brd.AddLoseTurnSpace(Color::TileColor::Yellow);
	brd.AddSpace(Color::TileColor::Blue);
	brd.AddSpace(Color::TileColor::Orange);
	brd.AddSpace(Color::TileColor::Green);
	brd.AddSpace(Color::TileColor::Red);
	brd.AddSpace(Color::TileColor::Purple);
	brd.AddSpace(Color::TileColor::Yellow);
	brd.AddSpace(Color::TileColor::Blue);
	brd.AddSpace(Color::TileColor::Orange);
	brd.AddSpace(Color::TileColor::Green);
	brd.AddSpace(Color::TileColor::Red);
	brd.AddSpace(Color::TileColor::Purple);
	brd.AddSpace(Color::TileColor::Yellow);
	brd.AddSpace(Color::TileColor::IceCream);
	brd.AddSpace(Color::TileColor::Blue);
	brd.AddSpace(Color::TileColor::Orange);
	brd.AddSpace(Color::TileColor::Green);
	brd.AddSpace(Color::TileColor::Red);
	brd.AddSpace(Color::TileColor::Purple);
	brd.AddSpace(Color::TileColor::Yellow);
	brd.AddSpace(Color::TileColor::Blue);
	brd.AddSpace(Color::TileColor::Orange);
	brd.AddSpace(Color::TileColor::Green);
	brd.AddSpace(Color::TileColor::Red);
	brd.AddSpace(Color::TileColor::Purple);
	brd.AddSpace(Color::TileColor::Yellow);
	brd.AddSpace(Color::TileColor::Blue);
	brd.AddSpace(Color::TileColor::Orange);
	brd.AddSpace(Color::TileColor::Green);
	brd.AddSpace(Color::TileColor::Empty);
	brd.LinkSpaces(SHORTCUT_1_BEGIN, SHORTCUT_1_END);
	brd.LinkSpaces(SHORTCUT_2_BEGIN, SHORTCUT_2_END);

	return brd;
}

/*
	Moves given player on a given Board based on a given Card

	Special occurances will be printed out to the console
*/
void MovePlayer(Player& player, const Card& card, Board& brd) 
{
	bool shortcutTaken = false;
	brd.LeaveSpaceAt(player.GetSpaceIndex());
	player.SetSpaceIndex(brd.GetNextColorSpaceIndex(player.GetSpaceIndex(), card, shortcutTaken));
	brd.OccupySpaceAt(player.GetSpaceIndex());

	if (shortcutTaken) 
	{
		std::cout << "Player " << player.GetPlayerNumber() << " used a shortcut!" << std::endl;
	}
	if (brd.IsTurnLostAt(player.GetSpaceIndex())) 
	{
		player.LoseTurn();
		std::cout << "Player " << player.GetPlayerNumber() << " lost a turn!" << std::endl;
	}
}

/*
	Chooses the better of two given cards when used on a given Board from
	at given Player

	returns a Card
*/
Card ChooseCard(Player& player, const Card& card1, const Card& card2, const Board& brd) 
{
	bool shortcutTaken = false;
	int index1 = brd.GetNextColorSpaceIndex(player.GetSpaceIndex(), card1, shortcutTaken);
	int index2 = brd.GetNextColorSpaceIndex(player.GetSpaceIndex(), card2, shortcutTaken);

	if ((brd.IsTurnLostAt(index1) && brd.IsTurnLostAt(index2))
		|| (!brd.IsTurnLostAt(index1) && !brd.IsTurnLostAt(index2)))
	{
		if (index1 > index2) 
		{
			return card1;
		}
		else 
		{
			return card2;
		}
	}
	else if (brd.IsTurnLostAt(index1)) 
	{
		return card2;
	}
	else 
	{
		return card1;
	}
}

/*
	Plays a game of Candy Land

	Players must reach the end to win

	Will return an int of the amount of turns it takes for thr game to finish
*/
int CandyLand(int numPlayers) 
{
	std::vector<Player> players;

	for (int num = 1; num <= numPlayers; num++) 
	{
		players.emplace_back(Player(num));
	}

	Board brd = CreateCandyLandBoard();
	//Create deck here

	int turns = 0;
	int playerTurn = 0;
	bool gameOver = false;

	std::cout << "Starting Candy Land Game" << std::endl;

	while (!gameOver) 
	{
		if (players[playerTurn].IsTurnLost()) 
		{
			players[playerTurn].WaitLostTurn();
		}
		else 
		{
			//replace below with deck draw
			Card card = Card(Color::TileColor::Red, 2);

			std::cout << "Player " << players[playerTurn].GetPlayerNumber() << " drew "
				<< card.ToString() << "! Updating Board." << std::endl;

			MovePlayer(players[playerTurn], card, brd);
			PrintBoard(players, brd);

			if (players[playerTurn].GetSpaceIndex() == brd.GetLastIndex()) 
			{
				std::cout << "Player " << players[playerTurn].GetPlayerNumber() << " WON!\n\n";
				gameOver = true;
			}
		}

		playerTurn++;

		if (playerTurn >= numPlayers) 
		{
			playerTurn = 0;
		}

		turns++;
	}

	return turns;
}

/*
	Plays a game of Candy with the rules for older players drawing 2 cards and choosing 1

	Players must reach the end to win

	Will return an int of the amount of turns it takes for thr game to finish
*/
int CandyLandForOlderPlayers(int numPlayers)
{
	std::vector<Player> players;

	for (int num = 1; num <= numPlayers; num++)
	{
		players.emplace_back(Player(num));
	}

	Board brd = CreateCandyLandBoard();
	//Create deck here

	int turns = 0;
	int playerTurn = 0;
	bool gameOver = false;

	std::cout << "Starting Candy Land For Older Players Game" << std::endl;

	while (!gameOver)
	{
		if (players[playerTurn].IsTurnLost())
		{
			players[playerTurn].WaitLostTurn();
		}
		else
		{
			//replace below with deck draw
			Card card1 = Card(Color::TileColor::Red, 2);
			//Replace below with deck draw
			Card card2 = Card(Color::TileColor::Blue, 2);

			std::cout << "Player " << players[playerTurn].GetPlayerNumber() << " drew ["
				<< card1.ToString() << ", " << card2.ToString() 
				<< "]! Updating Board." << std::endl;

			Card chosenCard = ChooseCard(players[playerTurn], card1, card2, brd);

			std::cout << "Player " << players[playerTurn].GetPlayerNumber() << " chose "
				<< chosenCard.ToString() << "! Updating Board." << std::endl;

			MovePlayer(players[playerTurn], chosenCard, brd);
			PrintBoard(players, brd);

			if (players[playerTurn].GetSpaceIndex() == brd.GetLastIndex())
			{
				std::cout << "Player " << players[playerTurn].GetPlayerNumber() << " WON!\n\n";
				gameOver = true;
			}
		}

		playerTurn++;

		if (playerTurn >= numPlayers)
		{
			playerTurn = 0;
		}

		turns++;
	}

	return turns;
}

int main()
{
	const int NUM_PLAYERS = 4;
	const int TOTAL_GAMES = 10;

	int totalStrdCLTurns = 0;
	double totalStrdCLRuntime = 0.0;
	int totalOldrCLTurns = 0;
	double totalOldrCLRuntime = 0.0;
	for (int game = 0; game < TOTAL_GAMES; game++) 
	{
		auto begin = std::chrono::steady_clock::now();
		totalStrdCLTurns += CandyLand(NUM_PLAYERS);
		auto end = std::chrono::steady_clock::now();
		totalStrdCLRuntime += (double)std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

		begin = std::chrono::steady_clock::now();
		totalOldrCLTurns += CandyLandForOlderPlayers(NUM_PLAYERS);
		end = std::chrono::steady_clock::now();
		totalOldrCLRuntime += (double)std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	}

	float avgStrdCLTurns = (float)totalStrdCLTurns / (float)TOTAL_GAMES;
	double avgStrdCLRuntime = totalStrdCLRuntime / (double)TOTAL_GAMES;
	float avgOldrCLTurns = (float)totalOldrCLTurns / (float)TOTAL_GAMES;
	double avgOldrCLRuntime = totalOldrCLRuntime / (double)TOTAL_GAMES;

	std::cout << "Games Played: " << TOTAL_GAMES << std::endl;
	std::cout << "Average Candy Land Turns: " << avgStrdCLTurns << std::endl;
	std::cout << "Average Candy Land Runtime: " << avgStrdCLRuntime << " ms" << std::endl;
	std::cout << "Average Candy Land For Older Players Turns: " << avgOldrCLTurns << std::endl;
	std::cout << "Average Candy Land For Older Players Runtime: " << avgOldrCLRuntime << " ms" << std::endl;
}

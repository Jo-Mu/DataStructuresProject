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
#include "Deck.h"
#include <map>
#include <string>
#include <chrono>
#include <random>

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
	Loads a given deck with a preset pool of cards at random

	no return
*/
void LoadDeck(Deck& deck) 
{
	std::vector<Card> cardPool{ Card(Color::TileColor::Red, 1), Card(Color::TileColor::Red, 2)
	, Card(Color::TileColor::Blue, 1), Card(Color::TileColor::Blue, 2),  Card(Color::TileColor::Green, 1)
	, Card(Color::TileColor::Green, 2), Card(Color::TileColor::Purple, 1), Card(Color::TileColor::Purple, 2)
	, Card(Color::TileColor::Yellow, 1), Card(Color::TileColor::Yellow, 2), Card(Color::TileColor::Orange, 1)
	, Card(Color::TileColor::Orange, 2), Card(Color::TileColor::Mint, 1), Card(Color::TileColor::Lollypop, 1)
	, Card(Color::TileColor::Peanut, 1), Card(Color::TileColor::IceCream, 1) };

	std::map<std::string, int> cardTotals;
	cardTotals["RED"] = 3;
	cardTotals["BLUE"] = 4;
	cardTotals["GREEN"] = 4;
	cardTotals["YELLOW"] = 4;
	cardTotals["PURPLE"] = 3;
	cardTotals["ORANGE"] = 4;
	cardTotals["DOUBLE RED"] = 3;
	cardTotals["DOUBLE GREEN"] = 3;
	cardTotals["DOUBLE YELLOW"] = 3;
	cardTotals["DOUBLE PURPLE"] = 3;
	cardTotals["DOUBLE ORANGE"] = 3;
	cardTotals["DOUBLE BLUE"] = 3;
	cardTotals["MINT"] = 1;
	cardTotals["PEANUT"] = 1;
	cardTotals["LOLLYPOP"] = 1;
	cardTotals["ICE CREAM"] = 1;

	std::random_device rd;
	std::mt19937 rng(rd());

	while (!cardPool.empty()) 
	{
		std::uniform_int_distribution<int> dist(0, ((int)cardPool.size() - 1));
		int index = dist(rng);
		deck.AddCard(cardPool[index]);
		cardTotals[cardPool[index].ToString()]--;
		
		if (cardTotals[cardPool[index].ToString()] <= 0) 
		{
			cardPool.erase(cardPool.begin() + index);
		}
	}
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
	Deck deck;
	LoadDeck(deck);

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
			if (deck.IsEmpty()) 
			{
				LoadDeck(deck);
			}

			Card card = deck.DrawCard();

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
	Deck deck;
	LoadDeck(deck);

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
			if (deck.IsEmpty())
			{
				LoadDeck(deck);
			}

			Card card1 = deck.DrawCard();

			if (deck.IsEmpty())
			{
				LoadDeck(deck);
			}

			Card card2 = deck.DrawCard();

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

/*
	Runs several games of Candy Land and Gandy Land For Older Players with
	a given amount of players and prints out the average turns and runtimes
	of the 2 with a given amount of games

	no return
*/
void RuntimeCompare(int numPlayers, int totalGames)
{
	int totalStrdCLTurns = 0;
	double totalStrdCLRuntime = 0.0;
	int totalOldrCLTurns = 0;
	double totalOldrCLRuntime = 0.0;

	for (int game = 0; game < totalGames; game++)
	{
		auto begin = std::chrono::steady_clock::now();
		totalStrdCLTurns += CandyLand(numPlayers);
		auto end = std::chrono::steady_clock::now();
		totalStrdCLRuntime += (double)std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

		begin = std::chrono::steady_clock::now();
		totalOldrCLTurns += CandyLandForOlderPlayers(numPlayers);
		end = std::chrono::steady_clock::now();
		totalOldrCLRuntime += (double)std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	}

	float avgStrdCLTurns = (float)totalStrdCLTurns / (float)totalGames;
	double avgStrdCLRuntime = totalStrdCLRuntime / (double)totalGames;
	float avgOldrCLTurns = (float)totalOldrCLTurns / (float)totalGames;
	double avgOldrCLRuntime = totalOldrCLRuntime / (double)totalGames;

	std::cout << "Games Played: " << totalGames << std::endl;
	std::cout << "Average Candy Land Turns: " << avgStrdCLTurns << std::endl;
	std::cout << "Average Candy Land Runtime: " << avgStrdCLRuntime << " ms" << std::endl;
	std::cout << "Average Candy Land For Older Players Turns: " << avgOldrCLTurns << std::endl;
	std::cout << "Average Candy Land For Older Players Runtime: " << avgOldrCLRuntime << " ms" << std::endl;
}

int main()
{
	const int NUM_PLAYERS = 4;
	const int TOTAL_GAMES = 10;

	RuntimeCompare(NUM_PLAYERS, TOTAL_GAMES);
}

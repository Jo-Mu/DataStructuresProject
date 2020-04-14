//File has functions for representing Player on a board game
#pragma once

class Player
{
	/*
		Constructor for Player

		takes in a player number
	*/
	public:
		Player(int playerNum) 
		{
			playerNumber = playerNum;
			spaceIndex = -1;
			turnLost = false;
		}

		/*
			Gets spaceIndex

			returns an int
		*/
		int GetSpaceIndex() const;
		/*
			Gets playerNumber

			returns an int
		*/
		int GetPlayerNumber() const;
		/*
			Sets spaceIndex with a given index

			no return
		*/
		void SetSpaceIndex(int index);
		/*
			Checks if player has currently lost a turn

			returns a boolean
		*/
		bool IsTurnLost() const;
		/*
			Player loses a turn; sets turnLost to true

			no return
		*/
		void LoseTurn();
		/*
			Player waits lost turn; sets turnLost to false
			
			no return
		*/
		void WaitLostTurn();
	private:
		int playerNumber; //Player number for ordering Player 1, Player 2, etc...
		int spaceIndex = -1; //Space the player is currently occupying
		bool turnLost = false; //Has the player lost a turn
};


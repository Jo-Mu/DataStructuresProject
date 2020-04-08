#pragma once

class Player
{
	public:
		Player(int playerNum) 
		{
			playerNumber = playerNum;
			spaceIndex = -1;
			turnLost = false;
		}

		int GetSpaceIndex() const;
		int GetPlayerNumber() const;
		void SetSpaceIndex(int index);
		bool IsTurnLost() const;
		void LoseTurn();
		void WaitLostTurn();
	private:
		int playerNumber;
		int spaceIndex = -1;
		bool turnLost = false;
};


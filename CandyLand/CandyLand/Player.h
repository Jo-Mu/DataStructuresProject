#pragma once

class Player
{
	public:
		Player() 
		{
			spaceIndex = -1;
			turnLost = false;
		}

		int GetSpaceIndex() const;
		void SetSpaceIndex(int index);
		bool IsTurnLost() const;
		void LoseTurn();
		void WaitLostTurn();
	private:
		int spaceIndex = -1;
		bool turnLost = false;
};


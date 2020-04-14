//File contains declarations for the methods in "Player.h"
#include "Player.h"

/*
	Gets spaceIndex

	returns an int
*/
int Player::GetSpaceIndex() const
{
	return spaceIndex;
}

/*
	Gets playerNumber

	returns an int
*/
int Player::GetPlayerNumber() const
{
	return playerNumber;
}

/*
	Sets spaceIndex with a given index

	no return
*/
void Player::SetSpaceIndex(int index)
{
	spaceIndex = index;
}

/*
	Checks if player has currently lost a turn

	returns a boolean
*/
bool Player::IsTurnLost() const
{
	return turnLost;
}

/*
	Player loses a turn; sets turnLost to true

	no return
*/
void Player::LoseTurn()
{
	turnLost = true;
}

/*
	Player waits lost turn; sets turnLost to false

	no return
*/
void Player::WaitLostTurn()
{
	turnLost = false;
}

#include "Player.h"

int Player::GetSpaceIndex() const
{
	return spaceIndex;
}

int Player::GetPlayerNumber() const
{
	return playerNumber;
}

void Player::SetSpaceIndex(int index)
{
	spaceIndex = index;
}

bool Player::IsTurnLost() const
{
	return turnLost;
}

void Player::LoseTurn()
{
	turnLost = true;
}

void Player::WaitLostTurn()
{
	turnLost = false;
}

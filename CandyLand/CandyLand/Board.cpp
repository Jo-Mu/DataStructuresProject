//File contains declarations for the methods in "Board.h"
#include "Board.h"

/*
	Gets the color of the Space

	returns a TileColor
*/
Color::TileColor Board::Space::GetColor() const
{
	return color;
}

/*
	Checks if Space is a lose turn space

	returns boolean loseTurn
*/
bool Board::Space::IsLoseTurn() const
{
	return loseTurn;
}

/*
	Checks if Space is linked to a shortcut

	returns boolean isShortcut
*/
bool Board::Space::IsShortcut() const
{
	return isShortcut;
}

/*
	Gets the index of the shorcut the Space is linked to

	returns int
*/
int Board::Space::GetShortcutIndex() const
{
	return shortcutIndex;
}

/*
	Sets the shortcutIndex of the Space to a given index

	Sets isShortcut to true
*/
void Board::Space::SetShortcutIndex(int index)
{
	isShortcut = true;
	shortcutIndex = index;
}

/*
	Creates a new Space in the board with the given TileColor

	no return
*/
void Board::AddSpace(Color::TileColor color)
{
	brd.emplace_back(Space(color));
}

/*
	Creates a new lose turn Space in the board with the given TileColor

	no return
*/
void Board::AddLoseTurnSpace(Color::TileColor color)
{
	brd.emplace_back(Space(color, true));
}

/*
	Links to Spaces at the given indicies as a shorcut

	if the either of the indicies are outside the board
	then nothing happens'

	no return
*/
void Board::LinkSpaces(int index1, int index2)
{
	if (index1 >= 0 && index1 < GetTotalSpaces() && index2 >= 0 && index2 < GetTotalSpaces())
	{
		brd[index1].SetShortcutIndex(index2);
		brd[index2].SetShortcutIndex(index1);
	}
}

/*
	Checks if there is a shortcut Space at the given index

	returns a boolean
*/
bool Board::IsShortcutAt(int index) const
{
	if (index >= 0 && index < GetTotalSpaces())
	{
		return brd[index].IsShortcut();
	}

	return false;
}

/*
	Checks if there is a lose turn Space at the given index

	returns a boolean
*/
bool Board::IsTurnLostAt(int index) const
{
	if (index >= 0 && index < GetTotalSpaces())
	{
		return brd[index].IsLoseTurn();
	}

	return false;
}

/*
	Gets the TileColor of a Space at the given index

	if outside the the board than an Empty TileColor is returned

	returns a TileColor
*/
Color::TileColor Board::GetColorAt(int index) const
{
	if (index >= 0 && index < GetTotalSpaces())
	{
		return brd[index].GetColor();
	}

	return Color::TileColor::Empty;
}

/*
	Gets the index of the other end of a shortcut at given index

	If there is no shortcut then the original index is returned

	returns an int
*/
int Board::GetShortcutAt(int index) const
{
	if (index >= 0 && index < GetTotalSpaces())
	{
		if (brd[index].IsShortcut()) 
		{
			return brd[index].GetShortcutIndex();
		}
	}

	return index;
}

/*
	Gets the total Spaces in the board

	returns an int
*/
int Board::GetTotalSpaces() const
{
	return brd.size();
}

/*
	Gets the Index of the last index of the board

	If the board is empty then -1 is retuned

	returns an int
*/
int Board::GetLastIndex() const
{
	return (GetTotalSpaces() - 1);
}

/*
	Gets the index of the next space using a given Card and the current
	index of the player

	Takes into account shortcuts

	returns an int
*/
int Board::GetNextColorSpaceIndex(int currIndex, const Card& card) const
{
	Color::TileColor cardColor = card.GetColor();

	if (cardColor == Color::TileColor::Mint || cardColor == Color::TileColor::Lollypop
		|| cardColor == Color::TileColor::IceCream || cardColor == Color::TileColor::Peanut) 
	{
		for (int index = 0; index < GetTotalSpaces(); index++) 
		{
			if (cardColor == GetColorAt(index)) 
			{
				return index;
			}
		}

		return GetLastIndex();
	}
	else 
	{
		int nextIndex = currIndex + 1;
		int quantity = card.GetQuantity();

		while (nextIndex < GetLastIndex() && quantity > 0) 
		{
			if (cardColor == GetColorAt(nextIndex))
			{
				quantity--;
			}

			if (quantity > 0) 
			{
				nextIndex++;
			}
		}

		if (IsShortcutAt(nextIndex)) 
		{
			return GetShortcutAt(nextIndex);
		}

		return nextIndex;
	}
}

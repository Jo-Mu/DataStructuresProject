#include "Board.h"

Color::TileColor Board::Space::GetColor() const
{
	return color;
}

bool Board::Space::IsLoseTurn() const
{
	return loseTurn;
}

bool Board::Space::IsShortcut() const
{
	return isShortcut;
}

int Board::Space::GetShortcutIndex() const
{
	return shortcutIndex;
}

void Board::Space::SetShortcutIndex(int index)
{
	isShortcut = true;
	shortcutIndex = index;
}

void Board::AddSpace(Color::TileColor color)
{
	brd.emplace_back(Space(color));
}

void Board::AddLoseTurnSpace(Color::TileColor color)
{
	brd.emplace_back(Space(color, true));
}

void Board::LinkSpaces(int index1, int index2)
{
	if (index1 >= 0 && index1 < brd.size() && index2 >= 0 && index2 < brd.size())
	{
		brd[index1].SetShortcutIndex(index2);
		brd[index2].SetShortcutIndex(index1);
	}
}

bool Board::IsShortcutAt(int index) const
{
	if (index >= 0 && index < brd.size())
	{
		return brd[index].IsShortcut();
	}

	return false;
}

bool Board::IsTurnLostAt(int index) const
{
	if (index >= 0 && index < brd.size())
	{
		return brd[index].IsLoseTurn();
	}

	return false;
}

Color::TileColor Board::GetColorAt(int index) const
{
	if (index >= 0 && index < brd.size())
	{
		return brd[index].GetColor();
	}

	return Color::TileColor::Empty;
}

int Board::GetShortcutAt(int index) const
{
	if (index >= 0 && index < brd.size())
	{
		if (brd[index].IsShortcut()) 
		{
			return brd[index].GetShortcutIndex();
		}
	}

	return index;
}

int Board::GetNextColorSpaceIndex(int currIndex, const Card& card) const
{
	Color::TileColor cardColor = card.GetColor();

	if (cardColor == Color::TileColor::Mint || cardColor == Color::TileColor::Lollypop
		|| cardColor == Color::TileColor::IceCream || cardColor == Color::TileColor::Peanut) 
	{
		for (int index = 0; index < brd.size(); index++) 
		{
			if (cardColor == GetColorAt(index)) 
			{
				return index;
			}
		}

		return (brd.size() - 1);
	}
	else 
	{
		int nextIndex = currIndex + 1;
		int quantity = card.GetQuantity();

		while (nextIndex < (brd.size() - 1) && quantity > 0) 
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

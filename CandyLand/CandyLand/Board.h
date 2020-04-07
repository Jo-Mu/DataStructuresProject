#pragma once
#include "Color.h"
#include "Card.h"
#include <vector>

class Board
{
	private:
		class Space
		{
			public:
				Space(Color::TileColor spaceColor) 
				{
					color = spaceColor;
					loseTurn = false;
				}

				Space(Color::TileColor spaceColor, bool isLoseTurn)
				{
					color = spaceColor;
					loseTurn = isLoseTurn;
				}

				Color::TileColor GetColor() const;
				bool IsLoseTurn() const;
				bool IsShortcut() const;
				int GetShortcutIndex() const;
				void SetShortcutIndex(int index);

			private:
				Color::TileColor color;
				bool loseTurn = false;
				bool isShortcut = false;
				int shortcutIndex = -1;
		};
	public:
		void AddSpace(Color::TileColor color);
		void AddLoseTurnSpace(Color::TileColor color);
		void LinkSpaces(int index1, int index2);
		bool IsShortcutAt(int index) const;
		bool IsTurnLostAt(int index) const;
		Color::TileColor GetColorAt(int index) const;
		int GetShortcutAt(int index) const;
		int GetNextColorSpaceIndex(int currIndex, const Card& card) const;
	private:
		std::vector<Space> brd;
};


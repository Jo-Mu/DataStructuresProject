/*
	File contains methods, varables, and subclasses to represent
	a Candy Land Board that can be traversed through
*/
#pragma once
#include "Color.h"
#include "Card.h"
#include <vector>

class Board
{
	private:
		//Subclass for a Space in the Board
		class Space
		{
			public:
				/*
					Constructor for Space

					Takes a TileColor, will set loseTurn to false by default
				*/
				Space(Color::TileColor spaceColor) 
				{
					color = spaceColor;
					loseTurn = false;
				}

				/*
					Constructor for Space

					Takes a TileColor and a boolean for whether or not 
					it's a lose turn space
				*/
				Space(Color::TileColor spaceColor, bool isLoseTurn)
				{
					color = spaceColor;
					loseTurn = isLoseTurn;
				}

				/*
					Gets the color of the Space

					returns a TileColor
				*/
				Color::TileColor GetColor() const;
				/*
					Checks if Space is a lose turn space

					returns boolean loseTurn
				*/
				bool IsLoseTurn() const;
				/*
					Checks if Space is linked to a shortcut

					returns boolean isShortcut
				*/
				bool IsShortcut() const;
				/*
					Gets the index of the shorcut the Space is linked to

					returns int
				*/
				int GetShortcutIndex() const;
				/*
					Sets the shortcutIndex of the Space to a given index

					Sets isShortcut to true
				*/
				void SetShortcutIndex(int index);
				/*
					Checks if Space is Occupied

					returns a boolean
				*/
				bool IsOccupied() const;
				/*
					Occupuies Space; sets isOccupied to true

					no return
				*/
				void Occupy();
				/*
					Leave Space; sets isOccupied to false

					no return
				*/
				void Leave();

			private:
				Color::TileColor color; //TileColor of the space
				bool loseTurn = false; //Is Space a lose turn space
				bool isShortcut = false; //Is Space a shortcut
				bool isOccupied = false; //Is Space occupied
				int shortcutIndex = -1; //Index of the shortcut, -1 if none
		};
	public:
		/*
			Creates a new Space in the board with the given TileColor

			no return
		*/
		void AddSpace(Color::TileColor color);
		/*
			Creates a new lose turn Space in the board with the given TileColor

			no return
		*/
		void AddLoseTurnSpace(Color::TileColor color);
		/*
			Links to Spaces at the given indicies as a shorcut

			if the either of the indicies are outside the board
			then nothing happens'

			no return
		*/
		void LinkSpaces(int index1, int index2);
		/*
			Occupies the Space at the given index

			If index outside of Board then nothing happens

			nor return
		*/
		void OccupySpaceAt(int index);
		/*
			Leaves the Space at the given index

			If index outside of Board then nothing happens

			nor return
		*/
		void LeaveSpaceAt(int index);
		/*
			Checks if there is a shortcut Space at the given index

			returns a boolean
		*/
		bool IsShortcutAt(int index) const;
		/*
			Checks if there is a lose turn Space at the given index

			returns a boolean
		*/
		bool IsTurnLostAt(int index) const;
		/*
			Checks if Space at the given index is occupied

			Returns false if not occupied or index is outside Board

			returns a boolean
		*/
		bool IsOccupiedAt(int index) const;
		/*
			Gets the TileColor of a Space at the given index

			if outside the the board than an Empty TileColor is returned

			returns a TileColor
		*/
		Color::TileColor GetColorAt(int index) const;
		/*
			Gets the index of the other end of a shortcut at given index

			If there is no shortcut then the original index is returned

			returns an int
		*/
		int GetShortcutAt(int index) const;
		/*
			Gets the total Spaces in the board

			returns an int
		*/
		int GetTotalSpaces() const;
		/*
			Gets the Index of the last index of the board

			If the board is empty then -1 is retuned

			returns an int
		*/
		int GetLastIndex() const;
		/*
			Gets the index of the next space using a given Card and the current
			index of the player as well as a update a given boolean variable is a shorcut
			is taken

			Takes into account shortcuts and occupied spaces

			returns an int
		*/
		int GetNextColorSpaceIndex(int currIndex, const Card& card, bool& outTakeShortcut) const;
	private:
		std::vector<Space> brd; //The board as a colllection of Space objects
};


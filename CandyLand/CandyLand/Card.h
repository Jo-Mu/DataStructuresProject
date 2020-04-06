#pragma once
#include "Color.h"

class Card
{
	public:
		Card(Color::TileColor cardColor, int numSpaces) 
		{
			color = cardColor;
			
			if (numSpaces > 1)
			{
				quantity = 2;
			}
			else 
			{
				quantity = 1;
			}
		}

		int GetQuantity() const;
		Color::TileColor GetColor() const;

	private:
		Color::TileColor color;
		int quantity;
};


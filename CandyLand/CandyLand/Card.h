//File contains methods to represent a Candy Land card
#pragma once
#include "Color.h"
#include <string>

class Card
{
	public:
		static constexpr int MIN_QUANTITY = 1; //minimum card quantity
		static constexpr int MAX_QUANTITY = 2; //maximum card quantity

		/*
			Card constructor

			Takes a TileColor and an a number of spaces it counts for
		*/
		Card(Color::TileColor cardColor, int numSpaces) 
		{
			color = cardColor;
			
			if (numSpaces > MIN_QUANTITY)
			{
				quantity = MAX_QUANTITY;
			}
			else 
			{
				quantity = MIN_QUANTITY;
			}
		}

		/*
			Gets the quantity of the Card

			returns an int
		*/
		int GetQuantity() const;

		/*
			Gets the TileColor of the Card

			returns an TileColor
		*/
		Color::TileColor GetColor() const;

		/*
			Returns a string representation of a Card

			string wil have the color and, if the quantity is 2, 'DOUBLE'
		*/
		std::string ToString() const;

	private:
		Color::TileColor color; //Card color
		int quantity; //Card quantity
};


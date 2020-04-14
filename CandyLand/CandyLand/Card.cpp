//File contains the declarations for the methods in "Card.h"
#include "Card.h"

/*
	Gets the quantity of the Card

	returns an int
*/
int Card::GetQuantity() const
{
	return quantity;
}

/*
	Gets the TileColor of the Card

	returns an TileColor
*/
Color::TileColor Card::GetColor() const
{
	return color;
}

/*
	Returns a string representation of a Card

	string wil have the color and, if the quantity is 2, 'DOUBLE'
*/
std::string Card::ToString() const
{
	std::string cardStr = "";

	switch (GetColor())
	{
		case Color::TileColor::Blue:
			cardStr = (GetQuantity() == MAX_QUANTITY) ? "DOUBLE BLUE" : "BLUE";
			break;
		case Color::TileColor::Red:
			cardStr = (GetQuantity() == MAX_QUANTITY) ? "DOUBLE RED" : "RED";
			break;
		case Color::TileColor::Green:
			cardStr = (GetQuantity() == MAX_QUANTITY) ? "DOUBLE GREEN" : "GREEN";
			break;
		case Color::TileColor::Purple:
			cardStr = (GetQuantity() == MAX_QUANTITY) ? "DOUBLE PURPLE" : "PURPLE";
			break;
		case Color::TileColor::Yellow:
			cardStr = (GetQuantity() == MAX_QUANTITY) ? "DOUBLE YELLOW" : "YELLOW";
			break;
		case Color::TileColor::Orange:
			cardStr = (GetQuantity() == MAX_QUANTITY) ? "DOUBLE ORANGE" : "ORANGE";
			break;
		case Color::TileColor::Mint:
			cardStr = "MINT";
			break;
		case Color::TileColor::Peanut:
			cardStr = "PEANUT";
			break;
		case Color::TileColor::Lollypop:
			cardStr = "LOLLYPOP";
			break;
		case Color::TileColor::IceCream:
			cardStr = "ICE CREAM";
			break;
		default:
			cardStr = "EMPTY";
			break;
	}

	return cardStr;
}

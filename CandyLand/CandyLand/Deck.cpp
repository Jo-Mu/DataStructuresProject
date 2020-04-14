//File contains declarations for the methods in "Deck.h"
#include "Deck.h"

/*
	Draws a card from the deck

	If the deck is empty then it will return an Empty Card

	returns a Cars
*/
Card Deck::DrawCard()
{
	if (!IsEmpty()) 
	{
		Card card = deck.top();
		deck.pop();
		return card;
	}

	return Card(Color::TileColor::Empty, 1);
}

/*
	Adds a card to the Deck

	no return
*/
void Deck::AddCard(const Card& card)
{
	deck.push(card);
}

/*
	Checks to see if the Deck is empty

	returns a boolean
*/
bool Deck::IsEmpty() const
{
	return deck.empty();
}

/*
	Gets the total Cards in the Deck

	returns an int
*/
int Deck::GetTotalCards() const
{
	return deck.size();
}

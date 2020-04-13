//File contains methods to represent a Deck of cards
#pragma once
#include "Color.h"
#include "Card.h"
#include <stack>

class Deck
{
	public:
		/*
			Draws a card from the deck

			If the deck is empty then it will return an Empty Card

			returns a Cars
		*/
		Card DrawCard();
		/*
			Adds a card to the Deck

			no return
		*/
		void AddCard(const Card& card);
		/*
			Checks to see if the Deck is empty

			returns a boolean
		*/
		bool IsEmpty() const;
		/*
			Gets the total Cards in the Deck

			returns an int
		*/
		int GetTotalCards() const;
	private:
		std::stack<Card> deck;
};


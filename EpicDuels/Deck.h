#pragma once

//#include <iostream>
#include <vector>
#include"CardNorm.h"
#include <random>
#include <algorithm>
using namespace std;

class Deck
{
public:
	Deck(int noc=1)
	{
		numberOfCards = noc;
	}

	//view number of cards in draw pile
	int drawpile()
	{
		return dek.size();
	}

	//view number of cards in discard pile
	int discardpile()
	{
		return disc.size();
	}

	//add a normal card to deck
	void addNCard(NCard a)
	{
		dek.push_back(a);
		shuffleDeck();
	}

	//add a special card

	//draw a card
	void draw()
	{
		
		NCard move;
		if (dek.size() == 0)
		{
			for (int a = 0; a < disc.size(); a++)
			{
				addNCard(disc.at(0));
				disc.erase(disc.begin());
			}
			shuffleDeck();
		}
		NCard pos = dek.at(0);
		dek.erase(dek.begin());
		hand.push_back(pos);
		
	}

	//see hand
	void viewHand()
	{
		if (hand.size() == 0)
			std::cout << "no cards in hand" << std::endl << std::endl;
		for (int a = 0; a < hand.size(); a++)
		{
			hand.at(a).printcard();
		}
	}

	//setnumber of cards in deck
	void setcard(int a)
	{
		numberOfCards = a;
	}

	//find card using card number and remove it fom hand add to discard
	NCard useCard(int c)
	{
		NCard pos;
		for (int a = 0; a < hand.size(); a++)
		{
			if (c == hand.at(a).getCardNumber())
			{
				pos = hand.at(a);
				disc.push_back(pos);
				hand.erase(hand.begin() + a);
			}
		}
		return pos;
	}

	//shuffer elements in dek
	void shuffleDeck()
	{
		std::random_device rd;
		std::default_random_engine rng(rd());
		shuffle(std::begin(dek), std::end(dek), rng);
	}
	

private:
	int numberOfCards;
	std::vector<NCard> dek;
	std::vector <NCard> disc;
	std::vector <NCard> hand;
};

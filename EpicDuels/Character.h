#pragma once

#include <iostream>
#include "Deck.h"
#include "CardNorm.h"

using namespace std;

class Character
{
public:
	//create a character with a name hitpoints a number for association and whether it is ranged or not
	Character(string n = "", int hp= 0, int cn= -1, bool r =0 )
	{
		name = n;
		hitpoint = hp;
		charnum = cn;
		ranged = r;
	}
	//set character number
	void setPlayer(int x)
	{
		charnum = x;
	}

	//check if ranged or not
	bool range()
	{
		return ranged;
	}

	//return the player
	int getPlayer()
	{
		return charnum;
	}

	//character recieves damage
	void takeDamage(int a)
	{
		hitpoint = hitpoint - a;
	}

	//return character name
	string getName()
	{
		return name;
	}

	//get hp
	int getHp()
	{
		return hitpoint;
	}

	//set hp
	void setHp(int hp)
	{
		hitpoint = hp;
	}

	//set name
	void setName(string nm)
	{
		name = nm;
	}

	//add a normal card to the deck
	void addnCard(NCard nc)
	{
		card.addNCard(nc);
	}

	//set the number of cards in the deck
	void setNumberOfCards(int a)
	{
		card.setcard(a);
	}

	//draw a card
	void drawCard()
	{
		card.draw();
	}

	//use attack
	int useAttack(int a)
	{
		NCard c;
		c = card.useCard(a);
		return c.getAttack();
	}

	//use defense
	int useDefense(int a)
	{
		NCard c;
		c = card.useCard(a);
		return c.getAttack();
	}

	//view info on char
	void seeChar()
	{	
		cout << "***************************" << endl;
		std::cout <<"Player: " << charnum<< std::endl << "Character: " << name << std::endl << std::endl;
		std::cout << "HP: " << hitpoint << std::endl<< std::endl;
		std::cout << "Draw pile: " << card.drawpile() << std::endl << "Discard pile: " << card.discardpile() << std::endl << std::endl;
		
		cout << "<<<<<<<<<< Hand <<<<<<<<<<" << endl;
		card.viewHand();
		cout << ">>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "***************************" << endl;
	}
	

private:
	string name;
	int hitpoint;
	Deck card;
	int charnum;
	bool ranged;
};

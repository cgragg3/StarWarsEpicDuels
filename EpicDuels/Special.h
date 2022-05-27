#pragma once

#include <iostream>

using namespace std;

class SpecialCards
{
public:
	//create a special card with card number and if it is attack/defense or just special
	SpecialCards()
	{
		card = 0;
	}

	//set to the particualr ability
	void setCard(int n)
	{
		if (n == 1)
			jediAttack();
	}
	
	int useAbility()
	{
		if (card == 0)
			cout << "not a special card";
		if (card == 1)
			return jediAttack();
	}
	//get ability number
	int getAbility()
	{
		return card;
	}

	
	
	//get attack
	int getSAttack()
	{
		return attack;
	}

	//get Defense
	int getSDefense()
	{
		return defense;
	}


	//obiwans jedi attack
	int jediAttack()
	{
		card = 1;
		combat = true;
		carname = "Jedi Attack";
		abil = "After attacking, you may move obi-wan kenobi up to 6 spaces";
		defense = 0;
		return attack = 6;
	}


	void print()
	{
		cout << "Card name: " << carname << endl << "Attack: " << attack << endl << "Defense: " << defense << endl << "Ability: " << abil << endl << endl;
	}


private:
	int card;
	bool combat;
	int attack;
	int defense;
	string abil;
	string carname;
};

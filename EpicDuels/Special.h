#pragma once

#include <iostream>

using namespace std;

class SpecialCards
{
public:
	//create a special card 
	SpecialCards()
	{
		card = 0;
	}

	//set to the particualr ability
	void setCard(int n)
	{
		if (n == 1)
			jediAttack();
		if (n == 2)
			forceControl();
		if (n == 3)
			forceBlock();
	}
	
	int useAbility()
	{
		if (card == 0)
			cout << "not a special card";
		if (card == 1)
			return jediAttack();
		if (card == 2)
			return forceControl();
		if (card == 3)
			return forceBlock();
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
		carname = "Jedi Attack";
		abil = "After attacking, you may move obi-wan kenobi up to 6 spaces";
		defense = 0;
		return attack = 6;
	}

	//obiwan force control
	int forceControl()
	{
		card = 2;
		carname = "Force Control";
		abil = "After attacking you may move Obi-Wan and the attacked character up to three spaces each";
		defense = 0;
		return attack = 5;
	}

	//obiwan force block
	int forceBlock()
	{
		card = 3;
		carname = "Force Block";
		abil = "Draw a card";
		attack = 0;
		return defense = 12;
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

#pragma once

#include <iostream>
#include <fstream>

#include "Special.h"

using namespace std;

class NCard
{
public:
	//create a card with attack and defense
	NCard(int n = 0 , int a = 0, int d= 0 , bool isp = 0)
	{

		attack = a;
		defense = d;
		cardnumber = n;
		isSpecial = isp;
		//image = i;
	}

	
	//set card to special
	void special(int num)
	{
		isSpecial = true;
		specialcard.setCard(num);
	}
	
	//return attack damage
	int getAttack() 
	{
		if (isSpecial)
			return specialcard.getSAttack();
		return attack;
	}

	//return defense
	int getDefense()
	{
		if (isSpecial)
			return specialcard.getSDefense();
		return defense;
	}

	//set the attack
	void setAttack(int a)
	{
		attack = a;
	}

	//set defense
	void setDefense(int d)
	{
		defense = d;
	}

	//set cardNumber
	void setCardNumber(int cn)
	{
		cardnumber = cn;
	}

	//return card number
	int getCardNumber() const
	{
		return cardnumber;
	}
	//open card image

	//print card
	void printcard()
	{
		if (isSpecial == 0)
		{
			cout << "Card Number: " << cardnumber << endl;
			cout << "Attack: " << attack << endl;
			cout << "Defense: " << defense << endl << endl;
		}
		else
		{
			cout << "Card Number: " << cardnumber << endl;
			specialcard.print();
		}
	}
	

	//get special nubmer
	int getAbility()
	{
		return specialcard.useAbility();
	}

	//get special ability number
	int getabilityNumber()
	{
		return specialcard.getAbility();
	}

	//check if special
	bool isitSpecial()
	{
		return isSpecial;
	}
private:
	int cardnumber;
	int attack;
	int defense;
	bool isSpecial;
	SpecialCards specialcard;
	//string image;
};

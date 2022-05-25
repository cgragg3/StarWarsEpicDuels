#pragma once

#include <iostream>
#include <fstream>

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

	void special(bool s)
	{
		isSpecial = s;
	}
	
	//return attack damage
	int getAttack() const
	{
		return attack;
	}

	//return defense
	int getDefense() const
	{
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
			cout << "Attack: "<<attack<< endl;
			cout << "Defense: " << defense<< endl << endl;
		}
		else
			cout << "not ready yet";
	}


private:
	int cardnumber;
	int attack;
	int defense;
	bool isSpecial;
	//string image;
};

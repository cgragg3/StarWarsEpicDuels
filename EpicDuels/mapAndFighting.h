#pragma once

#include <iostream>
#include <vector>
#include "Character.h"
#include "Dice.h"
#include "CardNorm.h"
#include "Deck.h"

using namespace std;

class Map
{
public:
	//constructor add number of players to be added
	Map(int n = 2)
	{
		
		numPlayers = n;
		turn = 0;
		who = 0;
		
	}

	//enter character then placement on map x,y
	void addPlayer(Character c, int x, int y)
	{
		players.push_back(c);
		mp[x][y] = c;

	}

	int rolldice()
	{
		srand(time(0));
		for (int i = 0; i < 10; i++)
		{
			return rollDie();
		}
	}

	void oneTurn()
	{
		turn++;
		if (turn == 3)
		{
			turn = 0;
			who++;
			if (who == numPlayers)
				who = 0;
		}
	}

	//enter character to be attacked, and which card to attack with
	void attack(int p, int c)
	{
		int dam = 0;
		int def = 0;
		int cardn = 0;
		bool ex = false;
		int ab = 0;
		Character d = players.at(p);
		string y;
		if (inRange(d))
		{
			if (players.at(who).checkspecial(c))
			{
				
				if (players.at(who).getSpecialAbilityidentifier(c) == 1)
				{
					dam = players.at(who).useAttack(c);
					ex = true;
					ab = 1;
				}

			}
			else
				dam = players.at(who).useAttack(c);
			system("CLS");
			cout << "defender do you wish to defend? yes or no:  ";
			cin >> y;
			if (y == "yes")
			{
				
				cout << "enter card number you want to use to defend: ";
				d.seeChar();
				cin >> cardn;
				def = players.at(p).useDefense(cardn);
			}
			dam = dam - def;
			if (dam < 0)
				cout << "no damage given" << endl;
			else
			{
				cout << "Player " << d.getName() << " has recieved " << dam << " damage" << endl;
				players.at(p).takeDamage(dam);
			}
			system("CLS");
			system("pause");
			system("CLS");
			if (ex)
			{
				if (ab == 1)
				{
					seeMap();
					moveCharacter(6);
				}
			}
			
			
			oneTurn();
		}
		else
			cout << "Not in range." << endl;
	}

	//see map
	void seeMap()
	{
		cout << " ";
		for (int a = 0; a < 10; a++)
			cout << " " << a;
		for (int x = 0; x < 5; x++)
		{
			cout << endl << x <<" ";
			for (int y = 0; y < 10; y++)
			{
				if (mp[x][y].getPlayer() <0)
					cout << "x ";
				else
					cout << mp[x][y].getPlayer() << " ";
			}
		}
		cout << endl;
	}

	//move character
	void moveCharacter(int a)
	{
		
		int posi = a;
		int x = findX(who);
		int y = findY(who);
		int nx = 0;
		int ny = 0;
		int dx = 0;
		int dy = 0;
		do
		{
			cout <<endl << "enter a new position within " << posi << " spaces of yourself" << endl;

			cout << "x: ";
			cin >> ny;
			cout << "y: ";
			cin >> nx;
			dx = nx - x;
			dy = ny - y;
			if (dx < 0)
				dx = x - nx;
			if (dy < 0)
				dy = y - ny;
			if (nx == x && ny == y)
			{
				return;
			}
		} while (dy + dx > posi || (mp[nx][ny].getPlayer() >(-1)));
		
		
		mp[nx][ny] = players.at(who);
		mp[x][y].setPlayer(-3);
		
	}

	int findX(int x)
	{
		for (int a = 0; a < 5; a++)
		{
			for (int y = 0; y < 10; y++)
				if (mp[a][y].getPlayer() == x)
					return a;
				else
					continue;
		}
		return -1;
	}

	int findY(int y)
	{
		for (int a = 0; a < 5; a++)
		{
			for (int x = 0; x < 10; x++)
				if (mp[a][x].getPlayer() == y)
					return x;
				else
					continue;
		}
		return -1;
	}
	
	bool inRange(Character d)
	{
		int mx = findX(who);
		int my = findY(who);
		int ex = findX(d.getPlayer());
		int ey = findY(d.getPlayer());
		if (players.at(who).range())
		{
			if (mx == ex || my == ey)
				return true;
			else if ((mx - my == ex - ey) || (mx + my == ex + ey))
				return true;
			else
				return false;
			
		}
		else
		{
			if (mx == ex && ((ey ==my+1)||(ey == my-1)))
				return true;
			if (mx + 1 == ex && ((ey == mx + 1) || (ey == mx) || (ey == mx - 1)))
				return true;
			if (mx - 1 == ex && ((ey == mx + 1) || (ey == mx) || (ey == mx - 1)))
				return true;
			else return false;
		}
	}

	//see current char info
	void seeinfo()
	{
		players.at(who).seeChar();
	}

	void action()
	{
		system("CLS");
		seeMap();
		seeinfo();
		moveCharacter(rolldice());

		char mChoice = '0';
		//error checking selection menu setup and selection execution
		while (turn < 2)
		{
			int playToAttack= 0;
			int cardToAttack = 0;
			//menu setup
			system("CLS");
			seeMap();
			seeinfo();
			cout << "D - Draw a card" << endl << endl;
			cout << "A - Attack" << endl << endl;
			cout << "H - Heal by discarding one card" << endl << endl;
			cout << "Selection: ";
			cin >> mChoice;

			while (!((mChoice == 'D') ||(mChoice == 'A') || (mChoice == 'H')))
			{
				cout << "You must enter one of the listed characters " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> mChoice;
			}


			switch (mChoice) {
			case 'D':   //input A add vehicle
				players.at(who).drawCard();
				oneTurn();
				mChoice = '0';
				break;
			case 'A':   
				do
				{
					system("CLS");
					cout << "Who would you like to attack" << endl;
					for (int a = 0; a < players.size(); a++)
					{
						if (!(a == who))
							cout << "Player " << players.at(a).getPlayer() << ": " << players.at(a).getName() << ", hp: " << players.at(a).getHp() << endl;
						else
							continue;
					}
					cout << "Selection: ";
					cin >> playToAttack;
				} while (!(inRange(players.at(playToAttack))));
				cout << "Which card would you like to attack with " << endl;
				seeinfo();
				cout << "Selection: ";
				cin >> cardToAttack;
				attack(playToAttack, cardToAttack);
				mChoice = '0';
				system("pause");
				break;
			case 'H':   //input A add vehicle
				cout << "Which card would you like to discard? " << endl;
				cout << "Selection: ";
				cin >> cardToAttack;
				players.at(who).discardToHeal(cardToAttack);
				oneTurn();
				mChoice = '0';
				break;
			default:
				system("CLS");
				oneTurn();
				cout << "Next players turn" << endl;
			}
			
		}
		system("CLS");
		oneTurn();
		cout << "Next players turn" << endl;
	}

private:
	int turn;
	int who;
	int numPlayers;
	Character mp[5][10];
	vector<Character> players;
	
};


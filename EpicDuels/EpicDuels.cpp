// EpicDuels.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "CardNorm.h"
#include"Deck.h"
#include "Character.h"
#include"mapAndFighting.h"
using namespace std;

int main()
{
   

    Character obw("obiwan kenobi", 32, 0, true);
    Character dm("Darth Maul", 32, 1, false);
    Character dv("Darth Vader", 32, 2, false);

    NCard sp(10, 0, 0, true);
    sp.special(2);

    NCard n0(0, 2, 3, false);
    NCard n1(1, 4, 1, false);
    NCard n2(2, 1, 4, false);
    NCard n3(3, 3, 3, false);
    NCard n4(4, 3, 3, false);
    NCard n5(5, 3, 3, false);
    NCard n6(6, 4, 2, false);
    NCard n7(7, 4, 2, false);
    NCard n8(8, 5, 1, false);
    NCard n9(9, 5, 1, false);

    obw.addnCard(n0);
    obw.addnCard(n1);
    obw.addnCard(n2);
    obw.addnCard(n3);
    obw.addnCard(n4);
    obw.addnCard(n5);
    obw.addnCard(n6);
    obw.addnCard(n7);
    obw.addnCard(n8);
    obw.addnCard(n9);
    obw.addnCard(jediAttack);

    dm.addnCard(n0);
    dm.addnCard(n2);
    dm.addnCard(n3);
    dm.addnCard(n4);
    dm.addnCard(n5);
    dm.addnCard(n6);
    dm.addnCard(n7);
    dm.addnCard(n8);
    dm.addnCard(n9);

    dv.addnCard(n0);
    dv.addnCard(n2);
    dv.addnCard(n3);
    dv.addnCard(n4);
    dv.addnCard(n5);
    dv.addnCard(n6);
    dv.addnCard(n7);
    dv.addnCard(n8);
    dv.addnCard(n9);

    for (int a = 0; a < 3; a++)
    {
        dm.drawCard();
        obw.drawCard();
        dv.drawCard();

    }

    Map gm(3);
    gm.addPlayer(obw, 1,1);
    gm.addPlayer(dm, 4, 8);
    gm.addPlayer(dv, 4, 5);
  
    






    
    char mChoice = '0';
    //error checking selection menu setup and selection execution
    while (!(mChoice == 'Q'))
    {
        //menu setup
        system("CLS");
        cout << "Main Menu" << endl << endl;
        cout << "S - Start turn" << endl << endl;
        cout << "Q - Quit" << endl << endl;
        cout << "Selection: ";
        cin >> mChoice;

        while (!((mChoice == 'S')|| (mChoice == 'Q')))
        {
            cout << "You must enter one of the listed characters " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> mChoice;
        }


        switch (mChoice) {
        case 'S':   //input A add vehicle
            system("CLS");
            gm.action();
            mChoice = '0';
            system("pause");
            break;
        default:
            system("CLS");
            cout << "Good bye" << endl;
        }
    }


   
   
    return 0;

}

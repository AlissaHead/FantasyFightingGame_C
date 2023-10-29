#include "player.h"
#include "knight.h"
#include "Wizard.h"
#include "Archer.h"
#include "Potions.h"

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    // GAME INTRO
    cout << "                                       ----Welcome to my fighting game!----" << endl;
    cout << "                                         " << endl;
    cout << "This game is a turn based fighting game that also includes classes.\nAfter each round you'll be able to buy potions, armor, and weapons." << endl;

    // PLAYER 1
    string player1Name;
    cout << "-> Player 1 what is your name? <-" << endl;
    cin >> player1Name;

    int player1Class;
    cout << "Type the number of what class would you like?\n1 - Knight\n2 - Wizard\n3 - Archer" << endl;
    cout << player1Name << " you choose... "; //Player has to be initualized after class is inputed so use player1Name
    cin >> player1Class;

    Player* player1;  

    switch (player1Class) {
    case 1:
        player1 = new Knight(player1Name);
        break;
    case 2:
        player1 = new Wizard(player1Name);
        break;
    case 3:
        player1 = new Archer(player1Name);
        break;
    default:
        cout << "Error: Not a player class" << endl;
        return 1; // Exit program with an error code
    }

    cout << "                                         " << endl;

    // PLAYER 2
    string player2Name;
    cout << "-> Player 2 what is your name? <-" << endl;
    cin >> player2Name;

    int player2Class;
    cout << "Type the number of what class would you like?\n1 - Knight\n2 - Wizard\n3 - Archer" << endl;
    cout << player2Name << " you choose... "; //Player has to be initualized after class is inputed so use player2Name
    cin >> player2Class;

    Player* player2;

    switch (player2Class) {
    case 1:
        player2 = new Knight(player2Name);
        break;
    case 2:
        player2 = new Wizard(player2Name);
        break;
    case 3:
        player2 = new Archer(player2Name);
        break;
    default:
        cout << "Error: Not a player class" << endl;
        return 1; // Exit program with an error code
    }

    cout << "                                         " << endl;

    // Number of Rounds
    int rounds;
    cout << "How many rounds would you like to play? (3-20)" << endl;
    cin >> rounds;

    cout << "                                         " << endl;

    // Checks for valid round answer
    bool playing = false;
    if (rounds > 2 && rounds < 21) {
        playing = true;
    }
    else {
        cout << "Not a valid answer. Minimum amount of rounds is 3 and max is 20." << endl;
        return 1; // Exit program with an error code
    }

    if (playing == true) {
        cout << "                                         " << endl;

        // Round loop
        for (int currentRound = 1; currentRound <= rounds; currentRound++) {
            cout << "                                         **Round " << currentRound << " of " << rounds << " is now starting!**" << endl;

            //Fight loop
            while (player1->getHealthPoints() > 0 && player2->getHealthPoints() > 0) {

                // Player 1's turn
                int choiceP1; 
                player1->displayAbilities(); //Displays abilities of player 1 class
                cout << player1->getName() << " you choose... ";
                cin >> choiceP1;

                player1->chooseAbility(choiceP1);
                player2->updateHealth(player2->getDefense());//Implements class defense
                player2->takeDamage(player1->getAttack()); //Takes the update attack of player 1 and damages hp of player 2
                
                // Check if player1 has potions before asking
                if (!player1->getInventory().empty()) {
                    cout << "Do you want to use a potion? (y/n): ";
                    char choice;
                    cin >> choice;

                    if (tolower(choice) == 'y') {
                        player1->usePotion(1);
                    }
                }
                

                cout << player2->getName() << " has been hit! " << player2->getName() << "'s Hp is now " << player2->getHealthPoints() << "." << endl;
                cout << "-----------------------------------------" << endl;

                // Player 2's turn
                if (player2->getHealthPoints() > 0) { //This loop is if player 1 has already won to not give player 2 a turn (stops tie)
                    int choiceP2;
                    player2->displayAbilities(); ////Displays abilities of player 2 class
                    cout << player2->getName() << " you choose... ";
                    cin >> choiceP2;

                    player2->chooseAbility(choiceP2);
                    player1->updateHealth(player1->getDefense()); //Implements class defense
                    player1->takeDamage(player2->getAttack()); //Takes the update attack of player 2 and damages hp of player 1

                    cout << player1->getName() << " has been hit! " << player1->getName() << "'s Hp is now " << player1->getHealthPoints() << "." << endl;
                    cout << "-----------------------------------------" << endl;
                }
            }
            
            //Post Round
          
            // Update player's money
            player1->addMoney(player1->updateMoney()); 
            player2->addMoney(player2->updateMoney());

            player1->shop();
            player2->shop();
            /*
            // Shopping Phase

            
            //Player 1 Shopping
            bool player1Shopping = true;
            while (player1Shopping == true) {
                int P1section;
                player1->displayShops();
                cin >> P1section;

                //Player1->chooseShop(P1section);
                //Player1->displayItems();
                //make sure player can afford & if they can then add new option for player to use
                //^^^ Maybe like an P1->displayAdditionalAbilties(){ if(vector is empty){display this new ability}???
                

                //Stop shopping phase for player 1
                char p1Input;
                cout << player1->getName() << " are you done shopping ('y' or 'n') ?" << endl;
                cin >> p1Input;
                char lowecaseP1Input = (char)tolower(p1Input);

                if (lowecaseP1Input == 'n') {
                    player1Shopping = false;
                }
            }

            //Player 2 shopping
            bool player2Shopping = true;
            while (player2Shopping == true) {
                int P2section;
                player2->displayShops();
                cin >> P2section;

                //Player1->chooseShop(P1section);
                //Player1->displayItems();
                //make sure player can afford & if they can then add new option for player to use
                //^^^ Maybe like an P1->displayAdditionalAbilties(){ if(vector is empty){display this new ability}???


                //Stop shopping phase for player 1
                char p2Input;
                cout << player2->getName() << " are you done shopping ('y' or 'n') ?" << endl;
                cin >> p2Input;
                char lowercaseP2Input = (char)tolower(p2Input);

                if (lowercaseP2Input == 'n') {
                    player2Shopping = false;
                }
            }
            */

            //Clean up
            
            //Reset health
            player1->updateHealth(100);
            player2->updateHealth(100);

            //Reset attack to default
            player1->resetAttack();
            player2->resetAttack();



        }
    }

    // Free memory
    delete player1;
    delete player2;

    return 0;
}

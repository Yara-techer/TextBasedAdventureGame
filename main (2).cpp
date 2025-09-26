
//#include <iostream>
#include "Inventory.h"
#include "Floor1.h"
#include "Floor2.h"
using namespace std;

int main()
{
    Floor1 floor1;
    
    
    string response;
    
    cout << "For purposes of playing this game, please use lowercase letters only and answer using one word." << endl << endl;
    cout << "Before starting here is a brief description: " << endl;
    cout << "You, the user, are stranded in a forest and seek for answers to get to a safe place." <<endl;
    cout << "Ready to start? ";
    
    
    cin >> response;
    
    
    
    if (response == "yes") {
        cout << "You wake up shivering as the cold asphalt draws out the minimal heat you have left in your body."; 
        cout << " You slowly open your eyes to find yourself in the middle of nowhere. The only thing you can make out"; 
        cout << " in the dark are all the trees surronding you and the light of a room in a nearby house." << endl << endl << "Would you like to enter? ";
        cin >> response;
        cout << endl;
        
        if ((response != "no") && (response != "yes")) {
            cout << "Hmmm.. Is that a \"yes\" or a \"no\"?";
            cin >> response;
        }
        if (response == "no") {
            cout << endl << "I refuse to let you die in this cold. You shall enter the house... "; 
            response = "yes";
        }
        if (response == "yes") {
            floor1.Hallway();
            
            
        } 
    }
    else {
        cout << "You'll then stay stranded forever....";
    }

    return 0;
}
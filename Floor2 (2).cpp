#include <iostream>
//#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
//#include <vector>
#include "Floor2.h"
#include "Inventory.h"
#include "Floor1.h"
using namespace std;

string userInput2;
Floor1 floor1;
Inventory Objects;

string direction;
int userGuess; //used for number guessing game

string Floor2::GetInput2() {
    cin >> userInput2;
    if (userInput2 == "inventory") {
        Objects.viewItems();
    }
	return userInput2;
}


void Floor2::Hallway2() {
    cout << "Once you reach the second floor, you find a few zombies standing guard outside the rooms down the hall."; 
    cout << " The only rooms without guards are situated immediately to your left and to your right. ";

    
    userInput2 = GetInput2();
    while (userInput2 != "left" && userInput2 != "right") {
        cout << "left or right? ";
        userInput2 = GetInput2();
    }
    if (userInput2 == "left") {
        MasterBedroomPt1();
        cout << "Where to now? ";
        userInput2 = GetInput2();
        while (userInput2 != "right") {
            cout << "Think again. ";
            userInput2 = GetInput2();
        }
        if (userInput2 == "right") {
            Bathroom2();
        }
    }
    else if (userInput2 == "right") {
        Bathroom2();
        cout << "Where to now? ";
        userInput2 = GetInput2();
        while (userInput2 != "left") {
            cout << "Are you sure? ";
            userInput2 = GetInput2();
        }
        if (userInput2 == "left") {
            MasterBedroomPt1();
        }
    }

    cout << endl << endl << "The first zombie guards the kids bedroom. The other guards the theater room. Where to now? ";
    userInput2 = GetInput2();
    while (userInput2 != "kids" && userInput2 != "bedroom") {
        cout << "Try going to the kids bedroom. ";
        userInput2 =GetInput2();
    }
    if (userInput2 == "kids" || userInput2 == "bedroom") {
        KidsRoom();
        cout << endl << "There is an inner door that leads to the kids playroom. ";
        userInput2 = GetInput2();
        while (userInput2 != "playroom") {
            cout << "Input room name. ";
            userInput2 = GetInput2();
        }
        if (userInput2 == "playroom") {
            KidsPlayRoom();
        }
    }
    cout << endl << "Where would you like to go now? ";
    userInput2 = GetInput2();
    while (userInput2 != "theater") {
        cout << "Think again. There's only one more room left. ";
        userInput2 = GetInput2();
    }
    TheaterRoom1();
}

void Floor2::MasterBedroomPt1() {
    cout << endl << "You are now in the master bedroom...Is that a ghost?! ";
    cout << "\"Looks like my siblings have done it again...but I can help! I'm Casper, by the way. ";
    cout << "Follow my instructions and you'll be out of here soon. There's a little game you must play to leave this room.";
    cout << endl << "It's simple. Guess my number!\" (Hint: It's between 0 and 10)" << endl;
    
    MasterBedroomPt2();
}

int Floor2::MasterBedroomPt2() {
    //NUMBER GUESSING GAME
    srand(time(0));
    int number = (rand() % 10);
    cout << "Number: " << number << " ";
    int i = 0;
    
    cin >> userGuess;

    while ((i != 2) && (userGuess != number)) {
        cout << "Wrong! Guess again." << endl;
        cin >> userGuess;
        i++;
    }
    if ((i == 2) && (userGuess != number)) {
        cout << "You've lost! You must start again." << endl;
        MasterBedroomPt2();
    }
    if (userGuess == number) {
        cout << "User Guess: " << userGuess << " ";
        cout << "\"Correct! Awesome job.\"" << endl << endl;
        cout << "\"The zombies in the hallway are safe to approach but expect a request from each "; 
        cout << "to enter the rooms they guard. Approach them one at a time.\"" << endl;
    }
    return userGuess;
}

void Floor2::Bathroom2() {
    cout << endl << "You enter a bathroom where you find a mirror. For the first time, you notice how dirty your ";
    cout << "you hair and face are. The faucets here work and the warm water is very soothing, but water won't be good ";
    cout << "enough for cleaning on its own. ";
    userInput2 = GetInput2(); 
    while (userInput2 != "soap") {
        cout << "Is there something useful you've found along the way? Something slippery... ";
        userInput2 = GetInput2();
    }
    if (userInput2 == "soap") {
        cout << "The shower was very refreshing! You're ready to continue...";
    }
}

void Floor2::KidsRoom() {
    cout << "The guard wants something. Listen closely.";
    cout << "\"Nummm...berrr...\" ";
    int userNum; //number inputted
    
    cout << userGuess; //FIXME
    
    cin >> userNum;
    while (userNum != userGuess) { //userGuess is a value returned from number guessing game
        cout << endl << "Don't think that's exactly what it wants, try again. ";
        cin >> userNum;
    }
    cout << endl;
    if (userNum == userGuess) {
        cout << "The guard allows you to enter the kids room only to find the largest spider you've ever seen." << endl;
        cout << "\"Oh hello, child. I hope you've enjoyed your time at our lovely home\" *chuckles* "; 
        cout << "\"You must have seen many strange things before you got here and I'm sure you have many questions.\" ";
        cout << "\"I'm Lisa and this is my home - I was born here. I only have time for one story before I go to sleep.\" ";
        cout << "What do you want to know?";
        cout << endl << "   a - What is Casper's story?"; 
        cout << endl << "   b - Who are the owners of this house? ";
     
        
        userInput2 = GetInput2();
        while (userInput2 != "a" && userInput2 != "b" ) {
            cout << endl << "Choose \"a,\" or \"b\". ";
            userInput2 = GetInput2();
        }
        if (userInput2 == "a") {
            cout << "\"Casper is a friendly ghost who likes to help others. He can't bring an end to the evil ";
            cout << "that his siblings do but he tries his best to make things right. Stick to what he tells you ";
            cout << "if you want to escape.\" ";
        }
        else if (userInput2 == "b") {
            cout << "\"This house was abandoned by its original owners a looong time ago. Casper's three siblings ";
            cout << "haunted the house to carry out their evil actions. They kidnap humans and turn them into zombies ";
            cout << "when they fail to escape. No one has ever managed to escape. They have all been enslaved in this ";
            cout << "some of them you've seen around the house.\" ";
        }

    
    }
}
void Floor2::KidsPlayRoom() {
    int i;
    
    string hangman = "______ ______ ______";
    char userChar;
    cout << endl << "\"It's Casper again! It's great to see you've made it this far. You're very close to leaving this house. But first, let's play a game of hangman.\"";
    cout << endl << "The words are all six letters each. Input a letter." << endl;

    while (message != hangman) {
        for (i = 0; i < hangman.length(); i++) {
            cout << hangman.at(i);        
        }
        cout << " ";
        cin >> userChar;
        for (i = 0; i < hangman.length(); i++) {
            if (userChar == message.at(i)) {
                hangman.at(i) = userChar;
            }
        }
        cout << endl;
    }
    cout << "Message: " << hangman;
    cout << endl << "\"Awesome! You've done very well. You will only have to go through one more room, my friend. "; 
    cout <<  "It's the theater room. Make sure you stay alert.\"";
}

    void Floor2:: TheaterRoom2() {
        cout << "\"You're not leaving this place!,\" one of the ghosts bellows. ";
        cout << "All three ghosts try to attack you. Do you have anything to fight them back? ";
        cout << "Hint: (Traditional weapons won't be effective against these smokey figures.) ";
        userInput2 = GetInput2();
        if (userInput2 != "vacuum") {
            cout << "You didn't use the mini vacuum to defend yourself. ";
            floor1.EndGame();
        }
        else if (userInput2 == "vacuum") {
            if (!Objects.Find(userInput2)) {
                cout << "The vacuum wasn't in your inventory. ";
                floor1.EndGame();
            }
            else {
                 cout << "All the ghost are sucked into the vacuum. Casper appears to help you successfully leave the house. ";
            cout << "\"Recite the message you collected in the playroom!\" A portal will appear and ";
            cout << "you'll be able to escape. ";
            
            getline(cin, userInput2);
            while (userInput2 != "rumble rustle swoosh") {
                cout << "What was the hangman message? ";
                getline(cin, userInput2);
            }
            if (userInput2 == "rumble rustle swoosh") {
                cout << "A portal appears in front of you, would you like to enter? ";
                userInput2 = GetInput2();
                while (userInput2 != "yes" && userInput2 != "no") {
                    cout << "Is that a yes or a no? ";
                    userInput2 = GetInput2();
                }
                if (userInput2 == "yes") {
                    cout << "You can finally go home. Congratulations!!" << endl;
                    cout << "GAME ENDED";
                }
                else if (userInput2 == "no") {
                    cout << "You will stay with Casper and help bring an end to the evil of the other ghosts." <<endl;
                    cout << "GAME ENDED";
                }
            }
            }
        }

    }

void Floor2::TheaterRoom1() {
    cout << endl << endl;
    cout << "The second guard blocks your way. \" Shi...nyy..yy\". ";
    userInput2 = GetInput2();
    while (userInput2 != "jewel") {
        cout << "Have you encountered anything shiny along the way? ";
        userInput2 = GetInput2();
    }
    if (userInput2 == "jewel") {
        cout << "\"Ooooh. Shinyyyy.\" The guard steps away as he turns the jewel around in his hand in awe. ";
        cout << "You step inside the room. There awaits three ghosts inside. ";
        cout << "\"We see you've made it this far. ";
        cout << "Answer some questions about the house. If you answer correctly we'll set you free. Ready?\" ";
        userInput2 = GetInput2();
        while (userInput2 != "yes") {
            cout << "Ready? ";
            userInput2 = GetInput2();
        }
        
        cout << "\"What were the rats eating in the garage?\" ";
        userInput2 = GetInput2();
        if (userInput2 != "finger" ) {
            cout  << "*chuckles* \" We'll give you one more chance. If you don't answer correctly...\" ";
            cout << "\"What is the zombies' favorite vegetable?\" ";
            userInput2 = GetInput2();
            if(userInput2 != "potato" && userInput2 != "potatoes") {
                floor1.EndGame();
            }
            else {
                TheaterRoom2();
            }
        }
        
        else{
            TheaterRoom2();
        }
    }
    
}
    
   
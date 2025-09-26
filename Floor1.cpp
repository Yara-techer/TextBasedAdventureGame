#include <iostream>
#include <iomanip>
#include <string>
#include "Floor1.h"
#include "Floor2.h"
#include "Inventory.h"
using namespace std;

string userInput;

string Floor1:: GetInput() {
    //this function checks to see if each input states inventory
        
        cin >> userInput;
        
        if (userInput == "inventory") {
            Objects.viewItems();
        }
	return userInput;
}

void Floor1::Hallway() {

	cout << "You are now on the first floor of the two-story house. The entire living room is mostly dark";
	cout << " save a corner with a very dim lamp. ";
	cout << "What do you see?" << endl;
	// ascii art by - Lester / itz / Nate - available @ https://ascii.co.uk/art/flashlight#google_vignette
	cout << "                   _.----." << endl;
	cout << " .----------------  /  /  \\" << endl;
	cout << "(     --         | |   |) |" << endl;
	cout << " `----------------._\\  \\  /" << endl;
	cout << "                    '----'" << endl;
	cin >> userInput;
	
	while(userInput != "flashlight") {
		cout << "Are you sure?" << endl;
		cin >> userInput;

	}

	if (userInput == "flashlight") {

		Objects.addItems(userInput);
		cout << "That should come in handy. (The flashlight will now be in your inventory. If you would like to view your inventory type \"inventory\".) " << endl;
		cout << "Try turning the flashlight on. ";

	}
	
	userInput = GetInput();
	cout << endl;

    while (userInput != "on") {
        cout << "Keep trying to turn it on. ";
        userInput = GetInput();
    }
    
	if (userInput == "on") {
		cout << "You can now see that there are two rooms, one to your left and the other to your right. Which one would you like to enter first? ";

		userInput = GetInput();
		while (userInput != "left" && userInput != "right") {
			cout << "Which direction is that? ";			
			userInput = GetInput();
		}
		if (userInput == "left") {
			cout << endl;
			Bathroom();
			cout << "Try checking out the other room. ";
			
			userInput = GetInput();
			while (userInput != "right") {
				cout << "Which direction is that? ";
				userInput = GetInput();
			}
			Kitchen();
			cout << "Continue checking out the other rooms, maybe you'll find some answers. ";
			cout << "Where would you like to go next to the office or garage? ";
			userInput = GetInput();
			
			while (userInput != "office" && userInput != "garage") {
			    cout << "office or garage? ";
			    userInput = GetInput();
			}
			
			if (userInput == "office") {
			LockedOffice();
			}
			
			if (userInput == "garage") {
			    Garage();
			}
		}
		else if (userInput == "right") {
		
			Kitchen();
			cout << "Continue checking out the other room, maybe you'll find some answers. ";
			userInput = GetInput();
			while (userInput != "left") {
				cout << "Which direction is that? ";
				userInput = GetInput();
			}
			cout << endl;
			Bathroom();
				cout << "Where would you like to go next to the office or garage? ";
			userInput = GetInput();
			
			while (userInput != "office" && userInput != "garage") {
			    cout << "Office or garage? ";
			    userInput = GetInput();
			}
			
			if (userInput == "office") {
			    cout << endl;
			    LockedOffice();
			}
			
			if (userInput == "garage") {
			    Garage();
			}
		}
	}
	

}

void Floor1:: Bathroom() {
	cout << "Thump! You've slipped on something in the bathroom. What could it be? ";
    
	userInput = GetInput();
	
	while(userInput != "soap") {
        cout << "Think of something slippery... ";
        userInput = GetInput();
    }
	
    if (userInput == "soap") {
        cout << "Good for taking a bath. The faucets here are broken, however. ";
        cout << "You look at the tub and realize it's still wet. Has someone been here?... "; 
        Objects.addItems(userInput);
    }
  
}

void Floor1:: Kitchen() {
    cout << endl;
    cout << "You're now in the kitchen, what should we check out first drawers or the pantry? ";
    userInput = GetInput();
    while (userInput != "drawers" && userInput != "pantry") {
        cout << "Is that drawers or pantry? ";
        userInput = GetInput();
    }
    
    if (userInput == "drawers") {
        cout << "They are all empty. Maybe check the pantry. ";
        userInput = GetInput();
    }
    while (userInput != "pantry"){
        cout << "Check pantry. ";
        userInput = GetInput();
    }
    
    if (userInput == "pantry") {
        cout << "There's a bag of chips and a mini vacuum cleaner. Which one would you like to take or would you like all? ";
        userInput = GetInput();
        while(userInput != "vacuum" && userInput != "chips" && userInput != "all"){
            cout << "Which pantry item would you like take or would you like all? ";
            userInput = GetInput();
        }
        if (userInput == "vacuum" || userInput == "mini"){
        Objects.addItems("mini vacuum");
        }
        else if (userInput == "all") {
            Objects.addItems("vacuum");
            cout << "The vacuum has been added to your inventory. That was also a well needed snack!! ";
        }
        else if (userInput == "chips") {
            cout << "That was a well needed snack!! ";
        }
        
        cout << "After searching the pantry you feel as if someone is watching you and see something move from the corner of your eye. ";
        cout << "You turn around frantically and see nothing. There's just silence. ";
        cout << "A rat then passes with something in it's mouth... it looks like a finger." << endl << endl; 
        cout << "You get out the kitchen in a hurry and go towards the main entrace only to realize the door is locked. " ;
    }
    
  
}

void Floor1:: LockedOffice() {
    cout << endl;
     cout << "Seems like the door is locked, we should find the key. ";
     userInput = GetInput();
     while (userInput != "garage") {
         cout << "We still haven't checked the garage. ";
         userInput = GetInput();
     }

     if (userInput == "garage") {
         Garage();
     }
     
}

void Floor1:: Garage() {
    cout << endl;
    cout << "We are now in the garage and it smells in here, like something has been rotting. You notice rats eating away at something. ";
    cout << "As you turn your head you notice a key holder on the wall with just one key. ";
    string userInput;
	userInput = GetInput();
	while(userInput != "take" && userInput != "key") {
	    cout << "Take the key. ";
	    userInput = GetInput();
	}
	if (userInput == "take" || userInput == "key") {
	    Objects.addItems("office key");
	}
    
    cout << "There's also a tool box with a scissor, hammer and axe. ";
    cout << "Which one would you like to take or would you like all? ";
    
	userInput = GetInput();

	
	while(userInput != "scissor" && userInput != "hammer" && userInput != "axe" && userInput != "all") {
        cout << "Which tools would you like to take? ";
        userInput = GetInput();
    }
    
    if (userInput == "scissor" || userInput == "hammer" || userInput == "axe") {
        cout << "Added to inventory. ";
        Objects.addItems(userInput);
    }
    else if (userInput == "all") {
        Objects.addItems("scissor");
        Objects.addItems("hammer");
        Objects.addItems("axe");
        cout << "They have been added to your inventory. ";
    }
    
    cout << "Where to next? " ;
    
    userInput = GetInput();

	
	while(userInput != "office") {
	    cout << "We should put this key to use. ";
	    userInput = GetInput();

	}
	if (userInput == "office"){
	    Office();
	}
}

void Floor1:: Office() {
    cout << "The door is locked. ";
    

	userInput = GetInput();

	
	while (userInput != "key") {
	    cout << "(door rattles) it's locked. " << endl;
	    userInput = GetInput();
	    cout << endl;
	}
	if (userInput == "key") {
	    cout << "You unlock the door and you take a few steps in. The door shuts behind you and gets locked. ";
	    cout << "You raise your flashlight as you hear groaning.... there's a zombie chained up." << endl << endl;
	    // ascii art by -https://emojicombos.com/zombie-ascii-art
	    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⠖⠊⠉⠉⠉⠉⢉⠝⠉⠓⠦⣄⠀⠀⠀" << endl;
	    cout << "⠀⠀⠀⠀⠀⠀⢀⡴⣋⠀⠀⣤⣒⡠⢀⠀⠐⠂⠀⠤⠤⠈⠓⢦⡀" << endl;
	    cout << "⠀⠀⠀⠀⠀⣰⢋⢬⠀⡄⣀⠤⠄⠀⠓⢧⠐⠥⢃⣴⠤⣤⠀⢀⡙⣆⠀" << endl;
	    cout << "⠀⠀⠀⠀⢠⡣⢨⠁⡘⠉⠀⢀⣤⡀⠀⢸⠀⢀⡏⠑⠢⣈⠦⠃⠦⡘⡆" << endl;
	    cout << "⠀⠀⠀⠀⢸⡠⠊⠀⣇⠀⠀⢿⣿⠇⠀⡼⠀⢸⡀⠠⣶⡎⠳⣸⡠⠃⡇" << endl;
	    cout << "⢀⠔⠒⠢⢜⡆⡆⠀⢿⢦⣤⠖⠒⢂⣽⢁⢀⠸⣿⣦⡀⢀⡼⠁⠀⠀⡇⠒⠑⡆ " << endl;
	    cout << "⡇⠀⠐⠰⢦⠱⡤⠀⠈⠑⠪⢭⠩⠕⢁⣾⢸⣧⠙⡯⣿⠏⠠⡌⠁⡼⢣⠁⡜⠁ " << endl; 
	    cout << "⠈⠉⠻⡜⠚⢀⡏⠢⢆⠀⠀⢠⡆⠀⠀⣀⣀⣀⡀⠀⠀⠀⠀⣼⠾⢬⣹⡾⠀" << endl;
	    cout << "⠀⠀⠀⠉⠀⠉⠀⠀⠈⣇⠀⠀⠀⣴⡟⢣⣀⡔⡭⣳⡈⠃⣼⠀⠀⠀⣼⣧⠀" <<endl;
	    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⠀⠀⣸⣿⣿⣿⡿⣷⣿⣿⣷⠀⡇⠀⠀⠀⠙⠊⠀" << endl;
	    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣠⠀⢻⠛⠭⢏⣑⣛⣙⣛⠏⠀⡇⠀⠀⠀⠀" << endl;
	    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡏⠠⠜⠓⠉⠉⠀⠐⢒⡒⡍⠐⡇⠀⠀⠀" << endl;
	    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠒⠢⠤⣀⣀⣀⣀⣘⠧⠤⠞⠁" << endl;
	    cout << endl << endl;
	    cout << "AHHHHHHH!" << endl;
	    cout << "Your scream upsets the zombie and it charges towards you. The zombie is in chains but it doesn't seem to calm down. ";
	    cout << endl;
	    cout << "The chains break... it's running towards you, act fast and defend yourself. ";
	    
	    userInput = GetInput();
	    
	    if ( !Objects.Find(userInput) ) {
	        cout << "This wasn't in your inventory. You couldn't defend yourself. " << endl;
	        EndGame();
	    }
	    else {
	        cout << "This item was in your inventory: " << userInput << endl;
	       if (userInput == "scissor") {
	           cout << "You must stab the zombie in the eye with the scissor. ";
	           userInput = GetInput();
	           while (userInput != "stab") {
	               cout << "Stab the zombie. ";
	               userInput = GetInput();
	           }
	           if (userInput == "stab") {
	               cout << "The zombie has calmed down and can't see." << endl;
	           }
	       }
	       if (userInput == "hammer") {
	           cout << "Smash its face with the hammer. ";
	           userInput = GetInput();
	           while (userInput != "smash") {
	               cout << "Smash the zombie with the hammer. ";
	               userInput = GetInput();
	           }
	           if (userInput == "smash") {
	               cout << "The zombie has been knocked down." << endl;
	           }
	       }
	       if (userInput == "axe") {
	           cout << "Cut its hand off. ";
	           userInput = GetInput();
	           while (userInput != "cut") {
	               cout << "Cut its hand. ";
	               userInput = GetInput();
	           }
	           if (userInput == "cut") {
	               cout << "The zombie has calmed down." << endl;
	           }
	       }
	       
	       cout << "Now that the zombie isn't attacking you, you realize the table in the middle of the room. ";
	       cout << "There's something shiny on the top of the table. It's a jewel. ";
	       userInput = GetInput();
	       while(userInput != "take" && userInput != "jewel") {
	           cout << "Why wouldn't you want something so shiny. ";
	           userInput = GetInput();
	       }
	       if (userInput == "take" || userInput == "jewel"){
	            Objects.addItems("jewel");
	            cout << "Jewel has been added to inventory. ";
	       
	       }
	       
	       cout << endl;
	       cout << "There's one room remaining on this floor, it's the dining room. ";
	       cout << "Let's check it out. " << endl << endl;
	       Diningroom();
	       
	    }
    }
	 
	//game ends if you don't use weapon against them
}

void Floor1:: Diningroom () {
    Floor2 floor2;

    floor2.Objects = Objects;
    
    cout << "You are now in the dining room. ";
    cout << "There's a table and on it there's a plate of food. ";
    cout << "Looks like raw meat with a side of potatoes... seems like someone has been here. ";
    cout << "Either you can go upstairs and figure out how to get out or stay locked up in this house. " << endl;
    cout << "Are you brave enough to continue? " ;
    
    userInput = GetInput();
    
    while (userInput != "no" && userInput != "yes") {
        cout << "Would you like to go upstairs? ";
        userInput = GetInput();
    }
    
    if (userInput == "yes") {
        cout << "Up these stairs we go..." << endl;
        floor2.Hallway2();
    }
    
    else if (userInput == "no") {
        cout << "Are you sure? ";
        userInput = GetInput();
        cout << endl;
        if (userInput == "yes") {
            EndGame();
        }
        else if (userInput == "no"){
            cout << "Up these stairs we go..." << endl;
            floor2.Hallway2();
        }
    }
}

void Floor1:: EndGame() {
    cout << "You'll now turn into a zombie like the rest did and stay in this house forever." << endl;
    cout << "GAME ENDED";
}



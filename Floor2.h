#ifndef FLOOR2H
#define FLOOR2H
#include "Inventory.h"
#include "Floor1.h"
#include <vector>
using namespace std;

class Floor2 {
    private:
        string message = "rumble rustle swoosh";
        
    public:
      
        Inventory Objects;
        string GetInput2();
        
        void Hallway2();
        string userResponse();
        
        void MasterBedroomPt1();
        int MasterBedroomPt2(); //number guessing game
        
        void Bathroom2();
        void KidsRoom();
        void KidsPlayRoom(); 
        void TheaterRoom1();
        void TheaterRoom2();
};

#endif
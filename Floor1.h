#ifndef FLOORH
#define FLOORH
#include <iostream>
#include <vector>
#include <string>
#include "Floor2.h"
#include "Inventory.h"
using namespace std;

class Floor1 {
    
    
    public:
    Inventory Objects;
    string GetInput();
    void Hallway();
    void Bathroom();
    void Kitchen();
    void Office();
    void Garage();
    void LockedOffice();
    void Diningroom();
    void EndGame();
    

};

#endif

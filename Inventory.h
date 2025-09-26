#ifndef INVENTORYH
#define INVENTORYH
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Inventory {
private:
    vector <string> ItemsCollected;

public:
    void addItems(string n) {
        //this function adds to the vector
       ItemsCollected.push_back(n);
    }
    
    void viewItems() {
        //this function allows to view what's in inventory
        cout << "Inventory: ";
        for (int i = 0; i < ItemsCollected.size(); ++i){
            cout << ItemsCollected.at(i) << ", ";
        }
        cout << endl;    
    }
    
    bool Find(string Input) {
        //this function checks to see if user has a certain item in inventory
        bool getback = false;
        for (int i = 0; i < ItemsCollected.size(); ++i){
            if (Input == ItemsCollected.at(i)) {
                getback = true;
                break;
            }
            
        }
        return getback;
          
    }
};

#endif
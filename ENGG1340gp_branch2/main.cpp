#include "Game.h"

int main() {
    Game game;
    run(&game);
    return 0;
}



/*
1. display cargoItem
2. Travel to another planet
3. exit

Initial planet=Earth
1. displaycargoItem
2. "Mars", 
3. "Venus", 
4. "Jupiter", 
5. "Saturn",
6. "Uranus", 
7. "Neptune"
8. Exit

Travel between planets--> trigger events randomly
After arriving a planet
max[0,Food, Water, Fuel-=distance]
Mars exmple:
    display the market price:   Food
                                Metal
                                Fuel
                                water
    1. sell
        Food
        Metal
        Fuel
        water
    2. sold
        Food
        Metal
        Fuel
        water
    
    
*/
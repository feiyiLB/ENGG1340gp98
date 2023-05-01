#ifndef FILE_H
#define FILE_H

#include <bits/stdc++.h>
using namespace std;


//to get identity, like the defence of play, factor should be:PlayerDefence, like the price of food in Mars should be :MarsFood
string GetIdentity(string factor);
// the format store in the file will be "PlayerDefence 100", if the new defence is 120, please use StorePlayerData(PlayerDefence, 120) 
// If store the price of food in Mars it should be StoreData(MarsFood,100)
void StoreData(string factor,string value);


#endif
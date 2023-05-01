#include "file.h"
#include <bits/stdc++.h>
using namespace std;

string GetIdentity(string factor)
{
    ifstream player;
    player.open("Data.txt");
    string identity,line,value;
    if (player.fail()) cout << " Error in opening the file !"<<endl;
    else
    {
        while (getline(player,line))
        {
            istringstream line_in(line);
            line_in >> identity;
            if (identity == factor)
            {
                line_in >> value;
                break;
            }
        }
    }
    player.close();
    return value;
}


void StoreData(string factor,string value)// modify the data
{
    fstream file("data.txt", ios::in | ios::out);
    if (file.fail())cout << "Error opening file!" << endl;
    else
    {
        int current_pos = 0;
        string new_content = factor + " " + value;
        string line;
        while (getline(file, line))
        {
            if (line.find(factor) != string::npos)
            {
                file.seekp(file.tellg() - line.length() - 1);
                file << new_content << endl;
            }
        }
    }
}
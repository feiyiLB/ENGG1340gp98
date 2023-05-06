# Galactic Space Trader

#### 1.Team members
- LU BO 3036104046 (feiyiLB)
- Yang Ziling 3036105911 (AnsonYMM)
- Gao Zhuojing 3036102335 (Granger19)
- Yin Aobing 3036104034 (AobingYin)
- Han Yuxin 3035974511 (asdacssda)
-------------------------------------------------------
#### 2.Introduction of game and rules
##### 2.1 Background of game
In this game, the player becomes a space trader, traveling between planets to **buy low and sell high**. The player must manage their ship, cargo, and finances while avoiding pirates and other dangers. Key components:
- Procedurally generated galaxy map with various planets, trade routes, and events
- Ship upgrades and customization options
- Combat encounters with pirates and other hostile entities
- **Random events** and encounters that can affect the player's journey
##### 2.2 Rules
- The only way to end the game is **Win the boss**
- The boss live on the **Earth**
- Player should earn the money in order to **arm himself** because the boss is to0 strong
- Mars is the **only planet** which allow player to arm himself
- Player can use money to join the **mystery game** on Jupiter and Saturn which allow player get **a numerous amount of money** or **lost all the money**
- Player **cannot travel** between planets without enough cargo (each unit distance cost 1 unit food, 1 unit water, 3 unit fuel)
#### 3.Feature of game
- This game also uses a linked list to get the quantity of trhe CargoItem and append and remove the quantity in CargoItem, which fulfills the dynamic mmemory management(Dynamic Memory Management)
- The game builds structure of CargoItem in CargoItem.cpp and structures of weapons to store the attack points of weapons.(Data structures for storing game status)
- This game allows users to save and load the data of the game by loading and saving the file. Players can choose save the file and enter the name of the file and the game will output "file saved successfully". After re-execute the main programme, "Load game" reads the data stored in the files if it can be found in the directory and allows player to play the game based on their former CargoItem. (File input/output)
- The planet position, the market price for each planet, events during travel are all randomly generated, which fulfills  the generation of random game events.(Generation of Random events)
- Apart from that, this game is formed by multiple files and meaningful variable name and proper indentation to make the programme more readable.
####4.Compilation and execution instructions
On **School Server**, input:
1. make
2. ./main

CXX = g++
CXXFLAGS = -Wall -std=c++17

# Object files
OBJ = BlackJack.o Boss.o CargoItem.o Event.o Galaxy.o Game.o Planet.o Player.o SaveLoad.o Weapons.o Dice.o main.o

# Executable name
EXE = game

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJ)

BlackJack.o: BlackJack.cpp BlackJack.h
	$(CXX) $(CXXFLAGS) -c BlackJack.cpp

Boss.o: Boss.cpp Player.h
	$(CXX) $(CXXFLAGS) -c Boss.cpp

CargoItem.o: CargoItem.cpp CargoItem.h
	$(CXX) $(CXXFLAGS) -c CargoItem.cpp

Event.o: Event.cpp Event.h Player.h Planet.h
	$(CXX) $(CXXFLAGS) -c Event.cpp

Galaxy.o: Galaxy.cpp Galaxy.h Planet.h
	$(CXX) $(CXXFLAGS) -c Galaxy.cpp

Game.o: Game.cpp Game.h Galaxy.h Planet.h Player.h CargoItem.h SaveLoad.h boss.h Weapons.h BlackJack.h Dice.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

Planet.o: Planet.cpp Planet.h
	$(CXX) $(CXXFLAGS) -c Planet.cpp

Player.o: Player.cpp Player.h CargoItem.h
	$(CXX) $(CXXFLAGS) -c Player.cpp

SaveLoad.o: SaveLoad.cpp Game.h CargoItem.h Player.h
	$(CXX) $(CXXFLAGS) -c SaveLoad.cpp

Weapons.o: Weapons.cpp Weapons.h Player.h
	$(CXX) $(CXXFLAGS) -c Weapons.cpp

Dice.o: Dice.cpp
	$(CXX) $(CXXFLAGS) -c Dice.cpp

main.o: main.cpp Game.h
	$(CXX) $(CXXFLAGS) -c main.cpp

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXE)

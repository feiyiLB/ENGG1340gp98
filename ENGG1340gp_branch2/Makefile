CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o Game.o Galaxy.o Planet.o Player.o CargoItem.o SaveLoad.o boss.o Weapons.o Event.o BlackJack.o

TARGET = space_game

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp Game.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Game.o: Game.cpp Game.h Galaxy.h Planet.h Player.h CargoItem.h SaveLoad.h boss.h Weapons.h Event.h BlackJack.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

Galaxy.o: Galaxy.cpp Galaxy.h Planet.h
	$(CXX) $(CXXFLAGS) -c Galaxy.cpp

Planet.o: Planet.cpp Planet.h
	$(CXX) $(CXXFLAGS) -c Planet.cpp

Player.o: Player.cpp Player.h CargoItem.h
	$(CXX) $(CXXFLAGS) -c Player.cpp

CargoItem.o: CargoItem.cpp CargoItem.h
	$(CXX) $(CXXFLAGS) -c CargoItem.cpp

SaveLoad.o: SaveLoad.cpp Game.h CargoItem.h Player.h
	$(CXX) $(CXXFLAGS) -c SaveLoad.cpp

boss.o: boss.cpp Player.h
	$(CXX) $(CXXFLAGS) -c boss.cpp

Weapons.o: Weapons.cpp Weapons.h Player.h
	$(CXX) $(CXXFLAGS) -c Weapons.cpp

Event.o: Event.cpp Event.h Player.h Planet.h
	$(CXX) $(CXXFLAGS) -c Event.cpp

BlackJack.o: BlackJack.cpp BlackJack.h
	$(CXX) $(CXXFLAGS) -c BlackJack.cpp


clean:
	rm -f $(TARGET) $(OBJS)

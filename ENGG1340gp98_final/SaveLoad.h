#ifndef SAVELOAD_H
#define SAVELOAD_H

#include "Game.h"
#include <string>

void saveGame(const Game* game, const std::string& filename);
void loadGame(Game* game, const std::string& filename);

#endif // SAVELOAD_H

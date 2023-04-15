#ifndef EVENT_H
#define EVENT_H

#include "Player.h"

struct PirateEvent {
    int stolen_goods[5];
};

void execute_pirate_event(Player* player, PirateEvent* pirate_event);

#endif // EVENT_H

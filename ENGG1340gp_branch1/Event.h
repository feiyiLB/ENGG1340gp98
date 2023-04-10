#ifndef EVENT_H
#define EVENT_H

#include "Player.h"

class Event {
public:
    virtual void execute(Player& player) = 0;
};

class PirateEvent : public Event {
public:
    void execute(Player& player) override;
};

#endif // EVENT_H

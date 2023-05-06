#include "CargoItem.h"
#include <cstring>

CargoItem* createCargoItem(const char* good, int quantity) {
    CargoItem* newItem = new CargoItem;
    strncpy(newItem->good, good, sizeof(newItem->good) - 1);
    newItem->good[sizeof(newItem->good) - 1] = '\0';
    newItem->quantity = quantity;
    newItem->next = nullptr;
    return newItem;
}

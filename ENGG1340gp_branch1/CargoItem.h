#ifndef CARGO_ITEM_H
#define CARGO_ITEM_H

#include <string>

class CargoItem {
public:
    std::string good;
    int quantity;
    CargoItem* next;

    CargoItem(const std::string& good, int quantity);
};

#endif // CARGO_ITEM_H


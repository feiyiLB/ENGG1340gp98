#ifndef CARGO_ITEM_H
#define CARGO_ITEM_H

typedef struct CargoItem {
    char good[10];
    int quantity;
    struct CargoItem* next;
} CargoItem;

CargoItem* createCargoItem(const char* good, int quantity);

#endif // CARGO_ITEM_H


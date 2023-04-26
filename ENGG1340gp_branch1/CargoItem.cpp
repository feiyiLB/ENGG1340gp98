#include "CargoItem.h"

CargoItem::CargoItem(const std::string& good, int quantity)
    : good(good), quantity(quantity), next(nullptr) {}

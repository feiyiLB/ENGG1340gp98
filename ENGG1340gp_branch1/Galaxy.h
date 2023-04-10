#ifndef GALAXY_H
#define GALAXY_H

#include "Planet.h"

class Galaxy {
public:
    Planet* planets;
    int num_planets;

    Galaxy(int num_planets);
    ~Galaxy();

    void generateGalaxy();
};

#endif // GALAXY_H

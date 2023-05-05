#ifndef GALAXY_H
#define GALAXY_H

#include "Planet.h"

typedef struct Galaxy {
    Planet* planets;
    int num_planets;
} Galaxy;
void initGalaxy(Galaxy* galaxy, int num_planets);
void freeGalaxy(Galaxy* galaxy);
void generateGalaxy(Galaxy* galaxy);

#endif // GALAXY_H

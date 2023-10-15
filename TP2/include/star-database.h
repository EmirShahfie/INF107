#ifndef STAR_DATABASE_H
#define STAR_DATABASE_H

#include "star-list.h"

static char *splitPrefix(char *s, char delimiter);

extern bool readStar(FILE *f, stars *etoile);

extern node *readAllStar(const char *file);

#endif
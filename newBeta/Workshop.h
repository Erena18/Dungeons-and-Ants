// Workshop.h
#ifndef WORKSHOP_H
#define WORKSHOP_H

#include "Building.h"

class Workshop : public Building {
public:
    Workshop();
    void dailyUpdate() override;
};

#endif // WORKSHOP_H

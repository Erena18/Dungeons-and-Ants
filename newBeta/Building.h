// Building.h
#ifndef BUILDING_H
#define BUILDING_H

class Building {
public:
    Building(int capacity, int count, int constructionCost);
    virtual ~Building() {}

    int getCapacity() const;
    int getCount() const;
    int getConstructionCost() const;

    virtual void dailyUpdate() = 0;

protected:
    int capacity;
    int count;
    int constructionCost;
};

#endif // BUILDING_H
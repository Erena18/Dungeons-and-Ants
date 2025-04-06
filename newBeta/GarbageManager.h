// GarbageManager.h
#ifndef GARBAGEMANAGER_H
#define GARBAGEMANAGER_H

#include "Garbage.h"
#include <vector>

class GarbageManager {
public:
    static GarbageManager& getInstance();

    void addGarbage(Garbage::Type type, int weight);
    void removeGarbage(int index);

    const std::vector<Garbage>& getGarbageList() const;

private:
    GarbageManager() {}
    std::vector<Garbage> garbageList;
};

#endif // GARBAGEMANAGER_H

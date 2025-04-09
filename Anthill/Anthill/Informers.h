#pragma once

#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Builder.h"
#include "Child.h"
#include "Cleaner.h"
#include "Collector.h"
#include "Heardsant.h"
#include "Nanny.h"
#include "Queen.h"
#include "Soldier.h"

#include "Anthill.h"
#include "Building.h"
#include "Food.h"
#include "FoodItem.h"
#include "Garbage.h"
#include "GarbageManager.h"
#include "Materials.h"
#include "MaterialsItem.h"
#include "Warehouse.h"

#include "Zone.h"
#include "DangerousZone.h"
#include "EmptyZone.h"
#include "FoodZone.h"
#include "MaterialZone.h"
#include "PastureZone.h"

#include "AntLogic.h"
#include "Dimensions.h"


#include <iostream>
#include <cstdlib>
#include <memory>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Role;
class Nanny;
class Collector;
class Soldier;
class Cleaner;

class Informer 
{
public:
    virtual ~Informer() {}

    void subscribe(Role* role);
    void unsubscribe(Role* role);
    void notify();
private:
    vector<Role*> subscribers;
};

//COLLECTOR
class CollectorInformer : public Informer
{
public:
    void addCollector(Collector* collector);
    void notify();

private:
    vector<Collector*> collectors;
};

//NANNY
class NannyInformer : public Informer
{
public:
    void addNanny(Nanny* nanny);
    void notify();

private:
    vector<Nanny*> nannys;
};

//CLEANER
class CleanerInformer : public Informer
{
public:
    void addCleaner(Cleaner* cleaner);
    void notify();

private:
    vector<Cleaner*> cleaners;
};

//SOLDIER
class SoldierInformer : public Informer
{
public:
    void addSoldier(Soldier* soldier);
    void notify();

private:
    vector<Soldier*> soldiers;
};
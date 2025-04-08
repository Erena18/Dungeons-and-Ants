#pragma once
#include "Role.h"
#include "Ant.h"
#include "Aphid.h"
#include "Nanny.h"
#include "Child.h"
#include "Queen.h"
#include "Builder.h"
#include "Cleaner.h"
#include "Soldier.h"
#include "Heardsant.h"
#include "Collector.h"

#include "Food.h"
#include "FoodItem.h"
#include "Anthill.h"

#include <iostream>
#include <cstdlib>
#include <memory>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Role;

class Informer 
{
public:
    virtual ~Informer() {}

    void subscribe(Role* role);
    void unsubscribe(Role* role);
    void notify(const std::string& message);
private:
    vector<Role*> subscribers;
};

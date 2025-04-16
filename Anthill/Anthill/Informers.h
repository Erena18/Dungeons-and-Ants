#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Role.h"

using namespace std;

class Ant;

class Informer 
{
public:
    virtual ~Informer() = default;

    void subscribe(Role* role);
    void unsubscribe(Role* role);
    virtual void notify(Ant& ant);
private:
    vector<Role*> subs;
};
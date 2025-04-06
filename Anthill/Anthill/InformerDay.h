#pragma once
#include "Nanny.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

//INFORMER 
class InformerDay
{
public:
	void subscribe(Nanny* nanny);
	void unsubscribe(Nanny* nanny);
	void notifyChildrenWantToEat();

private:
	vector<Nanny*> nannies;
};
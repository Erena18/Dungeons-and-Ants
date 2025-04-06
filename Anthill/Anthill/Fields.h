#pragma once
#include <iostream>
#include "Header.h"
#define FIELD_LEN 15

class Field {
public:
	Field();
	virtual ~Field();
	virtual void setCap();
	virtual void setField();
private:
	int x, y;
	int capacity;
	char type[FIELD_LEN];				//foodField, materialField, emptyField, grassField, deadField, dangerousField
};

class foodField : public Field {

};
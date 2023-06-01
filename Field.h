#pragma once
#include "Plant.h"

class Field : public Plant {
public:
	Field();
	Field(World* world, coords xy);
	void print() override;
	~Field();
};

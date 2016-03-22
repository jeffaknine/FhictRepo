#include "Wheel.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Wheel::Wheel(int diameter, const string& material)
:	diameter(diameter),
	material(material)
{
}

string Wheel::getMaterial() const
{
	return material;
}

void Wheel::setMaterial(const string& material)
{
	Wheel::material = material;
}

int Wheel::getDiameter() const
{
	return diameter;
}
#include "Wheel.h"

Wheel::Wheel(int diameter, const std::string& material)
{
	this->diameter = diameter;
	this->material = material;
}


std::string Wheel::getMaterial() const
{
	return material;
}

void Wheel::setMaterial(const std::string& material)
{
	this->material = material;
}


int Wheel::getDiameter() const
{
	return diameter;
}
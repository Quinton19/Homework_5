#include "Battery.h"

Battery::Battery(string n, int pn, double w, double c, string d, double e)
{
	Robot_Part(n, pn, w, c, d, Component_type::Battery);
	energy = e;
}

int Battery::get_energy_contained()
{
	return energy;
}

string Battery::to_string()
{
	string result;
	result = to_string() + "Energy contained: " + get_energy_contained() + "\n";
	return result;
}
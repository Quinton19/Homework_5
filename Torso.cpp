#include "Torso.h"

Torso::Torso(string n, int pn, double w, double c, string d, int bc)
{
	Robot_Part(n, pn, w, c, d, Component_type::Torso);
	battery_compartments = bc;
}

int Torso::get_battery_compartments()
{
	return battery_compartments;
}
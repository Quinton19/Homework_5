#include "Arm.h"

Arm::Arm(string n, int pn, double w, double c, string d, int pc) : Robot_Part(n, pn, w, c, d, Component_type::Arm)
{
	power_consumed = pc;
}

int Arm::get_power_consumed()
{
	return power_consumed;
}

string Arm::to_string()
{
	string result;
	result = Robot_Part::to_string() + "Power consumed: " + Robot_Part::to_string(get_power_consumed()) + "\n";
	return result;
}
#include "Locomotor.h"

Locomotor::Locomotor(string n, int pn, double w, double c, string d, int ms, int pc)
{
	Robot_Part(n, pn, w, c, d, Component_type::Locomotor);
	max_speed = ms;
	power_consumed = pc;
}

int Locomotor::get_max_speed()
{
	return max_speed;
}

int Locomotor::get_power_consumed()
{
	return power_consumed;
}
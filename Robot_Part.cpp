#include "Robot_Part.h"

Robot_Part::Robot_Part(string n, int pn, double w, double c, string d, Component_type t)
{
	name = n;
	part_num = pn;
	weight = w;
	cost = c;
	description = d;
	type = t;
}

string Robot_Part::get_name()
{
	return name;
}

int Robot_Part::get_part_num()
{
	return part_num;
}

double Robot_Part::get_weight()
{
	return weight;
}

double Robot_Part::get_cost()
{
	return cost;
}

string Robot_Part::get_description()
{
	return description;
}

Component_type Robot_Part::get_component_type()
{
	return type;
}

string Robot_Part::get_component_type_str()
{
	if (type == Component_type::Head)
		return "head";
	else if (type == Component_type::Locomotor)
		return "locomotor";
	else if (type == Component_type::Torso)
		return "torso";
	else if (type == Component_type::Battery)
		return "battery";
	else if (type == Component_type::Arm)
		return "arm";
}
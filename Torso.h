#include "Robot_Part.h"

class Torso : public Robot_Part
{
private:
	int battery_compartments;
public:
	Torso(string n, int pn, double w, double c, string d, int bc);
	int get_battery_compartments();
};
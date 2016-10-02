#include "Robot_Part.h"

class Arm : public Robot_Part
{
private:
	int power_consumed;
public:
	Arm(string n, int pn, double w, double c, string d, int pc);
	int get_power_consumed();
};
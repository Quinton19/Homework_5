#include "Robot_Part.h"

class Locomotor : public Robot_Part
{
private:
	int max_speed;
	double power_consumed;
public:
	Locomotor(string n, int pn, double w, double c, string d, int ms, double pc);
	int get_max_speed();
	double get_power_consumed();
	string to_string();
};

#include "Robot_Part.h"

class Battery : public Robot_Part
{
private:
	double energy;
public:
	Battery(string n, int pn, double w, double c, string d, double e);
	double get_energy_contained();
	string to_string();
};
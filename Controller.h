#include "View.h"

class Controller
{
private:
	int rand_num;
	Robot_Part* rand_part;
	View view;
public:
	Controller();
	void cli();
	void make_rand_part();
};

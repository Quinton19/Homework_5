#include "Controller.h"
#include "Head.h"
#include "Locomotor.h"
#include "Torso.h"
#include "Battery.h"
#include "Arm.h"

Controller::Controller()
{
	view();
	srand(time(NULL));
	rand_num = (rand() % 6) + 1;
}

void Controller::cli()
{
	make_rand_part();
	cout << "Random part created: \n";
	view.view_part_info(rand_part);
}

void Controller::make_rand_part()
{
	switch (rand_num)
	{
	case 1:
		Head h("Random Head", (rand() % 1000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random head.");
		rand_part = h;
		break;
	case 2:
		Locomotor l("Random Locomotor", (rand() % 1000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random locomotor.", (rand() % 100), (rand() % 1000));
		rand_part = l;
		break;
	case 3:
		Torso t("Random Torso", (rand() % 1000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random torso.", (rand() % 11));
		rand_part = t;
		break;
	case 4:
		Battery b("Random Battery", (rand() % 1000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random battery.", ((rand() % 100000000) / 100.0));
		rand_part = b;
		break;
	case 5:
		Arm a("Random Head", (rand() % 1000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random head.", (rand() % 1000));
		rand_part = a;
		break;
	default:
		Robot_Part r("Random Robot Part", (rand() % 1000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random robot part.");
		rand_part = r;
		break;
	}
}
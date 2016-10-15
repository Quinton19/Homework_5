#include "Shop.h"
#include <time.h>

Shop::Shop()
{
	srand(time(NULL));
}

void Shop::add(Head h)
{
	for (Head head : heads)
	{
		if (head.get_part_num() == h.get_part_num())
			throw Part_Num_Exists{};
	}
	heads.push_back(h);
}

void Shop::add(Torso t)
{
	for (Torso torso : torsos)
	{
		if (torso.get_part_num() == t.get_part_num())
			throw Part_Num_Exists{};
	}
	torsos.push_back(t);
}

void Shop::add(Locomotor l)
{
	for (Locomotor locomotor : locomotors)
	{
		if (locomotor.get_part_num() == l.get_part_num())
			throw Part_Num_Exists{};
	}
	locomotors.push_back(l);
}

void Shop::add(Arm a)
{
	for (Arm arm : arms)
	{
		if (arm.get_part_num() == a.get_part_num())
			throw Part_Num_Exists{};
	}
	arms.push_back(a);
}

void Shop::add(Battery b)
{
	for (Battery battery : batteries)
	{
		if (battery.get_part_num() == b.get_part_num())
			throw Part_Num_Exists{};
	}
	batteries.push_back(b);
}

void Shop::add(Robot_Model model)
{
	for (Robot_Model rm : models)
	{
		if (rm.get_model_num() == model.get_model_num())
			throw Model_Num_Exists{};
	}
	models.push_back(model);
	/*
	try
	{
		remove(model.get_head());
		remove(model.get_torso());
		remove(model.get_locomotor());
		for (Arm arm : model.get_arms())
			remove(arm);
		for (Battery battery : model.get_batteries())
			remove(battery);
	}
	catch (Part_Num_DNE& e)
	{
		models.pop_back();
		throw Invalid_Model{};
	}
	*/
}

vector<Robot_Model> Shop::get_models()
{
	return models;
}

void Shop::create_rand_part() //for testing purposes only
{
	Head *h;
	Locomotor *l;
	Torso *t;
	Battery *b;
	Arm *a;
	int rand_num = (rand() % 5) + 1;
	switch (rand_num)
	{
	case 1:
		h = new Head("Random Head", (rand() % 10000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random head.");
		heads.push_back(*h);
		break;
	case 2:
		l = new Locomotor("Random Locomotor", (rand() % 10000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random locomotor.", (rand() % 100), (rand() % 100000)/100.0);
		locomotors.push_back(*l);
		break;
	case 3:
		t = new Torso("Random Torso", (rand() % 10000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random torso.", (rand() % 3) + 1);
		torsos.push_back(*t);
		break;
	case 4:
		b = new Battery("Random Battery", (rand() % 10000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random battery.", ((rand() % 100000000) / 100.0));
		batteries.push_back(*b);
		break;
	case 5:
		a = new Arm("Random Arm", (rand() % 10000000), ((rand() % 100000) / 100.0), ((rand() % 1000000) / 100.0), "This is a random description of a random arm.", (rand() % 100000)/100.0);
		arms.push_back(*a);
		break;
	}
}

vector<Head> Shop::get_available_heads()
{
	return heads;
}

vector<Torso> Shop::get_available_torsos()
{
	return torsos;
}

vector<Locomotor> Shop::get_available_locomotors()
{
	return locomotors;
}

vector<Arm> Shop::get_available_arms()
{
	return arms;
}

vector<Battery> Shop::get_available_batteries()
{
	return batteries;
}
/*
void Shop::remove(Head h)
{
	bool found = false;
	vector<Head> new_heads;
	for (Head head : heads)
	{
		if (head.get_part_num() != h.get_part_num())
			new_heads.push_back(head);
		else
			found = true;
	}
	if (!found)
		throw Part_Num_DNE{};
	else
		heads = new_heads;
}

void Shop::remove(Torso t)
{
	bool found = false;
	vector<Torso> new_torsos;
	for (Torso torso : torsos)
	{
		if (torso.get_part_num() != t.get_part_num())
			new_torsos.push_back(torso);
		else
			found = true;
	}
	if (!found)
		throw Part_Num_DNE{};
	else
		torsos = new_torsos;
}

void Shop::remove(Locomotor l)
{
	bool found = false;
	vector<Locomotor> new_locomotors;
	for (Locomotor locomotor : locomotors)
	{
		if (locomotor.get_part_num() != l.get_part_num())
			new_locomotors.push_back(locomotor);
		else
			found = true;
	}
	if (!found)
		throw Part_Num_DNE{};
	else
		locomotors = new_locomotors;
}

void Shop::remove(Arm a)
{
	bool found = false;
	vector<Arm> new_arms;
	for (Arm arm : arms)
	{
		if (arm.get_part_num() != a.get_part_num())
			new_arms.push_back(arm);
		else
			found = true;
	}
	if (!found)
		throw Part_Num_DNE{};
	else
		arms = new_arms;
}

void Shop::remove(Battery b)
{
	bool found = false;
	vector<Battery> new_batteries;
	for (Battery battery : batteries)
	{
		if (battery.get_part_num() != b.get_part_num())
			new_batteries.push_back(battery);
		else
			found = true;
	}
	if (!found)
		throw Part_Num_DNE{};
	else
		batteries = new_batteries;
}
*/
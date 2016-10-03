#include "View.h"

View::View()
{}

void View::view_part_info(Robot_Part p)
{
	cout << p.to_string();
}
#include "Robot_Part.h"
#include "Arm.h"
#include "Battery.h"
#include "Head.h"
#include "Torso.h"
#include "Locomotor.h"

int main()
{
	bool pass = true;
	string fail_messages = "";

	//Testing Str_conversion
	if (Str_conversion::to_string(913).compare("913") != 0)
	{
		pass = false;
		fail_messages += ".to_string(int) in class Str_conversion failed\n";
	}
	if (Str_conversion::to_string(123.456).compare("123.456") != 0)
	{
		pass = false;
		fail_messages += ".to_string(double) in class Str_conversion failed\n";
	}

	//Testing Robot_Part
	Robot_Part rp("Test Robot Part", 123456789, 23.36664289109, 500.00, "This is simply a test to ensure that the program creates robot parts correctly.", Component_type::Locomotor);
	if (rp.get_name().compare("Test Robot Part") != 0)
	{
		pass = false;
		fail_messages += ".get_name() in class Robot_Part failed\n";
	}
	if (rp.get_part_num() != 123456789)
	{
		pass = false;
		fail_messages += ".get_part_num() in class Robot_Part failed\n";
	}
	if (rp.get_weight() != 23.36664289109)
	{
		pass = false;
		fail_messages += ".get_weight() in class Robot_Part failed\n";
	}
	if (rp.get_cost() != 500.00)
	{
		pass = false;
		fail_messages += ".get_cost() in class Robot_Part failed\n";
	}
	if (rp.get_description().compare("This is simply a test to ensure that the program creates robot parts correctly.") != 0)
	{
		pass = false;
		fail_messages += ".get_description() in class Robot_Part failed\n";
	}
	if (rp.get_component_type() != Component_type::Locomotor)
	{
		pass = false;
		fail_messages += ".get_component_type() in class Robot_Part failed\n";
	}
	if (rp.get_component_type_str().compare("locomotor") != 0)
	{
		pass = false;
		fail_messages += ".get_component_type_str() in class Robot_Part failed\n";
	}
	if (rp.to_string().compare("Name: " + rp.get_name() + "\n"
							+ "Part Number: " + Str_conversion::to_string(rp.get_part_num()) + "\n"
							+ "Weight: " + Str_conversion::to_string(rp.get_weight()) + "\n"
							+ "Cost: $" + Str_conversion::to_string(rp.get_cost()) + "\n"
							+ "Description: " + rp.get_description() + "\n"
							+ "Part type: " + rp.get_component_type_str() + "\n") != 0)
	{
		pass = false;
		fail_messages += ".to_string() in class Robot_Part failed\n";
	}

	//Testing Arm
	Arm a("Test Arm", 999999, 11.1, 45.99, "This is simply a test to ensure that the program creates arms correctly.", 20);
	if (a.get_power_consumed() != 20.0)
	{
		pass = false;
		fail_messages += ".get_power_consumed() in class Arm failed\n";
	}
	if (a.to_string().compare("Name: " + a.get_name() + "\n"
							+ "Part Number: " + Str_conversion::to_string(a.get_part_num()) + "\n"
							+ "Weight: " + Str_conversion::to_string(a.get_weight()) + "\n"
							+ "Cost: $" + Str_conversion::to_string(a.get_cost()) + "\n"
							+ "Description: " + a.get_description() + "\n"
							+ "Part type: " + a.get_component_type_str() + "\n"
							+ "Power consumed: " + Str_conversion::to_string(a.get_power_consumed()) + "\n") != 0)
	{
		pass = false;
		fail_messages += ".to_string() in class Arm failed\n";
	}

	//Testing Battery
	Battery b("Test Battery", -222, 50, 400, "This is simply a test to ensure that the program creates batteries correctly.", 0);
	if (b.get_energy_contained() != 0.0)
	{
		pass = false;
		fail_messages += ".get_energy_contained() in class Battery failed\n";
	}
	if (b.to_string().compare("Name: " + b.get_name() + "\n"
							+ "Part Number: " + Str_conversion::to_string(b.get_part_num()) + "\n"
							+ "Weight: " + Str_conversion::to_string(b.get_weight()) + "\n"
							+ "Cost: $" + Str_conversion::to_string(b.get_cost()) + "\n"
							+ "Description: " + b.get_description() + "\n"
							+ "Part type: " + b.get_component_type_str() + "\n"
							+ "Energy contained: " + Str_conversion::to_string(b.get_energy_contained()) + "\n") != 0)
	{
		pass = false;
		fail_messages += ".to_string() in class Battery failed\n";
	}

	//Testing Head
	Head h("Test Head", 1, 5000000.000001, 999999.02, "This is simply a test to ensure that the program creates heads correctly.");
	if (h.to_string().compare("Name: " + h.get_name() + "\n"
							+ "Part Number: " + Str_conversion::to_string(h.get_part_num()) + "\n"
							+ "Weight: " + Str_conversion::to_string(h.get_weight()) + "\n"
							+ "Cost: $" + Str_conversion::to_string(h.get_cost()) + "\n"
							+ "Description: " + h.get_description() + "\n"
							+ "Part type: " + h.get_component_type_str() + "\n") != 0)
	{
		pass = false;
		fail_messages += ".to_string() in class Head failed\n";
	}

	//Testing Torso
	Torso t("Test Torso", 00001101, 749673, 555, "This is simply a test to ensure that the program creates torsos correctly.", 100);
	if (t.get_battery_compartments() != 100)
	{
		pass = false;
		fail_messages += ".get_battery_compartments() in class Torso failed\n";
	}
	if (t.to_string().compare("Name: " + t.get_name() + "\n"
							+ "Part Number: " + Str_conversion::to_string(t.get_part_num()) + "\n"
							+ "Weight: " + Str_conversion::to_string(t.get_weight()) + "\n"
							+ "Cost: $" + Str_conversion::to_string(t.get_cost()) + "\n"
							+ "Description: " + t.get_description() + "\n"
							+ "Part type: " + t.get_component_type_str() + "\n"
							+ "Number of battery compartments: " + Str_conversion::to_string(t.get_battery_compartments()) + "\n") != 0)
	{
		pass = false;
		fail_messages += ".to_string() in class Torso failed\n";
	}

	//Testing Locomotor
	Locomotor l("Test Locomotor", 5639272, 0.9, 0.99, "This is simply a test to ensure that the program creates locomotors correctly.", 88, 1.21);
	if (l.get_max_speed() != 88)
	{
		pass = false;
		fail_messages += ".get_max_speed() in class Locomotor failed\n";
	}
	if (l.get_power_consumed() != 1.21)
	{
		pass = false;
		fail_messages += ".get_power_consumed() in class Locomotor failed\n";
	}
	if (l.to_string().compare("Name: " + l.get_name() + "\n"
							+ "Part Number: " + Str_conversion::to_string(l.get_part_num()) + "\n"
							+ "Weight: " + Str_conversion::to_string(l.get_weight()) + "\n"
							+ "Cost: $" + Str_conversion::to_string(l.get_cost()) + "\n"
							+ "Description: " + l.get_description() + "\n"
							+ "Part type: " + l.get_component_type_str() + "\n"
							+ "Max speed: " + Str_conversion::to_string(l.get_max_speed()) + "\n"
							+ "Power consumed: " + Str_conversion::to_string(l.get_power_consumed()) + "\n") != 0)
	{
		pass = false;
		fail_messages += ".to_string() in class Locomotor failed\n";
	}

	if (!pass)
	{
		cerr << fail_messages;
	}
	else
	{
		cout << "pass\n";
	}

	return 1;
}
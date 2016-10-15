#include "Controller.h"
#include <iomanip>

void Controller::cli()
{
	int cmd;
	do
	{
		view.display_menu();
		cout << "Please enter a command: ";
		cin >> cmd;
		cin.ignore();
		cout << "-------------------------------------------------\n\n";
		execute_cmd(cmd);
	} while (cmd != 0);
}

void Controller::execute_cmd(int cmd)
{
	switch (cmd)
	{
		case 1:
			add_new_part();
			break;
		case 2:
			add_new_model();
			break;
		case 3:
			list_all_models();
			break;
		case 4:
			order_robot_models();
			break;
		case 9:
			view.help();
			break;
		case 0:
			cout << "Goodbye.\n";
			break;
		case 913: //for testing purposes only
			break;
		default:
			cerr << "Invalid command. Please try again. (Type 9 for help)\n\n";
	}
}

void Controller::add_new_part()
{
	char correct;
	string name, description;
	int part_num, batt_compartments, speed, type_num;
	Component_type type;
	double weight, cost, pwr_consumed, energy;

	while (true)
	{
		do
		{
			cout << "1) Head\n"
				<< "2) Torso\n"
				<< "3) Locomotor\n"
				<< "4) Arm\n"
				<< "5) Battery\n"
				<< "Select the type of the robot part: ";
			cin >> type_num;
			cin.ignore();
			cout << "\n";

			if (!cin) 
			{
				cerr << "Invalid entry. Please try again.\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				type_num = -1;
			}
			else
			{
				switch (type_num)
				{
				case 1:
					type = Component_type::Head;
					break;
				case 2:
					type = Component_type::Torso;
					break;
				case 3:
					type = Component_type::Locomotor;
					break;
				case 4:
					type = Component_type::Arm;
					break;
				case 5:
					type = Component_type::Battery;
					break;
				default:
					cerr << "Invalid choice. Please try again.\n\n";
				}
			}
		} while (type_num < 1 || type_num > 5);

		cout << "Enter in the name of the part: ";
		getline(cin, name);
		cout << "Enter in the part number: ";
		cin >> part_num;
		cin.ignore();
		cout << "Enter in the part's weight (in pounds [lb]): ";
		cin >> weight;
		cin.ignore();
		cout << "Enter in the part's cost (in US dollars): $";
		cin >> cost;
		cin.ignore();
		cout << "Enter in a brief description of the part:\n";
		getline(cin, description);
		cout << "\n";

		switch (type)
		{
			case Component_type::Torso:
				do
				{
					cout << "Enter in the number of battery compartments within the torso: ";
					cin >> batt_compartments;
					cin.ignore();
					cout << "\n";

					if (batt_compartments < 1 || batt_compartments > 3)
						cerr << "Invalid number. Please try again.\n\n";
				} while (batt_compartments < 1 || batt_compartments > 3);
				break;
			case Component_type::Locomotor:
				cout << "Enter in the locomotor's maximum speed (in miles per hour [mph]): ";
				cin >> speed;
				cin.ignore();

				cout << "Enter in the power consumed when the locomotor is in operation (in watts [W]): ";
				cin >> pwr_consumed;
				cin.ignore();
				cout << "\n";
				break;
			case Component_type::Arm:
				cout << "Enter in the power consumed when the arm is in operation (in watts [W]): ";
				cin >> pwr_consumed;
				cin.ignore();
				cout << "\n";
				break;
			case Component_type::Battery:
				cout << "Enter in the amount of energy contained within the battery (in kilowatt-hours [kWh]): ";
				cin >> energy;
				cin.ignore();
				cout << "\n";
				break;
		}

		Head* h;
		Torso* t;
		Locomotor* l;
		Arm* a;
		Battery* b;

		switch (type)
		{
			case Component_type::Head:
				h = new Head(name, part_num, weight, cost, description);

				cout << h->to_string();
				cout << "\nIs this correct? [y/n] ";
				cin >> correct;
				cin.ignore();

				cout << "\n";

				if (correct == 'y')
				{
					try 
					{
						shop.add(*h);
						cout << "\nHead successfully added.\n";
						return;
					}
					catch (Part_Num_Exists& e)
					{
						cerr << "ERROR: Part number already exists. Please try again.\n";
					}
				}
				break;
			case Component_type::Torso:
				try
				{
					t = new Torso(name, part_num, weight, cost, description, batt_compartments);
				}
				catch (Compartment_Limit& e)
				{
					cerr << "ERROR: Unexepected error encountered while trying to create torso. Please try again.\n";
					break;
				}

				cout << t->to_string();
				cout << "\nIs this correct? [y/n] ";
				cin >> correct;
				cin.ignore();

				cout << "\n";

				if (correct == 'y')
				{
					try
					{
						shop.add(*t);
						cout << "\nTorso successfully added.\n";
						return;
					}
					catch (Part_Num_Exists& e)
					{
						cerr << "ERROR: Part number already exists. Please try again.\n";
					}
				}
				break;
			case Component_type::Locomotor:
				l = new Locomotor(name, part_num, weight, cost, description, speed, pwr_consumed);

				cout << l->to_string();
				cout << "\nIs this correct? [y/n] ";
				cin >> correct;
				cin.ignore();

				cout << "\n";

				if (correct == 'y')
				{
					try
					{
						shop.add(*l);
						cout << "\nLocomotor successfully added.\n";
						return;
					}
					catch (Part_Num_Exists& e)
					{
						cerr << "ERROR: Part number already exists. Please try again.\n";
					}
				}
				break;
			case Component_type::Arm:
				a = new Arm(name, part_num, weight, cost, description, pwr_consumed);

				cout << a->to_string();
				cout << "\nIs this correct? [y/n] ";
				cin >> correct;
				cin.ignore();

				cout << "\n";

				if (correct == 'y')
				{
					try
					{
						shop.add(*a);
						cout << "\nArm successfully added.\n";
						return;
					}
					catch (Part_Num_Exists& e)
					{
						cerr << "ERROR: Part number already exists. Please try again.\n";
					}
				}
				break;
			case Component_type::Battery:
				b = new Battery(name, part_num, weight, cost, description, energy);

				cout << b->to_string();
				cout << "\nIs this correct? [y/n] ";
				cin >> correct;
				cin.ignore();

				cout << "\n";

				if (correct == 'y')
				{
					try
					{
						shop.add(*b);
						cout << "\nBattery successfully added.\n";
						return;
					}
					catch (Part_Num_Exists& e)
					{
						cerr << "ERROR: Part number already exists. Please try again.\n";
					}
				}
				break;
		}
	}
}

void Controller::add_new_model()
{
	string name;
	int model_num, choice;
	double price;
	char another_part = 'q', correct;
	Head head;
	Torso torso;
	Locomotor locomotor;
	vector<Arm> arms;
	vector<Battery> batteries;

	cout << "Enter in the robot model's name: ";
	getline(cin, name);

	cout << "Enter in the model number: ";
	cin >> model_num;
	cin.ignore();

	do
	{
		view.display_heads_list();
		cout << "Select the head part to be used in this model: ";
		cin >> choice;
		if (choice < 1 || choice > shop.get_available_heads().size())
			cerr << "Invalid choice. Please try again.\n\n";
		else
		{
			vector<Head> shop_heads = shop.get_available_heads();
			head = shop_heads[choice - 1];
		}
	} while (choice < 1 || choice > shop.get_available_heads().size());

	do
	{
		view.display_torsos_list();
		cout << "Select the torso part to be used in this model: ";
		cin >> choice;
		if (choice < 1 || choice > shop.get_available_torsos().size())
			cerr << "Invalid choice. Please try again.\n\n";
		else
		{
			vector<Torso> shop_torsos = shop.get_available_torsos();
			torso = shop_torsos[choice - 1];
		}
	} while (choice < 1 || choice > shop.get_available_torsos().size());

	do
	{
		view.display_locomotors_list();
		cout << "Select the locomotor part to be used in this model: ";
		cin >> choice;
		if (choice < 1 || choice > shop.get_available_locomotors().size())
			cerr << "Invalid choice. Please try again.\n\n";
		else
		{
			vector<Locomotor> shop_locomotors = shop.get_available_locomotors();
			locomotor = shop_locomotors[choice - 1];
		}
	} while (choice < 1 || choice > shop.get_available_locomotors().size());

	for(int i = 0; i < 2; i++)
	{
		do
		{
			view.display_arms_list();
			cout << "Select an arm part to be used in this model: ";
			cin >> choice;
			if (choice < 1 || choice > shop.get_available_arms().size())
				cerr << "Invalid choice. Please try again.\n\n";
			else
			{
				vector<Arm> shop_arms = shop.get_available_arms();
				arms.push_back(shop_arms[choice - 1]);
			}
		} while (choice < 1 || choice > shop.get_available_heads().size());

		cout << "Would you like to add another arm? [y/n] ";
		cin >> another_part;
		cin.ignore();

		if (another_part != 'y')
			break;
	}

	for (int i = 0; i < torso.get_battery_compartments(); i++)
	{
		do
		{
			view.display_batteries_list();
			cout << "Select a battery part to be used in this model: ";
			cin >> choice;
			if (choice < 1 || choice > shop.get_available_heads().size())
				cerr << "Invalid choice. Please try again.\n\n";
			else
			{
				vector<Battery> shop_batteries = shop.get_available_batteries();
				batteries.push_back(shop_batteries[choice - 1]);
			}
		} while (choice < 1 || choice > shop.get_available_heads().size());

		if ((i + 1) == torso.get_battery_compartments())
			break;
		else
		{
			cout << "Would you like to add another battery? [y/n] ";
			cin >> another_part;
			cin.ignore();
		}

		if (another_part != 'y')
			break;
	}

	double total_cost = head.get_cost() + torso.get_cost() + locomotor.get_cost();
	for (Arm a : arms)
		total_cost += a.get_cost();
	for (Battery b : batteries)
		total_cost += b.get_cost();

	cout << "The total cost of all the selected components is $" << total_cost << ".\n"
		<< "Enter in the price of the model: $";
	cin >> price;
	cin.ignore();

	Robot_Model model(name, model_num, price, head, torso, locomotor, &arms, batteries);
	
	cout << model.to_string()
		<< "Parts: \n"
		<< "Head: " << head.get_name() << " - Part #" << head.get_part_num() << "\n"
		<< "Torso: " << torso.get_name() << " - Part #" << torso.get_part_num() << "\n"
		<< "Locomotor: " << locomotor.get_name() << " - Part #" << locomotor.get_part_num() << "\n";
	for (int i = 0; i < arms.size(); i++)
		cout << "Arm " << i + 1 << ": " << arms[i].get_name() << " - Part #" << arms[i].get_part_num() << "\n";
	for (int i = 0; i < batteries.size(); i++)
		cout << "Battery " << i + 1 << ": " << batteries[i].get_name() << " - Part #" << batteries[i].get_part_num() << "\n";

	cout << "\nIs this correct? [y/n] ";
	cin >> correct;
	cin.ignore();

	if (correct != 'y')
		add_new_model();
	else
	{
		try
		{
			shop.add(model);
			cout << "\nRobot model successfully added.\n";
		}
		catch (Model_Num_Exists& e)
		{
			cerr << "ERROR: That model number already exists. Please try again.\n";
			add_new_model();
		}
	}
}

void Controller::list_all_models()
{

}

void Controller::order_robot_models()
{

}
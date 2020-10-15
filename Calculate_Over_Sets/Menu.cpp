#include "Menu.h"

void Menu::choice_menu()
{
	Menu menu_choice;
	bool can = false;
	std::cout << "\t\t\t�������� ��� �����������\n";
	do
	{
		try
		{
			
			std::cout << "\n�������� ������ ��������\n1.) �������� �������� � � B;\n2.) ����� ��������;\n3.) ���������;\n4.) �����������;\n5.) �����������;\n6.) ��������;\n7.) �������������� ��������;\n8.) �����.\n";
			getline(std::cin, choice);
			choice_ = stoi(choice);
			if (choice_ > 0 && choice_ <= 8)
			{
				switch (choice_)
				{
				case 1:
					menu_choice.create_sets();
					break;
				case 2:
					menu_choice.cout_sets();
					break;
				case 3:
					std::cin.ignore(0, '\n');
					menu_choice.negation();
					break;
				case 4:
					std::cin.ignore(0, '\n');
					menu_choice.intersection_sets();
					break;
				case 5:
					std::cin.ignore(0, '\n');
					menu_choice.uinion_sets();
					break;
				case 6:
					std::cin.ignore(0, '\n');
					menu_choice.difference_sets();
					break;
				case 7:
					std::cin.ignore(0, '\n');
					menu_choice.simetricDifference_sets();
					break;
				case 8:
					can = true;
					break;
				default:
					std::cout << "\n��� �������� ��� ������ ��������, ��������� ����...\n";
					break;
				}
			}
			else if (choice_ < -2147483648 || choice_ > 2147483647)
				throw std::exception("\n�������� �������� ��������, ��������� ����\n");
			else
				std::cout << "\n��������� �������� ������ ����������������, ���� ������ ��� �� �����\n��������� ����...\n";
		
		}
		catch (std::invalid_argument e)
		{
			std::cout << "\n����������� ����, ���������\n";
		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}

	} while (!can);


	return;
}

Menu::~Menu(){}

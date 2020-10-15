#include "Menu.h"

void Menu::choice_menu()
{
	std::cin.ignore();
	Menu menu_choice;
	bool can = false;
	std::cout << "\t�������� ��� �����������\n";
	do
	{
		try
		{
			std::cout << "\n�������� ������ ��������\n1.) ���������;\n2.) �����������;\n3.) �����������;\n4.) ��������;\n5.) �.��������;\n6.) �����.\n";
			getline(std::cin, choice);
			choice_ = stoi(choice);
			if (choice_ == 1)
			{
				menu_choice.negation();
				continue;
			}
			else if (choice_ == 2)
			{
				menu_choice.intersection_sets();
				continue;
			}
			else if (choice_ == 3)
			{
				menu_choice.uinion_sets();
				continue;
			}
			else if (choice_ == 4)
			{
				menu_choice.difference_sets();
				continue;
			}
			else if (choice_ == 5)
			{
				menu_choice.simetricDifference_sets();
				continue;
			}
			else if (choice_ == 6)
			{
				break;
			}
			else
				std::cout << "\n��� �������� ��� ������ �������� ��������� ����...\n";
		}
		catch (std::invalid_argument e)
		{
			std::cout << "\n����������� ����, ���������\n";
		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}

	} while (true);
}

Menu::~Menu()
{
}

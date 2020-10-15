#include "Menu.h"

void Menu::choice_menu()
{
	std::cin.ignore();
	Menu menu_choice;
	bool can = false;
	std::cout << "\tОПЕРАЦИИ НАД МНОЖЕСТВАМИ\n";
	do
	{
		try
		{
			std::cout << "\nВыберите индекс действия\n1.) Отрицание;\n2.) Пересечение;\n3.) Объединение;\n4.) Разность;\n5.) С.Разность;\n6.) Выход.\n";
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
				std::cout << "\nНет действий под данным индексом повторите ввод...\n";
		}
		catch (std::invalid_argument e)
		{
			std::cout << "\nНекоректный ввод, повторите\n";
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

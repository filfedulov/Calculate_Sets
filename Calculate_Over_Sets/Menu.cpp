#include "Menu.h"

void Menu::choice_menu()
{
	Menu menu_choice;
	bool can = false;
	std::cout << "\t\t\tОПЕРАЦИИ НАД МНОЖЕСТВАМИ\n";
	do
	{
		try
		{
			
			std::cout << "\nВыберите индекс действия\n1.) Создание множеств А и B;\n2.) Вывод множеств;\n3.) Отрицание;\n4.) Пересечение;\n5.) Объединение;\n6.) Разность;\n7.) Симметрическая Разность;\n8.) Выход.\n";
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
					std::cout << "\nНет действия под данным индексом, повторите ввод...\n";
					break;
				}
			}
			else if (choice_ < -2147483648 || choice_ > 2147483647)
				throw std::exception("\nПревышен диапазон значений, повторите ввод\n");
			else
				std::cout << "\nВведенное значение больше предусмотренного, либо меньше или не число\nповторите ввод...\n";
		
		}
		catch (std::invalid_argument e)
		{
			std::cout << "\nНекоректный ввод, повторите\n";
		}
		catch (std::exception e)
		{
			std::cout << e.what() << std::endl;
		}

	} while (!can);


	return;
}

Menu::~Menu(){}

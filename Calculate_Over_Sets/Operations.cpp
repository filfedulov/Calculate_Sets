#include "Operations.h"


void Operations::create_sets()
{
	universal_set.resize(Max);
	for (size_t i = 0; i < universal_set.size(); i++)
	{
		universal_set[i] = i;
	}
	
	std::string power = "",
		x;
	bool can = false;
	int power_ = 0,
		x_ = 0;
	
	do
	{
		try
		{
			std::cout << "Введите мощность множества А: ";
			getline(std::cin, power);
			power_ = stoi(power);
			if (power_ >= 0 && power_ <= 20)
			{
				a.resize(power_);
				std::cout << "\nЗаполните элементами множество А" << std::endl;
				for (size_t i = 0; i < a.size(); i++)
				{
					try
					{
						std::cout << i + 1 << "-й элемент: ";
						std::cin >> x;
						x_ = stoi(x);
						if (x_ >= 0 && x_ <= 20)
						{
							a[i] = x_;
						}
						else if (x_ < -2147483648 || x_ > 2147483647)
							throw std::exception("Превышен диапазон значений, повторите ввод");
						else
						{
							std::cout << "\nПревышенно предусмотренное значение, либо преуменьшенно\nповторите ввод...";
							i -= 1;
						}
					}
					catch (std::invalid_argument e)
					{
						std::cout << "\nНекоректный ввод, повторите\n";
						i -= 1;
					}
					catch (std::exception e)
					{
						std::cout << e.what() << std::endl;
						i -= 1;
					}
				}
				can = true;
			}
			else if (power_ < -2147483648 || power_ > 2147483647)
				throw std::exception("Превышен диапазон значений, повторите ввод");
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
	
	power = "",
		x;
	can = false;
	power_ = 0,
		x_ = 0;
	std::cin.ignore();
	
	do
	{
		try
		{
			std::cout << "Введите мощность множества B: ";
			getline(std::cin, power);
			power_ = stoi(power);
			if (power_ >= 0 && power_ <= 20)
			{
				b.resize(power_);
				std::cout << "\nЗаполните элементами множество B" << std::endl;
				for (size_t i = 0; i < b.size(); i++)
				{
					try
					{
						std::cout << i + 1 << "-й элемент: ";
						std::cin >> x;
						x_ = stoi(x);
						if (x_ >= 0 && x_ <= 20)
						{
							b[i] = x_;
						}
						else if (x_ < -2147483648 || x_ > 2147483647)
							throw std::exception("Превышен диапазон значений, повторите ввод");
						else
						{
							std::cout << "\nПревышенно предусмотренное значение, либо преуменьшенно\nповторите ввод...";
							i -= 1;
						}
					}
					catch (std::invalid_argument e)
					{
						std::cout << "\nНекоректный ввод, повторите\n";
						i -= 1;
					}
					catch (std::exception e)
					{
						std::cout << e.what() << std::endl;
						i -= 1;
					}
				}
				can = true;
			}
			else if (power_ < -2147483648 || power_ > 2147483647)
				throw std::exception("Превышен диапазон значений, повторите ввод");
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

void Operations::cout_sets()
{
	if (a.size() != 0 && b.size() != 0)
	{
		std::cout << "\nМножество А = { ";
		for (size_t i = 0; i < a.size(); i++)
		{
			if (i == a.size() - 1)
				std::cout << a[i] << " }\n";
			else
				std::cout << a[i] << ", ";
		}
		
		std::cout << "\nМножество B = { ";
		for (size_t i = 0; i < b.size(); i++)
		{
			if (i == b.size() - 1)
				std::cout << b[i] << " }\n";
			else
				std::cout << b[i] << ", ";
		}
	}

	return;
}

void Operations::negation()
{
	for_a = a;
	for_b = b;
	std::string choice = "";
	int choice_ = 0,
		for_result = 0;
	bool can = false;
	std::cin.ignore();
	result = universal_set;
	int del = 0;

	do
	{
		try
		{
			std::cout << "\nВыберите отрицания\n1.) " << char(172) << "A;\n2.) " << char(172) << "B;\n3.) Выход.\n";
			getline(std::cin, choice);
			choice_ = stoi(choice);
			if (choice_ == 1)
			{
				for (size_t i = 0; i < for_a.size(); i++)
				{
					for (size_t j = 0; j < universal_set.size(); j++)
					{
						if (for_a[i] == universal_set[j])
						{
							del = for_a[i];
							result.erase(std::remove(result.begin(), result.end(), del), result.end());
							break;
						}
					}
				}
				std::cout << char(172) << "A = { ";
				for (size_t i = 0; i < result.size(); i++)
				{
					if (i == result.size() - 1)
						std::cout << result[i] << " }";
					else
						std::cout << result[i] << ", ";
				}
			}
			else if (choice_ == 2)
			{
				for (size_t i = 0; i < for_b.size(); i++)
				{
					for (size_t j = 0; j < universal_set.size(); j++)
					{
						if (for_b[i] == universal_set[j])
						{
							del = for_b[i];
							result.erase(std::remove(result.begin(), result.end(), del), result.end());
							break;
						}
					}
				}
				if (result.size() == 0)
					std::cout << char(172) << "A  = 0.\n";
				else
				{
					std::cout << char(172) << "B = { ";
					for (size_t i = 0; i < result.size(); i++)
					{
						if (i == result.size() - 1)
							std::cout << result[i] << " }";
						else
							std::cout << result[i] << ", ";
					}
				}
				result.resize(0);
			}
			else if (choice_ == 3)
			{
				break;
			}
			else if (choice_ < -2147483648 || choice_ > 2147483647)
				throw std::exception("Превышен диапазон значений, повторите ввод");
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

void Operations::intersection_sets()
{
	result.resize(0);
	std::string choice = "";
	int choice_ = 0,
		for_result = 0,
		del = 0;
	bool can = false;
	std::cin.ignore();
	
	do
	{
		try
		{
			std::cout <<"\nВыберите индекс действия\n1.) A пересечение B;\n2.) Выход.\n";
			getline(std::cin, choice);
			choice_ = stoi(choice);
			if (choice_ == 1)
			{
				for (size_t i = 0; i < a.size(); i++)
				{
					for (size_t j = 0; j < b.size(); j++)
					{
						if (a[i] == b[j])
						{
							result.push_back(a[i]);
							break;
						}
					}
				}
				if (result.size() == 0)
					std::cout << "A перечечение B = 0.\n";
				else
				{
					std::cout << "A перечечение B = { ";
					for (size_t i = 0; i < result.size(); i++)
					{
						if (i == result.size() - 1)
							std::cout << result[i] << " }";
						else
							std::cout << result[i] << ", ";
					}
				}
			}
			else if (choice_ == 2)
				break;
			else if (choice_ < -2147483648 || choice_ > 2147483647)
				throw std::exception("Превышен диапазон значений, повторите ввод");
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

void Operations::uinion_sets()
{
	result.resize(0);
	std::string choice = "";
	int choice_ = 0,
		for_result = 0,
		del = 0;
	bool can = false;
	std::cin.ignore();

	do
	{
		try
		{
			std::cout << "\nВыберите индекс действия\n1.) A пересечение B;\n2.) Выход.\n";
			getline(std::cin, choice);
			choice_ = stoi(choice);
			if (choice_ == 1)
			{
				for (size_t i = 0; i < a.size(); i++)
				{
					result.push_back(a[i]);
				}
				for (size_t i = 0; i < b.size(); i++)
				{
					result.push_back(b[i]);
				}
				if (result.size() == 0)
					std::cout << "A объединение B = 0.\n";
				else
				{
					std::cout << "A объединение B = { ";
					for (size_t i = 0; i < result.size(); i++)
					{
						if (i == result.size() - 1)
							std::cout << result[i] << " }";
						else
							std::cout << result[i] << ", ";
					}
				}
			}
			else if (choice_ == 2)
				break;
			else if (choice_ < -2147483648 || choice_ > 2147483647)
				throw std::exception("Превышен диапазон значений, повторите ввод");
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

void Operations::difference_sets()
{
	for_a = a;
	for_b = b;
	std::string choice = "";
	int choice_ = 0,
		for_result = 0,
		del = 0;
	bool can = false;
	std::cin.ignore();

	do
	{
		try
		{
			std::cout << "\nВыберите зазность\n1.) A "<<char(92)<<" B;\n2.) B " << char(92) << " A;\n3.) Выход.\n";
			getline(std::cin, choice);
			choice_ = stoi(choice);
			if (choice_ == 1)
			{
				for (size_t i = 0; i < for_a.size(); i++)
				{
					for (size_t j = 0; j < for_b.size(); j++)
					{
						if (for_a[i] == for_b[j])
						{
							del = for_a[i];
							for_a.erase(std::remove(for_a.begin(), for_a.end(), del), for_a.end());
							break;
						}
					}
				}
				std::cout << "A " << char(92) << " B = { ";
				for (size_t i = 0; i < for_a.size(); i++)
				{
					if (i == for_a.size() - 1)
						std::cout << for_a[i] << " }";
					else
						std::cout << for_a[i] << ", ";
				}
			}
			else if (choice_ == 2)
			{
				for (size_t i = 0; i < for_b.size(); i++)
				{
					for (size_t j = 0; j < for_a.size(); j++)
					{
						if (for_b[i] == for_a[j])
						{
							del = for_b[i];
							for_b.erase(std::remove(for_b.begin(), for_b.end(), del), for_b.end());
							break;
						}
					}
				}
				std::cout << "B " << char(92) << " A = { ";
				for (size_t i = 0; i < for_b.size(); i++)
				{
					if (i == for_b.size() - 1)
						std::cout << for_b[i] << " }";
					else
						std::cout << for_b[i] << ", ";
				}
			}
			else if (choice_ == 3)
				break;
			else if (choice_ < -2147483648 || choice_ > 2147483647)
				throw std::exception("Превышен диапазон значений, повторите ввод");
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

void Operations::simetricDifference_sets()
{
	result.resize(0);
	std::string choice = "";
	int choice_ = 0,
		for_result = 0,
		del = 0;
	bool can = false,
		repeat = false;
	std::cin.ignore();

	do
	{
		try
		{
			std::cout << "\nВыберите зазность\n1.) A  С.Разность  B;\n2.) Выход.\n";
			getline(std::cin, choice);
			choice_ = stoi(choice);
			if (choice_ == 1)
			{
				for (size_t i = 0; i < a.size(); i++)
				{
					repeat = false;
					for (size_t j = 0; j < b.size(); j++)
					{
						if (a[i] == b[j])
						{
							repeat = true;
							break;
						}
					}
					if (!repeat)
					{
						result.push_back(a[i]);
					}
				}
				for (size_t i = 0; i < b.size(); i++)
				{
					repeat = false;
					for (size_t j = 0; j < a.size(); j++)
					{
						if (b[i] == a[j])
						{
							repeat = true;
							break;
						}
					}
					if (!repeat)
					{
						result.push_back(b[i]);
					}
				}
				if (result.size() == 0)
					std::cout << "A С.Разность B = 0.\n";
				else
				{
					std::cout << "A С.Разность B = { ";
					for (size_t i = 0; i < result.size(); i++)
					{
						if (i == result.size() - 1)
							std::cout << result[i] << " }";
						else
							std::cout << result[i] << ", ";
					}
				}
			}
			else if (choice_ == 2)
				break;
			else if (choice_ < -2147483648 || choice_ > 2147483647)
				throw std::exception("Превышен диапазон значений, повторите ввод");
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

Operations::~Operations(){}




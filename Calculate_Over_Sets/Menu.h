#pragma once
#include"Operations.h"


class Menu: public Operations
{
public:
	void choice_menu();
	~Menu();
private:
	std::string choice = "";
	int choice_ = 0;
};


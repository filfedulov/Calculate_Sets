#pragma once
#include<iostream>
#include<vector>
#include<string>


class Operations
{
public:
	void create_sets();
	void cout_sets();
	void negation();
	void intersection_sets();
	void uinion_sets();
	void difference_sets();
	void simetricDifference_sets();

	~Operations();
private:
	const size_t Max= 20;
	std::vector<int> universal_set,
		a,
		b,
		result;
};


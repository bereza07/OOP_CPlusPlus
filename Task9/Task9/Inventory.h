#pragma once
#include <vector>
#include <iostream>
class Inventory
{
private:
	std::vector <std::string> m_items;

public:
	Inventory();
	void addItem(const std::string& name);
	void removeItem(const std::string& name);
	void showItems() const;

	std::string getItems() const;
};


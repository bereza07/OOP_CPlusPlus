#pragma once
#include <memory>
#include <iostream>

class Inventory
{
private:
	std::unique_ptr<std::string[]> m_inventory;

	size_t m_capacity; // Inventory max size
	size_t m_size; // Number of items in inventory

public:
	Inventory(size_t initCap = 2);

	void AddItem(const std::string& item);


	void DisplayInventory();
};


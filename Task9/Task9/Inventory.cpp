#include "Inventory.h"
#include <iostream>

Inventory::Inventory()
{
}

void Inventory::addItem(const std::string& name)
{
	m_items.push_back(name);
}

void Inventory::removeItem(const std::string& name)
{
	auto exist = std::find(m_items.begin(), m_items.end(), name);
	if (exist != m_items.end()) {
		m_items.erase(exist);
	}
}

void Inventory::showItems() const
{
	std::cout << "Inventory: \n";
	for (const auto& item : m_items) {
		std::cout << "- " << item << "\n";
	}
}

std::string Inventory::getItems() const
{
	std::string items;
	for (size_t i = 0; i < m_items.size(); ++i) {
		items += m_items[i];
		if (i != m_items.size() - 1) {
			items += ","; 
		}
	}
	return items;
	
}



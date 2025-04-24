#include "Inventory.h"
#include <memory>
#include <iostream>

Inventory::Inventory(size_t initCap)
	:m_capacity(initCap),
	m_size(0),
	m_inventory(std::make_unique<std::string[]> (initCap))
{
}

void Inventory::AddItem(const std::string& item)
{
	if (m_size >= m_capacity) {
		size_t newCapacity = m_capacity * 2;
		auto newItems = std::make_unique<std::string[]>(newCapacity);

		for (size_t i = 0; i < m_size; i++) {
			newItems[i] = std::move(m_inventory[i]);
		}
		m_inventory = std::move(newItems);
		m_capacity = newCapacity;
	}

	m_inventory[m_size++] = item;
}

void Inventory::DisplayInventory()
{
	std::cout << "Inventory: \n";
	for (size_t i = 0; i < m_size; i++) {
		std::cout << "- " << m_inventory[i] << std::endl;
	}
}

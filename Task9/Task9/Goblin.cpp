#include "Goblin.h"
#include "Utilities.h"
Goblin::Goblin(std::string name, float hp, float att, float def, float height)
	:Monster(name, hp, att,def),
	m_height(height)
{
}

void Goblin::displayInfo() const
{
	printColor(m_name, ConsoleColor::Magenta);
	std::cout << "HP: " << m_hp << "\nATT: " << m_attack << "\nDEF: " << m_def
		<< "\nHeight: "<< m_height << "\n";
}

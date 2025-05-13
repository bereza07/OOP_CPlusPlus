#include "Dragon.h"
#include "Utilities.h"
Dragon::Dragon(std::string n, float hp, float a, float d, float fP)
	:Monster (n,hp,a,d),
	m_firePower(fP)
{
}

void Dragon::displayInfo() const
{
	printColor(m_name, ConsoleColor::Red);
	std::cout << "HP: " << m_hp << "\nATT: " << m_attack << "\nDEF: " << m_def
		<< "\nFirePower: " << m_firePower << "\n";
}

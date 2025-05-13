#include "Skeleton.h"
#include "Utilities.h"
Skeleton::Skeleton(std::string n, float hp, float a, float d, float dur)
	:Monster (n,hp,a,d),
	m_durability(dur)
{
}

void Skeleton::displayInfo() const
{
	printColor(m_name, ConsoleColor::Gray);
	std::cout <<"HP: " << m_hp << "\nATT: " << m_attack << "\nDEF: " << m_def
		<< "\nDurability: " << m_durability << "\n";
}

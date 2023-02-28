#include "House.h"
#include "functions.h"

void House::addInfoAboutHouse()
{
	do
	{
		std::cout << "House area (10 - 100)\n";
		m_square = myCin<decltype(m_square)>();
	} while (m_square < 10 || m_square > 100) ;
}

House::~House()
{
}

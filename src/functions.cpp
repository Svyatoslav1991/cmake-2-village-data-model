#include "functions.h"


//total area of all houses in the village
int64_t totalArea(const std::vector<Plot>& vPlots) noexcept
{
	int64_t total = 0;
	for (const auto& plot : vPlots)
	{
		for (const auto* house : plot.m_vHouses)
		{
			total += house->m_square;
		}
	}

	return total;
}

/////////////////////////////////////////////////////////////////////////////

//Display information about the village
void printInfoAboutVillage(const std::vector<Plot>& vPlots) noexcept
{
	std::cout << "\n\n";
	std::cout << "////////////////////////////////////////////////\n";

	float totalSquare = static_cast<float>(totalArea(vPlots));

	std::cout << "The total area of the village is " << totalSquare << "\n\n";

	for (const auto& plot : vPlots)
	{
		int64_t plotSquare = 0;

		for (const auto* house : plot.m_vHouses)
		{
			plotSquare += house->m_square;
		}

		std::cout << "Plot number " << plot.m_number << " occupies " << std::floor((static_cast<float>(plotSquare) / totalSquare) * 100) 
			<< " percent of the area of the village\n";
	}
}

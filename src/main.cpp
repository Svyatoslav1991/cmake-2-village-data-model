#include "functions.h"
#include "dwellinghouse.h"
#include "plot.h"

int main() {
	std::cout << "\tTask number 2\n";
	std::cout << "\tVillage data model\n\n";

	int64_t plots;

	do
	{
		std::cout << "Number of plots (>1)\n";
		plots = myCin<decltype(plots)>();
	} while (plots < 1);

	int64_t areaOfHouses = 0;

	std::vector<Plot> vPlots;
	vPlots.reserve(plots);

	for (int64_t i = 1; i < plots + 1; ++i)
	{
		Plot plot;
		plot.m_number = i;

		int64_t amountOfHouses;
		do
		{
			std::cout << "\nNumber of houses in plot number " << plot.m_number << "(1 - 4)\n";
			amountOfHouses = myCin<decltype(amountOfHouses)>();
		} while (amountOfHouses < 1 || amountOfHouses > 4);

		plot.m_vHouses.reserve(amountOfHouses);

		House* livingHouse = new DwellingHouse;
		livingHouse->addInfoAboutHouse();

		plot.m_vHouses.push_back(livingHouse);

		for (int64_t j = 0; j < amountOfHouses; ++j)
		{
			int64_t houseType;
			do
			{
				std::cout << "Choose house type:\n";
				std::cout << "1 - living\n";
				std::cout << "2 - garage\n";
				std::cout << "3 - barn\n";
				std::cout << "4 - bath\n";
				houseType = myCin<decltype(houseType)>();
			} while (houseType < 1 || houseType > 4);

			House* house = nullptr;
			if (houseType == 1)
			{
				house = new DwellingHouse;
			}
			else
			{
				house = new House;
			}

			house->m_type = static_cast<house_type>(houseType - 1);
			house->addInfoAboutHouse();

			plot.m_vHouses.push_back(house);
		}

		vPlots.push_back(plot);
	}

	printInfoAboutVillage(vPlots);

	for (auto& plot : vPlots)
	{
		for (auto* house : plot.m_vHouses)
		{
			delete house;
			house = nullptr;
		}

		plot.m_vHouses.clear();
	}


	return 0;
}
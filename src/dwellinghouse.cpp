#include "dwellinghouse.h"
#include "functions.h"

void DwellingHouse::addInfoAboutHouse()
{
	do
	{
		std::cout << "House area (32 - 100)\n";
		m_square = myCin<decltype(m_square)>();
	} while (m_square < 32 || m_square > 100);

	int64_t amountFloors;
	do
	{
		std::cout << "Number of floors (1 - 3)\n";
		amountFloors = myCin<decltype(amountFloors)>();
	} while (amountFloors < 1 || amountFloors > 3);

	m_vFloors.reserve(amountFloors);
	for (int64_t f = 0; f < amountFloors; ++f)
	{
		Floor floor;
		
		do
		{
			std::cout << "Ceiling height (2.0 - 4.0)\n";
			floor.m_height = myCin<decltype(floor.m_height)>();
		} while (floor.m_height < 2.f || floor.m_height > 4.f);

		int64_t amountRooms;
		do
		{
			std::cout << "Number of rooms in the floor " << f + 1 << " (2 - 4)\n";
			amountRooms = myCin<decltype(amountRooms)>();
		} while (amountRooms < 2 || amountRooms > 4);
		
		floor.m_vRooms.reserve(amountRooms);
		int64_t freeSquare = m_square;
		for (int64_t r = 0; r < amountRooms; ++r)
		{
			Room room;
			if (r != amountRooms - 1)
			{
				int64_t maxSquare = freeSquare - MINIMUM_SQUARE_ROOM * (amountRooms - r - 1);
				do
				{
					std::cout << "Room square (" << MINIMUM_SQUARE_ROOM << " - " 
						<< maxSquare << ")\n";
					room.m_square = myCin<decltype(room.m_square)>();
				} while (room.m_square < MINIMUM_SQUARE_ROOM || room.m_square > maxSquare);

				freeSquare -= room.m_square;
			}
			else
			{
				room.m_square = freeSquare;
			}

			int64_t roomType;
			do
			{
				std::cout << "Choose room number " << r + 1 << " type:\n";
				std::cout << "1 - living\n";
				std::cout << "2 - children\n";
				std::cout << "3 - kitchen\n";
				std::cout << "4 - bathroom\n";
				roomType = myCin<decltype(roomType)>();
			} while (roomType < 1 || roomType > 4);

			room.m_type = static_cast<room_type>(roomType - 1);


			floor.m_vRooms.push_back(room);
		}

		m_vFloors.push_back(floor);
	}

	int64_t isExistOven;
	do
	{
		std::cout << "Is there an oven in the house\n";
		std::cout << "1 - yes\n";
		std::cout << "0 - no\n";
		isExistOven = myCin<decltype(isExistOven)>();
	} while (isExistOven < 0 || isExistOven > 1);

	m_isExistOven = isExistOven;
}

DwellingHouse::~DwellingHouse()
{
}

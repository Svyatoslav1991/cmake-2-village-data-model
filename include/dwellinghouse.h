#pragma once
#ifndef DWELLINGHOUSE_H
#define DWELLINGHOUSE_H

#include "House.h"
#include "Floor.h"

struct DwellingHouse final : public House
{
	bool m_isExistOven = false;
	std::vector<Floor> m_vFloors;

	virtual void addInfoAboutHouse() override;
	~DwellingHouse();
};


#endif // DWELLINGHOUSE_H
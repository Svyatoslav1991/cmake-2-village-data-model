#pragma once
#ifndef PLOT_H
#define PLOT_H

#include <vector>
#include "House.h"

struct Plot
{
	int64_t m_number;
	std::vector<House*> m_vHouses;
};


#endif // PLOT_H
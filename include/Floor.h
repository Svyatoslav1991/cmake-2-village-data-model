#pragma once
#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include "room.h"

struct  Floor
{
	std::vector<Room> m_vRooms;
	float m_height;
};

#endif // FLOOR_H
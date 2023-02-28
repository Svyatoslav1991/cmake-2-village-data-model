#pragma once
#ifndef ROOM_H
#define ROOM_H

#include <iostream>

constexpr int64_t MINIMUM_SQUARE_ROOM = 8;

enum class room_type;
struct Room;

enum class room_type {
    living,
    children,
    kitchen,
    bathroom
};

struct Room
{
    room_type m_type;
    int64_t m_square;
};


#endif // ROOM_H
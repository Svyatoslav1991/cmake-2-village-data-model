#pragma once
#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>

enum class house_type;
struct House;

enum class house_type {
    living,
    garage,
    barn,
    bath
};

struct House
{
    house_type m_type;
    int64_t m_square;

    virtual void addInfoAboutHouse();

    virtual ~House();
};

#endif // HOUSE_H
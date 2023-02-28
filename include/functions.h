#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <vector>

#include "Plot.h"

//variable value input function
template <typename T>
T myCin() noexcept
{
    bool good = true;

    T variable;

    do
    {
        std::cout << "Enter the value of the variable: ";
        std::cin >> variable;

        good = std::cin.good();

        if (!good)
        {
            std::cout << "You entered something wrong\n";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!good);

    return variable;
}


//total area of all houses in the village
int64_t totalArea(const std::vector<Plot>& vPlots) noexcept;

//Display information about the village
void printInfoAboutVillage(const std::vector<Plot>& vPlots) noexcept;


#endif // FUNCTION_H

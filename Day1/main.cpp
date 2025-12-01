/*******************************************************************************************
*
*   raylib [core] example - delta time
*
*   Example complexity rating: [★☆☆☆] 1/4
*
*   Example originally created with raylib 5.5, last time updated with raylib 5.6-dev
*
*   Example contributed by Robin (@RobinsAviary) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2025 Robin (@RobinsAviary)
*
********************************************************************************************/
#include <fstream>
#include <string>
#include <iostream>
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{

 std::ifstream file("data.txt");
    if (!file) {
        std::cout << "Error: cannot open file\n";
        return 1;
    }
    
    int num{0};
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
        num++; 
    }   

    std::cout << num;
    return 0;
}
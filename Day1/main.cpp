/*******************************************************************************************
Day 1
********************************************************************************************/
#include <fstream>
#include <string>
#include <iostream>
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{

 std::ifstream file("data.txt");
    if (!file) {
        std::cout << "Error: cannot open file\n";
        return 1;
    }
    

    int dial{50};
    int num{0};
    std::string line;
    while (std::getline(file, line)) {
        // std::cout << line << "\n";
        // char letter = line[0];     
        // int number = std::stoi(line.substr(1));
        // number %= 100;  
        // if (letter == 'R') {
        //     dial = dial + number;
        // }else{
        //     dial = dial - number;
        // }
        
        // if (dial > 99) dial -= 100;
        // if (dial < 0)  dial += 100;

        // if(dial == 0){
        //   num++;   
        // }

        char letter = line[0];     
        int number = std::stoi(line.substr(1));

        int step = (letter == 'R') ? 1 : -1;

        for (int i = 0; i < number; i++) {
            dial += step;

            if (dial > 99) dial = 0;
            else if (dial < 0) dial = 99;

            if (dial == 0) {
                num++;
            }
        }
    
    
    }   

    std::cout << num;
    return 0;
}
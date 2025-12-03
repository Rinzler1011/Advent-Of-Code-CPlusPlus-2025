/*******************************************************************************************
Day 2
********************************************************************************************/
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------


bool isInvalidID(long long num) {
    if (num < 0) return false;     

    std::string s = std::to_string(num);
    std::size_t len = s.size();
    if (len < 2) return false;

    for (std::size_t p = 1; p <= len / 2; ++p) {
        if (len % p != 0) continue;  

        std::string pattern = s.substr(0, p);

        bool allMatch = true;
        for (std::size_t i = p; i < len; i += p) {
            if (s.compare(i, p, pattern) != 0) {
                allMatch = false;
                break;
            }
        }

        if (allMatch) {
            return true;
        }
    }

    return false;
}

int main()
{

 std::ifstream file("data.txt");
    if (!file) {
        std::cout << "Error: cannot open file\n";
        return 1;
    }
    
    std::string text;
    std::getline(file, text);   // read entire line

    std::stringstream ss(text);
    std::string token;

    // long long numTotal{0};
    // while (std::getline(ss, token, ',')) { // split by comma
    //     size_t dash = token.find('-');
    //     if (dash == std::string::npos) continue;

    //     long long a = std::stoll(token.substr(0, dash));
    //     long long b = std::stoll(token.substr(dash + 1));

    //     std::cout << "A = " << a << ", B = " << b << "\n";

    //     // Compute

    //     // long long length = b-a;

    //     for(long i=a; i <= b; i++){
    //         long long num = i;

    //         std::string s = std::to_string(num);
    //         std::size_t len = s.size();
    //         if (len < 2 || (len % 2) == 1) continue;

    //         long long mid = s.size() / 2;

    //         long long left  = std::stoll(s.substr(0, mid));
    //         long long right = std::stoll(s.substr(mid));


    //         if(left == right){
    //             numTotal += num;
    //             if(num == 101){
    //                 numTotal -= 101;
    //             }
    //         }

     
    //     } 
    // }

        // PART 2

    long long numTotal{0};
    while (std::getline(ss, token, ',')) { // split by comma
        size_t dash = token.find('-');
        if (dash == std::string::npos) continue;

        long long a = std::stoll(token.substr(0, dash));
        long long b = std::stoll(token.substr(dash + 1));

        std::cout << "A = " << a << ", B = " << b << "\n";

        // Compute

        // long long length = b-a;

        for (long long i = a; i <= b; ++i) {
        if (isInvalidID(i)) {
            numTotal += i;

            if (i == 101) {
                numTotal -= 101;
            }
        }
    }
    }




    std::cout << numTotal;
    
    return 0;
}
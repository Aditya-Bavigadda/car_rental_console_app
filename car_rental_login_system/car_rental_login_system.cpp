#include "access.h"
#include "cars.h"
#include <limits>
#include <fstream>
#include <ios>
#include <cctype>
#include <algorithm>

//bunch of avaliable ferrari cars

int main()
{
    while (true)
    {
        std::cout << "1. Login\n2. Register\n"; //gives options for choices
        std::string choice; //will recieve choice, would have made integer, but string provides for any input
        std::cout << "your choice: ";
        std::cin >> choice; //recieves choice
        std::vector<char> unnacceptable_words = { ' ', '_', '*', '&', '=', '\'', '-', '\'', '-','+',',', '<', '>', '.' };
        if (choice == "1")
        {
            login_process();
        }
        else if (choice == "2")
        {
            registration_process(unnacceptable_words);
        }
        else
        {
            std::cout << "\ninvalid statement\n";
        }

    }
} 

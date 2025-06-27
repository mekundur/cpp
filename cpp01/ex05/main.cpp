#include "Harl.hpp"
#include "stdio.h"

int main (void)
{
    Harl        idiot;
    std::string input;
    
    while (1) {
        std::cout << "Enter a level: ";
        if (!std::getline(std::cin, input)) { 
            std::cin.clear();
            clearerr(stdin);
            return 0;
        }
        if (!input.compare("DEBUG"))
            idiot.complain("DEBUG"); 
        else if (!input.compare("INFO"))
            idiot.complain("INFO"); 
        else if (!input.compare("WARNING"))
            idiot.complain("WARNING"); 
        else if (!input.compare("ERROR"))
            idiot.complain("ERROR"); 

    }
    return 0;
}
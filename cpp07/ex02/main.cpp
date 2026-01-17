#include "Array.hpp"
#include <exception>

int main(void) {
    try {
        Array<double> myArr1(5);
        Array<double> myArr2(10);

        for(unsigned int i = 0; i < myArr1.size(); i++)
            std::cout << myArr1[i] << " ";
        std::cout << std::endl;

        myArr2[0] = 5;
        myArr1 = myArr2;
        const Array<double> myArr3(myArr1);

        for(unsigned int i = 0; i < myArr1.size(); i++)
            std::cout << myArr1[i] << " ";
        std::cout << std::endl;

        for(unsigned int i = 0; i < myArr1.size(); i++)
            std::cout << myArr2[i] << " ";
        std::cout << std::endl;

        for(unsigned int i = 0; i < myArr1.size(); i++)
            std::cout << myArr3[i] << " ";
        std::cout << std::endl;
    }
    catch(std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
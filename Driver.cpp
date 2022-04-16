// 363Assignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Calculator.h"
#include <sstream>
#include <string>

int main()
{
    bool keepGoing = true;

    while (keepGoing)
    {
        std::cout << "Enter an expression with spaces for tokens, type QUIT to exit" << std::endl;
        std::string infix;
        std::getline(std::cin, infix);

        if (infix == "QUIT")
        {
            keepGoing= false;
        }

        Calculator calculator;

        calculator.parse_expression(infix);
        
        std::cout << calculator.evaluate();




    }
}

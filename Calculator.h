#ifndef _CS507_CALCULATOR_H_
#define _CS507__CALCULATOR_H_



#include "Expr_tree.h"
#include "Expr_tree_builder.h"
#include <iostream>
#include <string>
#include<sstream>


class Calculator
{
public:

    Calculator(void);

    void parse_expression(std::string expression);

   
    int evaluate(void);

 

    ~Calculator(void);

private:
    
    
    Expr_tree_builder builder_;
};

#endif

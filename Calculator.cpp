
#include "Calculator.h"


Calculator::Calculator(void)
    : builder_()
{
  
}



Calculator::~Calculator(void)

{

}



void Calculator::parse_expression(std::string expression)
{
  
    std::stringstream ss(expression);
    
    std::string token;

    //add another calculator because anything inside of ( ) is technically another expression and can be evaluated separately and then the result can be added to the tree
    Calculator calc2;

    int num;

    
    this->builder_.start_expression();

    
    while (!ss.eof())
    {
       
        ss >> token;

        
        if (token == "+")
        {
            this->builder_.build_addition_operator();
        }
        else if (token == "-")
        {
            this->builder_.build_subtraction_operator();
        }
        else if (token == "*")
        {
            this->builder_.build_multiplication_operator();
        }
        else if (token == "/")
        {
            this->builder_.build_division_operator();
        }
        else if (token == "%")
        {
            this->builder_.build_modulus_operator();
        }
        else if (token == "(")
        {

            std::getline(ss, token);
            try
            {
                //pass the new token to parse_expression if, then build the number that is the result of the expression inside of the ( )
                
                calc2.parse_expression(token);
                num = calc2.evaluate();

              
                this->builder_.build_number(num);
                
            }
            catch (const std::logic_error& e)
            {
               
                throw e;
            }
           
        }
        else if (token == ")")
        {
            break;
        }
        else
        {
            try
            {
                num = std::stoi(token);
            }
            catch (const std::logic_error& e)
            {
                throw e;
            }

            this->builder_.build_number(num);
        }
    }

   
}


int Calculator::evaluate(void)
{
    
    Expr_tree eval;
    try
    {
       
        this->builder_.return_root_node()->accept(eval);
    }
    catch (const std::logic_error& e)
    {
       
        throw e;
    }

    
    return eval.return_result();
}



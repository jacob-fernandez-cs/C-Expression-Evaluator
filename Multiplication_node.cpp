#include "Multiplication_node.h"

Multiplication_node::Multiplication_node(void)
    :Binary_op_node() //call parent constructor setting its children to nullptr
{

}

void Multiplication_node::accept(Expr_visitor& visitor)
{

    visitor.visit_multiplication_node(this);
}


int Multiplication_node::priority(void)
{
    return 2;
}




Multiplication_node::~Multiplication_node(void)
{

}
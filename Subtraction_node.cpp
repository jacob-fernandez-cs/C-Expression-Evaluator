#include "Subtraction_node.h"

Subtraction_node::Subtraction_node(void)
    :Binary_op_node() //call parent constructor setting its children to nullptr
{

}

void Subtraction_node::accept(Expr_visitor& visitor)
{

    visitor.visit_subtraction_node(this);
}


int Subtraction_node::priority(void)
{
    return 1;
}




Subtraction_node::~Subtraction_node(void)
{

}
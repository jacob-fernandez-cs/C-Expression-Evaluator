#include "Division_node.h"

Division_node::Division_node(void)
    :Binary_op_node() //call parent constructor setting its children to nullptr
{

}

void Division_node::accept(Expr_visitor& visitor)
{

    visitor.visit_division_node(this);
}


int Division_node::priority(void)
{
    return 2;
}




Division_node::~Division_node(void)
{

}
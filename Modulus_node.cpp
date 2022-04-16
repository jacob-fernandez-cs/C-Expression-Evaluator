#include "Modulus_node.h"

Modulus_node::Modulus_node(void)
    :Binary_op_node() //call parent constructor setting its children to nullptr
{

}

void Modulus_node::accept(Expr_visitor& visitor)
{

    visitor.visit_modulus_node(this);
}


int Modulus_node::priority(void)
{
    return 2;
}




Modulus_node::~Modulus_node(void)
{

}
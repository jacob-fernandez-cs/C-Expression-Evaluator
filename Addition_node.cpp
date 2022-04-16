#include "Addition_node.h"

Addition_node::Addition_node(void)
	:Binary_op_node() //call parent constructor setting its children to nullptr
{

}

void Addition_node::accept(Expr_visitor& visitor)
{
   
    visitor.visit_addition_node(this);
}


int Addition_node::priority(void)
{
    return 1;
}




Addition_node::~Addition_node(void)
{
    
}
#include "Number_node.h"

Number_node::Number_node(int num)
    :number_(num) //call parent constructor setting its children to nullptr
{

}

void Number_node::accept(Expr_visitor& visitor)
{

    visitor.visit_number_node(this);
}


int Number_node::priority(void)
{
    return 3;
}

int Number_node::return_number(void)
{
    return this->number_;
}


Number_node::~Number_node(void)
{

}

void Number_node::set_left(Expr_node* node)
{
	//do nothing number nodes do not have children
}

void Number_node::set_right(Expr_node* node)
{
	//do nothing number nodes do not have children
}



bool Number_node::does_left_child_exist(void)
{
	
	//number nodes cannot have children must return false
return false;
	

}

bool Number_node::does_right_child_exist(void)
{
	//number nodes cannot have children must return false
	return false;

}
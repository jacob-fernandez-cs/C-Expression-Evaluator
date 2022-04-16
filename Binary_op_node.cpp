#include "Binary_op_node.h"
#include <stdexcept>

Binary_op_node::Binary_op_node(void)
	:left_(nullptr), right_(nullptr) // set left and right children to null pointer to make sure that children are NOT equal to nullptr
{

}


Expr_node* Binary_op_node::return_left(void)
{
	//check for nullptr 
	if (this->left_ == nullptr)
	{
		throw std::logic_error("left child is equal to nullptr");
	}



	return this->left_;
}

Expr_node* Binary_op_node::return_right(void)
{
	//check for nullptr 
	if (this->right_ == nullptr)
	{
		throw std::logic_error("right child is equal to nullptr");
	}
	


	return this->right_;

}

void Binary_op_node::set_left(Expr_node* node)
{
	//set left child to passed node
	this->left_ = node;
}

void Binary_op_node::set_right(Expr_node* node)
{
	//set right child to passed node
	this->right_ = node;
}



bool Binary_op_node::does_left_child_exist(void)
{
	//if the left child is not equal to nullptr return true, if not return false
	if (this->left_ != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Binary_op_node::does_right_child_exist(void)
{
	//if the right child is not equal to nullptr return true, if not return false
	if (this->right_ != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}


Binary_op_node::~Binary_op_node(void)
{
	
	//delete children
	delete this->left_;
	delete this->right_;

}
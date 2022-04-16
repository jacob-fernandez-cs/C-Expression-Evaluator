#include "Expr_tree.h"
#include <stdexcept>


Expr_tree::Expr_tree(void)
    : result_(0), leftchild_(0), rightchild_(0)
{

}

int Expr_tree::return_result(void)
{
    return this->result_;
}

void Expr_tree::visit_number_node(Number_node* node)
{
    
    this->result_ = node->return_number();
}

void Expr_tree::visit_addition_node(Addition_node* node)
{
    

    //if left child exists visit left child which will set result to the value of the number node then set leftchild_ to result
    //if left child does not exist then set leftchild_ to 0
    if (node->does_left_child_exist())
    {
        node->return_left()->accept(*this);
        this->leftchild_ = this->result_;
    }
    else
    {
        this->leftchild_ = 0;
    }

    //if right child exists visit right child which will set result to the value of the number node then set rightchild_ to result
    //if right child does not exist then set rightchild_ to 0
    if (node->does_right_child_exist())
    {
        node->return_right()->accept(*this);
        this->rightchild_ = this->result_;
    }
    else
    {
        this->rightchild_ = 0;
    }

    // set result to the sum of leftchild_ and rightchild_ 
    this->result_ =  this->leftchild_ + this->rightchild_ ;
}


void Expr_tree::visit_subtraction_node(Subtraction_node* node)
{
    // see vist_addition_node() for logic comments 
    if (node->does_left_child_exist())
    {
        node->return_left()->accept(*this);
        this->leftchild_ = this->result_;
    }
    else
    {
        this->leftchild_ = 0;
    }

    // see vist_addition_node() for logic comments 
    if (node->does_right_child_exist())
    {
        node->return_right()->accept(*this);
        this->rightchild_ = this->result_;
    }
    else
    {
        this->rightchild_ = 0;
    }

    // set result to the difference of leftchild_ and rightchild_ 
    this->result_ = this->leftchild_ - this->rightchild_;
}


void Expr_tree::visit_multiplication_node(Multiplication_node* node)
{
    // see vist_addition_node() for logic comments 
    if (node->does_left_child_exist())
    {
        node->return_left()->accept(*this);
        this->leftchild_ = this->result_;
    }
    else
    {
        this->leftchild_ = 0;
    }

    // see vist_addition_node() for logic comments 
    if (node->does_right_child_exist())
    {
        node->return_right()->accept(*this);
        this->rightchild_ = this->result_;
    }
    else
    {
        this->rightchild_ = 0;
    }

    //set result to the product of leftchild_ and rightchild_ 
    this->result_ = this->leftchild_ * this->rightchild_;
}


void Expr_tree::visit_division_node(Division_node* node)
{
    // see vist_addition_node() for logic comments 
    if (node->does_left_child_exist())
    {
        node->return_left()->accept(*this);
        this->leftchild_ = this->result_;
    }
    else
    {
        this->leftchild_ = 0;
    }
    // see vist_addition_node() for logic comments 
    if (node->does_right_child_exist())
    {
        node->return_right()->accept(*this);
        this->rightchild_ = this->result_;
    }
    else
    {
        this->rightchild_ = 0;
    }

    // rightchild_ cannot be equal to zero because you cannot divide by zero, throw error if rightchild_ is 0
    if (this->rightchild_ == 0)
    {
        throw std::logic_error("Cannot divide by zero");
    }

    //set result to the quotient of leftchild_ and rightchild_, rightchild_ is also the divisor hence why it cannot be equal to 0
    this->result_ = this->leftchild_ / this->rightchild_;
}


void Expr_tree::visit_modulus_node(Modulus_node* node)

{
    // see vist_addition_node() for logic comments 
    if (node->does_left_child_exist())
    {
        node->return_left()->accept(*this);
        this->leftchild_ = this->result_;
    }
    else
    {
        this->leftchild_ = 0;
    }

    // see vist_addition_node() for logic comments 
    if (node->does_right_child_exist())
    {
        node->return_right()->accept(*this);
        this->rightchild_ = this->result_;
    }
    else
    {
        this->rightchild_ = 0;
    }

    // rightchild_ cannot be equal to zero because you cannot divide by zero, throw error if rightchild_ is 0
    if (this->rightchild_ == 0)
    {
        throw std::logic_error("Cannot divide by zero");
    }

    // set result to the remainder of leftchild_ and rightchild_
    this->result_ = this->leftchild_ % this->rightchild_;
}





Expr_tree::~Expr_tree(void)
{
   
}
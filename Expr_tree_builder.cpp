#include "Expr_tree_builder.h"
#include <stdexcept>


Expr_tree_builder::Expr_tree_builder(void)
    : rootNode_(nullptr)
{

}


Expr_tree_builder::~Expr_tree_builder(void)
{
    
    delete this->rootNode_;
}

Expr_node* Expr_tree_builder::return_root_node(void)
{
    
    return this->rootNode_;
}

void Expr_tree_builder::start_expression(void)
{
    //the tree must be completely empty when start_expression is called
    delete this->rootNode_;
    this->rootNode_ = nullptr;
}


void Expr_tree_builder::build_number(int n)
{
    // if there is not value for rootNode_ make the rootNode_ a new number node 
    //otherwise rootNode_ has a value, set cuurent_node equal to rootNode_
    if (this->rootNode_ == nullptr)
    {
        this->rootNode_ = new Number_node(n);
    }
    else
    {
        
        Expr_node * current_node = this->rootNode_;

        // while the current node right child exists set current_node equal to its right child
        while (current_node->does_right_child_exist())
        {
            current_node = current_node->return_right();
        }

        // if current_node is a number node throw error because number nodes cannot have children, otherwise set current_node to a new number node
        if (current_node->priority() == 3)
        {
            throw std::logic_error("Number nodes are not allowed to have children");
           
        }
        else
        {
            
            current_node->set_right(new Number_node(n));
        }

    }
}


void Expr_tree_builder::build_addition_operator(void)
{

    // if rootNode_ is empty set rootNode_ to a new addition node
    if (this->rootNode_ == nullptr)
    {
        this->rootNode_ = new Addition_node();
    }
    else
    {
        //otherwise create a new node with the value of Addition_node()
        Expr_node* addition_node = new Addition_node();

        //check if the rootNode_ priority is greater or equal to 1
        if (this->rootNode_->priority() >= 1)
        {
            //since true, addition_node and rootNode_ must be swapped
            addition_node->set_left(this->rootNode_);
            this->rootNode_ = addition_node;
        }
        else
        {
            // the rootNode_ will never have a priority() < 1 if it does throw error
            throw std::logic_error("Tree was built incorrectly");
        }
    }
}


void Expr_tree_builder::build_subtraction_operator(void)
{
    // if rootNode_ is empty set rootNode_ to a new Subtraction_node
    if (this->rootNode_ == nullptr)
    {
        this->rootNode_ = new Subtraction_node();
    }
    else
    {
        //otherwise create a new node with the value of Subtraction_node()
        Expr_node* subtraction_node = new Subtraction_node();

        //check if the rootNode_ priority is greater or equal to 1
        if (this->rootNode_->priority() >= 1)
        {
            //since true, subtraction_node and rootNode_ must be swapped
            subtraction_node->set_left(this->rootNode_);
            this->rootNode_ = subtraction_node;
        }
        else
        {
            // the rootNode_ will never have a priority() < 1 if it does throw error
            throw std::logic_error("Tree was built incorrectly");
        }
    }
}


void Expr_tree_builder::build_multiplication_operator(void)
{
    // if rootNode_ is empty set rootNode_ to a new Multiplication_node()
    if (this->rootNode_ == nullptr)
    {
        this->rootNode_ = new Multiplication_node();
    }
    else
    {
        //otherwise create a new node with the value of Multiplication_node()
        Expr_node* multiplication_node = new Multiplication_node();

        //check if the rootNode_ priority is greater or equal to 2
        if (this->rootNode_->priority() >= 2)
        {
            //since true, multiplication_node and rootNode_ must be swapped
            multiplication_node->set_left(this->rootNode_);
            this->rootNode_ = multiplication_node;
        }
        else
        {
            // if the root node priority is < 2 and the if the right child exists
            //then set the left child of the multiplication_node to the rootNode_'s right child and make multiplication_node the new right child
            if (this->rootNode_->does_right_child_exist())
            {
               
                multiplication_node->set_left(this->rootNode_->return_right());
                this->rootNode_->set_right(multiplication_node);
            }
            else
            {
                //right child does not exist thus set the rootNode_ right child equal to the multiplication_node
                this->rootNode_->set_right(multiplication_node);
            }
        }
    }
}


void Expr_tree_builder::build_division_operator(void)
{
    // if rootNode_ is empty set rootNode_ to a new division node
    if (this->rootNode_ == nullptr)
    {
        this->rootNode_ = new Division_node();
    }
    else
    {
        //otherwise create a new node with the value of division_node()
        Expr_node* division_node = new Division_node();

        //check if the rootNode_ priority is greater or equal to 2
        if (this->rootNode_->priority() >= 2)
        {
            //since true, division_node and rootNode_ must be swapped
            division_node->set_left(this->rootNode_);
            this->rootNode_ = division_node;
        }
        else
        {
            // if the root node priority is < 2 and the if the right child exists
            //then set the left child of the division_node to the rootNode_'s right child and make division_node the new right child
            if (this->rootNode_->does_right_child_exist())
            {

                division_node->set_left(this->rootNode_->return_right());
                this->rootNode_->set_right(division_node);
            }
            else
            {
                //right child does not exist thus set the rootNode_ right child equal to the division_node
                this->rootNode_->set_right(division_node);
            }
        }
    }
}


void Expr_tree_builder::build_modulus_operator(void)
{
    // if rootNode_ is empty set rootNode_ to a new Modulus_node()
    if (this->rootNode_ == nullptr)
    {
        this->rootNode_ = new Modulus_node();
    }
    else
    {
        //otherwise create a new node with the value of Modulus_node()
        Expr_node* modulus_node = new Modulus_node();

        //check if the rootNode_ priority is greater or equal to 2
        if (this->rootNode_->priority() >= 2)
        {
            //since true, addition_node and rootNode_ must be swapped
            modulus_node->set_left(this->rootNode_);
            this->rootNode_ = modulus_node;
        }
        else
        {
            // if the root node priority is < 2 and the if the right child exists
            //then set the left child of the modulus_node to the rootNode_'s right child and make modulus_node the new right child
            if (this->rootNode_->does_right_child_exist())
            {

                modulus_node->set_left(this->rootNode_->return_right());
                this->rootNode_->set_right(modulus_node);
            }
            else
            {
                //right child does not exist thus set the rootNode_ right child equal to the modulus_node
                this->rootNode_->set_right(modulus_node);
            }
        }
    }
}



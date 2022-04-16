#ifndef _CS507_EXPR_TREE_BUILDER_H_
#define _CS507_EXPR_TREE_BUILDER_H_

#include "Expr_builder.h"

#include "Addition_node.h"
#include "Subtraction_node.h"
#include "Multiplication_node.h"
#include "Division_node.h"
#include "Modulus_node.h"
#include "Number_node.h"

class Expr_tree_builder : public Expr_builder
{
public:
   
    Expr_tree_builder(void);

    void start_expression(void);
    void build_number(int n);
    void build_addition_operator(void);
    void build_subtraction_operator(void);
    void build_multiplication_operator(void);
    void build_division_operator(void);
    void build_modulus_operator(void);

    Expr_node* return_root_node(void);
    
    ~Expr_tree_builder(void);
private:

    /// Root node of the expression tree
    Expr_node* rootNode_;

   
};

#endif
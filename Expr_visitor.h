#ifndef _EXPR_VISITOR_H_
#define _EXPR_VISITOR_H_


#include "Addition_node.h"
#include "Subtraction_node.h"
#include "Multiplication_node.h"
#include "Division_node.h"
#include "Modulus_node.h"
#include "Number_node.h"

class Expr_visitor
{
public:
   
    Expr_visitor(void);

    virtual void visit_addition_node(Addition_node* node) = 0;

    virtual void visit_subtraction_node(Subtraction_node* node) = 0;

    virtual void visit_multiplication_node(Multiplication_node* node) = 0;

    virtual void visit_division_node(Division_node* node) = 0;

    virtual void visit_modulus_node(Modulus_node* node) = 0;

    virtual void visit_number_node(Number_node* node) = 0;
  
    virtual ~Expr_visitor(void) = 0;
};

#endif

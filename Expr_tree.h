#ifndef _CS507_EXPR_TREE_H_
#define _CS507_EXPR_TREE_H_

#include "Expr_visitor.h"

class Expr_tree : public Expr_visitor
{
public:
   
    Expr_tree(void); 
    
    int return_result(void);

    void visit_addition_node(Addition_node* node);

    void visit_subtraction_node(Subtraction_node* node);

    void visit_multiplication_node(Multiplication_node* node);

    void visit_division_node(Division_node* node);

    void visit_modulus_node(Modulus_node* node);

    void visit_number_node(Number_node* node);
 
   ~Expr_tree(void);

protected:
   //final result
    int result_;

  //placeholders for the left and right childrens values to perform operations on  
   int leftchild_;
   int rightchild_;

};
#endif

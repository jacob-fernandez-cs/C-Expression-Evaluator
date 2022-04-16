#ifndef _CS507_EXPR_NODE_H_
#define _CS507_EXPR_NODE_H_

#include "Expr_visitor.h"

class Expr_node
{
public:

    Expr_node(void);

    virtual void accept(Expr_visitor& visitor) = 0;
    
    virtual int priority(void) = 0;

    virtual ~Expr_node(void);

    //added to make builder logic simpler but number node does not use these functions look into a fix, a question might need to be asked 
    virtual bool does_left_child_exist(void);
    virtual bool does_right_child_exist(void);
    virtual void set_left(Expr_node* node);
    virtual void set_right(Expr_node* node);
    Expr_node* return_left(void);
    Expr_node* return_right(void);


};

#endif
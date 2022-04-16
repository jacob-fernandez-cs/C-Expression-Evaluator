#ifndef _CS507_BINARY_OP_NODE_H_
#define _CS507_BINARY_OP_NODE_H_

#include "Expr_node.h"

class Binary_op_node : public Expr_node
{
public:
	Binary_op_node(void);
	
	Expr_node* return_left(void);
	Expr_node* return_right(void);
	
	
	bool does_left_child_exist(void);
	bool does_right_child_exist(void);
	

	void set_left(Expr_node* node);
	void set_right(Expr_node* node);
	

protected:
	
	//these variables are the children of the binary operator, left and right respectively 
	Expr_node* left_;
	Expr_node* right_;

};
#endif
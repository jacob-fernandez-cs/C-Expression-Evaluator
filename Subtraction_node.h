#ifndef _CS507_SUBTRACTION_NODE_H_
#define _CS507_SUBTRACTION_NODE_H_

#include "Binary_op_node.h"

class Subtraction_node : public Binary_op_node {
public:
	Subtraction_node(void);

	void accept(Expr_visitor& visitor);

	int priority(void);

	~Subtraction_node(void);
};

#endif
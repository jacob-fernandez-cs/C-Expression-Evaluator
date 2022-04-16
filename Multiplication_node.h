#ifndef _CS507_MULTIPLICATION_NODE_H_
#define _CS507_MULTIPLICATION_NODE_H_

#include "Binary_op_node.h"

class Multiplication_node : public Binary_op_node {
public:
	Multiplication_node(void);

	void accept(Expr_visitor& visitor);

	int priority(void);

	~Multiplication_node(void);
};

#endif

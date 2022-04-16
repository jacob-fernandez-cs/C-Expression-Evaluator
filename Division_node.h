#ifndef _CS507_DIVISON_NODE_H_
#define _CS507_DIVISON_NODE_H_

#include "Binary_op_node.h"

class Division_node : public Binary_op_node {
public:
	Division_node(void);

	void accept(Expr_visitor& visitor);

	int priority(void);

	~Division_node(void);
};

#endif
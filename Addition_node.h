#ifndef _CS507_ADDITION_NODE_H_
#define _CS507_ADDITION_NODE_H_

#include "Binary_op_node.h"

class Addition_node : public Binary_op_node {
public:
	Addition_node(void);

	void accept(Expr_visitor& visitor);

	int priority(void);

	~Addition_node(void);
};

#endif
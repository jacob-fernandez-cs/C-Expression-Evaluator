#ifndef _CS507_MODULUS_NODE_H_
#define _CS507_MODULUS_NODE_H_

#include "Binary_op_node.h"

class Modulus_node : public Binary_op_node {
public:
	Modulus_node(void);

	void accept(Expr_visitor& visitor);

	int priority(void);

	~Modulus_node(void);
};

#endif

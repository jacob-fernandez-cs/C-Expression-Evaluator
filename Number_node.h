#ifndef _CS507_NUMBER_NODE_H_
#define _CS507_NUMBER_NODE_H_

#include "Expr_node.h"

class Number_node : public Expr_node {
public:
	Number_node(int num);

	void accept(Expr_visitor& visitor);

	int priority(void);

	int return_number(void);

	~Number_node(void);

	bool does_left_child_exist(void);
	bool does_right_child_exist(void);

	void set_left(Expr_node* node);
	void set_right(Expr_node* node);


protected:
	int number_;
};

#endif


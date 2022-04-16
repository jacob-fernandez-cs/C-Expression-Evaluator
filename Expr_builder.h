#ifndef _CS507_EXPR_BUILDER_H_
#define _CS507_EXPR_BUILDER_H_


class Expr_builder
{
public:
   
    Expr_builder(void);

    virtual void start_expression(void) = 0;

    virtual void build_addition_operator(void) = 0;

    virtual void build_subtraction_operator(void) = 0;

    virtual void build_multiplication_operator(void) = 0;

    virtual void build_division_operator(void) = 0;

    virtual void build_modulus_operator(void) = 0;

    virtual void build_number(int n) = 0;

    virtual ~Expr_builder(void) = 0;
};

#endif
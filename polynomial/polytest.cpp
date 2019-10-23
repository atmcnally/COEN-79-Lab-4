//  polytest.cpp
//  coen79lab
//
// Uma Bahl and Angelus McNally

#include <stdio.h>
#include "poly.h"
#include <iostream>

using namespace std;
using namespace coen79_lab4;


// tests poly methods

int main()
{
	polynomial pol;

	//void assign_coef(double coefficient, unsigned int exponent);
	pol.assign_coef(2, 2);
	cout << pol << endl;
	
	cout << pol(3);
	//void update_current_degree();
	
	/*
	void add_to_coef(double amount, unsigned int exponent);
	void clear();
	polynomial antiderivative() const;
	double coefficient(unsigned int exponent) const;
	double definite_integral(double x0, double x1) const;
	unsigned int degree() const;
	polynomial derivative() const;
	double eval(double x) const;
	bool is_zero() const;
	unsigned int next_term(unsigned int e) const;
	unsigned int previous_term(unsigned int e) const;

	double operator( ) (double x) const;

	friend polynomial operator +(const polynomial& p1, const polynomial& p2);
	friend polynomial operator -(const polynomial& p1, const polynomial& p2);
	friend polynomial operator *(const polynomial& p1, const polynomial& p2); */
}
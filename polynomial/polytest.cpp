//  polytest.cpp
//  coen79lab
//
// implemented by Angelus McNally, tested by Uma Bahl

#include <stdio.h>
#include "poly.h"
#include <iostream>

using namespace std;
using namespace coen79_lab4;


// tests poly methods

int main()
{
	polynomial pol;

	cout << "is zero: " << pol.is_zero() << endl;

	//unsigned int degree() const;
	cout << "degree: " << pol.degree() << endl;

	//void assign_coef(double coefficient, unsigned int exponent);
	pol.assign_coef(4, 0);
	pol.assign_coef(3, 1);
	pol.assign_coef(2, 2);
	pol.assign_coef(1, 3);
	cout << "assignment: " << pol.getCoef(2) << endl;

	cout << "is zero: " << pol.is_zero() << endl;

	pol.update_current_degree();
	
	cout << "degree: " << pol.degree() << endl;

	//void add_to_coef(double amount, unsigned int exponent);
	pol.add_to_coef(3, 2);
	cout << "adding: " << pol.getCoef(2) << endl;

	pol.add_to_coef(-3, 2);
	cout << "revert coef: " << pol.getCoef(2) << endl;

	//double coefficient(unsigned int exponent) const;
	cout << "print coef: " << pol.coefficient(2) << endl;

	//unsigned int next_term(unsigned int e) const;
	cout << "next term: " << pol.next_term(2) << endl;

	//unsigned int previous_term(unsigned int e) const;
	cout << "prev term: " << pol.previous_term(2) << endl;

	//polynomial antiderivative() const;
	cout << "anti: " << pol.antiderivative() << endl;

	//polynomial derivative() const;
	cout << "deriv: " << pol.derivative() << endl;

	//double definite_integral(double x0, double x1) const;
	cout << "def integ: " << pol.definite_integral(0, 1) << endl;

	//double eval(double x) const;
	cout << "eval: " << pol.eval(2) << endl;

	//double operator( ) (double x) const;
	cout << "eval2: " << pol(2) << endl;

	cout << "print: " << pol << endl;

	polynomial second;
	second.assign_coef(1, 1);
	second.assign_coef(-1, 2);
	second.assign_coef(1, 3);

	//friend polynomial operator +(const polynomial& p1, const polynomial& p2);
	cout << "add: " << pol + second << endl;
	//friend polynomial operator -(const polynomial& p1, const polynomial& p2);
	cout << "sub: " << pol - second << endl;
	//friend polynomial operator *(const polynomial& p1, const polynomial& p2);
	cout << "mult: " << pol * second << endl;

	//void clear();
	pol.clear();
	cout << "cleared; is zero: " << pol.is_zero() << endl;
}
// FILE: poly.h
//Angelus McNally and Uma Bahl
//COEN 79
//Lab 4

#ifndef COEN79_POLY_H
#define COEN79_POLY_H
#include <cassert>
#include <ostream>

using namespace std;

namespace coen79_lab4
{
    class polynomial
    {

    public:

    	static const unsigned int MAXIMUM_DEGREE = 29;
		//exponent is unsigned, so no negative exponents

		void update_current_degree();
		polynomial(double c = 0.0, unsigned int exponent = 0);
		void assign_coef(double coefficient, unsigned int exponent);
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
		double getCoef(int loc) const;

		//i was getting weird errors with these outside of the class, so i declared them as friends

		// NON-MEMBER BINARY OPERATORS
		friend polynomial operator +(const polynomial& p1, const polynomial& p2);
		friend polynomial operator -(const polynomial& p1, const polynomial& p2);
		friend polynomial operator *(const polynomial& p1, const polynomial& p2);

	private:
		double coef[MAXIMUM_DEGREE + 1] = {};
		unsigned int current_degree;

    };

	// NON-MEMBER OUTPUT FUNCTIONS
	std::ostream& operator << (std::ostream& out, const polynomial& p);

	//determine sign preconditions: out is properly initalized as an ostream object and its value will return to the method this is called from, co is no bigger than a double
	//post conditions: sign (+ or -) is printed to the ostream as necessary, as well as co in most cases
	void determineSign(ostream& out, double co);

}
#endif

#include <iostream>  // Provides ostream
#include <cassert>
#include <climits>
#include <cmath>
#include "poly.h"

using namespace std;

namespace coen79_lab4
{

	//A polynomial has one variable x, real number coefficients, and non-negative integer exponents. 
	//Such a polynomial can be viewed as having the form:
	//	A[n]*x^n + A[n-1]*x^(n-1) + ... A[2]*x^2 + A[1]*x + A[0]
	//where the A[n] are the real number coefficients and x^i represents the variable x raised to the i power. 
	//The coefficient A[0] is called the "constant" or "zeroth" term of the polynomial.

		polynomial::polynomial(double c = 0.0, unsigned int exponent = 0) {
			assert(exponent <= MAXIMUM_DEGREE);
			unsigned int current_degree = 0;
		}
		//POSTCONDITION: This polynomial has been created with all zero coefficients, except for coefficient c for the specified exponent.
		//When used as a default constructor (using default values for both arguments), the result is a polynomial with all zero coefficients.

		void polynomial::update_current_degree() {

			for (int i = 1; i <= MAXIMUM_DEGREE; i++) {
				if (coef[i] != 0) {
					current_degree = i;
				}
			}
		}
		//POSTCONDITION: The current degree is set to the highest exponent with a non-zero coeficient.

		void polynomial::assign_coef(double coefficient, unsigned int exponent) {
			assert(exponent <= MAXIMUM_DEGREE);
			coef[exponent] = coefficient;

		}
		//POSTCONDITION: Sets the coefficient for the specified exponent.

		void polynomial::add_to_coef(double amount, unsigned int exponent) {
			assert(exponent <= MAXIMUM_DEGREE);
			coef[exponent] += amount;
			
		}
		//POSTCONDITION: Adds the given amount to the coefficient of the specified exponent.

		void polynomial::clear() {
			for (int i = 0; i < current_degree; i++) {
				coef[i] = 0;
			}
		}
		//POSTCONDITION: All coefficients of this polynomial are set to zero.

		polynomial polynomial::antiderivative() const {
			assert(degree() < MAXIMUM_DEGREE);
			polynomial result;

			for (int i = 0; i <= degree(); i++) {
				result.coef[i + 1] = coef[i] / (i + 1);
			}

			return result;
		}
		//POSTCONDITION: The return value is the antiderivative (indefinite integral) of this polynomial.
		//NOTE: The return polynomial always has a constant term of zero.

		double polynomial::coefficient(unsigned int exponent) const {
			if (exponent > MAXIMUM_DEGREE) {
				return 0;
			}
			else {
				return coef[exponent];
			}
		}
		//POSTCONDITION: Returns coefficient at specified exponent of this polynomial.
		//NOTE: For exponents > MAXIMUM_DEGREE, the return value is always zero.

		double polynomial::definite_integral(double x0, double x1) const {
			//-3x^2 + 4x + 1 becomes
			//-x^3 + 2x^2 + x
			polynomial result = antiderivative();

			/*
			for (int i = 0; i <= degree(); i++) {
				result.coef[i + 1] = coef[i] / (i + 1);
			} */

			double fin = result.eval(x1) - result.eval(x0);

			return fin;
		}
		//POSTCONDITION: Returns the value of the definite integral computed from x0 to x1.  The answer is computed analytically.

		unsigned int polynomial::degree() const {
			return current_degree;
		}
		//POSTCONDITION: The function returns the value of the largest exponent with a non-zero coefficient.
		//If all coefficients are zero, then the function returns zero (even though, technically, this polynomial does not have a degree).

		polynomial polynomial::derivative() const {
			polynomial deriv;

			for (int i = 1; i <= degree(); i++) {
				deriv.coef[i - 1] = coef[i] * i;
			}

			deriv.update_current_degree();

			return deriv;
		}
		//POSTCONDITION: The return value is the first derivative of this polynomial.

		double polynomial::eval(double x) const {
			double sum = 0;
			for (int i = 0; i <= degree(); i++) {
				sum += coef[i] * pow(x, i);
			}

			return sum;
		}
		//POSTCONDITION: The return value is the value of this polynomial with the given value for the variable x.

		bool polynomial::is_zero() const {
			if (degree() == 0) {
				return true;
			}

			return false;
		}
		//POSTCONDITION: The return value is true if and only if the polynomial is the zero polynomial.

		unsigned int polynomial::next_term(unsigned int e) const {
			int i = e + 1;
			while (i < degree()) {
				if (coef[i] != 0) {
					return i;
				}
				i++;
			}

			return 0;
		}
		//POSTCONDITION: The return value is the next exponent n which is LARGER than e such that coefficient(n) != 0.
		//If there is no such term, then the return value is zero.

		unsigned int polynomial::previous_term(unsigned int e) const {
			int i = e - 1;
			while (i > 0) {
				if (coef[i] != 0) {
					return i;
				}
				i--;
			}

			return UINT_MAX;
		}
		//POSTCONDITION: The return value is the next exponent n which is SMALLER than e such that coefficient(n) != 0.
		//If there is no such term, then the return value is UINT_MAX from <climits>.

		double polynomial::operator( ) (double x) const {
			//look at how i did this in lab 3
			return eval(x);
		}
		//Same as the eval member function.
		//POSTCONDITION: The return value is the value of this polynomial with the given value for the variable x.

	polynomial operator +(const polynomial& p1, const polynomial& p2) {
		int upper = 0;

		//figure out what the upperbound of the for loop should be
		//there's a faster way to do this but i don't know what it is
		if (p1.degree() > p2.degree()) {
			upper = p1.degree();
		}
		else {
			upper = p2.degree();
		}

		polynomial result;

		for (int i = 0; i <= upper; i++) {
			result.coef[i] = p1.coef[i] + p2.coef[i];
		}

		result.update_current_degree();
		return result;
		
	}
	//POSTCONDITION: return-value is a polynomial with each coefficient equal to the sum of the coefficients of p1 & p2 for any given exponent.

	polynomial operator -(const polynomial& p1, const polynomial& p2) {
		int upper = 0;

		if (p1.degree() > p2.degree()) {
			upper = p1.degree();
		}
		else {
			upper = p2.degree();
		}

		polynomial result;

		for (int i = 0; i <= upper; i++) {
			result.coef[i] = p1.coef[i] - p2.coef[i];
		}

		result.update_current_degree();
		return result;
	}
	//POSTCONDITION: return-value is a polynomial with each coefficient equal to the difference of the coefficients of p1 & p2 for any given exponent.

	polynomial operator *(const polynomial& p1, const polynomial& p2) {
		assert(p1.degree() + p2.degree() <= polynomial::MAXIMUM_DEGREE);

		polynomial result;
		int spot;

		for (int i = 0; i <= p1.degree(); i++) {
			for (int j = 0; j <= p2.degree(); j++) {
				spot = i + j;
				result.coef[spot] += p1.coef[i] * p2.coef[j];
			}
		}

		result.update_current_degree();
		return result;
	}
	//POSTCONDITION: Each term of p1 has been multiplied by each term of p2, and the answer is the sum of all these term-by-term products.
	//For example, if p1 is 2x^2 + 3x + 4
	//				  p2 is 5x^2 - 1x + 7, then the return value is 
	//	  10x^4 + 13x^3 + 31x^2 + 17x + 28.


	// NON-MEMBER OUTPUT FUNCTIONS
	std::ostream& operator << (std::ostream& out, const polynomial& p) {
		
		for (int i = p.degree(); i >= 0; i--) {
			if (p.coef[i] != 0) {
				if (i != 1 || i != 0) {
					if (p.coef[i] > 0) {
						//if positive, print with +
						cout << " + " << abs(p.coef[i]) << "x";
					}
					else {
						// if negative, print with -
						cout << " - " << abs(p.coef[i]) << "x";
					}
					cout << p.coef[i] << "x^" << i;
				}
				else if (i == 1) {
					cout << p.coef[i] << "x";
				}
				else if(i == 0) {
					cout << p.coef[i];
				}
				else if (i == p.degree()) {
					cout << p.coef[i] << "x^" << i;
				}
				
			}
		}

		cout << endl;

	}
	//POSTCONDITION: The polynomial has been printed to ostream out, which, in turn, has been returned to the calling function.
	//The format of the polynomial when printed should be as follows:
	//     -2.5x^2 - 4x + 5.9
	//1) There should be exactly 1 space between the numbers and the operators.
	//2) The constant coeficient should be printed by itself: 5.3, not 5.3x^0
	//3) The first coeficient chould be followed by a plain x: 4x, not 4x^1
	//4) The highest degree's coeficient should have a sign: -2.5x^2, but the following values 
	//should all be separated by appropriate operators and then printed unsigned: -2.5x^2 - 4x...
	//5) If you manipulate any settings of the outstream inside of this, such as the precision, 
	//they should be restored to what they were at the start of the function before returning.
}
/*
 * COMPLEXoverload.cpp
 * operator overload example
 * CSCI325
 *
 * Created on: Dec 8, 2020
 * Due: Dec 16, 2020
 *     Author: Mkrtschjan
 */


#include <iostream>
using namespace std;

class A {
	private:
		int	a;	// represent real part
		int b;	// represent image part of a complex number

	public:
		A() { a = b = 0; }
		A(int a, int b) { this->a = a; this->b = b; }

		void print() {
			// to account for positive b image part
			if (b > 0) {
				 cout << a << " + " << b << "i" << endl;
			}
			else {
				// to adjust alignment and account for negative b image part
				b = -b;
				cout << a << " - "<< b << "i" << endl;
			}
		}

		// overload+ to add two complex objects
		A operator+(const A &other);

		// overload- to subtract two complex objects
		A operator-(const A &other);

		// overload* to multiply two complex objects
		A operator*(const A &other);


		// overload+ to add one complex object with an integer
		A operator+(int x);

		// overload- to subtract one complex object with an integer
		A operator-(int x);

		// overload* to multiply one complex object with an integer
		A operator*(int x);


		// friend overload+ to add one integer to a complex object
		friend A operator+(int x, const A &other);

		// friend overload+ to subtract a complex object from an integer
		friend A operator-(int x, const A &other);

		// friend overload* to multiply a complex object with an integer
		friend A operator*(int x, const A &other);
};

// for equation: a1+b1(i) + a2+b2(i)
A A::operator+(const A &other) {
	A temp;
	temp.a = this->a + other.a;
	temp.b = this->b + other.b;
	return temp;
}

// for equation: (a1+b1(i)) - (2+b2(i))
A A::operator-(const A &other) {
	A temp;
	temp.a = this->a - other.a;
	temp.b = this->b - other.b;
	return temp;
}

// for equation: (a1+b1(i)) * (2+b2(i))
A A::operator*(const A &other) {
	A temp;
	temp.a = this->a * other.a;
	temp.a = temp.a - (this->b * other.b);
	temp.b = (this->a * other.b) + (this->b * other.a);
	return temp;
}

// for equation: a1+b1(i) + a2
A A::operator+(int x) {
	A temp;
	temp.a = this->a + x;
	temp.b = this->b;
	return temp;
}

// for equation: a1+b1(i) - a2
A A::operator-(int x) {
	A temp;
	temp.a = this->a - x;
	temp.b = this->b;
	return temp;
}

// for equation: (a1+b1(i)) * a2
A A::operator*(int x) {
	A temp;
	temp.a = this->a * x;
	temp.b = this->b * x;
	return temp;
}

// for equation: a2 + a1+b1(i)
A operator+(int x, const A &other) {
	A temp;
	temp.a = x + other.a;
	temp.b = other.b;
	return temp;
}

// for equation: a2 - a1+b1(i)
A operator-(int x, const A &other) {
	A temp;
	temp.a = x - other.a;
	temp.b = -other.b;
	return temp;
}

// for equation: a2 * (a1+b1(i))
A operator*(int x, const A &other) {
	A temp;
	temp.a = x * other.a;
	temp.b = x * other.b;
	return temp;
}


int main() {
	// initializing different variables for test cases
	int m = 0;
	int n = 1;
	int o = 2;
	int p = 3;
	int q = 4;
	int r = 5;
	int s = 6;
	int u = 7;
	int v = 8;
	int w = 9;

	cout <<"Using operator+ to compute (a1+b1i) + (a2+b2i)\n";
	cout << "(" << o << "+" << p <<"i) + (" << p << "+" << r << "i) = ";

	// creating complex number objects
	A a1(o, p);
	A a2(p, r);
	A a3(q, u);
	A a4(w, r);
	A a5(s, v);
	A a6(n, m);

	A t = a1 + a2;
	A t1 = a3 + a4;
	A t2 = a5 + a6;
	A t3 = a3 + a1;

	t.print();

	cout << "(" << q << "+" << u <<"i) + (" << w << "+" << r << "i) = ";
	t1.print();

	cout << "(" << s << "+" << v <<"i) + (" << n << "+" << m << "i) = ";
	t2.print();

	cout << "(" << q << "+" << u <<"i) + (" << o << "+" << p << "i) = ";
	t3.print();

	cout<<"\nUsing operator- to compute (a1+b1i) - (a2+b2i)\n";
	cout << "(" << o << "+" << p <<"i) - (" << p << "+" << r << "i) = ";

	A t4 = a1 - a2;
	t4.print();

	cout << "(" << q << "+" << u <<"i) - (" << w << "+" << r << "i) = ";
	A t5 = a3 - a4;
	t5.print();

	cout << "(" << s << "+" << v <<"i) - (" << n << "+" << m << "i) = ";
	A t6 = a5 - a6;
	t6.print();

	cout << "(" << q << "+" << u <<"i) - (" << o << "+" << p << "i) = ";
	A t7 = a3 - a1;
	t7.print();

	cout<<"\nUsing operator* to compute (a1+b1i) * (a2+b2i)\n";
	cout << "(" << o << "+" << p <<"i) * (" << p << "+" << r << "i) = ";

	A t8 = a1 * a2;
	t8.print();

	cout << "(" << q << "+" << u <<"i) * (" << w << "+" << r << "i) = ";

	A t9 = a3 * a4;
	t9.print();

	cout << "(" << s << "+" << v <<"i) * (" << n << "+" << m << "i) = ";
	A t10 = a5 * a6;
	t10.print();

	cout << "(" << q << "+" << u <<"i) * (" << o << "+" << p << "i) = ";
	A t11 = a3 * a1;
	t11.print();

	cout <<"\nUsing operator+ to compute (a1+b1i) + integer\n";
	cout << "(" << o << "+" << p <<"i) + " << s << " = ";
	A t12 = a1 + s;
	t12.print();


	cout<<"\nUsing operator+ to compute (a1+b1i) + (a2+b2i)\n";
	cout << "(" << o << "+" << p <<"i) + (" << p << "+" << r << "i) = ";
	A t13 = a1 + a2;
	t13.print();

	cout<<"\nUsing operator+ to compute (a2+b2i) + integer\n";
	cout << "(" << p << "+" << r <<"i) + "<< s << " = ";
	A t14 = a2 + s;
	t14.print();

	cout <<"\nUsing operator+ to compute integer + (a1+b1i)\n";
	cout << s << " + (" << o << "+" << p <<"i) = ";

	A t15 = s + a1;
	t15.print();

	cout <<"\nUsing operator- to compute (a1+b1i) - integer\n";
	cout << "(" << o << "+" << p <<"i) - " << s << " = ";
	A t16 = a1 - s;
	t16.print();


	cout<<"\nUsing operator- to compute (a1+b1i) - (a2+b2i)\n";
	cout << "(" << o << "+" << p <<"i) - (" << p << "+" << r << "i) = ";
	A t17 = a1 - a2;
	t17.print();

	cout<<"\nUsing operator- to compute (a2+b2i) - integer\n";
	cout << "(" << p << "+" << r <<"i) - "<< s << " = ";
	A t18 = a2 - s;
	t18.print();

	cout <<"\nUsing operator- to compute integer - (a1+b1i)\n";
	cout << s << " - (" << o << "+" << p <<"i) = ";

	A t19 = s - a1;
	t19.print();

	cout <<"\nUsing operator* to compute (a1+b1i) * integer\n";
	cout << "(" << o << "+" << p <<"i) * " << s << " = ";
	A t20 = a1 * s;
	t20.print();


	cout<<"\nUsing operator* to compute (a1+b1i) * (a2+b2i)\n";
	cout << "(" << o << "+" << p <<"i) * (" << p << "+" << r << "i) = ";
	A t21 = a1 * a2;
	t21.print();

	cout<<"\nUsing operator* to compute (a2+b2i) * integer\n";
	cout << "(" << p << "+" << r <<"i) * "<< s << " = ";
	A t22 = a2 * s;
	t22.print();

	cout <<"\nUsing operator* to compute integer * (a1+b1i)\n";
	cout << s << " * (" << o << "+" << p <<"i) = ";

	A t23 = s * a1;
	t23.print();


	return 0;
}



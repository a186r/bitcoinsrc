#include "boost\bind.hpp"
#include <iostream>
#include <vector>
using namespace std;

int f(int a, int b) {
	return a + b;
}

int g(int a, int b, int c) {
	return a + b + c;
}

struct P
{
	int x, y;
	P(int a=9,int b=9):x(a),y(b){}

	void print() {
		cout << "x:" << x << "y:" << y << endl;
	}
};

int main() {
	int x = 1, y = 2, z = 3;
	cout << boost::bind(f, x, y)() << endl;
	cout << boost::bind(g, _1, _2, _3)(x, y, z) << endl;
	cout << boost::bind(g, x, _2, x)(x, y, z) << endl;

	vector<P> v(10);
	for_each(v.begin(),v.end(),boost::bind(&P::print,_1));
	return 0;
}
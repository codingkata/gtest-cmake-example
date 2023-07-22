#include <iostream>
#include "myfoo.h"

using namespace std;

int main() {
	cout << "do stuff" << endl;
	int x = 4;
	cout << x << endl;
	independentMethod(x);
	cout << x << endl;
	MyFoo p;
	p.foo(x);
	cout << x << endl;
}
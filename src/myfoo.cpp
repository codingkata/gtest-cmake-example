#include "myfoo.h"

void MyFoo::foo(int &i) {
	i = 1;
}


void independentMethod(int &i) {
	i = 0;
}
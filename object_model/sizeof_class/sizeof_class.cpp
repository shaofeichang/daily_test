#include "class_type.h"
#include "test_union_size.h"
#include <iostream>
using namespace std;

int main()
{
	cout << sizeof(union_size) << endl;
	cout << "sizeof(A): " << sizeof(class_A) << endl;
	cout << "sizeof(B): " << sizeof(class_B) << endl;
	cout << "sizeof(C): " << sizeof(class_C) << endl;
	cout << "sizeof(D): " << sizeof(class_D) << endl;
	cout << "sizeof(E): " << sizeof(class_E) << endl;
	cout << "sizeof(class_derived_E): " << sizeof(class_derived_E) << endl;

	system("pause");
	return 0;
}
using namespace std;

#include <iostream>
#include "Gradebook.h"

void quadraticSolver(int a, int b, int c, double& xIntercept1, double& xIntercept2) {
	if (a == 0) {
		throw logic_error("That's not a quadratic function");
	}
	
	double determinant = b * b - 4 * a * c;

	if (determinant < 0) {
		throw logic_error("No x intercepts exist");
	}

	xIntercept1 = (-b + sqrt(determinant)) / (2 * a);
	xIntercept2 = (-b - sqrt(determinant)) / (2 * a);

}

int main()
{
	Gradebook cis200GradeBook("CIS 200", 35);

	Student bob = cis200GradeBook.getStudent(0);
	bob.setName("Bob");
	bob.setId(123);
	
	Gradebook cis200bGradeBook("CIS 200b", 50);
	cis200bGradeBook = cis200GradeBook;

	Gradebook anotherGradeBook(cis200bGradeBook);


	for (int classIndex = 0; classIndex < 1000; classIndex++) {
		Gradebook* gradebook = new Gradebook("some class", 50);
		delete gradebook;
	}
	



	int number = 42;
	int* anotherNumber;

	// assigns the memory address of number to anotherNumber pointer
	anotherNumber = &number;

	// gets the value referenced by the pointer
	cout << (*anotherNumber) << endl;

	number = 100;

	cout << (*anotherNumber) << endl;

	(*anotherNumber) = 7;

	cout << number << endl;

	// I'm lazy
	int a, b, c;
	double xIntercept1, xIntercept2;

	cout << "Please enter your a value: " << endl;
	cin >> a;

	cout << "Please enter your b value: " << endl;
	cin >> b;

	cout << "Please enter your c value: " << endl;
	cin >> c;

	try {
		quadraticSolver(a, b, c, xIntercept1, xIntercept2);
		cout << "Your intercepts are: " << xIntercept1 << " and " << xIntercept2 << endl;
	}
	catch (logic_error exception) {
		cout << exception.what() << endl;
	}
	
}
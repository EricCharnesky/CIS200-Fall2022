#pragma once

using namespace std;

#include "Student.h"
#include <string>

class Gradebook {
private:
	string className;
	int numberOfStudents;
	Student* students;
public:

	Gradebook(string className, int numberOfStudents) {
		this->className = className;
		this->numberOfStudents = numberOfStudents;
		students = new Student[numberOfStudents];
	}

	// copy constructor
	Gradebook(const Gradebook& gradebook) {
		this->className = gradebook.className;
		this->numberOfStudents = gradebook.numberOfStudents;
		this->students = new Student[numberOfStudents];
		for (int index = 0; index < numberOfStudents; index++) {
			// this isn't a 'deep' copy yet
			this->students[index] = gradebook.students[index];
		}
	}

	// copy assignment operator
	Gradebook& operator=(const Gradebook& gradebook) {
		if (this != &gradebook) {
			this->className = gradebook.className;
			this->numberOfStudents = gradebook.numberOfStudents;
			this->students = new Student[numberOfStudents];
			for (int index = 0; index < numberOfStudents; index++) {
				// this isn't a 'deep' copy yet
				this->students[index] = gradebook.students[index];
			}
		}

		return *this;
	}

	~Gradebook() {
		delete[] students;
	}

	string getClassName() {
		return this->className;
	}

	int getNumberOfStudents() {
		return this->numberOfStudents;
	}

	void addStudent(Student student, int index) {
		this->students[index] = student;
	}

	Student getStudent(int index) {
		return this->students[index];
	}

};
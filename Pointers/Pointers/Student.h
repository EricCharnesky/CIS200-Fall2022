#pragma once

using namespace std;

#include <string>
#include <stdexcept>

class Student {
private:
	string name;
	int id;
	double score;
	int* scores;
public:

	Student(string name = "", int id = 0, double score = 100) {
		this->name = name;
		this->id = id;
		setScore(score);
		scores = new int[50];
	}

	~Student() {
		delete[] scores;
	}

	string getName() {
		return this->name;
	}

	int getId() {
		return this->id;
	}

	double getScore() {
		return this->score;
	}

	void setName(string name) {
		this->name = name;
	}

	void setId(int id) {
		this->id = id;
	}

	void setScore(double score) {
		if (score < 0 || score > 100) {
			throw logic_error("invalid score");
		}
		this->score = score;
	}
};
#include <iostream> 
#include <string>
#include <list>
using namespace std; 

struct Student
{
	int id;
	string name;
	float score;
};

void input(int &id, string &name, float &score, list<Student> &studentList, Student &student) {
	
	cout << "Student ID: ";
	cin >> id;
	cout << "Student name: ";
	cin >> name;
	cout << "Student score: ";
	cin >> score;
	while (score > 10 || score < 0) {
		cout << "please input score again, score must > 0 and < 10." << endl;
		cout << "Student score: ";
		cin >> score;
	}
	
	student.id = id;
	student.name = name;
	student.score = score;

	studentList.push_back(student);
}

void display(Student student) {
	cout << "ID: " << student.id << endl;
	cout << "Name: " << student.name << endl;
	cout << "Score: " << student.score << endl;	
}

void main() {
	list<Student> studentList;
	Student student;
	int id;
	string name;
	float score;
	int inputChoice = 9;
	list <Student> ::iterator it;
	while (inputChoice != 0)
	{
		cout << "------------------MENU------------------\n";
		cout << "1. Input\n2. Display\n3. Save to file\n4. Load from file\n0. Exit" << endl;
		cout << "----------------------------------------\nChoose: ";
		cin >> inputChoice;

		switch (inputChoice) {
		case 1:
			input(id, name, score, studentList, student);
			break;
		case 2:
			for (it = studentList.begin(); it != studentList.end(); it++) {
				display(student);
			}			
			break;
		}
		cout << "size of list: " << sizeof(studentList) << endl;
	}
	
	
}
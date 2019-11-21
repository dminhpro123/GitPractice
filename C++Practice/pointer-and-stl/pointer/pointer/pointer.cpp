#include <iostream> 
#include <string>
#include <list>
#include <fstream>
using namespace std; 

struct Student
{
	int id;
	string name;
	float score;
};

Student input(Student student) {
	int id;
	string name;
	float score;
	cout << "Student ID: ";
	cin >> id;
	student.id = id;
	cout << "Student name: ";
	cin >> name;
	student.name = name;
	cout << "Student score: ";
	cin >> score;
	student.score = score;
	while (student.score > 10 || student.score < 0) {
		cout << "please input score again, score must > 0 and < 10." << endl;
		cout << "Student score: ";
		cin >> score;
		student.score = score;
	}

	return student;
}

void display(Student student) {
	cout << "ID: " << student.id << endl;
	cout << "Name: " << student.name << endl;
	cout << "Score: " << student.score << endl;	
}

void saveToFile(Student student, list <Student> studentList, list <Student> ::iterator it) {
	
	ofstream MyFile("student.txt");
	for (it = studentList.begin(); it != studentList.end(); it++) {
		// Write to the file
		MyFile << "ID: " << student.id << " ";
		MyFile << "name: " << student.name << " ";
		MyFile << "score: " << student.score << " ";
	}
	// Create and open a text file
	

	

	// Close the file
	MyFile.close();
}

void loadFromFile() {
	// Create a text string, which is used to output the text file
	string myText;

	// Read from the text file
	ifstream MyReadFile("student.txt");

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {
		// Output the text from the file
		cout << myText << endl;
	}

	// Close the file
	MyReadFile.close();
}

void main() {
	list<Student> studentList;
	Student *student = new Student();
	int inputChoice;
	list <Student> ::iterator it;
	do
	{
		cout << "------------------MENU------------------\n";
		cout << "1. Input\n2. Display\n3. Save to file\n4. Load from file\n0. Exit" << endl;
		cout << "----------------------------------------\nChoose: ";
		cin >> inputChoice;

		switch (inputChoice) {
		case 1:
			studentList.push_back(input(*student));
			break;
		case 2:
			for (it = studentList.begin(); it != studentList.end(); it++) {
				display(*it);
			}			
			break;
		case 3:
			//for (it = studentList.begin(); it != studentList.end(); it++) {
			//	saveToFile(*it);
			//}
			saveToFile(*student, studentList, it);
			break;
		case 4:
			loadFromFile();
			break;
		default:
			break;
		}
	} while (inputChoice != 0);
	
	
}
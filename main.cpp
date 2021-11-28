#include "Student.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void printMenu();
void addObject(Marray<Student>& students);
void changeObject(Marray<Student>& students);
void deleteObject(Marray<Student>& students);
void print(Marray<Student>& students);
void searchFellows(Marray<Student>& students);
void searchDeducting(Marray<Student>& students);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Marray<Student> students;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = safeInput(0, 6);
		switch (method)
		{
		case 1:
			addObject(students);
			break;
		case 2:
			changeObject(students);
			break;
		case 3:
			deleteObject(students);
			break;
		case 4:
			print(students);
			break;
		case 5:
			searchFellows(students);
			break;
		case 6:
			searchDeducting(students);
			break;
		case 0:

			isExit = true;
			break;
		}
	}

}

void printMenu() {
	cout << "1. �������� ������" << endl;
	cout << "2. �������� ������" << endl;
	cout << "3. ������� ������" << endl;
	cout << "4. ������� ������" << endl;
	cout << "5. ������� ������� �������� � ������ �����, ������� 4 � 5" << endl;
	cout << "6. ������� ������� �������� � ������ �����, ��� ������� ����������" << endl;
	cout << "0. �����" << endl;
	cout << "�������� ����� ����: ";
}

void addObject(Marray<Student>& students) {
	Student student;
	student.inputFromConsole();
	students += student;
	students.sort();
}

void changeObject(Marray<Student>& students) {
	if (students.getSize() > 0) {
		print(students);
		cout << "������� ����� �������� ��� ���������: ";
		students[safeInput(1, students.getSize()) - 1].change();
	}
	else
		cout << "������ ��������� ����. ������ ��������\n";
	students.sort();
}

void deleteObject(Marray<Student>& students) {
	if (students.getSize() > 0) {
		print(students);
		cout << "������� ����� �������� ��� ��������: ";
		students -= safeInput(1, students.getSize()) - 1;
	}
	else
		cout << "������ ��������� ����. ������ �������\n";
	students.sort();
}

void print(Marray<Student>& students) {
	if (students.getSize() == 0)
		cout << "������ ��������� ����.\n";
	else {
		cout << "������ ���������\n";
		for (int i = 0; i < students.getSize(); i++) {
			cout << i + 1 << ". �������\n";
			students[i].printToConsole();
		}
	}
}

void searchFellows(Marray<Student>& students) {
	if (students.getSize() == 0)
		cout << "������ ��������� ����\n";
	else {
		bool isPrint = false;
		for (int i = 0; i < students.getSize(); i++) {
			Marray<int> marks = students[i].getMarks();
			bool is5 = false, is4 = false;
			for (int j = 0; j < marks.getSize(); j++) {
				if (marks[j] == 4) is4 = true;
				if (marks[j] == 5) is5 = true;
			}	
			if (is5 && is4) {
				cout << students[i].getNumberGroup() << " " << students[i].getSecondName() << endl;
				isPrint = true;
			}
		}
			
		if (!isPrint)
			cout << "��������� ���� �� � 4 � 5 ���\n";
	}
}

void searchDeducting(Marray<Student>& students) {
	if (students.getSize() == 0)
		cout << "������ ��������� ����\n";
	else {
		bool isPrint = false;
		for (int i = 0; i < students.getSize(); i++) {
			Marray<int> marks = students[i].getMarks();
			int count2 = 0;
			for (int j = 0; j < marks.getSize(); j++) {
				if (marks[j] == 2) count2++;
			}
			if (count2 >= 2) {
				cout << students[i].getNumberGroup() << " " << students[i].getSecondName() << endl;
				isPrint = true;
			}
		}

		if (!isPrint)
			cout << "���������, ������������ � ���������� ���\n";
	}
}
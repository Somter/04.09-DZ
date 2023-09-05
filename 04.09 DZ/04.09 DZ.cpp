// 04.09 DZ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>	
#include <cstdio>
using namespace std;	
#define YELLOW_TEXT "\033[33m"	
#define RESET_COLOR "\033[0m"
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"	
#define PROBEL cout << endl;cout << "--------------" << endl;cout << endl;

const int SIZE = 15;	
const int MAX_EMPLOYEES = 50;	
struct Person {
	char* surname;
	char* name;
	char* number;
	double salary;			
};
void Data_Input(Person* Employee, int &count)		
{
	Person& employee = Employee[count];
	employee.surname = new char[SIZE];
	cout << "�������� �������: " ;
	cin >> employee.surname;

	employee.name = new char[SIZE];
	cout << "������� ���: ";
	cin >> employee.name;

	employee.number = new char[SIZE];	
	cout << "������� ����� ��������: " << endl;		
	cout << YELLOW_TEXT << "������: (063)5635904 " << RESET_COLOR;	
	int i = 0;
	do {
		i++;
		if (i > 1) {
			cout << RED_TEXT << "������������ ����� ��������" << RESET_COLOR;
		}
		cout << "\n����: ";
		cin >> employee.number;

	} while ((employee.number[0] != '(') || (employee.number[4] != ')'));				

	cout << "������� ������ ���������� �����: ";
	cin >> employee.salary;	
	count++;	
}
void Delete_Employee(Person* Employee, int& count) 
{
	int Delete_choice;
	char Yes_Or_No[5];	
	cout << "���������� �����������: " << count << endl;
	cout << "������ �������: ";
	cin >> Delete_choice;
	cout << "�� ������������� ������ ������� ����� ����������? Yes/No: ";
	cin >> Yes_Or_No;	
	if(strcmp(Yes_Or_No, "yes") == 0 || strcmp(Yes_Or_No, "Yes") == 0){
		if (Delete_choice <= count && Delete_choice > 0) {
			for (int i = Delete_choice - 1; i < count - 1; i++) {
				Employee[i] = Employee[i + 1];
			}
			cout << GREEN_TEXT << "��������� ������� �����!" << RESET_COLOR << endl;	
			count--;	
		}
		else {
			cout << RED_TEXT << "������������ ����� ��� ��������." << RESET_COLOR << endl;
		}	
	}
	else if (strcmp(Yes_Or_No, "no") == 0 || strcmp(Yes_Or_No, "No") == 0) {
		cout << GREEN_TEXT << "�������� ����������!" << RESET_COLOR << endl;	
		return;
	}		
	else {
		cout << RED_TEXT << "������������ �����" << RESET_COLOR << endl;	
	}

}
void SortingSurname(Person* Employee, int& count) 
{
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (strcmp(Employee[j].surname, Employee[j + 1].surname) > 0) {
				Person temp = Employee[j];
				Employee[j] = Employee[j + 1];
				Employee[j + 1] = temp;
			}
		}
	}
}
void SearchSurname(Person* Employee, int& count)			
{	
	char YourSurname[20];	
	cout << "������� ������� ������� ����� �����: ";
	cin >> YourSurname;	
	bool found = false; 
	for (int i = 0; i < count; i++) {
		if (strcmp(YourSurname, Employee[i].surname) == 0) {
			cout << GREEN_TEXT << "����� ��������� ����!" << RESET_COLOR << endl;	
			cout << "�������: ";	
			cout << Employee[i].surname << endl;	
			cout << "���: ";
			cout << Employee[i].name << endl;
			cout << "�����: ";
			cout << Employee[i].number << endl;	
			cout << "��������: ";
			cout << Employee[i].salary << endl;	
			found = true; 
		}
	}

	if (!found) {
		cout << RED_TEXT << "��������� � �������� " << RESET_COLOR << YourSurname << RED_TEXT <<  " �� ������." << RESET_COLOR << endl;	
	}	
}
void SalarySearch(Person* Employee, int& count) 
{
	double start, end;	
	cout << "������� �������� �������� " << endl;	
	cout << "�������� ������ ���������: ";
	cin >> start;
	cout << "������� ����� ��������: ";
	cin >> end;	
	for (int i = 0; i < count; i++) {
		if (Employee[i].salary >= start && Employee[i].salary <= end) 
		{
			cout << endl;	
			cout << GREEN_TEXT << "��������� � ����� ��������� ����! " << RESET_COLOR << endl;	
			cout << "�������: ";
			cout << Employee[i].surname << endl;
			cout << "���: ";
			cout << Employee[i].name << endl;
			cout << "�����: ";
			cout << Employee[i].number << endl;
			cout << "��������: ";
			cout << Employee[i].salary << endl;	
		}	
		else {
			cout << RED_TEXT << "����������� � ����� ��������� ���! " << RESET_COLOR << endl;	
		}
	}

}

void Print(Person* Employee) 
{
	cout << "�������: ";
	cout << Employee->surname << endl;	
	cout << "���: ";
	cout << Employee->name << endl;	
	cout << "�����: ";
	cout << Employee->number << endl;	
	cout << "��������: ";
	cout << Employee->salary << endl;		
}

int main()	
{
	setlocale(LC_ALL, "");
	Person Employee[MAX_EMPLOYEES];		
	int choise;	
	int count = 0;	
	FILE* file;
	const char* path = "probni.txt";		
	const int BUFFER_SIZE = 100;
	char buffer[BUFFER_SIZE];	


	do {
		cout << "�������� ��������: " << endl;
		cout << "1 - ���������� ������ ����������" << endl;
		cout << "2 - ������������ ����������� ���� ����� �� �����" << endl;
		cout << "3 - �������� ���������� �� ������" << endl;
		cout << "4 - ���������� �� �������" << endl;
		cout << "5 - ����� �� ������� � ������������ ����������� �� �����" << endl;
		cout << "6 - ����� �� ��������� ���������� ����� � ������������ ����������� �� �����" << endl;
		cout << "7 - �������� ���������� �� �����" << endl;
		cout << "8 - ������ ���������� � ����" << endl;
		cout << "9 - �����" << endl;
		cout << "��� �����: ";
		cin >> choise;
		system("cls");
		switch (choise) {
		case 1:
			Data_Input(Employee, count);
			PROBEL
				break;
		case 2:
			for (int i = 0; i < count; i++) {
				Print(Employee + i);
				PROBEL
			}
			break;
		case 3:
			Delete_Employee(Employee, count);
			PROBEL
				break;
		case 4:
			SortingSurname(Employee, count);
			cout << GREEN_TEXT << "���������� ���������! " << RESET_COLOR << endl;
			PROBEL
				break;
		case 5:
			SearchSurname(Employee, count);
			PROBEL
				break;
		case 6:
			SalarySearch(Employee, count);
			PROBEL
				break;
		case 7:

			if (fopen_s(&file, path, "r") != 0) {	
				cout << RED_TEXT << "������ �������� �����." << RESET_COLOR << endl;
				break; 
			}

			count = 0;	

			while (count < MAX_EMPLOYEES && fgets(buffer, BUFFER_SIZE, file)) {
				printf(buffer, "%s %s %s %lf", Employee[count].surname, Employee[count].name, Employee[count].number, &Employee[count].salary);	
				count++;
			}

			fclose(file);

			printf(GREEN_TEXT "\n���������� ������� ��������� �� �����." RESET_COLOR "\n");	
			break;
		case 8:
			if (fopen_s(&file, path, "w") != 0) {
				cout << RED_TEXT << "������ �������� ����� ��� ������." << RESET_COLOR << endl;
				break;
			}

			for (int i = 0; i < count; i++) {
				fprintf_s(file, "%s %s %s %.2lf\n", Employee[i].surname, Employee[i].name, Employee[i].number, Employee[i].salary);
			}

			fclose(file);

			printf(GREEN_TEXT "���������� ������� �������� � ����." RESET_COLOR "\n");	
			PROBEL
				break;
		}
	} while (choise != 9);

	delete[] Employee->surname;
	delete[] Employee->name;
	delete[] Employee->number;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

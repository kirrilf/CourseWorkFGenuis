#include "pch.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;


struct studentG
{

	int number;
	char *sourname = new char[50];
	char *name = new char[50];
	char *patronymic = new char[50];
	int *semesterGrades = new int[5];
	bool budgetOrContract; //0 - budget, 1 - contract
	int finance;
	

	studentG *next;
	studentG *previous;


};

struct group
{
	int numGroup;
	int count = 0;
	studentG *studentFirst = NULL;
	studentG *studentLast = NULL;
	group *next;
	group *previous;

};

group *firstElementGroup;
group *lastElementGroup;

int getValue()
{
	while (true) // Цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		int a;
		cin >> a;

		// Проверка на предыдущее извлечение
		if (cin.fail()) // если предыдущее извлечение оказалось провальным
		{
			cin.clear(); // возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "ERROR.  Please try again.\n";
		}
		else
		{
			cin.ignore(2147483647, '\n'); // удаляем лишние значения

			return a;
		}
	}
}

void createGroup() {

	group *Element = new group;
	group *temp;
	int numGroup;
	system("cls");
	cout << "ENTER GROUP NUMBER: ";
	numGroup = getValue();
	Element->numGroup = numGroup;

	

	if (firstElementGroup == NULL && firstElementGroup == lastElementGroup) {
		firstElementGroup = Element;
		firstElementGroup->previous = NULL;
		lastElementGroup = Element;
		lastElementGroup->next = NULL;
	}
	else {
		lastElementGroup->next = Element;
		temp = lastElementGroup;
		lastElementGroup = Element;
		lastElementGroup->previous = temp;
		lastElementGroup->next = NULL;
	}

}

void addCreateGroup(int numGroup){
	group *Element = new group;
	group *temp;

	Element->numGroup = numGroup;

	if (firstElementGroup == NULL && firstElementGroup == lastElementGroup) {
		firstElementGroup = Element;
		firstElementGroup->previous = NULL;
		lastElementGroup = Element;
		lastElementGroup->next = NULL;
	}
	else {
		lastElementGroup->next = Element;
		temp = lastElementGroup;
		lastElementGroup = Element;
		lastElementGroup->previous = temp;
		lastElementGroup->next = NULL;
	}

}

void addStudentToGroup() {
	int numGroup;
	cout << "ENTER GROUP NUMBER: ";
	numGroup = getValue();
	group *temp;
	temp = firstElementGroup;
	while (temp->numGroup != numGroup) {
		if (temp->next == NULL) {
			cout << "NO GROUP";
			_getch();
			return;
		}
		temp = temp->next;
	}


	studentG *Element = new studentG;
	studentG *temp1;
	studentG *firstElement = temp->studentFirst;
	studentG *lastElement = temp->studentLast;

	char *sourname = new char[50];
	char *name = new char[50];
	char *patronymic = new char[50];
	int *semesterGrades = new int[5];
	bool budgetOrContract;
	int finance;
	cout << "ENTER SOURNAME: ";
	cin >> sourname;
	cout << endl;
	cout << "ENTER NAME: ";
	cin >> name;
	cout << endl;
	cout << "ENTER PATRONYMIC: ";
	cin >> patronymic;
	cout << endl;
	cout << "ENTER SEMESTER GRADES: ";
	for (int i = 0; i < 5; i++) {
		int semGrade;
		semGrade = getValue();
		while(semGrade > 5 || semGrade < 2) {
			semGrade = getValue();
			cout << "ERROR";
			_getch();
		}
		semesterGrades[i] = semGrade;
	}
	cout << "ENTER FINANCE: ";
	finance = getValue();
	cout << "BUDGET- 1, CONTRACT - 0: ";
	int bg;
	bg = getValue();
	while (bg != 0 && bg != 1) {
		cout << "ERROR. TRY AGAIN";
		bg = getValue();
	}
	budgetOrContract = bg;



	Element->sourname = sourname;
	Element->name = name;
	Element->patronymic = patronymic;
	Element->semesterGrades = semesterGrades;
	Element->budgetOrContract = budgetOrContract;
	Element->finance = finance;

	if (firstElement == NULL && firstElement == lastElement) {
		firstElement = Element;
		firstElement->previous = NULL;
		lastElement = Element;
		lastElement->next = NULL;
	}
	else {
		lastElement->next = Element;
		temp1 = lastElement;
		lastElement = Element;
		lastElement->previous = temp1;
		lastElement->next = NULL;
	}
	temp->count++;
	temp->studentFirst = firstElement;
	temp->studentLast = lastElement;

}

void addStudent(int numGroup, char *sourname, char *name, char *patronymic, int *semesterGrades, bool budgetOrContract, int finance) {
	group *temp;
	temp = firstElementGroup;
	while (temp->numGroup != numGroup) {
		temp = temp->next;
	}
	studentG *Element = new studentG;
	studentG *temp1;
	studentG *firstElement = temp->studentFirst;
	studentG *lastElement = temp->studentLast;

	
	Element->sourname = sourname;
	Element->name = name;
	Element->patronymic = patronymic;
	Element->semesterGrades = semesterGrades;
	Element->budgetOrContract = budgetOrContract;
	Element->finance = finance;

	if (firstElement == NULL && firstElement == lastElement) {
		firstElement = Element;
		firstElement->previous = NULL;
		lastElement = Element;
		lastElement->next = NULL;
	}
	else {
		lastElement->next = Element;
		temp1 = lastElement;
		lastElement = Element;
		lastElement->previous = temp1;
		lastElement->next = NULL;
	}
	temp->count++;
	temp->studentFirst = firstElement;
	temp->studentLast = lastElement;

}

void deleteGroup() {

	group *temp;
	temp = firstElementGroup;
	int numDelete;
	cout << "ENTER NUMBER GROUP: ";
	numDelete = getValue();

	while (temp->numGroup != numDelete) {
		
		if (temp->next == NULL) {
			cout << "NO GROUP";
			_getch();
			return;
		}
		temp = temp->next;
	}




	if (firstElementGroup == lastElementGroup) {
		delete temp;
		firstElementGroup = NULL;
		lastElementGroup = NULL;
	}
	else if (temp == firstElementGroup) {
		firstElementGroup = firstElementGroup->next;
		firstElementGroup->previous = NULL;
		delete temp;
	}
	else if (temp == lastElementGroup) {
		lastElementGroup = lastElementGroup->previous;
		lastElementGroup->next = NULL;
		delete temp;
	}
	else {
		group *temp1;
		group *temp2;
		temp1 = temp->previous;
		temp2 = temp->next;
		delete temp;
		temp1->next = temp2;
		temp2->previous = temp1;
	}
	

}

void deleteStudent() {
	group *temp;
	temp = firstElementGroup;
	int numGroup;
	char *sourname = new char[50];
	cout << "ENTER NUMBER GROUP: ";
	numGroup = getValue();
	cout << "ENTER SOURNAME STUDENT: ";
	cin >> sourname;

	while (temp->numGroup != numGroup) {
	
		if (temp->next == NULL) {
			cout << "NO STUDENT";
			_getch();
			return;
		}
		temp = temp->next;
	}
	studentG *tempG;
	studentG *firstElement;
	studentG *lastElement;
	firstElement = temp->studentFirst;
	lastElement = temp->studentLast;
	tempG = temp->studentFirst;

	while (strcmp(tempG->sourname, sourname) != 0) {
		tempG = tempG->next;
	}

	if (firstElement == lastElement) {
		delete tempG;
		firstElement = NULL;
		lastElement = NULL;
	}
	else if (tempG == firstElement) {
		firstElement = firstElement->next;
		firstElement->previous = NULL;
		delete tempG;
	}
	else if (tempG == lastElement) {
		lastElement = lastElement->previous;
		lastElement->next = NULL;
		delete tempG;
	}
	else {
		studentG *temp1;
		studentG *temp2;
		temp1 = tempG->previous;
		temp2 = tempG->next;
		delete tempG;
		temp1->next = temp2;
		temp2->previous = temp1;
	}
	temp->studentFirst = firstElement;
	temp->studentLast = lastElement;
	temp->count--;


}

void deleteAllStudent() {
	group *temp;
	temp = firstElementGroup;
	
	while (temp) {
		studentG *tmp;
		tmp = temp->studentFirst;
		while (tmp){
			studentG  *tmp1;
			tmp1 = tmp;
			tmp = tmp->next;
			delete tmp1;
		}
		temp->studentFirst = NULL;
		temp->studentLast = NULL;
		temp->count = 0;

		temp = temp->next;
	}

}

void deleteAllGroup() {
	group *temp;
	temp = firstElementGroup;

	while (temp){
		group *temp1;
		temp1 = temp;
		temp = temp->next;
		delete temp1;
	}

	firstElementGroup = NULL;
	lastElementGroup = NULL;

}

void changeStudent() {
	group *temp;
	temp = firstElementGroup;
	int numGroup;
	char *sourname = new char[50];
	cout << "ENTER NUMBER GROUP: ";
	numGroup = getValue();
	cout << "ENTER SOURNAME STUDENT: ";
	cin >> sourname;

	while (temp->numGroup != numGroup) {
		
		if (temp->next == NULL) {
			cout << "NO STUDENT";
			_getch();
			return;
		}
		temp = temp->next;
	}
	studentG *tempG;
	studentG *firstElement;
	studentG *lastElement;
	firstElement = temp->studentFirst;
	lastElement = temp->studentLast;
	tempG = temp->studentFirst;

	while (strcmp(tempG->sourname, sourname) != 0) {
		tempG = tempG->next;
	}

	char *sournam = new char[50];
	char *name = new char[50];
	char *patronymic = new char[50];
	int *semesterGrades = new int[5];
	bool budgetOrContract;
	int finance;
	cout << "ENTER SOURNAME: ";
	cin >> sournam;
	cout << endl;
	cout << "ENTER NAME: ";
	cin >> name;
	cout << endl;
	cout << "ENTER PATRONYMIC: ";
	cin >> patronymic;
	cout << endl;
	cout << "ENTER SEMESTER GRADES: ";
	for (int i = 0; i < 5; i++) {
		int semGrade;
		semGrade = getValue();
		while (semGrade > 5 || semGrade < 2) {
			semGrade = getValue();
			cout << "ERROR";
			_getch();
		}
		semesterGrades[i] = semGrade;
	}
	cout << "ENTER FINANCE: ";
	finance = getValue();
	cout << "BUDGET- 1, CONTRACT - 0: ";
	budgetOrContract = getValue();
	while (budgetOrContract != 0 && budgetOrContract != 1) {
		budgetOrContract = getValue();
	}



	tempG->sourname = sournam;
	tempG->name = name;
	tempG->patronymic = patronymic;
	tempG->semesterGrades = semesterGrades;
	tempG->budgetOrContract = budgetOrContract;
	tempG->finance = finance;


}

void fileWrite(int countGrop) {
	ofstream File; 

	File.open("test.dat", ios::binary); 

	if (!File.is_open()) {
		cout << "ERROR";
		return ;
	}
	group *temp;
	temp = firstElementGroup;
	//File << countGrop << " ";
	File.write((char*)&countGrop, sizeof(int));
	while (temp){
		//File << temp->numGroup << " " << temp->count << " ";
		File.write((char*)&temp->numGroup, sizeof(int));
		File.write((char*)&temp->count, sizeof(int));
		studentG *tmp;
		tmp = temp->studentFirst;
		while (tmp) {
			//File << tmp->sourname << " " << tmp->name << " " << tmp->patronymic << " ";
			File.write((char*)tmp->sourname, sizeof(tmp->sourname));
			File.write((char*)tmp->name, sizeof(tmp->name));
			File.write((char*)tmp->patronymic, sizeof(tmp->patronymic));

			/*for (int i = 0; i < 5; i++) {
				File << tmp->semesterGrades[i] << " ";
			}*/
			File.write((char*)tmp->semesterGrades, sizeof(int[5]));
			//File << tmp->finance << " " << tmp->budgetOrContract<< " ";
			File.write((char*)&tmp->finance, sizeof(int));
			File.write((char*)&tmp->budgetOrContract, sizeof(bool));


			tmp = tmp->next;
		}

		temp = temp->next;
	}
	




	File.close(); 

	


	


}

int fileRead() {

	ifstream File;

	File.open("test.dat", ios::binary);

	if (!File.is_open()) {
		cout << "ERROR";
		return 0;
	}

	deleteAllStudent();
	deleteAllGroup();
	int countGrop = 0;
	//File >> countGrop;
	File.read((char*)&countGrop, sizeof(int));


	for (int i = 0; i < countGrop; i++) {
		int numGroup, count;
		//File >> numGroup >> count;
		File.read((char*)&numGroup, sizeof(int));
		File.read((char*)&count, sizeof(int));
		addCreateGroup(numGroup);
		for (int j = 0; j < count; j++) {
			char *sourname = new char[50];
			char *name = new char[50];
			char *patronymic = new char[50];
			int *semesterGrades = new int[5];
			bool budgetOrContract;
			int finance;
			//File >> sourname;
			//File >> name;
			//File >> patronymic;
			File.read((char*)sourname, sizeof(sourname));
			File.read((char*)name, sizeof(name));
			File.read((char*)patronymic, sizeof(patronymic));
			File.read((char*)semesterGrades, sizeof(int[5]));
			//for (int i = 0; i < 5; i++) {
			//	File >> semesterGrades[i];
			//}
			//File >> finance;
			File.read((char*)&finance, sizeof(finance));
			//File >> budgetOrContract;
			File.read((char*)&budgetOrContract, sizeof(budgetOrContract));
			addStudent(numGroup, sourname, name, patronymic, semesterGrades, budgetOrContract, finance);
		}

	}
	






	File.close();

	return countGrop;
}

void showStudents(studentG *temp) {

	int i = 1;

	while (temp) {
		cout << i << ")" << endl << "SOURNAME: " << temp->sourname << endl;
		cout << "NAME: " << temp->name << endl;
		cout << "PATRONYMIC: " << temp->patronymic << endl;
		cout << "ENTER SEMESTER GRADES: ";
		for (int i = 0; i < 5; i++) {
			cout << temp->semesterGrades[i] << " ";
		}
		cout << endl;
		cout << "BUDGET 1 - YES, 0 - NO: " << temp->budgetOrContract << endl << "FINANCE: " << temp->finance << endl;
		temp = temp->next;
		i++;
	}
}

void showGroup() {
	group *temp;
	temp = firstElementGroup;
	while (temp) {
		cout << "Num Group:" << temp->numGroup << "    Count:" << temp->count << endl;
		showStudents(temp->studentFirst);
		temp = temp->next;
	}
	_getch();
}

		
int menu() {



	int k = 1, num = 1;

	string	A = "1 CREATE A GROUP        ",
			B = "2 ADD STUDENT TO GROUP  ",
			C = "3 DELTE GROUP           ",
			D = "4 DELETE STUDENT        ",
			E = "5 CHANGE                ",
			F = "6 SHOW GROUP            ",
			G = "7 FILE WRITE            ",
			L = "8 FILE READ             ";
			
			
			
			




	system("cls");
	cout << A << "<---\n";
	cout << B << "\n";
	cout << C << "\n";
	cout << D << "\n";
	cout << E << "\n";
	cout << F << "\n";
	cout << G << "\n";
	cout << L << "\n";


	



	while (true) {

		int l = _getch(), c = 0;
		if (l == 224) {
			c = _getch();
		}
		system("cls");

		if (c == 80) {
			k++;
		}

		else if (c == 72) {
			k--;
		}


		if (k == 9) {
			k = 1;
		}

		else if (k == 0) {
			k = 8;
		}

		if (l == 13) {
			return k;
		}


		if (l == 49) {
			return 1;
		}
		else if (l == 50) {
			return 2;
		}
		else if (l == 51) {
			return 3;
		}
		else if (l == 52) {
			return 4;
		}
		else if (l == 53) {
			return 5;
		}
		else if (l == 54) {
			return 6;
		}
		else if (l == 55) {
			return 7;
		}
		else if (l == 56) {
			return 8;
		}
		

		



		if (k == 1) {
			cout << A << "<---\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "\n";
			cout << E << "\n";
			cout << F << "\n";
			cout << G << "\n";
			cout << L << "\n";
			
			
		
		}
		else if (k == 2) {
			cout << A << "\n";
			cout << B << "<---\n";
			cout << C << "\n";
			cout << D << "\n";
			cout << E << "\n";
			cout << F << "\n";
			cout << G << "\n";
			cout << L << "\n";
			
			
			
		}
		else if (k == 3) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "<---\n";
			cout << D << "\n";
			cout << E << "\n";
			cout << F << "\n";
			cout << G << "\n";
			cout << L << "\n";
			
			
			
		}
		else if (k == 4) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "<--\n";
			cout << E << "\n";
			cout << F << "\n";
			cout << G << "\n";
			cout << L << "\n";
			
			
			
		}
		else if (k == 5) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "\n";
			cout << E << "<--\n";
			cout << F << "\n";
			cout << G << "\n";
			cout << L << "\n";
			
			
			
		}
		else if (k == 6) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "\n";
			cout << E << "\n";
			cout << F << "<---\n";
			cout << G << "\n";
			cout << L << "\n";
			
			
			
		}
		else if (k == 7) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "\n";
			cout << E << "\n";
			cout << F << "\n";
			cout << G << "<---\n";
			cout << L << "\n";
			
			
			
		}
		else if (k == 8) {
			cout << A << "\n";
			cout << B << "\n";
			cout << C << "\n";
			cout << D << "\n";
			cout << E << "\n";
			cout << F << "\n";
			cout << G << "\n";
			cout << L << "<--\n";
			
		}
		
	
	}

}


void startMenu() {
	int countGrop = 0;

	while (true) {
		int infoMenu = menu();

		if (infoMenu == 1) {
			createGroup();
			countGrop++;
		}
		else if (infoMenu == 2) {
			addStudentToGroup();
		}
		else if (infoMenu == 3) {
			deleteGroup();
		}
		else if (infoMenu == 4) {
			deleteAllStudent();
		}
		else if (infoMenu == 5) {
			changeStudent();
		}
		else if (infoMenu == 6) {
			showGroup();
		}
		else if (infoMenu == 7) {
			fileWrite(countGrop);
		}
		else if (infoMenu == 8) {
			countGrop = fileRead();
		}
		





	}

}




int main()
{
	
	startMenu();

	return 0;
}


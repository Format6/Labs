#define _CRT_SECURE_NO_WARNINGS
#define filename "D:\\Lab15.txt"
#define filenameB "D:\\TestB15.dat"

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

struct FullName {
	string name;
	string surname;
};

struct Debtor {
	FullName fullName;
	long int phone;	  // номер телефона будет 7значным	
	int debt; //сумма задолжности	
	bool insurance;		//наличие страховки
};

void readFromFile(struct Debtor*,int);
void writeInFile(struct Debtor*,int);
void printOnScreen(struct Debtor*,int);
void sortByDebt(struct Debtor*,int);
Debtor createClient();
Debtor readFromFileBinary();
void writeInFileBinary(struct Debtor*,int);
int addMessage(struct Debtor* debtors, int size);
int removeMessage(struct Debtor* debtors, int size, int index);




#define _CRT_SECURE_NO_WARNINGS
#define SIZE 32
#define filename "D:\\Lab15.txt"
#define filenameB "D:\\TestB15.dat"

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

struct FullName {
	char name[SIZE];
	char surname[SIZE];
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




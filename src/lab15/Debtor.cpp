#include "Debtor.h"

void readFromFile(struct Debtor* debtors, int size) {
	FILE* file;
	file = fopen(filename, "r");

	for (int i = 0; i < size; i++) {		
		fgets(debtors[i].fullName.name, SIZE, file);
		fgets(debtors[i].fullName.surname, SIZE, file);
		fscanf(file, "%d\n", &debtors[i].debt);
		fscanf(file, "%d\n", &debtors[i].phone);
		fscanf(file, "%d\n", &debtors[i].insurance);
	}
	fclose(file);
}
void writeInFile(struct Debtor* debtors, int size) {
	FILE* file;
	file = fopen(filename, "w");

	for (int i = 0; i < size; i++) {
		fprintf(file, debtors[i].fullName.name);
		fprintf(file, "\n");
		fprintf(file, debtors[i].fullName.surname);
		fprintf(file, "\n");
		fprintf(file, "%d\n",debtors[i].debt);
		fprintf(file, "%d\n", debtors[i].phone);
		fprintf(file, "%d\n", debtors[i].insurance);
	}

	fclose(file);
}
void printOnScreen(struct Debtor* debtors, int size) {
	for (int i = 0; i < size; i++) {
		printf("Full name: %s %s\n", debtors[i].fullName.name, debtors[i].fullName.surname);
		printf("Tel.: %d\n", debtors[i].phone);
		printf("Debt amount: %d\n", debtors[i].debt);
								   
		printf("%s\n\n", debtors[i].insurance ? "[The client has insurance]" : "");
	}
}
void sortByDebt(struct Debtor* debtors, int size) {
	struct Debtor tmp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (debtors[j].debt > debtors[j + 1].debt) {
				tmp = debtors[j];
				debtors[j] = debtors[j + 1];
				debtors[j + 1] = tmp;
			}
		}
	}
}
Debtor createClient() {
	Debtor debtor;
	char tmp[SIZE]="";
	
	printf("Enter customer name:");
	scanf("%s",tmp);
	strcpy(debtor.fullName.name, tmp);

	printf("Enter customer surname:");
	scanf("%s", tmp);
	strcpy(debtor.fullName.surname, tmp);

	printf("Enter the customer's phone number (7-digit):");
	scanf("%ld", &debtor.phone);

	printf("Enter the customer loan amount: ");
	scanf("%d", &debtor.debt);
	printf("\n\n");
	debtor.insurance = rand() % 2;

	return debtor;
}

void writeInFileBinary(struct Debtor* debtor, int size) {
	FILE* file;
	file = fopen(filenameB, "wb");
	for (int i = 0; i < size; i++)
		fwrite(&debtor, sizeof(Debtor), 1, file);

	fclose(file);
}
Debtor readFromFileBinary()
{
	struct Debtor employee;
	FILE* file;
	file = fopen(filenameB, "rb");
	fread(&employee, sizeof(Debtor), 1, file);

	fclose(file);
	return employee;
}
#include "Debtor.h"

void readFromFile(struct Debtor* debtors, int size) {
	std::ifstream in(filename); // окрываем файл для чтения
	if (in.is_open()) {
		string tmp;

		for (int i = 0; i < size; i++) {
			getline(in, debtors[i].fullName.name);
			getline(in, debtors[i].fullName.surname);
			getline(in, tmp);
			debtors[i].debt = atoi(tmp.c_str());
			getline(in, tmp);
			debtors[i].phone = atoi(tmp.c_str());
			getline(in, tmp);
			debtors[i].insurance = atoi(tmp.c_str());
		}
	}in.close();
}
void writeInFile(struct Debtor* debtors, int size) {
	std::ofstream out(filename);
	if (out.is_open()) {

		for (int i = 0; i < size; i++) {
			out << debtors[i].fullName.name << endl << debtors[i].fullName.surname << endl
				<< debtors[i].debt << endl << debtors[i].phone << endl << debtors[i].insurance << endl;
		}

	}out.close();
}
void printOnScreen(struct Debtor* debtors, int size) {
	for (int i = 0; i < size; i++) {
		cout << "\nFull name:" << debtors[i].fullName.name << " " << debtors[i].fullName.surname;
		cout << "\nTel.:" << debtors[i].phone;
		cout << "\nDebt amount:" << debtors[i].debt;
		cout << debtors[i].insurance ? "[The client has insurance]" : "";
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
	string tmp;

	printf("Enter customer name:");
	cin >> debtor.fullName.name;

	printf("Enter customer surname:");
	cin >> debtor.fullName.surname;

	printf("Enter the customer's phone number (7-digit):");
	cin >> debtor.phone;

	printf("Enter the customer loan amount: ");
	cin >> debtor.debt;

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
int addMessage(struct Debtor* debtors, int size) {

	size++;
	Debtor* mass = (Debtor*)malloc(size * sizeof(Debtor));
	memcpy(mass, debtors, sizeof(Debtor) * (size - 1));
	mass[size - 1] = createClient();
	memcpy(debtors, mass, sizeof(Debtor) * size);

	return size;
}
int removeMessage(struct Debtor* debtors, int size, int index) {

	size--;
	Debtor* mass = (Debtor*)malloc(size * sizeof(Debtor));
	for (int i = 0; i < size; i++)
	{
		if (i < index)
		{
			mass[i] = debtors[i];
		}
		else
		{
			mass[i] = debtors[i + 1];
		}
	}
	memcpy(debtors, mass, sizeof(Debtor) * size);

	return size;
}
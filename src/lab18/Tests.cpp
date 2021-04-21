#include "Tests.h"

void testSort() {
	printf("Here the sort test works.\n");
	int size = 3;
	int counter = 0;
	struct Debtor* debtors = (struct Debtor*)malloc(size * sizeof(struct Debtor));

	for (int i = 0; i < size; i++)
		debtors[i] = createClient();


	sortByDebt(debtors, size);
	if (debtors[0].debt >= debtors[1].debt || debtors[1].debt >= debtors[2].debt) {
		counter++;
		printf("Debt sorting performed incorrect calculations!\n");
	}

	if (counter == 0)
		printf("Sort was succesful.\n");
	else
		printf("Sort was not succesful.\n");
}


void testAdd() {

	printf("Here the add test works.\n");

	int size = 2;
	Debtor* mass = (Debtor*)malloc(size * sizeof(Debtor));
	for (int i = 0; i < size; i++)
	{
		mass[i] = createClient();
	}
	size = addMessage(mass, size);

	if (mass[size - 1].debt > 0 && size == 3)
	{
		printf("Add was succesful.\n\n");
	}
	else
	{
		printf("Add was not succesful.\n\n");
	}

}

void testRemove() {

	printf("Here the remove test works.\n");

	int size = 3;
	Debtor* mass = (Debtor*)malloc(size * sizeof(Debtor));

	for (int i = 0; i < size; i++)
	{
		mass[i] = createClient();
	}

	int tmpDebt0 = mass[0].debt;
	int tmpDebt2 = mass[2].debt;

	size = removeMessage(mass, size, 1);

	if (tmpDebt0 == mass[0].debt && tmpDebt2 == mass[1].debt && size == 2)
	{
		printf("Remove was succesful.\n\n");
	}
	else
	{
		printf("Remove was not succesful.\n\n");
	}

}
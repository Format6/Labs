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
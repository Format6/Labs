#include "Debtor.h"

int main() {
	int size = 3;
	struct Debtor* debtors;
	debtors = (struct Debtor*)malloc(size * sizeof(struct Debtor));
	for (int i = 0; i < size; i++) {
		debtors[i] = createClient();
	}
	printOnScreen(debtors,size);
	sortByDebt(debtors,size);
	writeInFile(debtors,size);			
	
	return 0;
}
#include "Tests.h"

int main() {
	
	struct Debtor* debtors = (struct Debtor*)malloc(sizeof(Debtor) * 2);
	
	debtors[0] = createClient();
	debtors[1] = createClient();

	printOnScreen(debtors, 2);

	writeInFile(debtors, 2);

	return 0;
}
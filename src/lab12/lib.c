#include "lib.h"

int* counter(int* arr) {
	int countOfSought = 1;
	int count = 0;

	int sizeResult = size(arr);
	int* arrRes = (int*)malloc(sizeResult * 2 * sizeof(int));

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] == arr[j] && arr[i] != -1) {
				arr[j] = -1;
				countOfSought++;
			}
		}

		if (arr[i] != -1) {
			arrRes[count] = arr[i];
			arrRes[count + 1] = countOfSought;
			count += 2;
		}
		arr[i] = -1;
		countOfSought = 1;
	}

	puts("\nResult:\n");
	for (int i = 0; i < sizeResult * 2; i++)
		if (i % 2 == 0)
			printf("\"%d\":", arrRes[i]);
		else
			printf("%d times\n", arrRes[i]);

	return arrRes;
}

int size(int* arr) {
	int tmp[N];
	int sizeResult = 0;

	for (int k = 0; k < N; k++) {
		tmp[k] = arr[k];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (tmp[i] == tmp[j] && tmp[i] != -1) {
				tmp[j] = -1;
			}
		}
		if (tmp[i] != -1) {
			sizeResult++;
			tmp[i] = 1;
		}

	}
	return sizeResult;
}

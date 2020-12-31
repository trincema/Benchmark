#include "MethodCallSameCompilationUnit.h"

int computeSameUnit(int i) {
	return i + 1;
}

int testSameUnit(int i) {
    return i % 3;
}

int execSameUnit() {
	int sum = 0;
	for(int l = 0; l < 1000; l++) {
		int i = 0;
		while(i < 2000000) {
			if (testSameUnit(i))
			sum += computeSameUnit(i);
			i++;
		}
	}
    return sum;
}

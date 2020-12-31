#include "MethodCallAnotherCompilationUnit.h"

int execOtherUnit() {
	int sum = 0;
	for(int l = 0; l < 1000; l++) {
		int i = 0;
		while(i < 2000000) {
			if (testOtherUnit(i))
			sum += computeOtherUnit(i);
			i++;
		}
	}
	return sum;
}

#include "MethodCallSameCompilationUnit.h"

static int computeStatic(int i) {
	return i + 1;
}

static int testStatic(int i) {
    return i % 3;
}

int execStatic() {
	int sum = 0;
	for(int l = 0; l < 1000; l++) {
		int i = 0;
		while(i < 2000000) {
			if (testStatic(i))
			sum += computeStatic(i);
			i++;
		}
	}
	return sum;
}

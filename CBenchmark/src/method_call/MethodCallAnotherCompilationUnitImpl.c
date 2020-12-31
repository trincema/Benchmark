#include "MethodCallAnotherCompilationUnit.h"

int computeOtherUnit(int i) {
	return i + 1;
}
int testOtherUnit(int i) {
    return i % 3;
}

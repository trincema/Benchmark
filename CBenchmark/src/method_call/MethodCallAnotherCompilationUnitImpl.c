/*
 * MethodCallImpl.c
 *
 *  Created on: 31 dec. 2020
 *      Author: trincema
 */

#include "MethodCallAnotherCompilationUnit.h"

int computeOtherUnit(int i) {
	return i + 1;
}

int testOtherUnit(int i) {
	return i % 3;
}

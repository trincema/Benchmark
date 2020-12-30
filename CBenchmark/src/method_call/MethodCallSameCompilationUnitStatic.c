/*
 ============================================================================
 Name        : CBenchmark.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "MethodCallSameCompilationUnit.h"

static int compute(int i) {
	return i + 1;
}

static int test(int i) {
	return i % 3;
}

int execStatic() {
    int sum = 0;
    for(int l = 0; l < 1000; l++) {
        int i = 0;
        while(i < 2000000) {
            if (test(i))
            sum += compute(i);
            i++;
        }
    }
    return sum;
}

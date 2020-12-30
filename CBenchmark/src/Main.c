/*
 * Main.c
 *
 *  Created on: 31 dec. 2020
 *      Author: trincema
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "method_call/MethodCallSameCompilationUnit.h"
#include "method_call/MethodCallAnotherCompilationUnit.h"
#include "method_call/MethodCallSameCompilationUnitStatic.h"

int main(void) {
    int reps = 5, i;
    double time_taken;
    int callSameCUnit[reps];
    int callOtherCUnit[reps];
    int callSameUnitStatic[reps];
    clock_t t;
    for (i = 0; i < reps; i++) {
    	t = clock();
    	execSameUnit();
    	time_taken = ((double)t)/CLOCKS_PER_SEC;
    	callSameCUnit[i] = (int)time_taken;

    	t = clock();
    	execOtherUnit();
    	time_taken = ((double)t)/CLOCKS_PER_SEC;
    	callOtherCUnit[i] = (int)time_taken;

    	t = clock();
		execStatic();
		time_taken = ((double)t)/CLOCKS_PER_SEC;
		callSameUnitStatic[i] = (int)time_taken;
    }

    // Log results to CSV file
    FILE *fp;
    fp = fopen("./method_call_results.csv", "w+");
    fputs("Call same C unit;Call other C unit;Call static\n", fp);
    for (i = 0; i < reps; i++) {
    	fprintf(fp, "%d;%d;%d\n", callSameCUnit[i], callOtherCUnit[i], callSameUnitStatic[i]);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

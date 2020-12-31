#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "method_call/MethodCallSameCompilationUnit.h"
#include "method_call/MethodCallAnotherCompilationUnit.h"
#include "method_call/MethodCallSameCompilationUnitStatic.h"
#include "method_call/MethodCall100Parameters.h"

int main(void) {
    int reps = 5, i;
    double time_taken;
    int callSameCUnit[reps];
    int callOtherCUnit[reps];
    int callSameUnitStatic[reps];
    int call100Params[reps];
    clock_t start, end;
    for (i = 0; i < reps; i++) {
    	start = clock();
    	execSameUnit();
    	end = clock();
    	time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    	callSameCUnit[i] = (int)time_taken;

    	start = clock();
    	execOtherUnit();
    	end = clock();
    	time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    	callOtherCUnit[i] = (int)time_taken;

    	start = clock();
		execStatic();
		end = clock();
		time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
		callSameUnitStatic[i] = (int)time_taken;

		start = clock();
		exec100Params();
		end = clock();
		time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
		call100Params[i] = (int)time_taken;
    }

    // Log results to CSV file
    FILE *fp;
    fp = fopen("./method_call_results.csv", "w+");
    fputs("Call same C unit;Call other C unit;Call static;Call 100 params\n", fp);
    for (i = 0; i < reps; i++) {
    	fprintf(fp, "%d;%d;%d;%d\n", callSameCUnit[i], callOtherCUnit[i], callSameUnitStatic[i], call100Params[i]);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

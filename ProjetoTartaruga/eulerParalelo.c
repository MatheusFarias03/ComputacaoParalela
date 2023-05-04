#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]) {

	int thread_count = strtol(argv[1], NULL, 10);
	#pragma omp parallel num_threads(thread_count)
	
	printf("Hello from process %d\n", omp_get_thread_num());

	return 0;
}

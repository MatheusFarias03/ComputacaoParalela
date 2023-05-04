#include <stdio.h>
#include <omp.h>

int main(int argc, char* argv[]) {

	printf("Hello from process %d", omp_get_thread_num());

	return 0;
}

#include <stdio.h>

int main(){
	float n1 = 10;
	float n2 = 7.5;
	float n3 = 8;
	float me = (n1 + n2 + n3) / 3;
	float ma = (n1 + n2*2 + n3*3 + me)/7;
	if (ma >= 9) printf("A");
	else if (ma >= 7.5 && ma < 9) printf("B");
	else if (ma >= 6 && ma < 7.5) printf("C");
	else if (ma >= 4 && ma < 6) printf("D");
	else printf("E");
	return 0;
}

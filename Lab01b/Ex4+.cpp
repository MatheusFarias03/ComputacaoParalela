#include <iostream>

int main(){
	std::string nome1 = "Joana";
	std::string nome2 = "Banana";
	int res = nome1.compare(nome2);
	if (res == 0) std::cout << nome1 << "\n" << nome1;
	else if (res < 0) std::cout << nome1 << "\n" << nome2;
	else std::cout << nome2 << "\n" << nome1;
	return 0;
}

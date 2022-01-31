#include <iostream>

int stepPerms(int n) {
	// Initial try -> doesnt give the correct answer
	// if(n == 1) {
	// 	return 1;
	// } else if (n == 2) {
	// 	return 3 + stepPerms(n-1);
	// } else if (n == 3) {
	// 	return 4 + stepPerms(n-2);
	// } else {
	// 	return stepPerms(n-1) + stepPerms(n-2) + stepPerms(n-3);
	// }
	//base case, when there is one step, there is one way 
	//to climb the stair case
	if(n == 1) {
		return 1;
	} else if (n == 2) {
		return 1 + stepPerms(n-1);
	} else if (n == 3) {
		return 2 + stepPerms(n-1);
	} else {
		return stepPerms(n-3) + stepPerms(n-2) + stepPerms(n-1);
	}
}

int main(int argc, char const *argv[])
{
	std::cout << "height: 1 -> " << stepPerms(1) << "\n";
	std::cout << "height: 2 -> " << stepPerms(2) << "\n";
	std::cout << "height: 3 -> " << stepPerms(3) << "\n";
	std::cout << "height: 5 -> " << stepPerms(5) << "\n";
	std::cout << "height: 7 -> " << stepPerms(7) << "\n";
	return 0;
}
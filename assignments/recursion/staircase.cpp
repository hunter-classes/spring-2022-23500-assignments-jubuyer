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

	//-------- After understanding base cases---------------
	//base case, when there is one step, there is one way
	//to climb the stair case
	if(n == 1) {
		return 1;
	} else if (n == 2) {
		return 1 + stepPerms(n-1);
	} else if (n == 3) {
		return 2 + stepPerms(n-1);
	} else {
		//how to find all ways to climb if there are more than 3 steps
		return stepPerms(n-3) + stepPerms(n-2) + stepPerms(n-1);
	}
}

int combo[100000];
int memo_stepPerms(int n) {
	if (combo[n] != 0) {
		return combo[n];
	} else if (n < 2) {
		combo[n] = 1;
	} else if (n == 2) {
		combo[n] = 2;
	} else if (n == 3) {
		combo[n] = 4;
	} else {
		combo[n] = memo_stepPerms(n-3) + memo_stepPerms(n-2) + memo_stepPerms(n-1);
	}

	return combo[n];
}

int main(int argc, char const *argv[])
{
	// std::cout << "height: 1 -> " << stepPerms(1) << "\n"; // 1
	// std::cout << "height: 2 -> " << stepPerms(2) << "\n"; // 2
	// std::cout << "height: 3 -> " << stepPerms(3) << "\n"; // 4
	// std::cout << "height: 5 -> " << stepPerms(5) << "\n"; // 13
	// std::cout << "height: 7 -> " << stepPerms(7) << "\n"; //44
	// std::cout << "height: 21 -> " << stepPerms(21) << "\n"; //still ok 223317
	// std::cout << "height: 31 -> " << stepPerms(31) << "\n"; //begins to slow
	// std::cout << "height: 41 -> " << stepPerms(41) << "\n"; //slow

	std::cout << "height: 1 -> " << memo_stepPerms(1) << "\n";
	std::cout << "height: 2 -> " << memo_stepPerms(2) << "\n";
	std::cout << "height: 3 -> " << memo_stepPerms(3) << "\n";
	std::cout << "height: 5 -> " << memo_stepPerms(5) << "\n";
	std::cout << "height: 7 -> " << memo_stepPerms(7) << "\n";
	std::cout << "height: 21 -> " << memo_stepPerms(21) << "\n"; //still ok
	std::cout << "height: 31 -> " << memo_stepPerms(31) << "\n"; //begins to slow
	std::cout << "height: 41 -> " << memo_stepPerms(41) << "\n"; //slow

	return 0;
}

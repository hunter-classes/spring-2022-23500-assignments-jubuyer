#include <iostream>
#include <vector>

void print_vector(std::vector<int> a){
  for (auto i : a){
    std::cout << i << ", ";
  }
  std::cout << "\n";
}


std::vector<int> qsort (std::vector<int> list) {
	//base case
	if (list.size() <= 1) {
		return list;
	}

	//select a pivot value.
	//for now just pick list[0]
	int pivot = list[0];
	//make 2 new vectors
	std::vector<int> lower, higher;

	//copy all the values < pivot value to lower
	for(int i = 1; i < list.size(); i++) {
		if(list[i] < pivot) {
			lower.push_back(list[i]);
		} else {
			higher.push_back(list[i]);
		}
	}
	//copy all the values >= pivot value to higher

	lower = qsort(lower);
	higher = qsort(higher);

	//copy everything back into list
	list.clear();
	for(auto j: lower) {
		list.push_back(j);
	}
	
	list.push_back(pivot);

	for(auto k: higher) {
		list.push_back(k);
	}
	//return the sorted list

	return list;
}

int main(int argc, char const *argv[])
{
	std::vector<int> test1 = {1, 2, 5, 6, 3, 7, 8, 1, 16, 19, 20, 2, 10, 15};
	print_vector(qsort(test1));

	std::vector<int> test = { 129, 12,124,53,1,5,0,-3,1,6 };
   	print_vector(test);
  
	print_vector(qsort(test));

	return 0;
}
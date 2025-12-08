#include "sort_testing.h"

void sort_selection(std::vector<int> &array){
	int idx_smallest {0};
	for (int i {0}; i < array.size(); i++){
		idx_smallest = i;
		for (int ii {i}; ii < array.size(); ii++){
			if (array[ii] < array[idx_smallest])
				idx_smallest = ii;
		}
		std::swap(array[i], array[idx_smallest]);
	}
}

/*
int main (){
	std::vector<int> array = {1, 0, 3, 4, 8, 2, 33, 800, -1};

	sort_selection(array);

	for (int i {0}; i < array.size(); i++)
		std::cout << array[i] << " ";
} */
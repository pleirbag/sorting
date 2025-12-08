
#include "sort_testing.h"

int pivot_partition(std::vector<int> &array, int start, int end)
{
	int pivot_idx {(std::rand() % (end - start + 1)) + start};
	if (pivot_idx != end)
		std::swap(array[pivot_idx], array[end]);
	int pivot {array[end]};


	int i {start};
	int ii {start};


	while (ii < end){
		if (array[ii] <= pivot)
			std::swap(array[ii], array[i++]);
		ii++;
	}

	std::swap(array[i], array[end]);

	/*int pivot {array[(std::rand() % (end - start + 1)) + start]};

	int	pivot_idx {start};

	for (int i {start}; i <= end; i++){
		if (array[i] < pivot)
			pivot_idx++;
	}


	std::swap(array[pivot], array[pivot_idx]);

	int	i {start};
	int ii {end};
	
	while (i < pivot_idx && ii > pivot_idx){
		while (array[i] <= pivot)
			i++;
		while (array[ii] > pivot)
			ii--;
		if (i < pivot_idx && ii > pivot_idx)
			std::swap(array[i++], array[ii--]);
	}*/
	return (i);
}

void recursive_sort(std::vector<int> &array, int start, int end){

	if (start >= end)
		return;

	int	pivot_idx {0};
	pivot_idx = pivot_partition(array, start, end);

	recursive_sort(array, start, pivot_idx - 1); //from start to pivot

	recursive_sort(array, pivot_idx + 1, end); //after pivot to end
}

void sort_q(std::vector<int> &array){
	srand(time(nullptr));
	recursive_sort(array, 0, array.size() - 1);
}

/*
int main (){	
	std::vector<int> array = {1, 27, 3, 2, 1, 99, 18, 5};

	sort_q(array);
	for (int i {0}; i < array.size(); i++)
		std::cout << array[i] << '\n';
}*/
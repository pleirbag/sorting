#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>

void sort_q(std::vector<int> &array);

std::vector<int>	vec_creator(int size){
	std::vector<int> unsorted(size);

	srand(time(0));
	for	(int i {0}; i < size; i++)
		unsorted[i] = rand();
	return (unsorted);
}

int main(int argc, char *argv[]){

	if (argc < 4){
		std::cout << "missing parameters. Program - Argument - size - loops" << "\n";
		return (-1);
	}

	int	number_elements {atoi(argv[2])};
	int	number_loops	{atoi(argv[3])};
	std::string sort_type {argv[1]};
	if (sort_type == "quick_sort"){
		std::vector<int> vec;
		for (int i {0}; i < number_loops; i++){
			vec = vec_creator(number_elements);
			std::vector<int> vec2 = vec;
			sort_q(vec);
			// std::sort(vec2.begin(), vec2.end());
			// if (vec != vec2){
			// 	std::cout << "Incorrect sorting \n size:" << number_elements << " sort type:" << argv[1] << '\n';
			// }
		}
	}
	else if (sort_type == "help"){
		std::cout << "quick_sort" << "\n";
		return (-1);
	}
	else {
		std::cout << "Not a recognized sorting algorythm, you can use \"help\" to see available algos" << "\n";
		return (-1);
	}

}
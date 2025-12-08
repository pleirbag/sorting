#include "sort_testing.h"

std::vector<int>	vec_creator(int size){
	std::vector<int> unsorted(size);

	srand(time(0));
	for	(int i {0}; i < size; i++)
		unsorted[i] = rand();
	return (unsorted);
}

void	run_time(int number_loops, std::chrono::time_point<std::chrono::steady_clock> time_0, std::chrono::time_point<std::chrono::steady_clock> time_end){
	auto micro_seconds = std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_0); 
	std::cout << "loop ran in " <<micro_seconds.count() << " microseconds" <<'\n';
	std::cout << "avarage runtime " << micro_seconds.count() / number_loops << " microseconds" << '\n';
	return;
}

void	sort_bench(void(*sortfunc)(std::vector<int>&), int number_elements, int number_loops){
		std::vector<int> vec;
		auto time_0 = std::chrono::steady_clock::now();
		for (int i {0}; i < number_loops; i++){
			vec = vec_creator(number_elements);
			std::vector<int> vec2 = vec;
			sortfunc(vec);
			}
		auto time_end = std::chrono::steady_clock::now();
		run_time(number_loops, time_0, time_end);
		/* // comment for older versions of functions, and testing functions comparing to std::sort
		std::vector<int> vec;
		auto time_0 = std::chrono::steady_clock::now();
		for (int i {0}; i < number_loops; i++){
			vec = vec_creator(number_elements);
			std::vector<int> vec2 = vec;
			sort_q(vec);
			// std::sort(vec2.begin(), vec2.end());
			// if (vec != vec2){
				// 	std::cout << "Incorrect sorting \n size:" << number_elements << " sort type:" << argv[1] << '\n';
				// }
			}
		auto time_end = std::chrono::steady_clock::now();
		run_time(number_loops, time_0, time_end);
		//https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c
		//changed to steady clock - reccomended on the comments, and while on linux they are an alias, wouldnt work on windows*/
}

int main(int argc, char *argv[]){

	if (argc < 4){
		std::cout << "missing parameters. Program - Argument - size - loops" << "\n";
		return (-1);
	}

	int	number_elements {atoi(argv[2])};
	int	number_loops	{atoi(argv[3])};
	if (number_loops == 0){
		std::cout << "Performed 0 loops in 0 microseconds" << '\n';
		return (0);
	}
	std::string sort_type {argv[1]};
	if (sort_type == "quick_sort")
		sort_bench(sort_q, number_elements, number_loops);
	else if (sort_type == "default_sort"){
		std::vector<int> vec;
		auto time_0 = std::chrono::steady_clock::now();
		for (int i {0}; i < number_loops; i++){
			vec = vec_creator(number_elements);
			std::vector<int> vec2 = vec;
			sort(vec.begin(), vec.end());
			}
		auto time_end = std::chrono::steady_clock::now();
		run_time(number_loops, time_0, time_end);
	}
	else if (sort_type == "selection_sort")
		sort_bench(sort_selection, number_elements, number_loops);
	else if (sort_type == "help"){
		std::cout << "quick_sort" << "\n";
		std::cout << "default_sort - c++ sort()" << "\n";
		return (0);
	}
	else {
		std::cout << "Not a recognized sorting algorythm, you can use \"help\" to see available algos" << "\n";
		return (-1);
	}

}
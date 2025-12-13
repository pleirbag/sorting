#include "sort_testing.h"

int max_value(std::vector<int> array){
	int biggest {0};
	int size {static_cast<int>(array.size())};
	for (int i {0}; i < size; i++){
		if (array[i] > biggest)
			biggest = array[i];
	}
	return (biggest);
}

void matrix_print(std::vector<std::vector<int>> matrix){
	for (int i {0}; i < matrix.size(); i++){
		for (int ii {0}; ii < matrix[i].size(); ii++)
			std::cout << matrix[i][ii] << ' ';
		std::cout << '\n';
	}
}

void least_significant_digit(int array_size, int exponent, std::vector<int> &array){
	int size_bucket {0};
	int bucket_number {0};
	std::vector<int> buckets(10);

	for (int i {0}; i < array_size; i++){
		buckets[(array[i] / exponent) % 10]++;
	}
	size_bucket = max_value(buckets);
	std::vector<std::vector<int>> matrix(10, std::vector<int>(size_bucket + 1));
	for (int i {0}; i < matrix.size(); i++)
	matrix[i][0] = 1;
	for (int i {0}; i < array_size; i++){
		bucket_number = (array[i] / exponent) % 10;
		matrix[bucket_number][matrix[bucket_number][0]] = array[i];
		matrix[bucket_number][0]++;
	}
	std::cout << matrix.size() << " " << size_bucket << '\n';
	bucket_number = 0;
	for (int i {0}; i < array_size; 0){
		for (int ii {1}; matrix[bucket_number][0] > 1; ii++){
			matrix[bucket_number][0]--;
			array[i] = matrix[bucket_number][ii];
			matrix[bucket_number][ii] = 0;
			i++;
		}
		bucket_number++;
	}
	matrix.clear();
}

void sort_radix_b10(std::vector<int> &array){
	int	array_size {static_cast<int>(array.size())};
	int	exponent {1};
	int	biggest {max_value(array)};
	
	while (biggest / exponent > 0){
		least_significant_digit(array_size, exponent, array);
		exponent *= 10;
	}

}
/*
int main(){
	std::vector array = {10, 11, 12, 13, 4, 14, 1, 5, 24, 204, 54};

	sort_radix_b10(array);
	for (int i {0}; i < array.size(); i++)
		std::cout << array[i] << '\n';
}*/
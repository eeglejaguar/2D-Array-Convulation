
#include <iostream>
#include <vector>

void print_matrix(int matrix[3][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 2)
				std::cout << matrix[i][j];
			else
				std::cout << matrix[i][j] << " , ";
		}
		std::cout << std::endl;
	}
}

void print_line()
{
	std::cout << std::endl;
}







int main()
{
	// generate randon square matrix
	int input_matrix[3][3] = { {2,4,6},{8,10,12},{14,16,18} };    // squareMatrix(5);
	// kernel matrix
	int kernel_matrix[3][3] = { {1,2,3},{4,5,6},{7,8,9} };

	std::cout << " Input Matrix" << std::endl;

	// Displaying input matrix
	print_matrix(input_matrix);

	print_line();

	std::cout << " Kernel Matrix" << std::endl;

	// Displaying Kernel Matrix
	print_matrix(kernel_matrix);

	std::cout << std::endl;

	// Flipping The Mask or Kernel Metrix Horizontally
	for (int i = 0; i < 3; i++)
	{
		std::swap(kernel_matrix[i][0], kernel_matrix[i][2]);
	}

	// Flipping The Mask or Kernel Metrix Vertically
	for (int i = 0; i < 3; i++)
	{
		std::swap(kernel_matrix[0][i], kernel_matrix[2][i]);
	}

	print_matrix(kernel_matrix);

	print_line();

	std::cout << " Convulated Matrix";

	print_line();

	// Min value of Input Index
	int min = 0;
	// Max value of Input Index
	int max = 2;

	// Result of each Index Of Resultant Matrix will be stored here 
	int sum = 0;
	
	int result[3][3] = { {0,0,0},{0,0,0},{0,0,0} };

	int rows_in_input_matrix = 3;
	int cols_in_input_matrix = 3;
	int rows_in_kernel_matrix = 3;
	int cols_in_kernel_matrix = 3;

	//std::cout << "i" << "+" << "k -1 = "  << "x" << " , " << "j" << "+" << "l" << "-1 = " << "y" << std::endl;


	for (int i = 0; i < rows_in_input_matrix; i++) {
		for (int j = 0; j < cols_in_input_matrix; j++) {
			
			for (int k = 0; k < rows_in_kernel_matrix; k++) {
				for (int l = 0; l < cols_in_kernel_matrix; l++) {

					int x = (i + k) - 1;
					int y = (j + l) - 1;

					//std::cout << i << "+" << k << "-1 = " << x << " , " << j << "+" << l << "-1 = " << y << std::endl;

					// condition to avoid multiplication with elements outside the matrix
					if (x >= 0 && x < 3 && y >= 0 && y < 3) {
						result[i][j] += input_matrix[x][y] * kernel_matrix[k][l];



					}
				}
			}
		}
	}



	print_line();

	print_matrix(result);

}	
	





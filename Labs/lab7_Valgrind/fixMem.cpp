/* File 	: fixMem.cpp
 * Date		: 02/26/2020
 *
 * AUTHORS 	:
 * 			Emil Thomas 	ver 1.0
 * 			Bryson Mrosko		ver 1.1	(Fixed the memory leak by running
 * 									 valgrind)
 *
 *	TODO:
 *		1.Compile and run :
 *			g++ -std=c++11 -g fixMem.cpp -o driver.out
 *			./driver.out
 *		2.Run valgrind : valgrind ./driver.out
 *		3.Fix all the memory leak by changing code. Confirm by running valgrind
 *		4.Change YOURNAME in the AUTHORS Part(Only if you can fix the mem leak)
 *		5.Upload the changed and fixed file to ecampus
 *
 * ******************************************************************************/


#include <iostream>
using namespace std;

//Square Grid
class Grid_2D {

private:
	int row_col;	//ROW and COL dimension
	int **ptr;		//pointer to data array

public:

	//Constructor: Creates N*N grid, initilize it with init_val
	Grid_2D(int N, int init_val) : row_col{N}, ptr{nullptr}
	{
		//Create the 2D data array in HEAP
		ptr = new int* [N];
		for (int i = 0; i < N; i++) {
			ptr[i] = new int [N];
		}

		//Fill the Grid with Default value init_val
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ptr[i][j] = init_val;
			}
		}
	}

	//Destructor
	~Grid_2D()
	{
		//deallocate internal arrays
		for(int i = 0; i < row_col; i++)
		{
			delete[] ptr[i];
		}
		//deallocate the 2D data array
		delete[] ptr;
	}

	friend ostream& operator<<(ostream &out, const Grid_2D &grd);

};

//Prints the grid values
ostream& operator<<(ostream &out, const Grid_2D &grd)
{
		for (int i = 0; i < grd.row_col; i++) {
			for (int j = 0; j < grd.row_col; j++) {
				out << grd.ptr[i][j] << "\t" ;
			}
			out << endl;
		}
}

constexpr int DIM = 5;		//Size of the GRID = DIM * DIM
constexpr int VAL = 7;		//Default initial value

int main()
{
	Grid_2D *m1 = new Grid_2D(DIM, VAL);
	cout << *m1;
	delete m1;
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;
class Matrix {
	int rows, cols;
	vector<vector<int>> mat;
public:
	Matrix(int r = 3, int c = 3) : rows(r), cols(c) {
		mat.resize(rows, vector<int>(cols, 0));
	}
	void input()
	{
		for (int i = 0;i < rows;i++)
		{
			for (int j = 0;j < cols;j++)
			{
				cin>>mat[i][j];
			}
		}
	}
	void display() const {
		cout << "Matrix Contents:\n";
		for (const auto& row : mat) {
			for (int val : row) {
				cout << val << " ";
			}
			cout << "\n";
		}
	}
	vector<int>& operator[](int index)
	{
		if (index < 0 || index >= rows)
		{
			throw out_of_range("Row index out of range");
		}
		return mat[index];
	}
	const vector<int>& operator[](int index) const 
	{
		if (index < 0 || index >= rows)
		{
			throw out_of_range("Row index out of range");
		}
		return mat[index];
	}
};
int main()
{
	int r, c;
	cout << "Enter matrix dimensions (rows cols): ";
	cin >> r >> c;
	Matrix matrix(r, c);
	cout << "Enter the matrix elements " << endl;
	matrix.input();
	// Display the matrix
	matrix.display();
	// Access individual elements using overloaded []
	int row, col;
	cout << "Enter row and column index to access an element: ";
	cin >> row >> col;
	try {
		cout << "Element at (" << row << ", " << col << "): " << matrix[row][col] << endl;
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	return 0;
}

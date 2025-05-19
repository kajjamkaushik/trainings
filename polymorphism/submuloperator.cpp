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
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
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
	Matrix operator-(Matrix m2)
	{
		Matrix m3;
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				m3.mat[i][j] = mat[i][j] - m2.mat[i][j];
			}
		}
		return m3;
	}
	Matrix operator*(Matrix m2)
	{
		Matrix m3(rows,m2.cols);
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				m3.mat[i][j] = 0;
				for (int k = 0;k < 3;k++)
				{
					m3.mat[i][j] += mat[i][k] * m2.mat[k][j];
				}
			}
		}
		return m3;
	}
};
int main()
{
	cout << "Matrix Multiplication ::" << endl;
	cout << "\nEnter the contents of matrix 1" << endl;
	Matrix m1, m2,m3,m4;
	m1.input();
	cout << "\nEnter the contents of matrix 2" << endl;
	m2.input();
	cout << "\nMatrix mulptication operation and product matrix is below" << endl;
	m3 = m1 * m2;
	m3.display();
	cout << "\nMatrix subtraction operation and difference matrix is below" << endl;
	m4 = m1 - m2;
	m4.display();
	cout << "\n MAtrix 1 contents " << endl;
	m1.display();
	cout << "\n MAtrix 2 contents " << endl;
	m2.display();
	return 0;
}

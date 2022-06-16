#include "Mat.h"
#include <iostream>
using namespace std;

Mat::Mat()
{
	rows = 1;
	cols = 1;
	AllocMatrix();
}

Mat::Mat(const Mat& A)
{
	this->rows = A.rows;
	this->cols = A.cols;
	if (rows * cols != 0)
	{
		this->matrix = new int[rows * cols];

		for (int i = 0; i < (rows * cols); ++i)
			this->matrix[i] = A.matrix[i];
	}
	else
		matrix = NULL;
}


Mat::Mat(int m, int n): rows(m), cols(n)
{
	AllocMatrix();
}


Mat::Mat(int m, int n, int* vector): rows(m), cols(n)
{
	AllocMatrix();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(matrix + i * n + j) = *(vector + i * n + j);
		}
	}
}


Mat Mat::operator()(int a)
{
	if (a >= this->rows)
	{
		cout << "Mat(x) out of range" << endl;
		exit(-2);
	}
	Mat* m = new Mat(1, this->cols);
	for (int i = 0; i < this->cols; i++)
	{
		m->matrix[i] = this->matrix[a * this->cols + i];
	}
	return *m;
}

void Mat::Resize(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	AllocMatrix();
}

Mat& Mat::operator=(const Mat& A)
{
	// TODO: 在此处插入 return 语句
	if (this == &A)
		return *this;
	this->Resize(A.rows, A.cols);

	for (int i = 0; i < (cols * rows); i++)
		matrix[i] = A.matrix[i];
	return *this;
}

void Mat::AllocMatrix()
{
	matrix = new int[rows * cols];
	for (int i = 0; i < rows * cols; i++)
	{
		*(matrix + i) = 0;
	}
	if (NULL == matrix)
	{
		cout << "allocation failed!" << endl;
		exit(-1);
	}
}


Mat::~Mat()
{
	rows = 0;
	cols = 0;
	if (matrix != NULL)
	{
		delete[] this->matrix;
	}
}


Mat operator+(Mat& m, Mat& n)
{
	if (m.cols == n.cols)
	{
		if (m.rows == n.rows)
		{
			Mat* result = new Mat(m.rows, m.cols);
			for (int i = 0; i < m.rows * m.cols; i++)
			{
				*(result->matrix + i) = *(m.matrix + i) + *(n.matrix + i);
			}
			return *result;
		}
		else if (m.rows == 1)
		{
			Mat* result = new Mat(n.rows, n.cols);
			for (int i = 0; i < n.rows; i++)
				for (int j = 0; j < m.cols; j++)
				{
					*(result->matrix + i * n.cols + j) = *(m.matrix + j) + *(n.matrix + i * n.cols + j);
				}
			return *result;
		}
		else if (n.rows == 1)
		{
			Mat* result = new Mat(m.rows, m.cols);
			for (int i = 0; i < m.rows; i++)
				for (int j = 0; j < m.cols; j++)
				{
					*(result->matrix + i * n.cols + j) = *(n.matrix + j) + *(m.matrix + i * n.cols + j);
				}
			return *result;
		}
	}
	else
	{
		cout << "The tensor size needs to be the same!" << endl;
		exit(-99);
	}
}

Mat operator-(Mat& m, Mat& n)
{
	if (m.cols == n.cols)
	{
		if (m.rows == n.rows)
		{
			Mat* result = new Mat(m.rows, m.cols);
			//Mat result;
			for (int i = 0; i < (m.rows * m.cols); i++)
			{
				*(result->matrix + i) = *(m.matrix + i) - *(n.matrix + i);
			}
			//Mat result(m.rows, m.cols, nResult);
			return *result;
		}
		else if (m.rows == 1)
		{
			Mat* result = new Mat(n.rows, n.cols);
			for (int i = 0; i < n.rows; i++)
			{
				for (int j = 0; j < n.cols; j++)
				{
					*(result->matrix + i * n.cols + j) = *(m.matrix + j) - *(n.matrix + i * n.cols + j);
				}
			}

			return *result;
		}
		else if (n.rows == 1)
		{
			Mat* result = new Mat(m.rows, m.cols);
			for (int i = 0; i < m.rows; i++)
				for (int j = 0; j < m.cols; j++)
				{
					*(result->matrix + i * n.cols + j) = *(n.matrix + j) - *(m.matrix + i * m.cols + j);
				}

			return *result;
		}
	}
	else
	{
		cout << "The tensor size needs to be the same!" << endl;
		exit(-99);
	}
}


ostream& operator<<(ostream& out, Mat& m)
{
	out << "[";
	// TODO: 在此处插入 return 语句
	for (int i = 0; i < m.rows; i++)
	{
		if (i > 0)
		{
			out << " ";
		}
		for (int j = 0; j < m.cols; j++)
		{
			out << *(m.matrix + i * m.cols + j);
			if (j < m.cols - 1)
				out << ", ";
		}
		if (i < m.rows - 1)
			out << ";" << endl;
	}
	out << "]";
	return out;
}

bool operator>=(Mat& a, Mat& b)
{
	if (a.cols == b.cols && a.rows == a.rows)
	{
		int r = a.rows;
		int c = a.cols;
		Mat tmp = a - b;
		bool* compare = new bool[r];
		bool flag = true;
		for (int i = 0; i < r * c; i++)
		{
			if (a.matrix[i] < b.matrix[i])
			{
				flag = false;
			}
		}
		return flag;
	}
	else
	{
		exit(-2);
	}
}

bool operator<=(Mat& a, Mat& b)
{
	if (a.cols == b.cols && a.rows == a.rows)
	{
		int r = a.rows;
		int c = a.cols;
		Mat tmp = a - b;
		//bool* compare = new bool[r];
		bool flag = true;
		for (int i = 0; i < r * c; i++)
		{
			if (a.matrix[i] > b.matrix[i])
			{
				flag = false;
			}
		}
		return flag;
	}
	else
	{
		exit(-2);
	}
}

Mat operator<(Mat& a, Mat& b)
{
	return Mat();
}

#pragma once
#include <ostream>

class Mat
{
public:
	int rows, cols;
	int* matrix;
	Mat(int m, int n);
	Mat(int m, int n, int* vector);
	Mat();
	Mat(const Mat& A);
	friend Mat operator+(Mat& m, Mat& n);
	friend Mat operator-(Mat& m, Mat& n);
	~Mat();
	friend std::ostream& operator<<(std::ostream& out, Mat& m);
	//Mat& operator= (Mat& a);
	friend bool operator>=(Mat& a, Mat& b);
	Mat operator()(int a);
	void Resize(int rows, int cols);
	friend bool operator <=(Mat& a, Mat& b);
	Mat& operator =(const Mat& A);

private:
	void AllocMatrix();
};

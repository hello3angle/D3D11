#include <iostream>

#include "Libs.h"

using namespace std;
using namespace DirectX;

int* CreateMatrix(int orderNum);
void* DeleteMatrix(int* matrixPtr);
void TransposeMatrix(int* matrixPtr, int orderNum);
void PrintMatrix(int* matrixPtr, int orderNum, const char* matrixName);

ostream& operator<<(ostream& os, FXMVECTOR v)
{
	XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ", " << dest.w << ")";
	return os;
}

ostream& operator<<(ostream& os, CXMMATRIX m)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			os << m(i, j) << "\t";

		os << endl;
	}

	return os;
}

int main()
{
	int orderNum = 0;
	do
	{
		cout << "Order of a square matrix?: ";
		cin >> orderNum;
		if (orderNum < 1)
			continue;
	} while (orderNum < 1);

	cout << orderNum << " * " << orderNum << " matrix created!" << endl;

	// malloc
	/*int* matrix2D = (int*)malloc(sizeof(int) * orderNum * orderNum);

	free(matrix2D);
	matrix2D = nullptr;*/

	int* matPtr = nullptr;
	matPtr = CreateMatrix(orderNum);
	
	TransposeMatrix(matPtr, orderNum);

	matPtr = (int*)DeleteMatrix(matPtr);

	return 0;
}

int* CreateMatrix(int orderNum)
{
	int* matrixPtr = new int[orderNum * orderNum];
	int num;

	// Input elements
	for (int i = 0; i < orderNum; i++)
	{
		for (int j = 0; j < orderNum; j++)
		{
			cout << "A" << i << j << ": ";
			cin >> num;
			matrixPtr[i * orderNum + j] = num;
		}
	}

	// Print elements
	PrintMatrix(matrixPtr, orderNum, "Matrix");

	return matrixPtr;
}

void* DeleteMatrix(int* matrixPtr)
{
	if (matrixPtr == nullptr)
	{
		cout << "Matrix pointer is null!" << endl;
		return nullptr;
	}

	delete[] matrixPtr;
	matrixPtr = nullptr;
	cout << "Matrix deleted!" << endl;
	
	return nullptr;
}

void TransposeMatrix(int* matrixPtr, int orderNum)
{
	int num = *(matrixPtr - 4) / sizeof(int) / orderNum;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (i < j)
			{
				int temp = matrixPtr[i * orderNum + j];
				matrixPtr[i * orderNum + j] = matrixPtr[j * orderNum + i];
				matrixPtr[j * orderNum + i] = temp;
			}
		}
	}

	PrintMatrix(matrixPtr, orderNum, "Transpose");

	return;
}

void InverseMatrix(int* matrixPtr, int orderNum)
{
	// No. of order
	//int num = *(matrixPtr - 4) / sizeof(int) / orderNum;

	// a00, a01, a02, a03
	// a10, a11, a12, a13
	// a20, a21, a22, a23
	// a30, a31, a32, a33
	
	// a00 * a11, a12, a13
	//       a21, a22, a23
	//       a31, a32, a33

	//       a11 * a22, a23
	//             a32, a33



	//int detA = 0;
	//while (orderNum > 2)
	//{
	//	for (int i = 0; i < orderNum; i++)
	//	{
	//		int* minor = new int[orderNum - 1 * orderNum - 1];
	//		for (int j = 0; j < orderNum; j++)
	//		{
	//			for (int k = 0; k < orderNum; k++)
	//			{
	//				if (j != 0 && k != i)
	//				{
	//					minor[j * k] = matrixPtr[];
	//				}
	//				
	//			}
	//			
	//		}

	//		matrixPtr[i];
	//	}
	//}

//		detA += matrixPtr[blockNum] * det * (blockNum % 2 == 0 ? 1 : -1);
}

void PrintMatrix(int* matrixPtr, int orderNum, const char* matrixName)
{
	cout << matrixName << " =\n";
	for (int i = 0; i < orderNum; i++)
	{
		cout << "\t\t";
		for (int j = 0; j < orderNum; j++)
		{
			cout << matrixPtr[i * orderNum + j] << "\t";
		}
		cout << "\n";
	}

	cout << endl;
}
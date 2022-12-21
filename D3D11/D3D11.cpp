#include <iostream>

#include "Libs.h"
#include "CPrivateVector.h"

using namespace std;
using namespace DirectX;

bool Equals(float lhs, float rhs, float Epsilon)
{
	return fabs(lhs - rhs) < Epsilon ? true : false;
}

int main()
{
	cout.precision(8);
	if (!XMVerifyCPUSupport())
	{
		cout << "Math library not supported" << endl;
		return 0;
	}

	XMVECTOR u = XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);
	XMVECTOR n = XMVector3Normalize(u);
	float LU = XMVectorGetX(XMVector3Length(n));
	
	// Verify if LU == 1
	cout << LU << endl;
	if (LU == 1.0f)
		cout << "Length 1" << endl;
	else
		cout << "Length not 1" << endl;

	// Verify if LU to the power of n == 1
	float powLU = powf(LU, 1.0e6f);
	cout << "LU^(10^6) = " << powLU << endl;

	// Correct differential
	const float Epsilon = 0.001f;
	if (Equals(1.0f, LU, Epsilon))
		LU = 1.0f;
	cout << "Compensated: " << LU << endl;

	return 0;
}
#include <iostream>

#include "Libs.h"
#include "CPrivateVector.h"

using namespace std;
using namespace DirectX;

ostream& operator << (ostream& os, FXMVECTOR v)
{
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
	return os;
}

int main()
{
	cout.setf(ios_base::boolalpha);
	if (!XMVerifyCPUSupport())
	{
		cout << "Math library not supported" << endl;
		return 0;
	}

	XMVECTOR n = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	XMVECTOR v = XMVectorSet(-2.0f, 1.0f, -3.0f, 0.0f);
	XMVECTOR w = XMVectorSet(0.707f, 0.707f, 0.0f, 0.0f);

	// Operator +
	XMVECTOR a = u + v;

	// Operator -
	XMVECTOR b = u - v;

	// operator *
	XMVECTOR c = 10.0f * u;

	// Length of Vector; ||u||
	XMVECTOR L = XMVector3Length(u);

	// Unit Vector; d = u / ||u||
	XMVECTOR d = XMVector3Normalize(u);

	// Dot Product; s = u dot v
	XMVECTOR s = XMVector3Dot(u, v);

	// Cross Product; e = u x v
	XMVECTOR e = XMVector3Cross(u, v);

	// Projection and Perpendicular
	XMVECTOR projW;
	XMVECTOR perpW;
	XMVector3ComponentsFromNormal(&projW, &perpW, w, n);

	// If proj + perp == original vector
	bool equal = XMVector3Equal(projW + perpW, w) != 0;
	bool notEqual = XMVector3NotEqual(projW + perpW, w) != 0;

	// Angle between proj and perp
	XMVECTOR angleVec = XMVector3AngleBetweenVectors(projW, perpW);
	float angleRadians = XMVectorGetX(angleVec);
	float angleDegrees = XMConvertToDegrees(angleRadians);

	// Print
	cout << "v                    = " << v << endl;
	cout << "u                    = " << u << endl;
	cout << "w                    = " << w << endl;
	cout << "n                    = " << n << endl;
	cout << "a = u + v            = " << a << endl;
	cout << "b = u - v            = " << b << endl;
	cout << "c = 10 * u           = " << c << endl;
	cout << "d = u / ||u||        = " << d << endl;
	cout << "e = u x v            = " << e << endl;
	cout << "L = ||u||            = " << L << endl;
	cout << "s = u dot v          = " << s << endl;
	cout << "projW                = " << projW << endl;
	cout << "perpW                = " << perpW << endl;
	cout << "projW + perpW == w   = " << equal << endl;
	cout << "projW + perpW != w   = " << notEqual << endl;
	cout << "angle                = " << angleDegrees << endl;



	return 0;
}
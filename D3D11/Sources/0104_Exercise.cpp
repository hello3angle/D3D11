#include <iostream>

#include "Libs.h"

using namespace std;
using namespace DirectX;

ostream& operator<<(ostream& os, FXMVECTOR v)
{
	XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ", " << dest.w << ")";
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

	XMVECTOR p = XMVectorSet(2.0f, 2.0f, 1.0f, 0.0f);
	XMVECTOR q = XMVectorSet(2.0f, -0.5f, 0.5f, 0.1f);
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 4.0f, 8.0f);
	XMVECTOR v = XMVectorSet(-2.0f, 1.0f, -3.0f, 2.5f);
	XMVECTOR w = XMVectorSet(0.0f, XM_PIDIV4, XM_PIDIV2, XM_PI);

	cout << "MXVectorAbs(v)        = " << XMVectorAbs(v) << endl;
	cout << "MXVectorCos(w)        = " << XMVectorCos(w) << endl;
	cout << "MXVectorLog(u)        = " << XMVectorLog(u) << endl;
	cout << "MXVectorExp(p)        = " << XMVectorExp(p) << endl;

	cout << "XMVectorPow(u, p)     = " << XMVectorPow(u, p) << endl;
	cout << "XMVectorSqrt(u)       = " << XMVectorSqrt(u) << endl;

	cout << "XMVectorSwizzle(u, 2, 2, 1, 3) = "
		<< XMVectorSwizzle(u, 2, 2, 1, 3) << endl;
	cout << "XMVectorSwizzle(u, 2, 1, 0, 3) = "
		<< XMVectorSwizzle(u, 2, 1, 0, 3) << endl;

	cout << "XMVectorMultiply(u, v) = "
		<< XMVectorMultiply(u, v) << endl;
	cout << "XMVectorSturate(q)     = "
		<< XMVectorSaturate(q) << endl;
	cout << "XMVectorMin(p, v)      = " << XMVectorMin(p, v) << endl;
	cout << "XMVectorMax(p, v)      = " << XMVectorMax(p, v) << endl;


	return 0;
}
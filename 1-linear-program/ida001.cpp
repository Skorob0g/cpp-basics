#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double x, y, z1, z2;
	cout << "Write x ";
	cin >> x;
	cout << "Write y ";
	cin >> y;

	z1 = pow(cos(x), 4) + pow(sin(y), 2) + pow(sin(2*x), 2) * (1/4) - 1;

	z2 = sin(y + x) * sin(y - x);
	
	cout << "z1 = " << z1 << endl << "z2 = " << z2 << endl;
	return 0;
}

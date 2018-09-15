#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	double a, b, c, x1, x2, dx, f = 0;
	cout << "Write a, b, c ";
	cin >> a >> b >> c;
	cout << "Write x(beg), x(end), dx ";
	cin >> x1 >> x2 >> dx;
	cout << "-------------------------" << endl << setw(10) << "X" << setw(10) << "F" << endl << "-------------------------" << endl;

	for (double x = x1; x < x2; x += dx){
		if ((a < 0) & (x != 0))
			f = a * pow(x, 2) + pow(b, 2) * x ;
		else
			if ((a > 0) & (x == 0))
				f = x - (a / (x - c));
			else
				f = 1 + (x / c);

		if (!((((int) a) | ((int) b)) & (((int) b) | ((int) c))))
			cout << "|" << setw(10) << x <<"|" << setw(10) <<  f << "|" << endl;
		else
			cout << "| " << setw(10) << x <<"|" << setw(10) << (int) f << "|" << endl;
		f = 0;
	}

	return 0;
}
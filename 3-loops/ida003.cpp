#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	double x1, x2, dx;
	long double a1, a2, eps;
	const long NMAX = 1000000000000;
	cout << "Write x1, x2, dx, eps ";
	cin >> x1 >> x2 >> dx >> eps;
	cout <<endl << "---------------------------------------------------"<< endl << "|"  << setw(13) << "X|" << setw(13) << "arctg(x)|" << setw(11) << "n|" << setw(13) << "P-d arctg(x)|" << endl << "---------------------------------------------------" << endl;
	int k;

	for(double x = x1; x < x2; x += dx){ 
		a2 = x; 
		for(long n = 1; n < NMAX; n++){
			k = n;
			a1 = pow((-1), n) * pow(x, (2 * n + 1)) / (2 * n + 1) + a2;
			if(abs(abs(a1) - abs(a2)) < eps)
				break;
			a2 = a1;
			if ((NMAX - n) < 2){
				cout << "too small exp";
				return 1;
			}
		}
		cout << "|" <<setw(12) <<  x << "|" << setw(12) << a1 << "|" << setw(10) << k << "|" << setw(12) << atan(x) << "|" << endl;
	} 
	cout << "---------------------------------------------------" << endl;
	return 0;
}

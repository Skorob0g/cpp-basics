#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

long double mcalc(double x, long double a2, long n){
	return pow((-1), n) * pow(x, (2 * n + 1)) / (2 * n + 1) + a2;
}

long double my_arctg(double x, long double eps){
	const long NMAX = 1000000000000;
	long double a2 = x, a1;
	for(long n = 1; n < NMAX; n++){
		a1 = mcalc(x, a2, n);
		if (abs(abs(a1) - abs(a2)) < eps)
			return a1;
		a2 = a1;
	}
	return a1; //вывод при недостаточной точности
}

int main(){
	double x1, x2, dx;
	long double a1, a2, eps;
	const long NMAX = 1000000000000;
	cout << "Write x1, x2, dx, eps ";
	cin >> x1 >> x2 >> dx >> eps;
	cout <<endl << string(40, '-') << endl << "|"  << setw(13) << "X|" << setw(13) << "arctg(x)|" << setw(13) << "P-d arctg(x)|" << endl << string(40, '-') << endl;
	int k;

	for(double x = x1; x < x2; x += dx){ 
		a1 = my_arctg(x, eps);

		cout << "|" <<setw(12) << fixed << x << "|" << setw(12) << fixed <<  a1 << "|" << setw(12) << fixed << atan(x) << "|" << endl;
	} 
	cout << string(40, '-') << endl;
	return 0;
}

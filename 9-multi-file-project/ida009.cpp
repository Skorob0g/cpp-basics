#include "myheader.hpp"
using namespace std;

int main(){
	int n;
	cout << "Write n, n > 0 ";
	cin >> n;
	if (n <= 0){
		cout << "error, n <= 0" << endl;
		return 1;
	}
	double *a = new double[n];
	cout << "input the array ";

	readarr(a, n);
	printarr(a, n);

	absmax(a, n);
	sumbpos(a, n);
    badsort(a, n);

	printarr(a, n);
	delete [] a;
	cout << endl;
	return 0;
}

#include <iostream>
#define EPS 0.00000001

using namespace std;

double fabs(double a){
	if (a < EPS)
		return -1 * a;
	else
		return a;
}

void badsort(double * a, int n){
	for (int j = 0; j < n; j++)
		for (int i = 1; i < n - j; i++)
			if ((fabs(a[i - 1]) < EPS) && (fabs(a[i]) > EPS))
				swap(a[i - 1], a[i]);
}

int main(){
	int n, iabsmax = 0;
	bool pos1 = false, pos2 = false;
	cout << "Write n ";
	cin >> n;
	double a[n], absmax, sum = 0;
	cout << "input the array ";
	cin >> a[0];
	absmax = fabs(a[0]);

	for (int c = 1; c < n; c++){
		cin >> a[c];
		if (fabs(a[c]) > absmax){
			absmax = fabs(a[c]);
			iabsmax = c;
		}

		if (!pos1){
			if (a[c] > EPS)
				pos1 = true;
		}
		else 
			if (!pos2){
				if (a[c] > EPS)
					pos2 = true;
				else
					sum += a[c];
			}

	}

	badsort(a, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	cout << endl << "Abs max = " << a[iabsmax] << endl;
	// first task done!

	if (pos1 && pos2)
		cout << "sum = " << sum << endl;
	else
		cout << "there are no 2 positive elements" << endl; 
	// second task done!
	return 0;
}

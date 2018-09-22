#include "myheader.hpp"
void badsort(double * a, int n){

    for (int j = 0; j < n; j++)
		for (int i = 1; i < n - j; i++)
			if ((fabs(a[i - 1]) < EPS) && (fabs(a[i]) > EPS))
				std::swap(a[i - 1], a[i]);
}

void absmax(double * a, int n){
	double absmax = -1;
	int iabsmax = 0;
	for (int i = 0; i < n; i++){
		if (fabs(a[i]) > absmax){
			absmax = fabs(a[i]);
			iabsmax = i;
		}
	}
	cout << endl << "Abs max = a["<< iabsmax <<"] = " << a[iabsmax] << endl;
}

void sumbpos(double * a, int n){
	bool pos1 = false, pos2 = false;
	double sum = 0;
	for (int i = 0; i < n; i++){
		if (!pos1){
			if (a[i] > EPS)
				pos1 = true;
		}
		else
			if (!pos2){
				if (a[i] > EPS)
					pos2 = true;
				else
					sum += a[i];
			}
	}
	if (pos1 && pos2)
		cout << "sum = " << sum << endl;
	else
		cout << "there are no 2 positive elements" << endl;
}

void printarr(double * a, int n){
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

void readarr(double * a, int n){
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

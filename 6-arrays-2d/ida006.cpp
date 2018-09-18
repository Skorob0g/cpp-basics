#include <iostream>
#include <iomanip>
#include <cmath>
#define N 10

using namespace std;

int main(){
	double a[N][N], b[N][N];
	cout << "Write a matrix 10 x 10" << endl;

	for (int j = 0; j < N; j++)
		for(int i = 0; i < N; i++)
			cin >> a[i][j];

	double sum = 0, sumabs = 0;
	int k = 0;

	for (int j = 0; j < N; j++){
		for (int i = 0; i < N; i++){	//out-of-border check
			if ((i - 1) >= 0){
				sum += a[i - 1][j];
				k++;
			}
			if ((i + 1) < N){
				sum += a[i + 1][j];
				k++;
			}
			if ((j - 1) >= 0){
				sum += a[i][j - 1];
				k++;
			}
			if ((j + 1) < N){
				sum += a[i][j + 1];
				k++;
			}
			b[i][j] = sum / k;
			sum = k = 0;
			cout << setw(5) << fixed << b[i][j] << "|";

			if (j > i)
				sumabs += fabs(a[i][j]);
		}
		cout << endl;
	}

	cout << "sum os abs = " << sumabs << endl;
	return 0;
}

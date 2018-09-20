#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#define N 10

using namespace std;

int main(){
	double a[N][N], b[N][N];
	int q;
	cout << "Choose input: (1 - file, 2 - long one) ";
	cin >> q;
	if (q == 1){
		string s;
		cout << "Write file name ";
		cin >> s;
		ifstream fin(s);
		if (!fin.is_open()){
			cout << "can't open file" << endl;
			return 1;
		}

		for (int j = 0; j < N; j++)
	        for(int i = 0; i < N; i++)
		        fin >> a[i][j];

		fin.close();
	}
	else
		if (q == 2){
			cout << "Write a matrix 10 x 10" << endl;

			for (int j = 0; j < N; j++)
				for(int i = 0; i < N; i++)
					cin >> a[i][j];
		}
		else{
			cout << "wrong q!" << endl;
			return 2;
		}

	double sum = 0, sumabs = 0;
	int k = 0;

	for (unsigned int j = 0; j < N; j++){
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
			if (((i - 1) >= 0) && ((j - 1) >= 0)){
				sum += a[i - 1][j - 1];
				k++;
			}
			if (((i + 1) < N) && ((j - 1) >= 0)){
				sum += a[i + 1][j - 1];
				k++;
			}
			if (((i + 1) < N) && ((j + 1) < N)){
				sum += a[i + 1][j + 1];
				k++;
			}
			if (((i - 1) >= 0) && ((j + 1) < N)){
				sum += a[i - 1][j + 1];
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

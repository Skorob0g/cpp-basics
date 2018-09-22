#include <iostream>
#include <iomanip>
#include <string>
#define N 8

using namespace std;

struct train{
	string dest;
	unsigned int number;
	string time;
};

int main(){
	train a[N], buff;
	cout << "write destination, number, leaving time " << endl;
	for (int c = 0; c < N; c++)
		cin >> a[c].dest >> a[c].number >> a[c].time;

	for (int i = 0; i < N - 1; i++){
		for (int j = 0; j < N - 1; j++){
			if (a[j].number > a[j + 1].number){
				buff = a[j];
				a[j] = a[j + 1];
				a[j + 1] = buff;
			}
		}
	}

	cout << endl;
	unsigned int num;
    cout << "write the number of the train ";
    cin >> num;
	for (int k = 0; k < N; k++){
		if (num == a[k].number){
			cout << a[k].dest << " | " << a[k].number << " | " << a[k].time << endl;
			break;
		}
		if (k == N -1)
			cout << "no such train" << endl;
	}

	return 0;
}

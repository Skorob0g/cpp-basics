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

void inputTrain(train *a){
	for (int i = 0; i < N; i++){
		getline(cin, a[i].dest, ';');
		cin >> a[i].number >> a[i].time;
	}
}

void sortTrain(train *a){
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N -i -1; j++)
			if (a[j].number > a[j + 1].number)
                swap(a[j], a[j + 1]);
}

void searchTrain(train *a, int num){
	for (int i = 0; i < N; i++){
		if (num == a[i].number){
			cout << "destanation: "<< a[i].dest << endl;
			cout << "train number: "<< a[i].number << endl;
			cout << "departure time: "<< a[i].time << endl;
			break;
		}
		if (i == N -1)
			cout << "no such train" << endl;
	}
}

void infinite(train *a){
	int num;
	cout << "write the train number (to quit wite -1)" << endl;
	bool endFlag = false;
	while(!endFlag){
		cin >> num;
		if (num == -1)
			break;
		searchTrain(a, num);
	}
}

int main(){
	train a[N], buff;
	cout << "write destination;(you have to use \";\") number, leaving time " << endl;
	inputTrain(a);
	sortTrain(a);
	cout << endl;
	infinite(a);
	return 0;
}

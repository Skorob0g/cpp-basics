#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	cout << "write file name ";
	string filename, s;
	cin >> filename;
	ifstream fin(filename);
	if (!fin.is_open()){
		cout << "can't open file!" << endl;
		return 1;
	}

	int n, k = 0;
	cout << "write quantity of words ";
	cin >> n;

	bool fileEndFlag = false;
	while(getline(fin, s, '.')){
		for (unsigned int i = 1; i < s.length(); i++){
			if (s[i] == ' ')
				k++;
		}

		if (k == (n - 1))
			cout << s << endl;
		k = 0;
	}

	fin.close();
	return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
void toFile(int);

int main()
{
	string in;
	ifstream fin("chaos.in");
	getline(getline(fin, in), in);
	fin.close();

	vector<int> abcdk;
	int n;
	istringstream stream(in);
	while (stream >> n)
		abcdk.push_back(n);

	bool tofile = false;
	vector<int> a = abcdk;
	for (int i = 0; i < abcdk[4]; i++) {
		if (a[0] * a[1] < a[2]) {
			toFile(0);
			tofile = true;
			break;
		}
		else {
			if ((a[0] * a[1] - a[2]) > a[3])
				a[0] = a[3];
			else
				a[0] = a[0] * a[1] - a[2];
		}
	}
	if(!tofile)
		toFile(a[0]);
}
void toFile(int start) {
	ofstream fout("chaos.out");
	fout << start;
	fout.close();
}

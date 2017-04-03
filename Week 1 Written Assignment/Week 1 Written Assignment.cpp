// Week 1 Written Assignment.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <fstream>

using namespace std;


unsigned int helperMemory[4][100];
unsigned int memoizeAcker(unsigned int m, unsigned int n);

/*
//int Acker(int m, int n);

 int Acker( int m,  int n) {

	if (m == 0) {
		return n + 1;
	}
	if (m > 0 && n == 0) {
		return Acker(m - 1, 1);
	}
	if (m > 0 && n > 0)
		return Acker(m - 1, Acker(m, n - 1));
}
*/
unsigned int memoizeAcker(unsigned int m, unsigned int n) {

	//TODO: Save values in an array to be read back in time of need.

	cout << "memoizeAcker Initiated and m = " << m << " n = " << n << endl;
	if (m == 0) {
		cout << "First if (m==0) called and m = " << m << " n = " << n << endl;
		return n + 1;
	}
	if (n == 0) {
		cout << "Second if (n==0) was called and m = " << m << " n = " << n << endl;
	return memoizeAcker(m - 1, 1);
}

	if (helperMemory[m][n] != 0) {
		cout << "Third if (helperMemory[m][n] != 0) was called and m = " << m << " n = " << n  << endl;
		return helperMemory[m][n];
	}
	
	else {
		cout << "Else was called and m = " << m << " n = " << n << endl;
		helperMemory[m][n] = memoizeAcker(m - 1, memoizeAcker(m, n - 1));
		return helperMemory[m][n];
	}
}

int main()
{
	unsigned int m;
	unsigned int n;

	for (int i = 0; i < 5; i++) {
		for (int l = 0; l < 101; l++) {
			helperMemory[i][l] = { 0 };
		}
	}

/*
	//Top 3 numbers to find
	cout << "Some values for the Ackermann function" << endl << endl;
	m = 3;	
	n = 20;
	cout << "Ackermann(" << m << ", " << n << ") = " << memoizeAcker(m, n) << endl;
	m = 4; 
	n = 0;
	cout << "Ackermann(" << m << ", " << n << ") = " << memoizeAcker(m, n) << endl;
	m = 4; 
	n = 1;
	cout << "Ackermann(" << m << ", " << n << ") = " << memoizeAcker(m, n) << endl << endl;
*/

	//Running through the list of possible options from 0 to 4 for m and from 0 to 20 for n.
	for (m = 0; m < 5; m++) {
		for (n = 0; n < 21; n++) {
			cout << "\nAckermann(" << m << ", " << n << ") = " << memoizeAcker(m, n) << endl << endl;
		}
		cout << endl;
	}

	cout << "Finished";
	cin.get();
	return 0;
}
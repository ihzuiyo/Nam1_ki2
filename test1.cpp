#include<cstdlib>
#include<iostream>
using namespace std;
int main(){
	int x,y;
	cout << "Please enter two numbers: ";
	cin >> x >> y;
	int sum = x + y;
	cout << "Sum = " << sum << endl;
	return EXIT_SUCCESS;
}
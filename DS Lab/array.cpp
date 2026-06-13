#include<iostream>
using namespace std;
int main(){
int mimo[5], a, b, i; // declaration of a new array
mimo[2] = 75;         // store 75 in the third element of mimo
a = mimo[2];          // copy/assign a with the third value of mimo
cin >> mimo[2]; // read a value for the third element of mimo
/* read 5 values for the five elements of mimo sequentially */
for(i=0; i<5; i++)
	cin >> mimo[i];
/* print 5 values for the five elements of mimo sequentially */
for(i=0; i<5; i++)
	cout << mimo[i];
/* some more interesting accesses */
a = 4;
mimo[2] = a;
mimo[a] = 3; //mimo[4] = 3
b = mimo[a-2] + 2;	//use of expression in index;  b= mimo [4-2]+2=6
mimo[mimo[a]] = mimo[2] + b; // mimo[3]= 4 + 6=10
cout << endl;
cout << mimo[3];
}

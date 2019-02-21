/* Kickstart Round A

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;

int length(int n)
{
	int length;

	for(; n != 0; n /= 10, length++);

	return length;
}

int firstDigit(int n)
{
	while( n >= 10 )
		n /= 10;

	return n;
}

int integerOfEights(int length) {
	char eights[length];
	for(int i = 0; i < length; i++) {
		eights[i] = '8';
	}
	return atoi(eights);
}

int main () 
{
	int t;
	cin >> t;
	cout << t << " Test Cases: " << endl;
	for( int i = 1 ; i <= t ; i++ )
	{	
		int num, len, sum = 0, result = 0;
		string n;
		cin >> n;
		cout << n;
		num = stoi(n);
		len = n.length();
		cout << "len: " << len;
		for (int j = 0; j < len; j++) {
			int digit = n[j] - '0';
			cout << endl;
			cout << "digit: " << digit << endl;
			if (digit % 2 == 1 and digit != 9) {
				int upper = (digit + 1) * pow(10, len-(j+1));
				cout << "upper: " << upper << " ";
				int lower = (digit - 1) + integerOfEights(len-(j+1));
				cout << "lower: " << lower << " " << endl;
				int remainder = num - sum;
				cout << "remainder: " << remainder << endl;
				cout << "sum: " << sum << endl;
				result = min(upper-remainder, remainder-lower);
				break;
			}
			else if (digit == 9) {
				result = num - ((digit - 1) + integerOfEights(len - (j+1)));
				break;
			}
			sum += digit * pow(10,len-(j+1));
		}
		cout << "result: " << result << endl;
	}
	return 0;
}
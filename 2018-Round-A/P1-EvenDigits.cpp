/* Kickstart Round A

*/

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string>
using namespace std;

long long int integerOfEights(int length) {
	char eights[length];
	for(int i = 0; i < length; i++) {
		eights[i] = '8';
	}
	return atoll(eights);
}

int main () 
{
	int t;
	cin >> t;
	for( int i = 1 ; i <= t ; i++ )
	{	
		long long int num, len, result = 0;
		string n;
		cin >> n;
		num = stoll(n);
		len = n.length();

		int firstOddDigitPos = -1;
		for (int j = 0; j < len; j++) {
			if (n[j] % 2 == 1) {
				firstOddDigitPos = j;
				break;
			}
		}
		if (firstOddDigitPos == -1) {
			cout << "Case #" << i << ": " << 0 << endl;
			continue;
		}

		long long int remain;
		string r;
		for (int j = firstOddDigitPos; j < len; j++) {
			r += n[j];
		}
		remain = stoll(r);
		int digit = r[0] - '0';
		long long int lower = ((digit - 1) * pow(10, r.length()-1)) + integerOfEights(r.length()-1);

		if (digit == 9) {
			result = remain - lower;
		}
		else {
			long long int upper = (digit+ 1) * pow(10, r.length()-1);
			result = min(upper-remain, remain-lower);
		}

		cout << "Case #" << i << ": " << result << endl;
	}
	return 0;
}
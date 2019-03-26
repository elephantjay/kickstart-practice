/* Kickstart Round A
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	for( int i = 1; i <= t; i++ )
	{
		cout << "Case #" << i << ": ";

		double n, k;
		cin >> n >> k;
		
		vector<double> values;
		double sum= 0;
		for(int j = 0; j < n; j++) {
			double value;
			cin >> value;
			values.push_back(value);
			sum += value;
		}

		double e = sum/n, count = 0;

		sort(values.begin(), values.end());

		for (int l = 0; l < k; l++) {
			while (values.at(count) < e) {

				sum -= values.at(count);
				count++;
			}
			e = (e * count / n + sum / n);
		}
		cout << fixed;
		cout << setprecision(6);
		cout << e << endl;
	}

	return 0;
}

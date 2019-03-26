/* Kickstart Round A

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool desc (int i, int j) { return (i>j); }

int main () 
{
	int t;
	cin >> t;
	for( int i = 1 ; i <= t ; i++ )
	{	
		cout << "Case #" << i << ": ";
		int n, p;
		cin >> n;
		cin >> p;

		vector<int> a;

		for(int j = 0; j < n; j++) {
			int skill;
			cin >> skill;
			a.push_back(skill);

		}

		sort(a.begin(), a.end(), desc);

		// use a prefix sum to calculate the sum from an array quicker
		vector<int> prefixSumVector;
		int prefixSum;
		for(int j = 0; j < n; j++) {
			prefixSum += a.at(j);
			prefixSumVector.push_back(prefixSum);
		}

		vector<int> best;
		for(int j = 0; j < (n-p+1); j++) {
			int base = a.at(j);
			int score = 0;
			// the score for a given base
			score = ((p-1) * base) - (prefixSumVector.at(j+(p-1)) - prefixSumVector.at(j));
			cout << "base: " << base << "\t" << "score: " << score << endl;
			best.push_back(score);
		}

		vector<int>::iterator result = min_element(begin(best), end(best));
		if (end(best) != result) cout << *result << '\n';

	}

	return 0;

}
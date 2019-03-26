/* Kickstart Round A
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge (vector<float> * a, int low, int mid, int high) {
	int h, i, j;
	vector <float> b;
	h = low;
	i = low;
	j = mid + 1;
	
	while ( (h <= mid) && (j <= high) ) {
		if (a[h] <= a[j]) {
			b.push_back(a->at(h));
		} else {
			b.push_back(a->at(j));
		}
		i++;
	}
	if (h > mid) {
		for(int k = j; k <= high; k++) {
			b.push_back(a->at(k));
		}
	} else {
		for(int k = h; k <= mid; k++) {
			b.push_back(a->at(k));
		}
	}
	a = &b;
}

void merge_sort(vector<float> * a, int low, int high) {
	int mid = low + (high -low)/2;
	merge_sort(a, low, mid);
	merge_sort(a, mid+1, high);
	merge(a, low, mid, high);
}

float sum(vector<float> values) {
	float sum;
	for(vector<float>::iterator it = values.begin(); it != values.end(); ++it) {
		sum += *it;
	}
	return sum;
}

int main() 
{
	int t;
	cin >> t;
	for( int i = 1; i <= t; i++ )
	{
		cout << "Case #" << i << ": ";

		float n, k;
		cin >> n >> k;
		
		// Put the values into a vector of floats
		vector<float> values;

		for(int j = 0; j < n; j++) {
			cout << "for loop: ";
			float value;
			cin >> value;
			values.push_back(value);
			cout << "j: " << j << " " << "value: " << value << endl;
		}

		float e0, e;

		e0 = sum(values) / n;
		e = max(e0, )
		
		else {
			merge_sort(&values, 1, values.size());
			for(vector<float>::iterator it = values.begin(); it != values.end(); ++it) {
				cout << *it << " ";
			}
		}
	}

	return 0;
}

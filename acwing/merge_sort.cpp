#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;
const int MM = 1e5 + 10;
int n;
vector <int> q(MM, 0);
vector <int> temp(MM, 0);

void merge_sort(int l, int r){
	if (l >= r){return;}

	int mid = (l + r)/2;
	merge_sort(l, mid); merge_sort(mid + 1, r);
	
	int k = 0; int i = l; int j = mid + 1;
	temp.clear();
	while(i <= mid && j <= r){
		if (q[i] < q[j]){temp.push_back(q[i]); ++i;}
		else {temp.push_back(q[j]); ++j;}
	}	
	while(i <= mid){temp.push_back(q[i]); ++i;}
	while(j <= r){temp.push_back(q[j]); ++j;}
	for (int i = l; i <= r; ++i){
		q[i] = temp[k];
		++k;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i){cin >> q[i];}
	merge_sort(0, n - 1);
	for (int i = 0; i < n; ++i){cout << q[i] << " ";}
	cout << endl;


	return 0;
}

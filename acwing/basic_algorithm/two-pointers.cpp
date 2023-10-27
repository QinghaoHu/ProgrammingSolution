#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;
const int MM = 1e5 + 10;
int n, q, k;
vector <int> arr(MM);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	while(q--){
		int x; cin >> x;
		int l = 0, r = n - 1;
		while(l < r){
			int mid = (l + r)/2;
			if (arr[mid] >= x) r = mid;
			else l = mid + 1;
		}
		if (arr[l] != x){cout << "-1 -1" << endl;}
		else {
			cout << l << " ";
			int l = 0, r = n - 1;
			while(l < r){
				int mid = (l + r + 1)/2;
				if (arr[mid] <= x)l = mid;
				else r = mid - 1;
			}
			cout << l << endl;
		}
	}

	return 0;
}

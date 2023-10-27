#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;
int tc, q, cnt = 1;
vector <vector <int> > relation;
unordered_map <string, int> mymap;
vector <int> depth;
int highest = INT_MIN;

void bfs(int src){
	vector <bool> isV(q + 1, false);
	isV[src] = true;
	queue <int> myq;
	myq.push(src);
	while(!myq.empty()){
		int cur = myq.front(); myq.pop();
		for (int nxt : relation[cur]){
			if (!isV[nxt]){
				isV[nxt] = true;
				depth[nxt] = depth[cur] + 1;
				highest = max (depth[nxt], highest);
				myq.push(nxt);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> tc;
	while(tc--){
		mymap.clear();
		cin >> q;
		highest = INT_MIN;
		cnt = 1; relation.clear(); depth.clear();depth.resize(q + 1, 0);
		relation.resize(q + 1);
		vector <string> names;
		for (int i = 0; i < q; ++i){
			string name;
			cin >> name;
			if (mymap.find(name) == mymap.end()){
				mymap[name] = cnt;
				++cnt;
			}
			names.push_back(name);
		}
		relation[mymap[names[q - 1]]].push_back(mymap[names[0]]);
		for (int i = 0; i < q - 1; ++i){
			relation[mymap[names[i]]].push_back(mymap[names[i + 1]]);
		}
		bfs (mymap[names[q - 1]]);
		cout << q*10 - 20*highest << endl;
	}

	return 0;
}

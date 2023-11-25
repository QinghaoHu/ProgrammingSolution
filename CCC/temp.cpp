#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef std::pair <int, int> PII;

using namespace std;
const int INF = 0x3f3f3f3f, MM = 110;
int n, m;
struct node
{
	int aim, cost, ris;
};
vector <PII> dist(MM, {INF, 1});
bool isV[MM];
vector <vector <node> > g(MM); 

void prime()
{
	for (int i = 0; i < n; i ++)
	{
		int t = -1;
		for (int j = 1; j <= n; ++ j)
		{
			if (!isV[j] && (t == -1 || dist[t].first > dist[j].first))
			{
				t = j;
			}
		}
		if (i && dist[t].first == INF)break;
		isV[t] = true;
		for (auto j : g[t])
		{
			if (dist[j.aim].second == 1 && j.ris == 1)
			{
				dist[j.aim].first = min(dist[j.aim].first, j.cost);
			}	else if (dist[j.aim].second == 0 && j.ris == 1)
			{
				continue;
			}	else if (dist[j.aim].second == 1 && j.ris == 0)
			{
				dist[j.aim].first = j.cost; dist[j.aim].second = 0;
			}	else 
			{
				dist[j.aim].first = min(dist[j.aim].first, j.cost);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		node ae, be;
		ae.aim = b, ae.cost = c, ae.ris = d;
		be.aim = a, be.cost = c, be.ris = d;
		g[a].push_back(ae);
		g[b].push_back(be);
	}
	prime();
	int cost = 0; int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		cost += dist[i].first;
		ans += dist[i].second;
	}
	cout << ans << ' ' << cost << endl;
	for (int i = 1; i <= n; ++i)
	{
		cout << dist[i].first << " " ;
	}
	cout << endl;

	return 0;
}

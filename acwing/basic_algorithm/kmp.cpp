#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;
const int MM = 1e6 + 10;
int n, m;
char p[MM], s[MM];
int ne[MM];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p + 1 >> m >> s + 1;
    for (int i = 2, j = 0; i <= n; ++i)
    {
        while(j && p[i] != p[j + 1]){j = ne[j];}
        if (p[i] == p[j + 1]){++j;}
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; ++i)
    {
        while(j && s[i] != p[j + 1]){
            j = ne[j];
        }
        if (s[i] == p[j + 1]){++j;}
        if (j == n){cout << i - n << " "; j = ne[j];}
    }

    return 0;
}


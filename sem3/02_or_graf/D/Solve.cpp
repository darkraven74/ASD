#include <stdio.h>
#include <string>
#include <stack>
#include <vector>
#pragma comment(linker, "/STACK:32000000")
using namespace std;

int m, n, x, y;
vector< vector < int > > a;
vector<int> used;

void Dfs (int v, int c) {
	used[v] = c;
	for (int i = 0; i < a[v].size(); i++) {
		if (used[a[v][i]] == 0) {
			if (c == 1)
				Dfs(a[v][i], 2);
			if (c == 2)
				Dfs(a[v][i], 1);
		}
		else {
			if (used[a[v][i]] == c) {
				printf("NO");
				exit(0);
			}
		}
	}
}

int main() {
	freopen ("bipartite.in", "r", stdin);
	freopen ("bipartite.out", "w", stdout);
	scanf("%d %d", &n, &m);
	a.resize(n);
	used.resize(n);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		a[x - 1].push_back(y - 1);
		a[y - 1].push_back(x - 1);
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			Dfs(i, 1);
		}
	}
	printf("YES");
	return 0;
}
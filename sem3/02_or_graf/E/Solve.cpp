#include <stdio.h>
#include <string>
#include <stack>
#include <vector>
#pragma comment(linker, "/STACK:32000000")
using namespace std;

int m, n, x, y, timer, count, color, maxcolor;
vector< vector < int > > a;
vector<int> used, anwser, tin, tup;

void Dfs (int v, int p) {
	used[v] = 1;
	tin[v] = timer;
	tup[v] = timer;
	timer++;
	for (int i = 0; i < a[v].size(); i++) {
		int to = a[v][i];
		if (to == p) 
			continue;
		if (used[to] == 1)
			tup[v] = min(tup[v], tin[to]);
		else {
			Dfs(to, v);
			tup[v] = min(tup[v], tup[to]);
		}
	}
}

void Paint(int v) {
	anwser[v] = color;
	for (int i = 0; i < a[v].size(); i++) {
		if (anwser[a[v][i]] == 0) {
			if (tup[a[v][i]] > tin[v]) {
				maxcolor++;
				color = maxcolor;
				Paint(a[v][i]);
			}
			else {
				color = anwser[v];
				Paint(a[v][i]);
			}
		}
	}
}

int main() {
	freopen ("bicone.in", "r", stdin);
	freopen ("bicone.out", "w", stdout);
	scanf("%d %d", &n, &m);
	a.resize(n);
	used.resize(n);
	tin.resize(n);
	tup.resize(n);
	anwser.resize(n);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		a[x - 1].push_back(y - 1);
		a[y - 1].push_back(x - 1);
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			Dfs(i, -1);
		}
	}

	for (int i = 0; i < n; i++) {
		if (anwser[i] == 0) {
			maxcolor++;
			color = maxcolor;
			Paint(i);
			
		}
	}
	printf("%d\n", maxcolor);
	for (int i = 0; i < n; i++) {
			printf("%d ", anwser[i]);
	}
	
	return 0;
}
#include <stdio.h>
#include <string>
#include <stack>
#include <vector>
#pragma comment(linker, "/STACK:32000000")
using namespace std;

int m, n, x, y, timer, count;
vector< vector < int > > a;
vector<int> used, anwser, tin, tup;

void Dfs (int v, int p) {
	used[v] = 1;
	tin[v] = timer;
	tup[v] = timer;
	timer++;
	int chld = 0;
	for (int i = 0; i < a[v].size(); i++) {
		int to = a[v][i];
		if (to == p) 
			continue;
		if (used[to] == 1)
			tup[v] = min(tup[v], tin[to]);
		else {
			Dfs(to, v);
			tup[v] = min(tup[v], tup[to]);
			if ((tup[to] >= tin[v]) && (p != -1) && (anwser[v] == 0)) {
				count++;
				anwser[v] = 1;
			}
			chld++;
		}
	}
	if ((p == -1) && (chld > 1) && (anwser[v] == 0)) {
		count++;
		anwser[v] = 1;
	}
}

int main() {
	freopen ("points.in", "r", stdin);
	freopen ("points.out", "w", stdout);
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
	printf("%d\n", count);
	for (int i = 0; i < anwser.size(); i++) {
		if (anwser[i] == 1)
			printf("%d ", i + 1);
	}
	
	return 0;
}
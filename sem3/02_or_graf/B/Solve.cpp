#include <stdio.h>
#include <string>
#include <stack>
#include <vector>
#pragma comment(linker, "/STACK:32000000")
using namespace std;

int m, n, x, y, timer, count;
struct my_pair {
	int data, id;
};
vector< vector < my_pair > > a;
vector<int> used, anwser, tin, tup;

void Dfs (int v, int p) {
	used[v] = 1;
	tin[v] = timer;
	tup[v] = timer;
	timer++;
	for (int i = 0; i < a[v].size(); i++) {
		int to = a[v][i].data;
		if (to == p) 
			continue;
		if (used[to] == 1)
			tup[v] = min(tup[v], tin[to]);
		else {
			Dfs(to, v);
			tup[v] = min(tup[v], tup[to]);
			if (tup[to] > tin[v]) {
				count++;
				anwser[a[v][i].id] = 1;
			}
		}
	}
}

int main() {
	freopen ("bridges.in", "r", stdin);
	freopen ("bridges.out", "w", stdout);
	scanf("%d %d", &n, &m);
	a.resize(n);
	used.resize(n);
	tin.resize(n);
	tup.resize(n);
	anwser.resize(m + 1);
	my_pair t;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		t.data = y - 1;
		t.id = i + 1;
		a[x - 1].push_back(t);
		t.data = x - 1;
		a[y - 1].push_back(t);
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			Dfs(i, -1);
		}
	}
	printf("%d\n", count);
	for (int i = 0; i < anwser.size(); i++) {
		if (anwser[i] == 1)
			printf("%d ", i);
	}
	
	return 0;
}
#include <stdio.h>
#include <string>
#include <stack>
#include <vector>
#pragma comment(linker, "/STACK:32000000")
using namespace std;

int m, n, x, y, color = 1;
vector< vector <int> > a;
vector<int> used, anwser;
void Dfs(int v) {
	used[v] = 1;
	for (int i = 0; i < a[v].size(); i++) {
		if (used[a[v][i]] == 0) {
			Dfs(a[v][i]);
		}
	}
	used[v] = 2;
	anwser[v] = color;
}

int main() {
	freopen ("components.in", "r", stdin);
	freopen ("components.out", "w", stdout);
	scanf("%d %d", &n, &m);
	a.resize(n);
	used.resize(n);
	anwser.resize(n);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);	
		a[x - 1].push_back(y - 1);
		a[y - 1].push_back(x - 1);
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			Dfs(i);
			color++;
		}
	}
	printf("%d\n", color - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", anwser[i]);
	}
	
	return 0;
}
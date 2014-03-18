#include <stdio.h>
#include <string>
#include <stack>
#include <vector>
#pragma comment(linker, "/STACK:32000000")
using namespace std;

int m, n, ans, x, y;
vector< vector <int> > a;
vector<int> used;
vector<int> nex;
void Print_ans(int v, int i) {
	printf("%d ", i + 1);
	if (i != v) {
		i = nex[i];
		Print_ans(v, i);
	}
}
void Dfs(int v) {
	used[v] = 1;
	for (int i = 0; i < a[v].size(); i++) {
		if (used[a[v][i]] == 0) {
			nex[v] = a[v][i];
			Dfs(a[v][i]);
		} else if (used[a[v][i]] == 1) {
			if (v == a[v][i]) {
				printf("NO");
				exit(0);
			}
			printf("YES\n");
			nex[v] = a[v][i];
			Print_ans(v, a[v][i]);
			exit(0);
		}
	}
	used[v] = 2;
}

int main() {
	freopen ("cycle.in", "r", stdin);
	freopen ("cycle.out", "w", stdout);
	scanf("%d %d", &n, &m);
	a.resize(n);
	used.resize(n);
	nex.resize(n);
	for (int i = 0; i < n; i++) {
		nex[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);	
		a[x - 1].push_back(y - 1);
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			Dfs(i);
		}
	}
	printf("NO");
	return 0;
}
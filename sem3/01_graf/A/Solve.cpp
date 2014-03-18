#include <stdio.h>
#include <string>
#include <stack>
#include <vector>
#pragma comment(linker, "/STACK:32000000")
using namespace std;

int m, n, ans, x, y, timer;
stack<int> st;
vector< vector <int> > a;
vector<int> used;
void Dfs(int v) {
	used[v] = 1;
	for (int i = 0; i < a[v].size(); i++) {
		if (used[a[v][i]] == 0) {
			Dfs(a[v][i]);
		} else if (used[a[v][i]] == 1) {
			printf("-1");
			exit(0);
		}
	}
	used[v] = 2;
	st.push(v);
}

int main() {
	freopen ("topsort.in", "r", stdin);
	freopen ("topsort.out", "w", stdout);
	scanf("%d %d", &n, &m);
	a.resize(n);
	used.resize(n);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);	
		a[x - 1].push_back(y - 1);
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			Dfs(i);
		}
	}
	while (!st.empty()) {
		ans = st.top() + 1;
		st.pop();
		printf("%d ", ans);
	}
	
	return 0;
}
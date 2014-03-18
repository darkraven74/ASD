#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#pragma comment(linker, "/STACK:32000000")
using namespace std;

int m, n, cycle, ans, color = 1, x, y;
stack<int> st;
vector< vector <int> > a;
vector< vector <int> > a2;
vector<int> used;
vector<int> anwser;
void Dfs(int v) {
	used[v] = 1;
	for (int i = 0; i < a[v].size(); i++) {
		if (used[a[v][i]] == 0) {
			Dfs(a[v][i]);
		}
	}
	used[v] = 2;
	st.push(v);
}

void Dfs2(int v) {
	used[v] = 1;
	anwser[v] = color;
	for (int i = 0; i < a2[v].size(); i++) {
		if (used[a2[v][i]] == 0) {
			Dfs2(a2[v][i]);
		}
	}
	used[v] = 2;
}

int main() {
	freopen ("cond.in", "r", stdin);
	freopen ("cond.out", "w", stdout);
	scanf("%d %d", &n, &m);
	a.resize(n);
	a2.resize(n);
	used.resize(n);
	anwser.resize(n);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);	
		a[x - 1].push_back(y - 1);
		a2[y - 1].push_back(x - 1);
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			Dfs(i);
		}
	}
	for (int i = 0 ; i < n; i++) {
		used[i] = 0;
	}

	while (!st.empty()) {
		x = st.top();
		st.pop();
		if (used[x] == 0) {
			Dfs2(x);
			color++;
		}
	}
	printf("%d \n", --color);
	for (int i = 0; i < n; i++) {
		printf("%d ", anwser[i]);	
	}
	return 0;
}
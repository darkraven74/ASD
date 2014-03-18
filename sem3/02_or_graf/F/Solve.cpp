#include <stdio.h>
#include <string>
#include <stack>
#include <vector>
#pragma comment(linker, "/STACK:32000000")
using namespace std;

int m, n, x, y, timer, count, color;
struct my_pair {
	int data, id;
};
vector< vector < my_pair > > a;
vector<int> used, anwser, tin, tup;
stack < int > st;

void Dfs (int v, int p) {
	used[v] = 1;
	tin[v] = timer;
	tup[v] = timer;
	timer++;
	int chld = 0;
	for (int i = 0; i < a[v].size(); i++) {
		int to = a[v][i].data;
		if (to == p) 
			continue;
		if (used[to] == 1) {
			tup[v] = min(tup[v], tin[to]);
			if (tin[to] < tin[v]) {
				st.push(a[v][i].id);
			}
		}
		else {
			st.push(a[v][i].id);
			Dfs(to, v);
			tup[v] = min(tup[v], tup[to]);
			if ((tup[to] >= tin[v]) /*&& (p != -1)*/) {
				color++;
				while (st.top() != a[v][i].id) {
					anwser[st.top()] = color;
					st.pop();
				}
				anwser[a[v][i].id] = color;
				st.pop();
			}
			chld++;
		}
	}
	//if ((p == -1) && (chld > 1)) {
	//	count++;
	//	anwser[v] = 1;
	//}
}
int main() {
	freopen ("biconv.in", "r", stdin);
	freopen ("biconv.out", "w", stdout);
	scanf("%d %d", &n, &m);
	a.resize(n);
	used.resize(n);
	tin.resize(n);
	tup.resize(n);
	anwser.resize(m + 1);
	my_pair t;

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		t.id = i + 1;
		t.data = y - 1;
		a[x - 1].push_back(t);
		t.data = x - 1;
		a[y - 1].push_back(t);
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			Dfs(i, -1);
		}
	}
	printf("%d\n", color);
	for (int i = 1; i < m + 1; i++) {
		printf("%d ", anwser[i]);
	}
	
	return 0;
}
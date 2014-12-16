#include <iostream>
#include <vector>
using namespace std;
 
const int MAXN = 60; /* slightly more than the max. number of stars on the tree */
 
bool adj[MAXN][MAXN], vis[MAXN];
int n, e; /* numbers of lights, stars resp. */
 
class ChristmasTreeDecoration {
public:
  void mark(int v) {
    vis[v] = true;
    for (int i = 0; i < n; i++) {
      if (!vis[i] && adj[v][i])
        mark(i);
    }
  }
 
  int solve(vector <int> col, vector <int> x, vector <int> y) {
    n = col.size();
    e = x.size();
    
    for (int i = 0; i < e; i++) {
      int a = x[i] - 1;
      int b = y[i] - 1;
      if (col[a] != col[b])
        adj[a][b] = adj[b][a] = true;
    }
    
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        mark(i);
        c++;
      }
    }
    return c - 1;
  }
};

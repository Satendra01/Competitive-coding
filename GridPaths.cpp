#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
#define fo(k,n) for( k=0;k<n;k++)
#define fo(l,m) for(l=0;l<m;l++)
const int M = 1000000007;

int main() {
  int n,k,l;
  cin >> n;
  vs s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  vvi a(n, vi(n));
  fo(k,n)
  fo(l,n)cout<<a[k][l];cout<<endl;
  a[0][0] = s[0][0] == '.';
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '*') continue;
      if (i > 0) (a[i][j] += a[i - 1][j]) %= M;
      if (j > 0) (a[i][j] += a[i][j - 1]) %= M;
    }
  cout << a[n - 1][n - 1] << "\n";
}
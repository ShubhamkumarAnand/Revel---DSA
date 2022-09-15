/*
   * Author :  imskanand
   ^ Time   : 14 September 2022 (17:07)
*/

/*
  This approach contains the use of Recursion and Dynamic Programming
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using i64 = long long;

#define ll long long
#define v(x) vector<int> v(x)
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x));
#define desc(x) sort(all(x), greater<int>{});
#define dbe(x) cout << x << endl;
#define dbz(x) cout << x << " ";

ll mod = 1e9 + 7;
ll currentSum = 0;

int findAllPossibleCount(int currentSum, int n, vector<int> &dp) {
  if (n == currentSum)
    return 1;
  if (n < currentSum)
    return 0;
  if (dp[currentSum] != -1) {
    return dp[currentSum];
  }
  ll possibleSolutionCount = 0;
  for (int i = 3; i <= n; i += 2) {
    possibleSolutionCount += findAllPossibleCount(currentSum + i, n, dp);
  }
  dp[currentSum] = possibleSolutionCount % mod;
  return possibleSolutionCount % mod;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> dp(n, -1);
  cout << findAllPossibleCount(currentSum, n, dp) << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  int a[N];
  for (int i = 0; i < N-1; i++)
  {
    cin >> a[i];
  }
  
  int b[N];
  for (int i = 0; i < N; i++)
  {
    cin >> b[i];
  }

  long long res = 0;
  long long minb = b[0];
  for (int i = 0; i < N-1; i++)
  {
    minb = min(minb, (long long)b[i]);
    res += minb * a[i];
  }
  
  cout << res;

  return 0;
}

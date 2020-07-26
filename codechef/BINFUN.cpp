// July lunchtime 2020
// https://www.codechef.com/LTIME86A/problems/BINFUN

#include <bits/stdc++.h>
using namespace std;

int digitLen(long long r)
{
  int ans = 0 ;
  while(r != 0)
  {
    ans++ ;
    r /= 2 ;
  }
  return ans;
}

int main()
{
  int t ; cin >> t ;
  while(t--)
  {
    int n ;  cin >> n ;
    map<int, long long> maxL, minL;
    for(int i = 0 ; i < n ; i++)
    {
      long long r ; cin >> r ; 
      int m = digitLen(r);
      if(maxL.find(m) != maxL.end())
      {
        maxL[m] = max(maxL[m], r);
      }
      else{
        maxL[m] = r ;
      }

      if(minL.find(m) != minL.end())
      {
        minL[m] = min(minL[m], r);
      }
      else{
        minL[m] = r ;
      }
    }

    long long powR[34]; 
    powR[0] = 1; 
    for(int i= 1 ; i < 34 ; i++)
      powR[i] = (powR[i - 1]) * 2 ; 
    
    long long ans = 0 ;
    for(int i = 0 ; i < 34 ; i++)
    {
      for(int j = 0 ; j < 34; j++)
      { 
        if(maxL.find(i) != maxL.end() && minL.find(j) != minL.end())
        {
                long long best = maxL[i] * (powR[j] - 1) - minL[j] * (powR[i] - 1);
                ans = max(best, ans);
        }
      }
    }

    cout << ans << endl ;
  }
}

// Moral of this code
// don't use pow, use precomputed values in cp.

#include <bits/stdc++.h>
using namespace std;

int max_gcd(vector<pair<int, int> >& v)
{    
    if (v.size() == 1 || v.size() == 0)
        return 0;
  
    sort(v.begin(), v.end());
    
    pair<int, int> a = v[0];
    pair<int, int> b;
    int ans = INT_MIN;
    for (int i = 1; i < v.size(); i++) {
        b = v[i];
                
        if (b.first == a.first)
                                    
            ans
                = max(ans,
                      __gcd(a.second,
                            b.second));
                
        a = b;
    }
    return ans;
}

int main()
{
    vector<pair<int, int> > v;
    v.push_back(make_pair(5, 4));
    v.push_back(make_pair(5, 8));
    v.push_back(make_pair(4, 6));
    v.push_back(make_pair(4, 9));
    v.push_back(make_pair(8, 10));
    v.push_back(make_pair(10, 20));
    v.push_back(make_pair(10, 30));

    cout << max_gcd(v);
    return 0;
}

/*
 * POTD 14.07.2025
 * https://codeforces.com/contest/1709/problem/B
 */

#include <iostream>
#include <vector>
using namespace std;

long long max(long long a, long long b){
    if(a > b)
        return a;
    else
        return b;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<long long> arr(n), sumL(n, 0), sumR(n, 0);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 1; i < n; i++)
        sumL[i] = sumL[i-1] + max((arr[i-1] - arr[i]), 0);
    for(int i = n - 2; i >= 0; i--)
        sumR[i] = sumR[i+1] + max((arr[i+1] - arr[i]), 0);

    for(int i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;
        if(s < t)
            cout << sumL[t - 1] - sumL[s - 1] << '\n';
        else
            cout << abs(sumR[s - 1] - sumR[t - 1]) << '\n';
    }
}

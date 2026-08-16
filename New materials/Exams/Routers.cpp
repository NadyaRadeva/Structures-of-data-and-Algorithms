#include <bits/stdc++.h>
using namespace std;

long long MIN_N = 2;
long long MAX_N = 200000;
long long MIN_K = 2;
long long MIN_Xi = 0;
long long MAX_Xi = 1000000000;

bool canPlace(long long* routers, long long N, long long K, long long D) {
    long long count = 1;
    
    long long lastPosition = routers[0];
    
    for(long long i = 1; i < N; ++i) {
        if(routers[i] - lastPosition >= D) {
            ++count;
            lastPosition = routers[i];
            
            if(count >= K) {
                return true;
            }
        }
    }
    
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long N, K;
    
    cin >> N;
    
    if(N < MIN_N || N > MAX_N) {
        return -1;
    }
    
    cin >> K;
    
    if(K < MIN_K || K > N) {
        return -1;
    }
    
    long long* routers = new long long[N];
    
    for(long long i = 0; i < N; ++i) {
        cin >> routers[i];
        
        if(routers[i] < MIN_Xi || routers[i] > MAX_Xi) {
            delete[] routers;
            return -1;
        }
    }
    
    sort(routers, routers + N);
    
    long long left = 0;
    long long right = routers[N - 1] - routers[0];
    
    long long answer = 0;
    
    while(left <= right) {
        long long mid = left + (right - left) / 2;
        
        if(canPlace(routers, N, K, mid)) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    cout << answer << '\n';
    
    delete[] routers;
    
    return 0;
}

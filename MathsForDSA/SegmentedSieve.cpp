#include <bits/stdc++.h>
using namespace std;
void simpleSieve(int limit, vector<int> &prime){
    // Create a boolean array "mark[0..n-1]" and initialize
    // all entries of it as true. A value in mark[p] will
    // finally be false if 'p' is Not a prime, else true.
    vector<bool> mark(limit + 1, true);
    for (int p=2; p*p<limit; p++){
        // If p is not changed, then it is a prime
        if (mark[p] == true){
            // Update all multiples of p
            for (int i=p*p; i<limit; i+=p)
                mark[i] = false;
        }
    }
    // Print all prime numbers and store them in prime
    for (int p=2; p<limit; p++){
        if (mark[p] == true){
            prime.push_back(p);
            cout << p << " ";
        }
    }
}
// Prints all prime numbers smaller than 'n'
void segmentedSieve(int n){
    // Compute all primes smaller than or equal
    // to square root of n using simple sieve
    int limit = floor(sqrt(n))+1;
    vector<int> prime;
    prime.reserve(limit);
    simpleSieve(limit, prime);
    // Divide the range [0..n-1] in different segments
    // We have chosen segment size as sqrt(n).
    int low = limit;
    int high = 2*limit;
    // While all segments of range [0..n-1] are not processed,
    // process one segment at a time
    while (low < n){
        if (high >= n) high = n;
        // To mark primes in current range. A value in mark[i]
        // will finally be false if 'i-low' is Not a prime,
        // else true.
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
        // Use the found primes by simpleSieve() to find
        // primes in current range
        for (int i = 0; i < prime.size(); i++){
            // Find the minimum number in [low..high] that is
            // a multiple of prime[i] (divisible by prime[i])
            // For example, if low is 31 and prime[i] is 3,
            // we start with 33.
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
            /* Mark multiples of prime[i] in [low..high]:
                We are marking j - low for j, i.e. each number
                in range [low, high] is mapped to [0, high-low]
                so if range is [50, 100] marking 50 corresponds
                to marking 0, marking 51 corresponds to 1 and
                so on. In this way we need to allocate space only
                for range */
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
        for (int i = low; i<high; i++)
            if (mark[i - low] == true)
                cout << i << " ";
        low = low + limit;
        high = high + limit;
    }
}
int main(){
    int n;
    cout<<"Number of segments: ";
    cin>>n;
    cout << "Primes smaller than " << n << ":\n";
    segmentedSieve(n);
    return 0;
}
//Time Complexity : O(n * ln(sqrt(n)))
// Auxiliary Space: O(sqrt(n))
What is segmented sieve?
Segmented is the way to generate prime numbers in a given range

Sieve does the same so why we need segmented sieve?

  
To generate prime upto N we need an array of size N.So if the N is 10^12 will that sieve work?
  
When we need to find prime numbers in the range L to R and where L and R can be as large as 10^12 but still R-L+1<=10^6

Step1: We need to take an array of size R-L+1
Step2: We will generate all primes up to R
Step3:Every time we will take a prime and mark if its multiplyer in the range L to R exis

 -----------------------------------------------------------------------------------------------------------------------------
 
 //https://www.spoj.com/problems/PRIME1/

#include <bits/stdc++.h>
#include <iostream>
#define MAX 32000

using namespace std;

using ll = long long;

vector<int> primes;

void sieve()
{
    bool isPrime[MAX];
    for (int i = 0; i < MAX; ++i) isPrime[i] = true;
    for (int i = 3; i * i <= MAX; i += 2)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i < MAX; i += 2)
    {
        if (isPrime[i]) primes.push_back(i);
    }
}

void segSieve (ll l, ll r)
{
    bool isPrime[r-l+1];
    for (int i = 0; i < r - l + 1; ++i) 
    isPrime[i] = true;
    
    if (l == 1)
    isPrime[0] = false;
    
    for (int i = 0; primes[i]*primes[i] <= r; ++i)
    {
        int currentPrime = primes[i];
      // Find the minimum number in [low..high] that is
			// a multiple of prime[i] (divisible by prime[i])
			// For example, if low is 31 and prime[i] is 3,
			// we start with 33.
        ll base = (l/currentPrime)*currentPrime;
        if (base < l) base += currentPrime;
        for (ll j = base; j <= r; j += currentPrime)
        {
            isPrime[j-l] = false;
        }
        if (base == currentPrime)
         isPrime[base-l] = true;
    }
    for (int i = 0; i < r - l + 1; ++i)
    {
        if (isPrime[i]) cout << (i+l) << endl;
    }
    puts("");
}

int main()
{
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        segSieve(l, r);
    }


    return 0;
}

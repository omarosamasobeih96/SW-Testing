#include <bits/stdc++.h>

using namespace std;

typedef long long Long;

const int N = 1010;
const int MOD = 1e9 + 7;

// Returns true if number is happy
// Happy numbers that have at least two features satisfied
bool checkHappy(int x) {
	int hasSqrt = 0;
	for (int i = 0; i * i <= x; ++i)
		if (x == i * i) hasSqrt = 1;
	int isEven = x % 2 == 0;
	int isLucky = 1;
	while (x) {
		isLucky &= x % 10 == 4 || x % 10 == 7;
		x /= 10;
	}
	if ((hasSqrt && isEven) || (isLucky && (hasSqrt || isEven))) return true;
	else return false;
}

// Returns the greatest common divisors (GCD) of the given two numbers.
// Worst case when (a, b) are two consecutive Fibonacci numbers.
// O(log(n))
int gcd(int a, int b) {
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

// Returns the greatest common divisors (GCD) of the given two numbers recursively.
// Worst case when (a, b) are two consecutive Fibonacci numbers.
// O(log(n))
int gcd_rec(int a, int b) {
    return b == 0 ? a : gcd_rec(b, a % b);
}

// Returns the least common multiple (LCM) of the given two numbers.
// O(GCD(a, b)) = O(log(n))
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

// Returns the Bezout's coefficients of the smallest positive linear combination of a and b
// using the extended Euclidean algorithm.
// (i.e. GCD(a, b) = s.a + t.b).
// O(GCD(a, b)) = O(log(n))
pair<int, int> extendedEuclid(int a, int b) {
    if (b == 0) {
        return { 1, 0 };
    }

    pair<int, int> p = extendedEuclid(b, a % b);

    int s = p.first;
    int t = p.second;

    return { t, s - t * (a / b) };
}

// Returns ((base^exp) mod m) using iterative fast power algorithm
// Note that if (base=0, exp=0) is passed to the function it will return 1.
// O(log(exp))
Long powerr(Long base, Long exp) {
	Long ans = 1;
	base %= MOD;

	while (exp > 0) {
		if (exp & 1) ans = (ans * base) % MOD;
		exp >>= 1;
		base = (base * base) % MOD;
	}

	return ans;
}

// Returns ((base^exp) mod m) using iterative fast power algorithm
// Note that if (base=0, exp=0) is passed to the function it will return 1.
// O(log(exp))
Long power(Long base, Long exp, Long mod) {
    Long ans = 1;
    base %= MOD;

    while (exp > 0) {
        if (exp & 1) ans = (ans * base) % MOD;
        exp >>= 1;
        base = (base * base) % MOD;
    }

    return ans;
}

// Returns ((base^exp) mod m) using recursive fast power algorithm.
// Note that if (base=0, exp=0) is passed to the function it will return 1.
// O(log(exp))
Long power_rec(Long base, Long exp) {
    if (exp == 0) {
        return 1;
    }

    Long p = power_rec((base * base) % MOD, exp >> 1);

    return (exp & 1) ? (p * base) % MOD : p;
}


// Returns n choose r.
// (i.e. The number of distinct sets of size k chosen from n-items).
// Note that C(n, r) = C(n, n - r)
// So call the function with nCr(n, min(r, n-r)) for better performance.
// O(r)
int nCr(int n, int r) {
    if (n < r)
        return 0;

    if (r == 0)
        return 1;

    return n * nCr(n - 1, r - 1) / r;
}

// Builds Pascal's triangle of size n for computing the combinations.
// After calling this function, comb[n][r] will be equals to nCr.
// O(n^2)
int comb[N][N];
void buildPT(int n) {
    for (int i = comb[0][0] = 1; i <= n; ++i)
        for (int j = comb[i][0] = 1; j <= i; ++j)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
}

// Returns whether the given number is prime or not.
// O(sqrt(n))
bool isPrime(int n) {
    if (n < 2)
        return 0;
    if (n % 2 == 0)
        return (n == 2);
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

// Returns circle area
double circleArea(double r) {
	return acos(-1)*r*r;
}

// Probabilistic primality check using Miller Rabin algorithm.
// Returns false if the given number 'n' is a composite number, true if it is a probable prime.
bool millerRabin(Long a, Long k, Long q, Long n) {
    Long x = power(a, k, n);

    if (x == 1) {
        return 1;
    }

    while (k--) {
        if (x == n - 1) {
            return 1;
        }

        x = (x * x) % n;
    }

    return 0;
}

// Generates all the prime numbers from 1 to the given number n
// using Sieve of Eratosthenes' algorithm.
// After calling this function, prime[i] will be equal 1 if i is prime, 0 otherwise.
// O(n.log(log(n)))
bool prime[N];
void generatePrimes(int n) {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (!prime[i]) continue;

        for (int j = i * i; j <= n; j += i) {
            prime[j] = false;
        }
    }
}

// Generates all the prime divisors of the numbers from 1 to n.
// After calling this function,
// primeDivs[i] will contains all the prime divisors of number i.
// O(n.log(log(n)))
vector<int> primeDivs[N];
void generatePrimeDivisors(int n) {
    for (int i = 2; i <= n; ++i) {
        if (primeDivs[i].size()) continue;

        for (int j = i; j <= n; j += i) {
            primeDivs[j].push_back(i);
        }
    }
}

// Returns a list of divisors of the given number.
// O(sqrt(n))
vector<int> getDivisors(int n) {
    vector<int> divs;

    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divs.push_back(i);

            if (i * i != n) {
                divs.push_back(n / i);
            }
        }
    }

    sort(divs.begin(), divs.end());

    return divs;
}

// Generates all the divisors of the numbers from 1 to n.
// After calling this function,
// divs[i] will contains all the divisors of number i.
// O(n.log(n))
vector<int> divs[N];
void generateDivisors(int n) {
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            divs[j].push_back(i);
}

// Returns n P r
int nPr(int n, int r)
{
	if (r == 0)return 1;
	return n * nPr(n - 1, r - 1);
}
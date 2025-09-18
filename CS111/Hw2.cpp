#include <iostream>
#include <vector>
#include "math.h"

bool isPrime(long long n) {
    if (n <= 1) 
        return false;
   for (long long i = 2; i<= (n/2); i++) {
		if (n % i == 0) 
			return false;
	}
	return true;
}

bool factor(long long n, long long& p, long long& q) {
    for (p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            q = n / p;
            return true;
        }
    }
    return false;
}


long long gcd(long long a, long long b) {
	if(b==0)
        return a;
	else
		return gcd(b, a % b);
}

long long ModExponent(long long base, long long power, long long mod) {
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        power /= 2;
    }
    return result;
}

long long ModInverse(long long e, long long phi)
{
    e = e % phi;
    for (int d = 1; d < phi; d++)
    {
        if ((e * d) % phi == 1)
            return d;
    }
    return -1;
}


int main() {
    long long e, n;
    std::cin >> e >> n;       // first line: e n
    long long m;
    std::cin >> m;            // second line: m
    std::vector<long long> C(m);
    for (int i = 0; i < m; i++) {
        std::cin >> C[i];     // next m integers
    }

    long long p = 0, q = 0;
    for (long long i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            long long j = n / i;
            if (isPrime(i) && isPrime(j)) {
                p = i;
                q = j;
                break;
            }
        }
    }
    if (p == 0 || q == 0 || p == q) {
        std::cout << "Public key is not valid!";
        return 0;
    }
    if (p > q) std::swap(p, q);

    long long phi = (p - 1) * (q - 1);
    if (gcd(e, phi) != 1) {
        std::cout << "Public key is not valid!";
        return 0;
    }

    long long d = ModInverse(e, phi);

    std::vector<long long> M(m);
    for (int i = 0; i < m; i++) {
        M[i] = ModExponent(C[i], d, n);
    }

    std::cout << p << " " << q << " " << phi << " " << d << '\n';

    for (int i = 0; i < m; i++) {
        std::cout << M[i] << (i + 1 < m ? ' ' : '\n');
    }

    std::vector<char> msg;
    msg.reserve(m);
    for (int i = 0; i < m; i++) {
        long long x = M[i];
        char c;
        if (7 <= x && x <= 32) c = char('A' + (x - 7));
        else if (x == 33)             c = ' ';
        else if (x == 34)             c = '"';
        else if (x == 35)             c = ',';
        else if (x == 36)             c = '.';
        else if (x == 37)             c = '\'';
        else                          c = '?';
        msg.push_back(c);
    }

    for (int i = 0; i < (int)msg.size(); i++) {
        std::cout << msg[i];
    }


    return 0;
}

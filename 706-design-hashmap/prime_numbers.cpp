#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stdexcept>

using ll = long long; 

std::vector<ll> primes(ll limit) {
    std::vector<ll> primes;
    if (limit < 2) {
        return primes; 
    }
    primes.push_back(2);

    for (ll i = 3; i <= limit; i++) {
        bool stop = false;
        bool isPrime = true;
        for (ll j = 0; stop != true; j++) {
            if (primes[j] <= std::sqrt(i)) {
                if (i % primes[j] == 0)
                    isPrime = false;
            } else {
                stop = true;
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <limit>\n";
        return 1;
    }

    ll limit;
    try {
        std::size_t pos;
        limit = std::stoll(argv[1], &pos);
        if (argv[1][pos] != '\0') {
            throw std::invalid_argument("caratteri non numerici");
        }
    } catch (const std::exception&) {
        std::cerr << "Errore: limit deve essere un intero rappresentabile come long long.\n";
        return 1;
    }

    auto p = primes(limit);
    ll better = 0;
    ll betterPrime = 0;

    ll p2 = 2;
    ll base2 = 2;
    ll p10 = 10;
    ll base10 = 10;

    for (auto i = 0; i < p.size(); i++) {
        while (p2 <= p[i]) {
            p2 *= base2;
        }
        p2/=base2;

        while (p10 <= p[i]) {
            p10 *= base10;
        }
        p10/=base10;

        ll d2 = std::min(p[i] - p2, p2*base2 - p[i]);
        ll d10 = std::min(p[i] - p10, p10*base10 - p[i]);

        if (d2 + d10 > better) {
            std::cout << p[i] << " with distances: { 2: " << d2 << ", 10: " << d10 << "}" << std::endl; 
            better = d2 + d10;
            betterPrime = p[i];
        }
    }

    std::cout << std::endl;

    std::cout << "Better prime: " << betterPrime << std::endl;
}


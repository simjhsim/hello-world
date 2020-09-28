import math

def sieve_of_erat(n):
    # implements sieve of eratosthenes to create list of all primes < n
    cand = list(range(n))

    # sieve through cand
    for i in range(2,n):
        if cand[i] != 0:
            for j in range(2,n):
                if i * j >= n:
                    break
                else:
                    cand[i*j] = 0

    cand[:] = [x for x in cand if x != 0]

    return cand


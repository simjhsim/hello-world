import math

def false_frac():
    # iterates through pairs of digits from 1 to 9
    # for each pair, iterates through digits from 1 to 9
    # to get two pairs of 2-digit numbers. The pairs
    # are then analyzed to see if the quotient is equal to
    # the naive quotient
    digits = list(range(1,10))

    pairs = []

    for i in digits:
        for j in range(i+1,10):
            pairs.append([i,j])

    unusual_fracs = []

    for quo in pairs:
        c = 9 * quo[0] * quo[1]
        for alpha in digits:
            # a := quo[0] and b := quo[1] can produce an unusual fraction
            # if and only if 9ab=(10a-b)alpha or 9ab=(10b-a)alpha
            if (c % alpha) == 0:
                if c == (10*quo[0] - quo[1])*alpha :
                    unusual_fracs.append([quo[0] * 10 + alpha, 10 * alpha + quo[1]])
                if c == (10*quo[1] - quo[0])*alpha :
                    unusual_fracs.append([alpha * 10 + quo[0],10*quo[1] + alpha])

    return unusual_fracs 

def answer():
    unusuals = false_frac()

    num = 1
    den = 1

    for frac in unusuals:
        num *= frac[0]
        den *= frac[1]
    
    com = math.gcd(num,den)

    return [num / com, den / com]

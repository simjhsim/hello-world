

def div_list(n):
    # returns list of all divisors of n non-inclusive
    divisors = []

    for i in range(n-1):
        j = i+1
        
        if n % j == 0:
            divisors.append(j)

    return divisors

def sum_list(intlist):
    listsum = 0
    for i in intlist:
        listsum += i

    return listsum

def amicable_numbers(bound):
    alist = []
    rrange = list(range(bound))

    for i in rrange:
        j = i+1
        
        pair = sum_list(div_list(j))
        
        if pair != j:
            if sum_list(div_list(pair)) == j:
                alist.append(j)
                if pair < bound:
                    alist.append(pair)
                    rrange.remove(pair-1)
    print(alist)

    return sum_list(alist)
        
        

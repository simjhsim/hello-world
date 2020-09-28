import primes
import algebra

def pos_tuples(n,bound):
    # creates list of all n-tuples of non-negative integers such that the sum of
    # coordinates is < bound
    if bound <= 0:
        tup = []
        for i in range(n):
            tup.append(0)
        return [tup]
    elif n <= 0:
        return []

    comp_list = []

    if n == 1:
        for i in range(bound):
            comp_list.append([i])
    else:
        for i in range(bound):
            buff_list = pos_tuples(n-1,bound-i)
            for x_tup in buff_list:
                comp_list.append([i]+x_tup)

    return comp_list
        
def is_elem(x):
    # takes in an n-tuple and checks if the tuple is
    # a scalar multiple of an elementary vector
    ind = 0
    for i in x:
        if i != 0:
            ind += 1
    if ind == 1:
        return True
    else:
        return False

def diglist_to_num(x):
    # takes in list of integers between 0 and 9 inclusive
    # and returns a number whose digits line up with the given
    # list
    num = 0
    for i in x:
        if i < 10 and i >= 0:
            num = (10 * num) + i
        else:
            return None

    return num



def cyclic_primes(n):
    if n <= 0:
        return None
    # determines all cyclic primes up to 10^n
    # uses the fact that no digit of cylic primes can be
    # even or 5 since numbers with even digits or 5 can
    # be cycled to be divisible by 2 or 5; the total number
    # of 1's and 7's also cannot be divisible by 3 since
    # then the entire number will be divisible by 3 regardless
    # of order
    digs = [1,3,7,9]

    # generate all 4-tuples counting number of occurances of
    # each digit for each candidate
    cand = pos_tuples(4,n+1)

    # filter elements of cand where the 1st and 3rd entries
    # sum to 0, 3, or 6

    cand[:] = [x for x in cand if (((x[0] + x[2]) % 3 != 0) and is_elem(x) == False)
            or (x[0]+x[1]+x[2]+x[3]==1)]

    # remove 1 since not prime
    cand.remove([1,0,0,0])

    # add back possible repunit primes
    for i in range(2,n+1):
        cand.append([i,0,0,0])

    # create list of length n where the i-th element (zero indexed)
    # is a list of permutation representatives of i+1 elements 
    # for each cycle-class
    cycle_lists = [[1]]
    for i in range(1,n):
        perms = algebra.symmetric_grp(i)
        cy_reps = []
        for x in perms: 
            cy_reps.append(x+[i+1])
        cycle_lists.append(cy_reps)

    

    # use each tuple to check all classes of cycles for prime-ness
    cprimes = [2,5] # include exceptional 2 and 5
    prime_n = primes.sieve_of_erat(10**n)

    for tup in cand:
        # for each tuple, make list of digits
        given = []
        tot = 0
        for i in range(4):
            for j in range(tup[i]):
                given.append(digs[i])
            tot = tot + tup[i]
        
        # generate list of cycle reps using cycle_lists
        cycle_reps = cycle_lists[tot-1]
        reps = []

        for x in cycle_reps:
            buff = []
            if x == 1:
                reps.append(given)
            else:
                # generate cycle rep and store in buff
                for i in range(len(x)):
                    buff.append(given[x[i]-1])
                reps.append(buff)

        
        # check each rep and its cycles to see if they are all prime
        # keep list of checked cycles to append to cprimes at the end
        for x in reps:
            buff = []
            y = list(x)
            x_num = diglist_to_num(x)


            if (x_num in prime_n):

                buff.append(x_num)

                while True:
                    # cycle y
                    elem = y[0]
                    y.remove(elem)
                    y.append(elem)

                    y_num = diglist_to_num(y)

                    if y_num == x_num:
                        cprimes = cprimes + buff
                        break

                    # check if new cycled number is prime

                    if y_num in prime_n:
                        buff.append(y_num)
                    else:
                        buff = []
                        break



    return cprimes

n = 6
cycs = cyclic_primes(n)
cycs = list(set(cycs))
cycs.sort()




print('Circular primes up to ' , 10**n , ': ' , cycs)
print('Length: ',len(cycs))


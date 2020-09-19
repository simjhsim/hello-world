import q21


def is_abun_num(number):
    # returns true if abundant number
    if q21.sum_list(q21.div_list(number)) > number:
        return True
    else:
        return False

def abun_nums(bound):
    # returns list of all abundant numbers less than a given bound
    rrange = list(range(bound))
    rrange.remove(0)

    abunlist = []

    for i in rrange:
        if is_abun_num(i): 
            abunlist.append(i)

    print(abunlist)

    return abunlist

def abun_sums(bound):
    # returns a list of all numbers that can be written as a sum of two abundant numbers
    abun_num_list = abun_nums(bound)
    abun_sum = []

    rrange = list(range(bound))
    rrange.remove(0)

    for i in rrange:
        for j in abun_num_list:
            cand = i - j
            if cand > 0:
                if cand in abun_num_list:
                    abun_sum.append(i)
                    break


    print(abun_sum)
    return q21.sum_list(abun_sum)

def cumul_sum(number):
    # returns sum from 1 to number
    return (number +1)*number /2


print(abun_sums(28123))


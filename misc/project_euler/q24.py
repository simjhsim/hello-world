import math


# lexi_order uses numbers of permutations for n elements (no repetition) to find
# the first element of the m-th element, then the second, then so on.
def lexi_order(num_elem,m):
    perm_list = []
    buff = m
    
    elems = list(range(num_elem))

    for i in range(num_elem-1):
        factor = math.factorial(num_elem-i-1)
        bound = int(math.floor(buff / factor))
        print(bound)
        perm_list.append(elems[bound])
        elems.pop(bound)
        buff -= bound * factor
        print(elems)
        print(perm_list)
    
    perm_list.append(elems[0])

    print(perm_list)
    return perm_list

    

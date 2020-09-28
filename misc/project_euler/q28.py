

def corner_numbers(n):
    # 2n+1 x 2n+1 is the dimension of the grid
    # the m-th corner numbers (zero indexed) are the four
    # numbers in the corner of the 2m+1 x 2m+1 grid
    # so the 1st corner numbers are 3,5,7,9
    # the (m+1)-th corner numbers are precisely 
    # max_m + 2(m+1), max_m +4(m+1), max_m+6(m+1), max_m+8(m+1)
    # where max_m is the largest of the m-1 corner numbers
    if (n < 1):
        return [1]

    cornums = [1]
    max_cor = 1

    for i in range(1,n+1):
        for j in range(4):
            max_cor += 2*i
            cornums.append(max_cor)

    return cornums

def cor_sum(n):
    # returns the sum of all corner_numbers, i.e. the
    # diagonals in the 2n+1 x 2n+1 grid spiral
    sum = 0
    for i in corner_numbers(n):
        sum += i
    return sum

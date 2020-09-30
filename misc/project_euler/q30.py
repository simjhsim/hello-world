from itertools import product

def list_to_num(x):
    num = 0
    for i in x:
        num = (10 * num) + i
    return num

def dig_power_sum(n):
    cand = list(product(range(10), repeat=n+1))
    ans = []

    for x in cand:
        num = list_to_num(x)
        nsum = 0
        for i in x:
            nsum = nsum + (i ** n)
        if nsum == num:
            ans.append(num)

    return ans

answer = dig_power_sum(5)
answer.remove(0)
answer.remove(1)
print('Fifth power sum numbers: ', answer)
print('Sum: ',sum(answer))
        


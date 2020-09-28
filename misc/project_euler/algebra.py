# algebra.py
# library of useful functions for abstract algebra

def symmetric_grp(n):
    # returns list of symmetric group reps where each
    # element is represented by a list of length n
    # such that for an element x, x[i] is the position
    # that i is permuted
    if n <= 1:
        return [list(range(1,2))]
    else:
        sym = symmetric_grp(n-1)
        sym_n = []
        # for each S_{n-1} element, insert n at each 
        # possible location to create an S_n element
        for x in sym:
            buff = []
          
            for i in range(n-1):
                xlist = list(x)
                xlist.insert(i,n)
                buff.append(xlist)
            
            # lastly include if n is sent to itself
            xlist = list(x)
            xlist.append(n)
            buff.append(xlist)

            sym_n = sym_n + buff

        return sym_n
                


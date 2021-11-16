



// # def solution(T):
// #     # write your code in Python 3.6
// #     if T.x == None:
// #         return 0

// #     hashmap = {T.x : 1}
// #     q = [(T, hashmap)]

// #     res = 1


// #     while not q == []:
// #         (t, hm) = q.pop()

// #         if t == None or isinstance(t, int):
// #             continue
// #         if t.l == None and t.r == None:
// #             continue

// #         lx = -1
// #         rx = -1

// #         if not t.l == None:
// #             lx = t.l.x
// #         if not t.r == None:
// #             rx = t.r.x

// #         print(str(lx) + "  " + str(rx))

// #         if not lx in hm and not lx == -1:
// #             newhm = hm.copy()

// #             print(newhm)
// #             newhm[lx] = 1
// #             print(newhm)
// #             if len(newhm) > res:
// #                 res = len(newhm)
            
// #             q = q + [(t.l, newhm)]
            
        
// #         if not rx in hm and not rx == -1:
// #             newhmr = hm.copy()
// #             newhmr[rx] = 1
// #             if len(newhmr) > res:
// #                 res = len(newhmr)
            
// #             q = q + [t.r, newhmr]


// #     return res

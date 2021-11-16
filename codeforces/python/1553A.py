# -*- coding: utf-8 -*-
"""
Created on Thu Jul 29 19:39:53 2021

@author: LeranCai
"""

def solve():
    inp = input()
    n = int(inp)
    
    for i in range(n):
        x = int(input())
        if x < 9:
            print(0)
        else:
            print( (x+1) // 10)
        


if __name__ == "__main__":
    solve()
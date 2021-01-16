"""
combinations solution
"""
from math import factorial

infast = lambda: input().strip()
T = int(infast())
M = int(infast())
N = int(infast())

if T == 0:
    print(factorial(M) // factorial(M - N))
else:
    print(factorial(M) // factorial(N) // factorial(M - N))

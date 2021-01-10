"""
data_gen.py -- generate datasets
"""
import random
import sys

assert len(sys.argv) == 4
height = int(sys.argv[1])
width = int(sys.argv[2])
wall_threshold = float(sys.argv[3])
print(height, width)
for y in range(height):
    for x in range(width):
        if x != 0:
            print(' ', end='')
        place_wall = random.random() < wall_threshold
        if place_wall:
            val = -999
        else:
            val = random.randint(-100, 100)
        if (x == 0 and y == 0) or (x == width - 1 and y == height - 1):
            val = 0
        print(val, end='')
    print()

"""
lasergame solution
"""
from collections import deque
from math import inf
from pprint import pprint
from sys import exit, stdin

infast = lambda: stdin.readline().strip()
H, W = map(int, infast().split())
board = []
for _ in range(H):
    board.append(list(map(int, infast().split())))

q = deque()
visited = set([(0, 0)])
q.append((0, 0))
available = lambda pos: 0 <= pos[0] < H and 0 <= pos[1] < W and \
                        board[pos[0]][pos[1]] != -999
while q:
    u = q.popleft()
    nextpos = []
    if u != (0, 0):
        nextpos.append((u[0] + 1, u[1]))
    nextpos.append((u[0], u[1] + 1))
    for pos in nextpos:
        if available(pos) and pos not in visited:
            visited.add(pos)
            q.append(pos)

if (H - 1, W - 1) not in visited:
    print('SOHYUN GAVE UP')
    exit(0)

dp = []
for _ in range(H):
    dp.append([(-inf, '')] * W)

dp[-1][-1] = (0, '')
add = lambda t1, x, d: (t1[0] + x, d)
for y in range(H - 1, -1, -1):
    for x in range(W - 1, -1, -1):
        vert = (-inf, '')
        horiz = (-inf, '')
        if board[y][x] != -999 and y >= 1:
            vert = add(dp[y][x], board[y - 1][x], '|')
        if board[y][x] != -999 and x >= 1:
            horiz = add(dp[y][x], board[y][x - 1], '-')
        dp[y - 1][x] = max(dp[y - 1][x], vert)
        dp[y][x - 1] = max(dp[y][x - 1], horiz)

print(dp[0][1][0])
last_dir = '-'
y = 0
x = 1
while not (y == H - 1 and x == W - 1):
    current_dir = dp[y][x][1]
    if current_dir != last_dir:
        print(y, x)
    last_dir = current_dir
    if current_dir == '-':
        x += 1
    else:
        y += 1

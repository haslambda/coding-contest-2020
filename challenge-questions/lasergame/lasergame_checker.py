"""
lasergame_checker.py -- check answers
"""
def check(process_output: str, judge_output: str, **kwargs):
    judge_input = str(kwargs['judge_input'])
    judge_input_numbers = list(map(int, judge_input.split()))
    process_score = int(process_output.split()[0])
    judge_score = int(judge_output.split()[0])
    if process_score != judge_score:
        return False

    mirror_coords = []
    mirror_coords_unprocessed = list(map(int, process_output.split()[1:]))
    for i in range(0, len(mirror_coords_unprocessed), 2):
        mirror_coords.append((mirror_coords_unprocessed[i],
                              mirror_coords_unprocessed[i + 1]))

    H = judge_input_numbers[0]
    W = judge_input_numbers[1]
    board = []
    for y in range(H):
        line = []
        for x in range(W):
            line.append(judge_input_numbers[2 + y * W + x])
        board.append(line)

    y = 0
    x = 0
    direction = '-'
    score = 0
    try:
        while not (y == H - 1 and x == W - 1):
            if board[y][x] == -999:
                return False
            score += board[y][x]
            if (y, x) in mirror_coords:
                direction = '-' if direction == '|' else '|'
            if direction == '-':
                x += 1
            else:
                y += 1
    except:
        return False
    return True

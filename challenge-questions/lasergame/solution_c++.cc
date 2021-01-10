/*
 * lasergame solution
 */

#include <algorithm>
#include <cstring>
#include <ios>
#include <iostream>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;

const int MAX_SIZE = 1001, BARRIER_VAL = -999;
int H, W, board[MAX_SIZE][MAX_SIZE];
pair<int, char> dp[MAX_SIZE][MAX_SIZE];
bool solved[MAX_SIZE][MAX_SIZE];

bool check_solvable(int y, int x) {
  bool vert = false, horiz = false;
  if (y == H - 1 && x == W - 1) return true;
  if (y < H - 1 && board[y][x] != -999) vert = check_solvable(y + 1, x);
  if (x < W - 1 && board[y][x] != -999) horiz = check_solvable(y, x + 1);
  return vert || horiz;
}

int solve(int y, int x) {
  auto& ret = dp[y][x];
  if (solved[y][x]) return ret.first;
  if (y == H - 1 && x == W - 1) return 0;
  int vert = numeric_limits<int>::min(), horiz = numeric_limits<int>::min();
  if (y < H - 1 && !(y == 0 && x == 0) && board[y][x] != -999)
    vert = solve(y + 1, x) + board[y][x];
  if (x < W - 1 && board[y][x] != -999) horiz = solve(y, x + 1) + board[y][x];
  ret = max(make_pair(vert, '|'), make_pair(horiz, '-'));
  solved[y][x] = true;
  return ret.first;
}

void print_mirror_pos() {
  char last_dir = '-';
  int y = 0, x = 1;
  while (!(y == H - 1 && x == W - 1)) {
    char current_dir = dp[y][x].second;
    if (current_dir != last_dir) cout << y << ' ' << x << '\n';
    last_dir = current_dir;
    if (current_dir == '-')
      x++;
    else
      y++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> H >> W;
  for (int y = 0; y < H; ++y)
    for (int x = 0; x < W; ++x) cin >> board[y][x];
  if (check_solvable(0, 1)) {
    int result = solve(0, 0);
    cout << result << '\n';
    print_mirror_pos();
  } else
    cout << "SOHYUN GAVE UP\n";
  return 0;
}

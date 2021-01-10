/*
 * lasergame solution
 */

#include <algorithm>
#include <cstring>
#include <ios>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

const int MAX_SIZE = 1001, BARRIER_VAL = -999;
int H, W, board[MAX_SIZE][MAX_SIZE];
pair<int, char> dp[MAX_SIZE][MAX_SIZE];
bool solved[MAX_SIZE][MAX_SIZE];

inline bool available(pair<int, int> pos) {
  return 0 <= pos.first && pos.first < H && 0 <= pos.second && pos.second < W &&
         board[pos.first][pos.second] != -999;
}

bool check_solvable() {
  queue<pair<int, int>> q;
  set<pair<int, int>> visited;
  visited.insert({0, 0});
  q.push({0, 0});
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    vector<pair<int, int>> nextpos;
    if (u != make_pair(0, 0)) nextpos.push_back({u.first + 1, u.second});
    nextpos.push_back({u.first, u.second + 1});
    for (int i = 0; i < 2; ++i) {
      if (available(nextpos[i]) && visited.count(nextpos[i]) == 0) {
        visited.insert(nextpos[i]);
        q.push(nextpos[i]);
      }
    }
  }
  return visited.count({H - 1, W - 1}) == 1;
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
  if (check_solvable()) {
    int result = solve(0, 0);
    cout << result << '\n';
    print_mirror_pos();
  } else
    cout << "SOHYUN GAVE UP\n";
  return 0;
}

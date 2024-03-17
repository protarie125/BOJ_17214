#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vii = vector<pii>;
using vll = vector<pll>;
using vs = vector<string>;

using vvb = vector<vb>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

string s;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> s;

  if (s == "0") {
    cout << "W";
    return 0;
  }

  const auto& idx = s.find('x');
  if (idx == string::npos) {  // 0x+c
    auto iss = istringstream{s};
    ll c;
    iss >> c;

    if (1 == c) {
      cout << "x+W";
      return 0;
    }

    if (-1 == c) {
      cout << "-x+W";
      return 0;
    }

    cout << c << "x+W";
    return 0;
  }

  const auto& c1s = s.substr(0, idx);
  auto iss1 = istringstream{c1s};
  ll c1;
  iss1 >> c1;

  const auto& pp = s.find('+');
  auto pn = s.find_last_of('-');
  if (pn < idx) {
    pn = string::npos;
  }

  if (pp == string::npos && (pn == string::npos || pn < idx)) {  // cx
    if (2 == c1) {
      cout << "xx+W";
      return 0;
    }

    if (-2 == c1) {
      cout << "-xx+W";
      return 0;
    }

    cout << c1 / 2 << "xx+W";
    return 0;
  }

  auto pi = pp;
  if (pn != string::npos) {
    pi = pn;
  }

  const auto& c2s = s.substr(pi + 1);
  auto iss2 = istringstream{c2s};
  ll c2;
  iss2 >> c2;

  if (2 == c1) {
    cout << "xx";
  } else if (-2 == c1) {
    cout << "-xx";
  } else {
    cout << c1 / 2 << "xx";
  }

  if (pp != string::npos) {
    cout << "+";
  } else {
    cout << "-";
  }

  if (1 != c2 && -1 != c2) {
    cout << c2;
  }
  cout << "x+W";

  return 0;
}
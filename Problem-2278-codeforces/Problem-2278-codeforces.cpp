#include <iostream>
#include <string>
#include <vector>

using namespace std;

static constexpr long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        string x, y;
        cin >> x >> y;

        // Build the rooted tree and group nodes by depth.
        vector<int> parent(n, -1);
        vector<vector<int>> levels;
        vector<int> order;

        parent[0] = 0;
        order.push_back(0);

        for (int i = 0; i < static_cast<int>(order.size()); ++i) {
            int v = order[i];
            int depth = 0;

            if (v != 0) {
                depth = static_cast<int>(levels.size()); // unused; set below
            }
        }

        // Rebuild order with depths using an iterative traversal.
        vector<int> depth(n, 0);
        order.clear();
        order.push_back(0);

        for (int i = 0; i < static_cast<int>(order.size()); ++i) {
            int v = order[i];
            for (int to : graph[v]) {
                if (parent[to] != -1) {
                    continue;
                }
                parent[to] = v;
                depth[to] = depth[v] + 1;
                order.push_back(to);
            }
        }

        int max_depth = 0;
        for (int d : depth) {
            if (d > max_depth) max_depth = d;
        }

        levels.resize(max_depth + 1);
        for (int v = 0; v < n; ++v) {
            levels[depth[v]].push_back(v);
        }

        vector<int> carry(n, 0);
        vector<int> required_bit(max_depth + 1, 0);
        bool possible = true;

        for (int d = 0; d <= max_depth && possible; ++d) {
            int chosen = -1;

            for (int v : levels[d]) {
                int bit = (x[v] - '0') ^ (y[v] - '0') ^ carry[v];

                if (chosen == -1) {
                    chosen = bit;
                } else if (chosen != bit) {
                    possible = false;
                    break;
                }
            }

            if (!possible) {
                break;
            }

            required_bit[d] = chosen;

            for (int v : levels[d]) {
                int sum = (x[v] - '0') + chosen + carry[v];
                int outgoing_carry = sum / 2;

                for (int child : graph[v]) {
                    if (parent[child] == v) {
                        carry[child] = outgoing_carry;
                    }
                }
            }
        }

        if (!possible) {
            cout << -1 << '\n';
            continue;
        }

        long long answer = 0;
        long long power_of_two = 1;

        for (int d = 0; d <= max_depth; ++d) {
            if (required_bit[d]) {
                answer = (answer + power_of_two) % MOD;
            }
            power_of_two = (power_of_two * 2) % MOD;
        }

        cout << answer << '\n';
    }

    return 0;
}

// 题 23：排行榜

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Leaderboard {
private:
    std::unordered_map<std::string, int> scores_;

public:
    void updateScore(const std::string& name, int score) {
        scores_[name] = score;
    }

    void printTop(std::size_t n) const {
        std::vector<std::pair<std::string, int>> players(scores_.begin(), scores_.end());

        std::sort(players.begin(), players.end(), [](const auto& a, const auto& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });

        n = std::min(n, players.size());
        for (std::size_t i = 0; i < n; ++i) {
            std::cout << players[i].first << ' ' << players[i].second << '\n';
        }
    }
};

int main() {
    Leaderboard board;
    board.updateScore("Tom", 90);
    board.updateScore("Alice", 100);
    board.updateScore("Bob", 90);
    board.updateScore("Tom", 110);
    board.printTop(3);
}

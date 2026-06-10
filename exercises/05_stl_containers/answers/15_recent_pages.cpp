// 题 15：最近访问记录

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

class RecentPages {
private:
    std::list<std::string> pages_;
    std::size_t limit_;

public:
    explicit RecentPages(std::size_t limit) : limit_(limit) {}

    void visit(const std::string& page) {
        auto it = std::find(pages_.begin(), pages_.end(), page);
        if (it != pages_.end()) {
            pages_.erase(it);
        }

        pages_.push_front(page);

        if (pages_.size() > limit_) {
            pages_.pop_back();
        }
    }

    void print() const {
        for (const auto& page : pages_) {
            std::cout << page << '\n';
        }
    }
};

int main() {
    RecentPages pages(5);
    pages.visit("cppreference");
    pages.visit("github");
    pages.visit("stackoverflow");
    pages.visit("github");
    pages.print();
}

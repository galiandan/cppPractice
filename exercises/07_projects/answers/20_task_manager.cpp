// 题 20：任务管理器

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Task {
private:
    int id_;
    std::string title_;
    int priority_;
    bool done_ = false;

public:
    Task(int id, std::string title, int priority)
        : id_(id), title_(std::move(title)), priority_(priority) {}

    int id() const {
        return id_;
    }

    int priority() const {
        return priority_;
    }

    bool done() const {
        return done_;
    }

    void markDone() {
        done_ = true;
    }

    void print() const {
        std::cout << "[" << id_ << "] "
                  << title_
                  << " priority=" << priority_
                  << " done=" << std::boolalpha << done_ << '\n';
    }
};

class TaskManager {
private:
    std::vector<Task> tasks_;
    int nextId_ = 1;

public:
    int addTask(const std::string& title, int priority) {
        int id = nextId_++;
        tasks_.emplace_back(id, title, priority);
        return id;
    }

    bool finishTask(int id) {
        auto it = std::find_if(tasks_.begin(), tasks_.end(), [&](const Task& task) {
            return task.id() == id;
        });

        if (it == tasks_.end()) {
            return false;
        }

        it->markDone();
        return true;
    }

    bool removeTask(int id) {
        auto oldSize = tasks_.size();
        tasks_.erase(
            std::remove_if(tasks_.begin(), tasks_.end(), [&](const Task& task) {
                return task.id() == id;
            }),
            tasks_.end()
        );
        return tasks_.size() != oldSize;
    }

    void printPendingByPriority() const {
        std::vector<Task> pending;

        std::copy_if(tasks_.begin(), tasks_.end(), std::back_inserter(pending), [](const Task& task) {
            return !task.done();
        });

        std::sort(pending.begin(), pending.end(), [](const Task& a, const Task& b) {
            if (a.priority() != b.priority()) {
                return a.priority() > b.priority();
            }
            return a.id() < b.id();
        });

        for (const auto& task : pending) {
            task.print();
        }
    }
};

int main() {
    TaskManager manager;
    int a = manager.addTask("review OOP", 3);
    manager.addTask("practice STL", 5);
    manager.addTask("write notes", 1);

    manager.finishTask(a);
    manager.printPendingByPriority();
}

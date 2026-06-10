// 题 43：保存任务列表

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Task {
    int id;
    std::string title;
    bool done;
};

void saveTasks(const std::vector<Task>& tasks, const std::string& filename) {
    std::ofstream output(filename);
    for (const auto& task : tasks) {
        output << task.id << '\t' << task.done << '\t' << task.title << '\n';
    }
}

std::vector<Task> loadTasks(const std::string& filename) {
    std::ifstream input(filename);
    std::vector<Task> tasks;

    Task task{};
    while (input >> task.id >> task.done) {
        input.ignore();
        std::getline(input, task.title);
        tasks.push_back(task);
    }

    return tasks;
}

int main() {
    std::vector<Task> tasks = {
        {1, "learn file stream", false},
        {2, "write serializer", true}
    };

    saveTasks(tasks, "tasks.txt");
    auto loaded = loadTasks("tasks.txt");

    for (const auto& task : loaded) {
        std::cout << task.id << ' ' << task.done << ' ' << task.title << '\n';
    }
}


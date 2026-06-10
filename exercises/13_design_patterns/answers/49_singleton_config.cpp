// 题 49：单例模式

#include <iostream>
#include <mutex>
#include <string>
#include <unordered_map>

class ConfigCenter {
private:
    std::unordered_map<std::string, std::string> data_;
    mutable std::mutex mutex_;

    ConfigCenter() = default;

public:
    ConfigCenter(const ConfigCenter&) = delete;
    ConfigCenter& operator=(const ConfigCenter&) = delete;

    static ConfigCenter& instance() {
        static ConfigCenter center;
        return center;
    }

    void set(const std::string& key, const std::string& value) {
        std::lock_guard<std::mutex> lock(mutex_);
        data_[key] = value;
    }

    std::string get(const std::string& key) const {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = data_.find(key);
        return it == data_.end() ? "" : it->second;
    }
};

int main() {
    ConfigCenter::instance().set("host", "127.0.0.1");
    std::cout << ConfigCenter::instance().get("host") << '\n';
}


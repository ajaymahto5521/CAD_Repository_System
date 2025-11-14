#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <iostream>

template<typename T>
class Repository {
    std::vector<std::shared_ptr<T>> items;

public:
    Repository() = default;
    ~Repository() = default;

    void add(std::shared_ptr<T> item) {
        if (!item) throw std::invalid_argument("Null item");
        
        auto it = std::find_if(items.begin(), items.end(),
            [&item](const std::shared_ptr<T>& p) { return p->getId() == item->getId(); });
        if (it != items.end()) throw std::runtime_error("Duplicate ID");
        items.push_back(std::move(item));
    }

    std::vector<std::shared_ptr<T>> viewAll() const {
        return items;
    }

    std::shared_ptr<T> findById(int id) const {
        auto it = std::find_if(items.begin(), items.end(),
            [id](const std::shared_ptr<T>& p) { return p->getId() == id; });
        if (it != items.end()) return *it;
        return nullptr;
    }

    std::vector<std::shared_ptr<T>> findByName(const std::string& name) const {
        std::vector<std::shared_ptr<T>> res;
        std::for_each(items.begin(), items.end(), [&](const std::shared_ptr<T>& p) {
            if (p->getName().find(name) != std::string::npos) res.push_back(p);
            });
        return res;
    }

    bool removeById(int id) {
        auto it = std::remove_if(items.begin(), items.end(),
            [id](const std::shared_ptr<T>& p) 
            { 
                return p->getId() == id; 
            });
        if (it != items.end()) {
            items.erase(it, items.end());
            return true;
        }
        return false;
    }

    size_t count() const { return items.size(); }
};


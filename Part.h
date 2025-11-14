#pragma once
#include <string>
#include <iostream>


class Part {
protected:
    int id;
    std::string name;
    std::string material;
    double diameter;

public:
    Part(int id, const std::string& name, const std::string& material, double diameter);
    virtual ~Part() = default;

    int getId() const;
    std::string getName() const;
    std::string getMaterial() const;
    double getDiameter() const;

    virtual std::string typeName() const = 0;
    virtual void print(std::ostream& os) const;

    // operator overloads
    bool operator==(const Part& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Part& p) {
        p.print(os);
        return os;
    }
};

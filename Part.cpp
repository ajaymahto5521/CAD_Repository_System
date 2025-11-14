// Part.cpp
#include "Part.h"

Part::Part(int id, const std::string& name, const std::string& material, double diameter)
    : id(id), name(name), material(material), diameter(diameter) {
}

int Part::getId() const { return id; }
std::string Part::getName() const { return name; }
std::string Part::getMaterial() const { return material; }
double Part::getDiameter() const { return diameter; }

void Part::print(std::ostream& os) const {
    os << "[" << typeName() << "] ID: " << id
        << ", Name: " << name
        << ", Material: " << material
        << ", Diameter: " << diameter;
}

bool Part::operator==(const Part& other) const {
    return this->id == other.id;
}

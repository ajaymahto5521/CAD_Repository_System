#include "Valve.h"
#include <stdexcept>

Valve::Valve(int id, const std::string& name, const std::string& material,
    double diameter, ValveType vtype, double pressureRating)
    : Part(id, name, material, diameter), vtype(vtype), pressureRating(pressureRating) {
}

ValveType Valve::getValveType() const { return vtype; }
double Valve::getPressureRating() const { return pressureRating; }

std::string Valve::typeName() const { return "Valve"; }

void Valve::print(std::ostream& os) const {
    Part::print(os);
    os << ", ValveType: " << valveTypeToString(vtype)
        << ", PressureRating: " << pressureRating;
}

std::string Valve::valveTypeToString(ValveType vt) {
    switch (vt) {
    case ValveType::Ball: return "Ball";
    case ValveType::Gate: return "Gate";
    case ValveType::Globe: return "Globe";
    case ValveType::Check: return "Check";
    }
    return "Unknown";
}

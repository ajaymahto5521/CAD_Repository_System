#include "Elbow.h"

Elbow::Elbow(int id, const std::string& name, const std::string& material,
    double diameter, double angleDeg)
    : Part(id, name, material, diameter), angleDeg(angleDeg) {
}

double Elbow::getAngle() const { return angleDeg; }

std::string Elbow::typeName() const { return "Elbow"; }

void Elbow::print(std::ostream& os) const {
    Part::print(os);
    os << ", AngleDeg: " << angleDeg;
}

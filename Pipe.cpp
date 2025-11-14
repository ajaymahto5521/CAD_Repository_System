#include "Pipe.h"
#include <sstream>

Pipe::Pipe(int id, const std::string& name, const std::string& material,
    double diameter, double length, double thickness)
    : Part(id, name, material, diameter), length(length), thickness(thickness) {
}

double Pipe::getLength() const { return length; }
double Pipe::getThickness() const { return thickness; }

std::string Pipe::typeName() const { return "Pipe"; }

void Pipe::print(std::ostream& os) const {
    Part::print(os);
    os << ", Length: " << length << ", Thickness: " << thickness;
}

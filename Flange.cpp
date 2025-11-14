#include "Flange.h"

Flange::Flange(int id, const std::string& name, const std::string& material,
    double diameter, const std::string& flangeType, int boltCount)
    : Part(id, name, material, diameter), flangeType(flangeType), boltCount(boltCount) {
}

std::string Flange::getFlangeType() const { return flangeType; }
int Flange::getBoltCount() const { return boltCount; }

std::string Flange::typeName() const { return "Flange"; }

void Flange::print(std::ostream& os) const {
    Part::print(os);
    os << ", FlangeType: " << flangeType << ", BoltCount: " << boltCount;
}

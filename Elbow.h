#pragma once
#include "Part.h"

class Elbow : public Part {
    double angleDeg; 
public:
    Elbow(int id, const std::string& name, const std::string& material,
        double diameter, double angleDeg);
    virtual ~Elbow() = default;

    double getAngle() const;
    virtual std::string typeName() const override;
    virtual void print(std::ostream& os) const override;
};


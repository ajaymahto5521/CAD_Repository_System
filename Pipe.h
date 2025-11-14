#pragma once
#include "Part.h"

class Pipe : public Part {
    double length;
    double thickness;
public:
    Pipe(int id, const std::string& name, const std::string& material,
        double diameter, double length, double thickness);
    virtual ~Pipe() = default;

    double getLength() const;
    double getThickness() const;

    virtual std::string typeName() const override;
    virtual void print(std::ostream& os) const override;
};

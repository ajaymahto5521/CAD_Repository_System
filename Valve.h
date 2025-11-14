#pragma once
#include "Part.h"

enum class ValveType { Ball, Gate, Globe, Check };

class Valve : public Part {
    ValveType vtype;
    double pressureRating;
public:
    Valve(int id, const std::string& name, const std::string& material,
        double diameter, ValveType vtype, double pressureRating);
    virtual ~Valve() = default;

    ValveType getValveType() const;
    double getPressureRating() const;

    virtual std::string typeName() const override;
    virtual void print(std::ostream& os) const override;
    static std::string valveTypeToString(ValveType vt);
};

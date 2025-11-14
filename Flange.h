#pragma once
#pragma once
#include "Part.h"

class Flange : public Part {
    std::string flangeType;
    int boltCount;
public:
    Flange(int id, const std::string& name, const std::string& material,
        double diameter, const std::string& flangeType, int boltCount);
    virtual ~Flange() = default;

    std::string getFlangeType() const;
    int getBoltCount() const;

    virtual std::string typeName() const override;
    virtual void print(std::ostream& os) const override;
};


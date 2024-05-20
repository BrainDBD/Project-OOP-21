#ifndef ANYCARD_H
#define ANYCARD_H

#include <iostream>

class AnyCard
{
public:
    virtual std::string getType() const = 0;
};

#endif  // ANYCARD_H

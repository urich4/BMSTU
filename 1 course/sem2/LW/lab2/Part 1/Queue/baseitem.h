#ifndef BASEITEM_H
#define BASEITEM_H

#include <string>
#include <cstdio>
class BaseItem
{
public:
    virtual std::string toString() const = 0;
    virtual bool isString() const = 0;
    virtual ~BaseItem() = default;
};

class IntItem: public BaseItem
{
    int number;
public:
    IntItem(int n): number(n) {};
    std::string toString() const override;
    bool isString() const override;
    ~IntItem() override;
};

class StrItem: public BaseItem
{
    std::string str;
public:
    StrItem(std::string s): str(s) {}
    std::string toString() const override;
    bool isString() const override;
    ~StrItem() override;
};
#endif // BASEITEM_H

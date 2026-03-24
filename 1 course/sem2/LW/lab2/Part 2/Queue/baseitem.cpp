#include "baseitem.h"

std::string IntItem::toString() const {
    return std::to_string(number);
}
bool IntItem::isString() const {
    return 0;
}
IntItem::~IntItem() {

}

std::string StrItem::toString() const {
    return str;
}
bool StrItem::isString() const {
    return 1;
}
StrItem::~StrItem() {

}

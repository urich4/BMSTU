// ... existing code ...
#include "student.h"

Student::Student() : name("") {}

Diplom::Diplom() : Student(), date(QDate()) {}

QString Student::getName() const
{
    return name;
}

QDate Diplom::getDef() const {
    return date;
}

void Group::addGroup(const Diplom &student){
    students.append(student);
}

QVector<Diplom> Group::findByDate(const QDate &targetDate) const {
    QVector<Diplom> result;

    for (const auto &student: students){
        if (student.getDef() == targetDate)
            result.append(student);
    }

    if (result.isEmpty()){
        throw NotFoundException("Защит в указанную дату не найдено.");
    }
    return result;
}

QVector<Diplom> Group::getAllStudents() const {
    return students;
}

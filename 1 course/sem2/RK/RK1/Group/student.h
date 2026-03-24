// ... existing code ...
#include <QString>
#include <QDate>
#include <QVector>
#include <stdexcept>
#include <string>

class NotFoundException : public std::runtime_error {
public:
    NotFoundException(const std::string& msg) : std::runtime_error(msg) {}
};

class Student
{
    QString name;
public:
    Student();
    Student(QString n): name(n){}
    QString getName() const;
};

class Diplom: public Student
{
    QDate date;
public:
    Diplom();
    Diplom(QString n, QDate d): Student(n), date(d){}
    QDate getDef() const;
};

class Group
{
    QVector<Diplom> students;
public:
    void addGroup(const Diplom &student);
    QVector<Diplom> findByDate(const QDate & targetDate) const;
    QVector<Diplom> getAllStudents() const;
};



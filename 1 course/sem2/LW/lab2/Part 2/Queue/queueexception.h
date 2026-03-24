#ifndef QUEUEEXCEPTION_H
#define QUEUEEXCEPTION_H

#include <string>

class QueueException
{
    std::string message;
public:
    QueueException(std::string s): message(s) {}
    std::string getMessage();
};

class QueueEmptyException: public QueueException{
public:
    QueueEmptyException(): QueueException("Ошибка: попытка удаления из пустой очереди!"){}
};

class InvalidDataException: public QueueException
{
public:
    InvalidDataException():QueueException("Ошибка: введено некорректное число!"){}
};


#endif // QUEUEEXCEPTION_H

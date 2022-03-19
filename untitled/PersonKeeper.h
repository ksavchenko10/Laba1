#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H

#endif // PERSONKEEPER_H

#include <string>
#include <iostream>
#include "Person.h"
#include "stack.cpp"

class PersonKeeper //класс для работы со стеком
{

    public:
        static PersonKeeper* instance(); //создаем либо возвращаем экземпляр нашего класса
        STACK <Person>* readPersons(std::istream& stream); //метод чтения данных из файла и возвращения стека
        void writePersons(STACK <Person> a, std::ostream &stream); //запись данных в файл

    private:
        static PersonKeeper* singleton; //переменная которая хранит наш экземпляр класса
};

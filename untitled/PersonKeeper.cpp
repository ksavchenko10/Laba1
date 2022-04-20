/*#include "PersonKeeper.h"
#include "Person.h"
#include "stack.cpp"
#include <iostream>



PersonKeeper* PersonKeeper::singleton = NULL; //изначально экземпляр класса равен NULL, пока не будет объявлен

PersonKeeper* PersonKeeper::instance()  //Реализация паттерна Singleton
{
    if (singleton == NULL) //если экземпляра этого класса еще нет, то создаем его
    {
        singleton = new PersonKeeper;
    }

    return singleton; //если экземпляр этого класса уже есть, отдаем его же
}

STACK <Person>* PersonKeeper::readPersons(std::istream& stream) //чтение из файла
{
    std::string name, surname, patronymic;
    STACK <Person>* st; //создаем стек из экземпляров класса Person
    st = new STACK <Person>();
    while (stream >> name >> surname >> patronymic) //пока в потоке stream будут данные для чтения (3 строковых: имя фамилия отчество)
    {
        Person pers; //создаем экземпляр класса Person
        pers.setFirstName(name); //Задаем имя
        pers.setLastName(surname); //Задаем фамилию
        std::cout << surname;
        st->push(pers); //Добавляем экземляр класса Person в наш стек st
    }

    return st; //Возвращаем наш стек
}

void PersonKeeper::writePersons(STACK <Person> a, std::ostream &stream) //запись стека с именами и фамилиями в файл, передаем стек с данными и поток вывода
{
    while (!(a.IsEmpty())) //если стек еще не пуст, проходим дальше
    {
        Person p = a.pop(); //берем из стека верхний элемент
        stream << p.getFirstName() << " " << p.getLastName() <<  std::endl; //выводим в поток имя и фамилию
    }
}
*/

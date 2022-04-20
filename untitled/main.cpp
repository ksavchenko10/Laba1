#include <QCoreApplication>

#include <iostream>
#include <string>
#include <fstream>


template <typename T>

class STACK //класс для реализации стека
{
private:
    T* stack; //стек
    int count; //количество элементов в стеке

public:
    void push(T item) //добавить элемент в стек
    {
        T* tmp; //временная переменная указатель
        tmp = stack;
        stack = new T[count + 1]; //выделить больше памяти в стеке чем было

        count++; //количество элементов в стеке увеличиваем

        for (int i = 0; i < count - 1; i++)
        {
            stack[i] = tmp[i]; //копируем данные из tmp (куда он указывает) в наш стек
        }

        stack[count - 1] = item; //добавляем последний элемент

        if (count > 1)
        {
            delete[] tmp; //освобождаем память
        }
    }

    T pop() //изъять элемент из стека
    {
        T tmp;
        if (count == 0) //если наш стек пуст
        {
            return tmp;
        }

        count--; //уменьшаем количество элементов в стеке
        return stack[count]; //возвращаем  элемент стека
    }

    bool IsEmpty() //если наш стек пуст
    {
        return count == 0; //если количество элементов в стеке равна 0
    }

};


class Person
{
private:
    long key;
    std::string last_name; //Имя
    std::string first_name; //Фамилия
public:
    Person(); //Конструктор
    Person(const Person&); //Конструктор
    const std::string& getLastName() const { return last_name; }; //Получить фамилию
    const std::string& getFirstName() const { return first_name; }; //Получить имя
    void setLastName(const std::string&); //Изменить фамилию
    void setFirstName(const std::string&); //Изменить имя
};

Person::Person()
{
    key = 1;
    first_name = "NAME";
    last_name = "SURNAME";
}

Person::Person(const Person& value)
{
    first_name = value.getFirstName(); //При создании экземпляра ласса копируем переданные значения имени и фамилии экземпляра этого же класса
    last_name = value.getLastName();

}

void Person::setLastName(const std::string& value)
{
    last_name = value;
}

void Person::setFirstName(const std::string& value)
{
    first_name = value;
}

class PersonKeeper //класс для работы со стеком
{

public:
    static PersonKeeper* instance(); //создаем либо возвращаем экземпляр нашего класса-синглтон
    STACK <Person>* readPersons(std::istream& stream); //метод чтения данных из файла и возвращения стека
    void writePersons(STACK <Person> a, std::ostream& stream); //запись данных в файл

private:
    static PersonKeeper* singleton; //переменная которая хранит наш экземпляр класса-синглтона
};

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

void PersonKeeper::writePersons(STACK <Person> a, std::ostream& stream) //запись стека с именами и фамилиями в файл, передаем стек с данными и поток вывода
{
    while (!(a.IsEmpty())) //если стек еще не пуст, проходим дальше
    {
        Person p = a.pop(); //берем из стека верхний элемент
        stream << p.getFirstName() << " " << p.getLastName(); //выводим в поток имя и фамилию
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PersonKeeper personKeeperInstance;	//создаем экземпляр класса personKeeperInstance

        std::fstream file_in;
        file_in.open("vvod.txt"); // открываем файл для чтения

        STACK <Person> st;	//создаем стэк из элементов стека класса Person
        st = *personKeeperInstance.readPersons(file_in); // метод readPersons возвращает стек с объектами класса Person

        file_in.close(); //закрывает поток чтения из файла

        std::fstream file_out;
        file_out.open("vyvod.txt"); //открываем файл для записи

        personKeeperInstance.writePersons(st, file_out); //записываем в файл данные из стека

        file_out.close();

    return a.exec();
}

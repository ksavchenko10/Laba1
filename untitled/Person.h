#include <string>

class Person
{
    private:
        long key;
<<<<<<< HEAD
        std::string last_name; //Имя
        std::string first_name; //Фамилия
    public:
        Person(); //Конструктор
        Person(const Person&); //Конструктор
        const std::string& getLastName() const { return last_name;}; //Получить фамилию
        const std::string& getFirstName() const { return first_name;}; //Получить имя
        void setLastName(const std::string&); //Изменить фамилию
        void setFirstName(const std::string&); //Изменить имя
=======
        std::string last_name;
        std::string first_name;
    public:
        Person();
        Person(const Person&);
        const std::string& getLastName() const { return last_name;};
        const std::string& getFirstName() const { return first_name;};
        void setLastName(const std::string&);
        void setFirstName(const std::string&);
>>>>>>> main
};

Person::Person()
{
    key = 1;
    first_name = "NAME";
    last_name = "SURNAME";
}

Person::Person(const Person& value)
{
<<<<<<< HEAD
    first_name = value.getFirstName(); //При создании экземпляра класса копируем переданные значения имени и фамилии экземпляра этого же класса
=======
    first_name = value.getFirstName();
>>>>>>> main
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

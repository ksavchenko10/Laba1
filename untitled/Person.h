#include <string>

class Person
{
    private:
        long key;
        std::string last_name;
        std::string first_name;
    public:
        Person();
        Person(const Person&);
        const std::string& getLastName() const { return last_name;};
        const std::string& getFirstName() const { return first_name;};
        void setLastName(const std::string&);
        void setFirstName(const std::string&);
};

Person::Person()
{
    key = 1;
    first_name = "NAME";
    last_name = "SURNAME";
}

Person::Person(const Person& value)
{
    first_name = value.getFirstName();
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

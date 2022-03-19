#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H

#endif // PERSONKEEPER_H

#include <string>
#include <iostream>
#include "Person.h"
#include "stack.cpp"

class PersonKeeper
{

    public:
        static PersonKeeper* instance();
        STACK <Person>* readPersons(std::istream& stream);
        void writePersons(STACK <Person> a, std::ostream &stream);

    private:
        static PersonKeeper* singleton;
};

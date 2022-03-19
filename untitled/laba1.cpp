#include <iostream>
#include <fstream>
#include "Person.h"
#include "PersonKeeper.cpp"

int main()
{
    PersonKeeper personKeeperInstance;

        std::fstream file_in;
        file_in.open("vvod.txt");

        STACK <Person> st;
        st = *personKeeperInstance.readPersons(file_in);

        file_in.close();

        std::fstream file_out;
        file_out.open("vyvod.txt");

        personKeeperInstance.writePersons(st, file_out);

        file_out.close();
}

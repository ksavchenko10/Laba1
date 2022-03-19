#include <iostream>
#include <fstream>
#include "Person.h"
#include "PersonKeeper.cpp"

int main()
{
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
}

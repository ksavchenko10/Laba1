#pragma once
#include "PersonKeeper.h"
#include "Person.h"
#include <iostream>

PersonKeeper* PersonKeeper::singleton = NULL; //изначально экземпляр класса равен NULL, пока не будет объявлен

PersonKeeper* PersonKeeper::instance() //Реализация Singleton
{
    if (singleton == NULL) //если экземпляра этого класса еще нет, то создаем его
    {
        singleton = new PersonKeeper;
    }

    return singleton; //если экземпляр этого класса уже есть, отдаем его же
}

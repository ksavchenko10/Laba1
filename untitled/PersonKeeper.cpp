#pragma once
#include "PersonKeeper.h"
#include "Person.h"
#include <iostream>

PersonKeeper* PersonKeeper::singleton = NULL;

PersonKeeper* PersonKeeper::instance()
{
    if (singleton == NULL)
    {
        singleton = new PersonKeeper;
    }

    return singleton;
}

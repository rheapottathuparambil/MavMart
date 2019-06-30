#include <iostream>
#include "store.h"

class View : public Store
{
    public:
    View(Store s);
    std::string main_menu();
    std::string help();

    private:
    Store _store;

};
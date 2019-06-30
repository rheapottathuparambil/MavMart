#include <iostream>
#include "view.h"

class Controller
{
    Store _store;
    View _view;

    public:

    Controller();
    Controller(Store store);
    void cli();
    void execute_cmd(int cmd);
    void add_product();
    void list_all_products();
    void add_order();
    void list_all_orders();
    void easter_egg();
    void help();
};
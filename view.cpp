#include "view.h"
#include <iostream>
#include <sstream>
#include <iomanip>


View::View(Store s) : _store{s} {}

std::string View::main_menu()
{
    std::ostringstream c;
    c << "<span font='16' weight ='bold'>Welcome to C1325 MavMart<sup><small>TM</small></sup></span>\n\n";
    c << "<span weight = 'bold' underline = 'double'>Products</span>\t"<<std::setw(15)<<"<span weight = 'bold' underline = 'double'>Orders</span>\t"<<std::setw(33)<<"<span weight = 'bold' underline = 'double'>Utility</span>\n\n";
    c << "(1) Add product\t"<<std::setw(24)<<"(4) Place order\t"<<std::setw(17)<<"<span color = '#007f00' weight = 'bold'>(9) Help\n</span>";
    c << "(2) List all products\t"<<std::setw(19)<<"(5) List all orders\t"<<std::setw(8)<<"(0) Exit\n";
    c << "Command? ";
    return c.str();
}

std::string View::help()
{
    std::ostringstream d;
    d << "These are the following commmands you can give : \n";
    d << "(0) Exits the program.\n";
    d << "(1) Add product requires you to add products. You will need to provide the name of the product along with the cost for each product.\n";
    d << "(2) List all products will list all the products added.\n";
    d << "(4) Place order requires you to enter in your email address. You will then be asked to enter the product number along with the quantity.\n";
    d << "(5) List all orders will list all the orders.\n";
    d << "(10) Easter egg, adds products for testing.\n";
    return d.str();
}



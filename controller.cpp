#include <iostream>
#include "controller.h"
#include "dialogs.h"

Controller::Controller() : _store{Store{"Mavmart"}} , _view{View{_store}} {}


Controller::Controller(Store s)  : _store{s} , _view{View{s}} {}


void Controller::cli()
{
    int cmd;
    std::string a;
    while (true)
    {
        a = Dialogs::input(_view.main_menu(),"Main Menu","","0");
        cmd  = std::stoi(a);
        execute_cmd(cmd);
    }
}

void Controller::execute_cmd (int cmd)
{
    
    switch (cmd)
    {
        case 1: add_product(); break;
        case 2: list_all_products(); break;
        case 4: add_order(); break;
        case 5: list_all_orders(); break;
        case 9: help(); break;
        case 0: exit(0);

        case 10: easter_egg(); break;

        default: Dialogs::message("Invalid option!", "Error"); break;
        
    }
}


void Controller::add_product()
{
    std::string name;
    std::string c;
    double cost;

    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog-> set_title("Add Product");

    //name
    Gtk::HBox bname;
    Gtk::Label lname{"Name : "};
    lname.set_width_chars(14);
    bname.pack_start(lname,Gtk::PACK_SHRINK);
    Gtk::Entry ename;
    ename.set_max_length(50);
    bname.pack_start(ename,Gtk::PACK_SHRINK);
    dialog-> get_vbox()->pack_start(bname, Gtk::PACK_SHRINK);

    //cost
    Gtk::HBox bcost;
    Gtk::Label lcost{"Cost : "};
    lcost.set_width_chars(14);
    bcost.pack_start(lcost,Gtk::PACK_SHRINK);
    Gtk::Entry ecost;
    ecost.set_max_length(50);
    bcost.pack_start(ecost,Gtk::PACK_SHRINK);
    dialog-> get_vbox()->pack_start(bcost, Gtk::PACK_SHRINK);

    //show dialog
    dialog -> add_button("Cancel",0);
    dialog -> add_button("Ok",1);
    dialog -> show_all();
    int result = dialog -> run();
    dialog -> close();
    while (Gtk::Main::events_pending()) Gtk::Main::iteration();

    name = ename.get_text();
    c = ecost.get_text();
    if(result == 1)
    {   
        cost = std::stoi(c);
        Product p(name, cost);
        _store.add_product(p);
    }
}

void Controller::list_all_products()
{
    if(_store.num_products()==0)
    {
        Dialogs::message("No current products","Error");
        return;
    }
    std::ostringstream c;
    c<<_store;
    Dialogs::message(c.str(),"List of Products");
}
        
void Controller::add_order()
{
    std::string email;
    email = Dialogs::input("Please enter your email address ","Add Order");
    int i = _store.create_order(email);
    int n, q;
    std::string N, Q;
    std::string x;
    while (x != "n")
    {
        std::cout<<"\n\n";
        list_all_products();
        N = Dialogs::input("Enter the product number","Add Product");
        n = std::stoi(N);
        Product p = _store.product(n); 
        Q = Dialogs::input("Enter the quantity","Add Product");
        q = std::stoi(Q);
        Product_order po = Product_order(p,q);  
        _store.add_to_order(i, po); 
        x = Dialogs::input("(y/n)?","Do you want to continue"); 
    }
}

void Controller::list_all_orders()
{
    if(_store.num_orders()==0)
    {
        Dialogs::message("No current orders","Error");
        return;
    }
    
    std::ostringstream c;

    

    int n = _store.num_orders();
    for (int i =0 ; i < n; i++)
    {
       Order o = _store.order(i);
       c <<i<<")"<<o<<"\n";
    }
    Dialogs::message(c.str(),"List of Orders");
}

void Controller::easter_egg()
{
    /*easter_egg() loads a selection of typical product data to accelerate interactive testing prior to 
    implementation of Save and Load (on the bonus level)*/

    std::string name;
    double cost;
    
    name = "Donut";
    cost = 2;
    Product p(name, cost);
    _store.add_product(p);

    name = "Coffee";
   cost = 5;
    p = Product(name, cost);
    _store.add_product(p);

    name = "Burger";
    cost = 3;
    p = Product(name, cost);
    _store.add_product(p);
 
    name = "Pizza";
    cost = 9;
    p= Product(name, cost);
    _store.add_product(p);

    name = "Ice cream";
    cost = 1;
    p= Product(name, cost);
    _store.add_product(p);

}



void Controller::help()
{
    Dialogs::message(_view.help(),"Help!");
}


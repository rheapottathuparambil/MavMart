#include <iostream>
#include <gtkmm.h>
#include "controller.h"

int main(int argc, char* argv[]) 
{

Gtk::Main kit (argc, argv);
Controller controller;
controller.cli();

}



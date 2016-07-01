#include <gtkmm/button.h>
#include <iostream>

void on_button_clicked()
{
    std::cout << "Hello World" << std::endl;
}

int main()
{
    Gtk::Button button("Hello World");
    button.signal_clicked().connect(sigc::ptr_fun(&on_button_clicked));
    return 0;
}

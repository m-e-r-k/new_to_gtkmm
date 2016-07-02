#ifndef _RANDOMIZER_HPP_
#define _RANDOMIZER_HPP_

#include <gtkmm.h> 

class Randomizer : public Gtk::Window
{

public:
	Randomizer();
	virtual ~Randomizer();

	Gtk::Button r_button;
	
};
#endif

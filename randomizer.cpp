#include "randomizer.hpp"
#include <gtkmm.h>

Randomizer::Randomizer() :
r_button("_Randomize", true)
{
	set_title("Generating a random number.");
	set_border_width(10);
	set_default_size(300, 150);
	
	add(r_button);
	show_all_children();
}

Randomizer::~Randomizer()
{
	
}


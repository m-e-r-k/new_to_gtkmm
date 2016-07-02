#ifndef _RANDOMIZER_HPP_
#define _RANDOMIZER_HPP_

#include <gtkmm.h> 


class Randomizer : public Gtk::Window
{

public:
	Randomizer();
	virtual ~Randomizer();

enum Limit
{
	Left,
	Right
};

//Widgets
	Gtk::Frame range, prev_numb_frame;
	Gtk::Box init, left, right, from_box, to_box, range_box;
	Gtk::Label label_from, label_to, text, label_last_number;
	Glib::RefPtr<Gtk::Adjustment> adj_from, adj_to;
	Gtk::SpinButton button_from, button_to;
	Gtk::Button generate;
	Gtk::Entry last_number;

//Signal handlers
	void generate_number();
	void monitor_limits(Limit limit);

};

#endif

#include "randomizer.hpp"
#include <ctime>
#include <string>
#include <iostream>

Randomizer::Randomizer()
:
	range("Range"),
	prev_numb_frame("Previous random numbers"),
	init(Gtk::ORIENTATION_HORIZONTAL, 10),
	left(Gtk::ORIENTATION_VERTICAL, 10),
	right(Gtk::ORIENTATION_VERTICAL, 10),
	from_box(Gtk::ORIENTATION_VERTICAL, 5),
	to_box(Gtk::ORIENTATION_VERTICAL, 5),
	range_box(Gtk::ORIENTATION_HORIZONTAL, 10),
	label_from("From: ", Gtk::ALIGN_CENTER),
	label_to("To: ", Gtk::ALIGN_CENTER),
	label_last_number("Result: ", Gtk::ALIGN_CENTER),
	text(),
	adj_from(Gtk::Adjustment::create(0.0, -32768.0, 32767, 1.0, 100.0, 0.0)),
	adj_to(Gtk::Adjustment::create(1.0, -32768.0, 32767, 1.0, 100.0, 0.0)),
	button_from(adj_from),
	button_to(adj_to),
	generate("_Generate", true)

{
	srand(time(0));
	
	set_title("Generating a random number.");
	set_border_width(10);
	set_default_size(600, 300);
	
	//Packing widgets
	add(init);
	init.pack_start(left);
	init.pack_start(right);
	
	left.pack_start(range);
	left.pack_end(generate);
	
	range.add(range_box);
	
	range_box.pack_start(from_box);
	range_box.pack_start(to_box);
	
	from_box.pack_start(label_from);
	from_box.pack_start(button_from);
	
	to_box.pack_start(label_to);
	to_box.pack_start(button_to);
	
	right.pack_start(label_last_number);
	right.pack_start(last_number);
	right.pack_end(prev_numb_frame);
	
	prev_numb_frame.add(text);
	
	//Customizing widgets
	
	button_from.set_wrap();
	button_to.set_wrap();
	button_from.set_numeric();
	button_to.set_numeric();
	
	
	last_number.set_editable(false);
	
	
	
	//Connecting signals
	generate.signal_clicked().connect(sigc::mem_fun(*this, &Randomizer::generate_number));
	adj_from->signal_value_changed().connect(sigc::bind(sigc::mem_fun(*this, 
					&Randomizer::monitor_limits), Left));
	adj_to->signal_value_changed().connect(sigc::bind(sigc::mem_fun(*this, 
					&Randomizer::monitor_limits), Right));
	
	//
	show_all_children();
}

Randomizer::~Randomizer()
{
	
}

void Randomizer::generate_number()
{
	if(last_number.get_text_length())
	{
		if(!text.get_text().empty())
			text.set_text(text.get_text() + Glib::ustring(", ") + last_number.get_text());
		else
			text.set_text(last_number.get_text());
	}
	
	int range = button_to.get_value() - button_from.get_value() + 1;
	int r_num = rand();
	if(range)
	{
		std::string Str = std::to_string((short)(button_from.get_value() + r_num%range));

		last_number.set_text(Glib::ustring(Str));
	}

}

void Randomizer::monitor_limits(Limit limit)
{
	if(button_from.get_value() >= button_to.get_value())
	{
		if(limit == Left)
			button_from.set_value(button_to.get_value() - 1);
		else
			button_to.set_value(button_from.get_value() + 1);
	}
}

#include "randomizer.hpp"
#include <gtkmm.h>

int main(int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app =
    Gtk::Application::create(argc, argv,
      "org.gtkmm.examples.base");

	Randomizer Rand_Window;

  return app->run(Rand_Window);
}

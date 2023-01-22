#include <ruby.h>

#include "extconf.h"
#if defined(__APPLE__)
	#include <ApplicationServices/ApplicationServices.h>
#elif defined(__linux__)
	#include <X11/Xlib.h>
	#include "xdisplay.h"
#endif


static VALUE display_info_dimensions(VALUE none);

void Init_display_info()
{
  VALUE mod = rb_define_module("DisplayInfo");
  rb_define_singleton_method(mod, "dimensions", display_info_dimensions, 0);
}


static VALUE display_info_dimensions(VALUE none)
{
  size_t width = 0;
  size_t height = 0;

#if defined(__APPLE__)
	CGDirectDisplayID displayID = CGMainDisplayID();
  width  = CGDisplayPixelsWide(displayID);
  height = CGDisplayPixelsHigh(displayID);
  
#elif defined(__linux__)
	Display *display = XGetMainDisplay();
	const int screen = DefaultScreen(display);
	width  = (size_t)DisplayWidth(display, screen);
  height = (size_t)DisplayHeight(display, screen);
  
#elif defined _WIN32 || defined _WIN64
  width  = (size_t)GetSystemMetrics(SM_CXSCREEN);
  height = (size_t)GetSystemMetrics(SM_CYSCREEN);
#else
#warning Unknown OS
#endif

  VALUE hash = rb_hash_new();
  rb_hash_aset(hash, rb_str_new2("width"), INT2FIX(width));
  rb_hash_aset(hash, rb_str_new2("height"), INT2FIX(height));

  return hash;
}

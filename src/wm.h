#ifndef WM_H_
#define WM_H_

#include <list>
#include "geom.h"

class Window;

class WindowManager {
private:
	std::list<Window*> windows;
	std::list<Rect> dirty_rects;

	int bg_color[3];
	Window *focused_win;

public:
	WindowManager();

	void invalidate_region(const Rect &rect);
	void process_windows();

	void add_window(Window *win);

	void set_focused_window(Window *win);
	const Window *get_focused_window() const;
	Window *get_focused_window();
};

extern WindowManager *wm;

#endif	// WM_H_

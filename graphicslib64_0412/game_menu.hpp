#ifndef GAME_MENU_HPP_INCLUDED
#define GAME_MENU_HPP_INCLUDED

#include "Widgets.hpp"
#include "Application.hpp"

class Menu:public Widgets{
protected:
    int screen_x;
    int screen_y;
public:
    Menu(Application *,int px,int py,int sx, int sy,int scx,int scy);
    void draw(genv::event ev);
    int handle(genv::event ev,int par);
};

#endif // GAME_MENU_HPP_INCLUDED

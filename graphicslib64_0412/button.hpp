#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "Widgets.hpp"
#include "Application.hpp"

class Button:public Widgets{
protected:
    int r;
    int g;
    int b;
    std::string text;
    int mode;
    genv::canvas xkep;
    genv::canvas korkep;
public:
    Button(Application *,int px,int py,int sx, int sy,int pr,int pg,int pb,std::string pt,genv::canvas pxkep,genv::canvas pkorkep);
    void draw(genv::event ev);
    int handle(genv::event ev,int par);
    bool is_selected(int eger_x, int eger_y);
    int get_int_value();
    void restart();
};

#endif // BUTTON_HPP_INCLUDED

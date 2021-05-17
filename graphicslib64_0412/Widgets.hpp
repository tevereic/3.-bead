#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

class Application;

class Widgets{
protected:
    int size_x,size_y,pos_x,pos_y;
    Application *parent;
public:
    Widgets(Application*,int px,int py,int sx, int sy);
    virtual bool is_selected(int eger_x, int eger_y);
    virtual void draw(genv::event ev)=0;
    virtual int handle(genv::event ev,int par)=0;
};

#endif // WIDGETS_HPP_INCLUDED

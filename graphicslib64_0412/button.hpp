#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include <functional>
#include "Widgets.hpp"
#include "Application.hpp"

class Button:public Widgets{
protected:
    int r;
    int g;
    int b;
    std::string text;
    int mode;
public:
    Button(Application *,int px,int py,int sx, int sy,int pr,int pg,int pb,std::string pt);
    void draw(genv::event ev);
    void handle(genv::event ev);
};

#endif // BUTTON_HPP_INCLUDED

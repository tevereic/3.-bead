#include "button.hpp"
#include "graphics.hpp"
//#include <iostream>

using namespace genv;

Button::Button(Application*p,int px,int py,int sx, int sy,int pr, int pg, int pb,std::string pt):Widgets(p,px,py,sx,sy){
    r=pr;
    g=pg;
    b=pb;
    text=pt;
    mode=0;
}

void Button::draw(event ev){
    gout<<color(r,g,b);
    gout<<move_to(pos_x*size_x+pos_x+1,pos_y*size_y+pos_y+1)<<box(size_x,size_y);
    if (mode==1){

    }
    else if (mode==2){

    }
}

int Button::handle(event ev){
    return 0;
}

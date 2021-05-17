#include "button.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;

Button::Button(Application*p,int px,int py,int sx, int sy,int pr, int pg, int pb,std::string pt,canvas pxkep,canvas pkorkep):Widgets(p,px,py,sx,sy){
    r=pr;
    g=pg;
    b=pb;
    text=pt;
    mode=0;
    xkep=pxkep;
    korkep=pkorkep;
}

void Button::draw(event ev){
    gout<<color(r,g,b);
    gout<<move_to(pos_x*size_x+pos_x+1,pos_y*size_y+pos_y+1)<<box(size_x,size_y);
    if (mode==1){
        gout<<stamp(xkep,pos_x*size_x+pos_x+1,pos_y*size_y+pos_y+1);
    }
    else if (mode==2){
        gout<<stamp(korkep,pos_x*size_x+pos_x+1,pos_y*size_y+pos_y+1);
    }
}

int Button::handle(event ev,int par){
    if (mode==0){
        if (ev.button==btn_left){
            if (par==10){
                mode=1;
            }
            else if (par==11){
                mode=2;
            }
        }
    }
    //std::cout<<"hand"<<std::endl;
    return mode;
}

int Button::get_int_value(){
    return mode;
}

bool Button::is_selected(int eger_x, int eger_y){
    return eger_x>=pos_x*size_x+pos_x+1 && eger_x<=(pos_x*size_x+pos_x+1+size_x) && eger_y>=pos_y*size_y+pos_y+1 && eger_y<=(pos_y*size_y+pos_y+1+size_y);
}

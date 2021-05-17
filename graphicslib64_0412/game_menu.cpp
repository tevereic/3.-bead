#include "game_menu.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;

Menu::Menu(Application*p,int px,int py,int sx, int sy,int scx,int scy):Widgets(p,px,py,sx,sy){
    screen_x=scx;
    screen_y=scy;
}

void Menu::draw(event ev){
    gout.load_font("LiberationSerif-Bold.ttf",66);
    if (ev.pos_x>screen_x/2-gout.twidth("Play")/2 && ev.pos_x<screen_x/2+gout.twidth("Play")/2 && ev.pos_y>screen_y/2.5 && ev.pos_y<screen_y/2.5+gout.cascent()+gout.cdescent()){
        gout<<move_to(screen_x/2-gout.twidth("Play")/2-10,screen_y/2.5-10)<<color(0,191,255)<<box(gout.twidth("Play")+20,gout.cascent()+gout.cdescent()+20);
        gout<<move_to(screen_x/2-gout.twidth("Play")/2-5,screen_y/2.5-5)<<color(0,0,0)<<box(gout.twidth("Play")+10,gout.cascent()+gout.cdescent()+10);
    }
    else if (ev.pos_x>screen_x/2-gout.twidth("Exit")/2 && ev.pos_x<screen_x/2+gout.twidth("Exit")/2 && ev.pos_y>screen_y/1.6 && ev.pos_y<screen_y/1.6+gout.cascent()+gout.cdescent()){
        gout<<move_to(screen_x/2-gout.twidth("Exit")/2-10,screen_y/1.6-10)<<color(0,191,255)<<box(gout.twidth("Exit")+20,gout.cascent()+gout.cdescent()+20);
        gout<<move_to(screen_x/2-gout.twidth("Exit")/2-5,screen_y/1.6-5)<<color(0,0,0)<<box(gout.twidth("Exit")+10,gout.cascent()+gout.cdescent()+10);
    }
    gout<<move_to(screen_x/2-gout.twidth("Amoeba")/2,screen_y/10)<<color(255,69,0)<<text("Amoeba");
    gout<<move_to(screen_x/2-gout.twidth("Play")/2,screen_y/2.5)<<color(0,191,255)<<text("Play");
    gout<<move_to(screen_x/2-gout.twidth("Exit")/2,screen_y/1.6)<<color(0,191,255)<<text("Exit");

    //std::cout<<"rajzol"<<std::endl;
}

int Menu::handle(event ev,int par){
    if (ev.pos_x>screen_x/2-gout.twidth("Play")/2 && ev.pos_x<screen_x/2+gout.twidth("Play")/2 && ev.pos_y>screen_y/2.5 && ev.pos_y<screen_y/2.5+gout.cascent()+gout.cdescent() && ev.button==btn_left){
        return 1;
    }
    else if (ev.pos_x>screen_x/2-gout.twidth("Exit")/2 && ev.pos_x<screen_x/2+gout.twidth("Exit")/2 && ev.pos_y>screen_y/1.6 && ev.pos_y<screen_y/1.6+gout.cascent()+gout.cdescent() && ev.button==btn_left){
        return 3;
    }
    else{
        return 0;
    }
}

int Menu::get_int_value(){
    return 0;
}

void Menu::restart(){
}

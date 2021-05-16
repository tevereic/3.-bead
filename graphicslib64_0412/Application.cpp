#include "Application.hpp"
#include "graphics.hpp"
#include <vector>

using namespace genv;

Application::Application(){}

void Application::event_loop(int XX,int YY){
    event ev;
    selected=-1;
    while (gin>>ev && ev.keycode != key_escape){
        gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY);
        //gout<<move_to(XX/2,YY/2)<<color(255,255,255)<<text("press enter to write in file");
        //std::cout<<XX<<" "<<YY<<std::endl;
        if (ev.type == ev_mouse && ev.button == btn_left){
            for (unsigned int i=0;i<widgetek.size();i++){
                if (widgetek[i]->is_selected(ev.pos_x,ev.pos_y)){
                    selected=i;
                }
            }
        }
        if (selected >= 0){
            widgetek[selected]->handle(ev);
        }
        for (unsigned int i=0;i<widgetek.size();i++){
            widgetek[i]->draw(ev);
        }
        gout<<refresh;
    }

}

void Application::registerWidget(Widgets* w){
    widgetek.push_back(w);
}

int Application::get_selected(){
    return selected;
}

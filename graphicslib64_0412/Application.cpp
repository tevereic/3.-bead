#include "Application.hpp"
#include "graphics.hpp"
#include <vector>
#include <iostream>

using namespace genv;

Application::Application(){
    game_mode=0;
    player=10;
}

void Application::menu(event ev){
    widgetek[0]->draw(ev);
    game_mode=widgetek[0]->handle(ev,0);
}

void Application::the_game_itself(event ev){
    if (ev.type == ev_mouse && ev.button == btn_left){
            for (unsigned int i=1;i<widgetek.size();i++){
                if (widgetek[i]->is_selected(ev.pos_x,ev.pos_y)){
                    selected=i;
                }
            }
            if (selected >= 0){
                if (widgetek[selected]->get_int_value()==0){
                    if (widgetek[selected]->handle(ev,player)!=0){
                        if (player==10){
                            player=11;
                        }
                        else{
                            player=10;
                        }
                    }
                }
            }
        }
        /*if (selected >= 0){
            if (widgetek[selected]->handle(ev,player)!=0){
                if (player==10){
                    player=11;
                }
                else{
                    player=10;
                }
            }
        }*/
        for (unsigned int i=1;i<widgetek.size();i++){
            widgetek[i]->draw(ev);
        }
}

void Application::game_over(event ev){

}

void Application::event_loop(int XX,int YY){
    event ev;
    selected=-1;
    while (gin>>ev && ev.keycode != key_escape){
        gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY);
        //gout<<move_to(XX/2,YY/2)<<color(255,255,255)<<text("press enter to write in file");
        //std::cout<<XX<<" "<<YY<<std::endl;
        if (game_mode==0){
            menu(ev);
        }
        else if(game_mode==1){
            the_game_itself(ev);
        }
        else if (game_mode==2){
            game_over(ev);
        }
        else if (game_mode==3){
            break;
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

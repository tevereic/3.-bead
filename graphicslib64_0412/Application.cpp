#include "Application.hpp"
#include "graphics.hpp"
#include <vector>
#include <iostream>

using namespace genv;
using namespace std;

Application::Application(){
    game_mode=0;
    player=10;
    is_win=false;
    screen_x=700;
    screen_y=700;
}

int Application::win_condition(int player_par){
    int alak=player_par-9;
    bool vanwin=false;
    vector<vector<int>> alakvector=vector<vector<int>>(20,vector<int>(20,0));
    for (unsigned int i=1;i<widgetek.size();i++){
        if (widgetek[i]->get_int_value()==alak){
            alakvector[widgetek[i]->get_pos_x()][widgetek[i]->get_pos_y()]=1;
        }
    }
    for (unsigned int i=0;i<alakvector.size()-4;i++){
        for (unsigned int j=0;j<alakvector[i].size()-4;j++){
            if (alakvector[i][j]==1){
                if (alakvector[i][j+1]==1 && alakvector[i][j+2]==1 && alakvector[i][j+3]==1 && alakvector[i][j+4]==1){
                    vanwin=true;
                    break;
                }
                if (alakvector[i+1][j]==1 && alakvector[i+2][j]==1 && alakvector[i+3][j]==1 && alakvector[i+4][j]==1){
                    vanwin=true;
                    break;
                }
                if (alakvector[i+1][j+1]==1 && alakvector[i+2][j+2]==1 && alakvector[i+3][j+3]==1 && alakvector[i+4][j+4]==1){
                    vanwin=true;
                    break;
                }
            }
        }
        if (vanwin){
            break;
        }
    }
    if (!vanwin){
        for (unsigned int i=0;i<alakvector.size()-4;i++){
            for (unsigned int j=4;j<alakvector[i].size();j++){
                if (alakvector[i][j]==1){
                    if (alakvector[i+1][j-1]==1 && alakvector[i+2][j-2]==1 && alakvector[i+3][j-3]==1 && alakvector[i+4][j-4]==1){
                        vanwin=true;
                        break;
                    }
                }
            }
            if (vanwin){
                break;
            }
        }
    }
    if (!vanwin){
        int counter=0;
        for (unsigned int i=1;i<widgetek.size();i++){
            if (widgetek[i]->get_int_value()!=0){
                counter++;
            }
        }
        if (counter>=400){
            alak=3;
            vanwin=true;
        }
    }
    if (vanwin){
        return alak;
    }
    else{
        return 0;
    }
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
                        is_win=win_condition(player);
                        if (is_win>0){
                            game_mode=2;
                        }
                    }
                }
            }
        }
        for (unsigned int i=1;i<widgetek.size();i++){
            widgetek[i]->draw(ev);
        }
}

void Application::game_over(event ev,int nyertes){
    if (nyertes==2){
        gout<<move_to(screen_x/2-gout.twidth("Circle wins!")/2,screen_y/3)<<color(255,215,0)<<text("Circle wins!");
    }
    else if (nyertes==1){
        gout<<move_to(screen_x/2-gout.twidth("Cross wins!")/2,screen_y/3)<<color(255,215,0)<<text("Cross wins!");
    }
    else{
        gout<<move_to(screen_x/2-gout.twidth("Draw")/2,screen_y/3)<<color(70,130,180)<<text("Draw");
    }
    if (ev.pos_x>screen_x/2-gout.twidth("Restart")/2 && ev.pos_x<screen_x/2+gout.twidth("Restart")/2 && ev.pos_y>screen_y/1.6 && ev.pos_y<screen_y/1.6+gout.cascent()+gout.cdescent()){
        gout<<move_to(screen_x/2-gout.twidth("Restart")/2-10,screen_y/1.6-10)<<color(255,165,0)<<box(gout.twidth("Restart")+20,gout.cascent()+gout.cdescent()+20);
        gout<<move_to(screen_x/2-gout.twidth("Restart")/2-5,screen_y/1.6-5)<<color(0,0,0)<<box(gout.twidth("Restart")+10,gout.cascent()+gout.cdescent()+10);
        if (ev.button==btn_left){
            game_mode=1;
            for (unsigned int i=1;i<widgetek.size();i++){
                widgetek[i]->restart();
            }
        }
    }
    gout<<move_to(screen_x/2-gout.twidth("Restart")/2,screen_y/1.6)<<color(255,165,0)<<text("Restart");
}

void Application::event_loop(int XX,int YY){
    event ev;
    selected=-1;
    while (gin>>ev && ev.keycode != key_escape){
        gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY);
        if (game_mode==0){
            menu(ev);
        }
        else if(game_mode==1){
            the_game_itself(ev);
        }
        else if (game_mode==2){
            game_over(ev,is_win);
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

void Application::set_screen_x_y(int px,int py){
    screen_x=px;
    screen_y=py;
}

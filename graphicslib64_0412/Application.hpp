#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "Widgets.hpp"
#include "graphics.hpp"
#include <vector>

class Application{
protected:
    std::vector <Widgets*> widgetek;
    int selected;
    int game_mode;
    int player;
    int is_win;
    int screen_x,screen_y;
public:
    Application();
    virtual ~Application(){}
    void run(int XX,int YY);
    void registerWidget(Widgets*);
    int get_selected();
    void menu(genv::event ev);
    void the_game_itself(genv::event ev);
    void game_over(genv::event ev,int nyertes);
    int win_condition(int player_par);
    void set_screen_x_y(int px,int py);
};

#endif // APPLICATION_HPP_INCLUDED

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
public:
    Application();
    virtual ~Application(){}
    void event_loop(int XX,int YY);
    void registerWidget(Widgets*);
    int get_selected();
    void menu(genv::event ev);
    void the_game_itself(genv::event ev);
    void game_over(genv::event ev);
};

#endif // APPLICATION_HPP_INCLUDED

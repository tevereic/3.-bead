#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "Widgets.hpp"
#include "graphics.hpp"
#include <vector>

class Application{
protected:
    std::vector <Widgets*> widgetek;
    int selected;
public:
    Application();
    virtual ~Application(){}
    void event_loop(int XX,int YY);
    void registerWidget(Widgets*);
    int get_selected();
};

#endif // APPLICATION_HPP_INCLUDED

#include "Widgets.hpp"
#include "Application.hpp"

Widgets::Widgets(Application* p,int px,int py, int sx, int sy): parent(p),pos_x(px),pos_y(py),size_x(sx),size_y(sy){
    parent->registerWidget(this);
}

bool Widgets::is_selected(int eger_x, int eger_y){
    return eger_x>pos_x && eger_x<(pos_x+size_x) && eger_y>pos_y && eger_y<(pos_y+size_y);
}

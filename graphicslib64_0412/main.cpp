#include "graphics.hpp"
#include "Application.hpp"
#include "button.hpp"
#include "Widgets.hpp"
#include "game_menu.hpp"
#include "kepbeolvas.hpp"
#include <fstream>
#include <vector>
#include <iostream>

using namespace genv;
using namespace std;

const int XX=700;
const int YY=700;

canvas beolvas(string ezt){
    Kepbeolvas k;
    canvas C=k.the_main(ezt);
    return C;
}

class GameApp:public Application{
private:
    Menu *m;
    vector<vector<Button*>> field;
public:
    GameApp(){
        m=new Menu(this,0,0,XX,YY,XX,YY);
        set_screen_x_y(XX,YY);
        canvas C2=beolvas("circle.kep");
        canvas C1=beolvas("x.kep");
        for (int i=0;i<20;i++){
            vector<Button*> temp;
            for (int j=0;j<20;j++){
                Button *tempbutton=new Button(this,i,j,(XX-20)/20,(YY-20)/20,255,255,255,"",C1,C2);
                temp.push_back(tempbutton);
            }
            field.push_back(temp);
        }
    }
    /*GameApp(int sx,int sy){
    m=new Menu(this,0,0,XX,YY,XX,YY);
        canvas C2=beolvas("circle.kep");
        canvas C1=beolvas("x.kep");
        for (int i=0;i<20;i++){
            vector<Button*> temp;
            for (int j=0;j<20;j++){
                Button *tempbutton=new Button(this,i,j,(XX-20)/20,(YY-20)/20,255,255,255,"",C1,C2);
                temp.push_back(tempbutton);
            }
            field.push_back(temp);
        }
    }*/
};


int main()
{
    gout.open(XX,YY);
    GameApp game;
    game.event_loop(XX,YY);
    return 0;
}

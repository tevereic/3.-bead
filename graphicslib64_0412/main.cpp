#include "graphics.hpp"
#include "Application.hpp"
#include "button.hpp"
#include "Widgets.hpp"
#include "game_menu.hpp"
#include <iostream>

using namespace genv;
using namespace std;

const int XX=700;
const int YY=700;

class GameApp:public Application{
private:
    Menu *m;
    vector<vector<Button*>> field;
public:
    GameApp(){
        m=new Menu(this,0,0,XX,YY,XX,YY);
        for (int i=0;i<20;i++){
            vector<Button*> temp;
            for (int j=0;j<20;j++){
                Button *tempbutton=new Button(this,i,j,(XX-20)/20,(YY-20)/20,255,255,255,"");
                temp.push_back(tempbutton);
            }
            field.push_back(temp);
        }
    }
};


int main()
{
    gout.open(XX,YY);
    gout.load_font("LiberationSerif-Bold.ttf",16);
    GameApp game;
    game.event_loop(XX,YY);
    return 0;
}

#include "graphics.hpp"
#include "Application.hpp"
#include "button.hpp"
#include "Widgets.hpp"
#include <iostream>

using namespace genv;
using namespace std;

const int XX=700;
const int YY=700;

class GameApp:public Application{
private:
    vector<vector<Button*>> field;
public:
    GameApp(){
        for (unsigned int i=0;i<20;i++){
            vector<Button*> temp;
            for (unsigned int j=0;j<20;j++){
                Button *tempbutton=new Button(this,i,j,(XX-20)/20,(YY-20)/20,100,100,100,"");
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

#include "graphics.hpp"
#include "kepbeolvas.hpp"
#include <fstream>
#include <vector>
#include <iostream>
using namespace genv;
using namespace std;

Kepbeolvas::Kepbeolvas(){}


vector<vector<vector<int>>> Kepbeolvas::beolvas(ifstream & befajl){
    int xx,yy;
    befajl >>xx>>yy;
    vector<vector<vector<int>>> kep(yy,vector<vector<int>>(xx,vector<int>(3)));
    for (size_t i=0;i<yy;i++){
        for (size_t j=0;j<xx;j++){
            befajl >> kep[i][j][0] >> kep[i][j][1]>>kep[i][j][2];
        }
    }
    befajl.close();
    return kep;
}

void Kepbeolvas::rajzol(vector<vector<vector<int>>> kep, canvas & C){
    for (size_t i=0;i<kep.size();i++){
        for (size_t j=0;j<kep[0].size();j++){
            C<<move_to(j,i)<<color(kep[i][j][0],kep[i][j][1],kep[i][j][2])<<dot;
        }
    }
}

canvas Kepbeolvas::the_main(string ezt)
{
    ifstream befajl(ezt.c_str());
    vector<vector<vector<int>>> kep = beolvas(befajl);
    canvas C;
    C.open(kep[0].size(),kep.size());
    rajzol(kep, C);
    return C;
}

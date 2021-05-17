#ifndef KEPBEOLVAS_HPP_INCLUDED
#define KEPBEOLVAS_HPP_INCLUDED

#include "graphics.hpp"
#include <vector>

using namespace std;

class Kepbeolvas{
public:
    Kepbeolvas();
    void rajzol(vector<vector<vector<int>>> kep, genv::canvas & C);
    vector<vector<vector<int>>> beolvas(ifstream & befajl);
    genv::canvas the_main(string ezt);
};

#endif // KEPBEOLVAS_HPP_INCLUDED

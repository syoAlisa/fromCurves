
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <any>

#include "curve3D.h"
#include "circle.h"
#include "ellipse.h"
#include "spiral.h"
#include< afxver_.h >
#include <numeric>

using namespace std;


bool comp(circle* a, circle*  b)
{
    return a->get_radius() < b->get_radius();
}


int main()
{
    vector<any> curves;
    vector<circle*> circles;

    int nRandElems = 31;
    for (int i = 0; i < nRandElems; i++)
    {
        int typeRandElem = rand() % 3 + 1;
        int randX = rand() % 11 -1;
        int randY = rand() % 3 -2;
        int randZ = rand() % 5 + 2;
        int randR = rand() % 15 + 2;
        any a0;
        switch (typeRandElem)
        {
            case CIRCLE:
            {
                a0 = std::make_any<circle>(randX, randY, 0.0, randR);
                break;
            }
            case ELLIPSE:
            {
                int randMj = rand() % 15 + 2;
                int randMn = rand() % 7 + 1;
                a0 = std::make_any<ellipse>(randX, randY, 0.0, randMj, randMn);
                break;
            }
            case SPIRAL:
            {
                 int randS = rand() % 4 + 1;
                 a0 = std::make_any<spiral>(randX, randY, randZ, randR, randS);
                 break;
            }
        }
        curves.push_back(a0);
    }
    cout << endl << endl;

    double alpha = pi / 4;
    for (auto& elem : curves)
    {
        if (elem.type() == typeid(circle))
        {
            auto tmp = any_cast<circle>(elem);
            tmp.print_curve();
            cout << "  point      koords :   ";
            point pointT = tmp.get_coords(alpha);
            pointT.print();
            cout << "  derivative koords :   ";
            point pointV = tmp.get_vector(alpha);
            pointV.print();
            cout << endl << endl;

            circles.emplace_back(any_cast<circle>(&elem));
        }
        else  if (elem.type() == typeid(ellipse))
        {
            auto tmp = any_cast<ellipse>(elem);
            tmp.print_curve();
            cout << "  point      koords :   ";
            point pointT = tmp.get_coords(alpha);
            pointT.print();
            cout << "  derivative koords :   ";
            point pointV = tmp.get_vector(alpha);
            pointV.print();
            cout << endl << endl;
        }
        else  if (elem.type() == typeid(spiral))
        {
            auto tmp = any_cast<spiral>(elem);
            tmp.print_curve();
            cout << "  point      koords :   ";
            point pointT = tmp.get_coords(alpha);
            pointT.print();
            cout << "  derivative koords :   "; 
            point pointV = tmp.get_vector(alpha);
            pointV.print();
            cout << endl << endl;
        }
        else
        {
            cout << "ERROR TYPE" << endl;
        }
    }
    
    double summRadius = 0.0;
    for (auto elem : circles)
    {
        summRadius += (*elem).get_radius();
    }
    cout << "summRadius = " << summRadius << endl;



    cout <<" radius from contain circles" << endl;
    for (auto elem : circles)
    {
        cout<<(*elem).get_radius()<<"  ";
    }
    cout << endl;

    sort(circles.begin(), circles.end(), comp);
    cout << " radius from contain circles after sort" << endl;
    for (auto elem : circles)
    {
        cout << (*elem).get_radius() << "  ";
    }
    cout << endl;
    
    

    circles.clear();
    vector<circle*>().swap(circles);

    curves.clear();
    vector<any>().swap(curves);

    _CrtDumpMemoryLeaks();
    return 0;
}
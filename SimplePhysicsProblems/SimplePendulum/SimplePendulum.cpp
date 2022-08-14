#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

//1D Classical Simple Pendulum Problem
int main()
{
    ofstream MyFile("output.txt");
    
    //linear kinematic variables
    double lpos;
    double lvel;
    double lacel;
    
    //angular kinematic variables
    double angpos;
    double angvel;
    double angacel;
    double ampl;
    double phi0;
    double t;

    //Initial conditions
    lpos = 10.;
    lvel = 10.;
    lacel = 0.; //cte
    angvel = 1.;
    ampl = 10.;
    phi0 = 0.;
    t = 0;

    cout << "Time   Position " << endl;
    for(int i= 0; i <= 1000; i++){
        lpos = ampl*sin(angvel*t+phi0);
        lvel = ampl*angvel*cos(angvel*t+phi0);
        lacel = -ampl*angvel*angvel*sin(angvel*t+phi0);
        t+=0.01;
        cout << t << "       " << lpos << "       " << lvel << "       " << lacel << endl;
        MyFile << t << " " << lpos << lvel << " " << lacel << "\n";
    
    }
    
    MyFile.close();

    return 0;
}
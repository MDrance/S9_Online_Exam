#ifndef FORME_H
#define FORME_H
#include <iostream>
using namespace std;

class Forme{

    protected:
        double x;
        double y;

    public:
        Forme(double _x=0.0, double _y=0.0){x=_x;y=_y;}
        virtual void affiche()=0;
        void deplace(double dx,double dy){x=x+dx;y=y+dy;}
};

class Point:public Forme{

    public:
        Point(double _x=0.0, double _y=0.0):Forme(_x,_y){}
        virtual void affiche() {cout<<"Affiche point x="<<x<<"y="<<y<<endl;}
};

class Cercle:public Point{

    protected:
        double rayon;

    public:
        Cercle(double _x, double _y, double _r):Point(_x,_y){rayon=_r;}
        virtual void affiche(){cout<<"Affiche Cercle x="<<x<<" y="<<y<<"r="<<rayon<<endl;}
};

class Sphere:public Cercle{
    protected:
        double z;
    public:
        Sphere(float _x, float _y, float _z, float _r):Cercle(_x,_y,_r){z=_z;}
        virtual void affiche(){cout<<"Affiche Sphere"<<" x="<<x<<" y="<<y<<"z="<<z<<" rayon="<<rayon<<endl;}
        void deplace(double dx, double dy, double dz){
        Cercle::deplace(dx,dy);z=z+dz;}
};

#endif
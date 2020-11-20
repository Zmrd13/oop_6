//
// Created by egor on 17.10.2020.
//

#ifndef OOP_4_ALT_CLSOURCE_H
#define OOP_4_ALT_CLSOURCE_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

using namespace std;

class ShapeObj {
protected:
    float modx = rand() % 50 - 25, mody = rand() % 50 - 25;
    float red = rand() % 255, green = rand() % 255, blue = rand() % 255;
    float deltax = 1, deltay = 1;
public:
    float posx;
    float posy;

    ShapeObj(float x, float y) : posx(x), posy(y) {
        this->posy = y;
        this->posx = x;
    };

    void strMove(float lim) {
        if (posx <= 0 + deltax || posx >= lim - deltax) {
            modx = -modx;
        }
        if (posy <= 0 + deltay || posy >= lim - deltay) {
            mody = -mody;
        }
        this->posy += mody / 10;
        this->posx += modx / 10;

    }
};

class Dot : public ShapeObj {
protected:
    CircleShape obj;

public:

    Dot(float x, float y, float r = 1) : ShapeObj(x, y) {
        this->deltax = this->deltay = r;
        obj.setRadius(r);
        obj.setFillColor(Color(red, green, blue));
        obj.setOrigin(r, r);
    }

    CircleShape draw() {
        obj.setPosition(this->posx, this->posy);
        obj.rotate(4);
        return (obj);
    }


};


class Circle : public Dot {
public:
    Circle(float x=20, float y=20, float r=15) : Dot(x, y, r) {
    }

    Circle(float x, float y, float r, float s) : Dot(x, y, r) {
        this->modx *= s;
        this->mody *= s;
    }
};

class Ellips : public Circle {
public:
    float distx = 1, disty = 0.4;

    Ellips(float x=100, float y=100, float r=100) : Circle(x, y, r) {
        obj.scale(distx, disty);
        this->deltax *= distx;
        this->deltay *= disty;
    }
};

class Square : public ShapeObj {
private:
    float sidex, sidey;
protected:
    RectangleShape obj;

public:
    Square(float x, float y, float sx = 50, float sy = 50) : ShapeObj(x, y), sidex(sx), sidey(sy) {
        this->deltax = sidex;
        this->deltay = sidey;
        obj.setSize(Vector2f(sidex, sidey));
        obj.setOrigin(sidex / 2, sidey / 2);
        obj.setFillColor(Color(red, green, blue));
    }

    RectangleShape draw() {
        obj.setPosition(this->posx, this->posy);
        obj.rotate(4);
        return (obj);
    }
};

class Line : public Square {
private:
    float lenght;
public:
    Line(float x, float y, float sy = 50) : Square(x, y, 1, sy), lenght(sy) {
    }
};

class Rombic : public Dot {
public:
    Rombic(float x, float y, float side = 50) : Dot(x, y, side / 2) {
        obj.setPointCount(4);
        obj.scale(1, 0.5);

    }
};

#endif //OOP_4_ALT_CLSOURCE_H

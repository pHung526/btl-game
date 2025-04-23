#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Constants.h"
#include "ObjectType.h"

struct GameObject {
    int x, y;
    float speed;
    int peakHeight;
    bool rising;
    ObjectType type;
    bool sliced;
    int fragmentDirection;

    GameObject(int startX, int startY, ObjectType objType, int direction = 0);
    void update(); 
    bool isSliced(int x1, int y1, int x2, int y2); 
};

#endif

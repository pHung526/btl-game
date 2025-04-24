#include "GameObject.h"
#include <cmath> // dùng cho sqrt, fabs
#include <cstdlib>

GameObject::GameObject(int startX, int startY, ObjectType objType, int direction) {
    x = startX;
    y = startY;
    speed = (rand() % 4 + 2) * 1.5;
    peakHeight = SCREEN_HEIGHT - (speed * 40);
    rising = true;
    type = objType;
    sliced = false;
    fragmentDirection = direction;
}

void GameObject::update() {
    if (type == FRAGMENT) {
        y += speed;
        x += fragmentDirection * 3;
    } else {
        if (rising) {
            y -= speed;
            if (y <= peakHeight) {
                rising = false;
            }
        } else {
            y += speed;
        }
    }
}

bool GameObject::isSliced(int prevX, int prevY, int mouseX, int mouseY) {
    int radius = OBJECT_SIZE / 4;
    float centerX = x + radius;
    float centerY = y + radius;

    float dx = mouseX - prevX;
    float dy = mouseY - prevY;
    float len = sqrt(dx * dx + dy * dy);
    if (len < 1) return false;

    float A = dy;
    float B = -dx;
    float C = dx * prevY - dy * prevX;
    float distance = fabs(A * centerX + B * centerY + C) / len;
    bool intersects = distance <= radius;

    float endDx = mouseX - centerX;
    float endDy = mouseY - centerY;
    float endDistance = sqrt(endDx * endDx + endDy * endDy);
    bool closeEnough = endDistance < OBJECT_SIZE;

    float movementX = mouseX - prevX;
    float movementY = mouseY - prevY;
    bool hasMovement = (movementX * movementX + movementY * movementY) > 25;

    return intersects && closeEnough && hasMovement;
}

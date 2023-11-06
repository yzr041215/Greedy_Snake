#include "snake.h"
#include <QRect>
Snake::Snake(QRect rect)
{
    snake_inf.clear();
    snake_inf.append(rect);
    direction=snake_right;
}
bool Snake::move(snake_direction direction,bool iseat){
    QRect head=snake_inf.front();
    int x,y,a,b;head.getRect(&x,&y,&a,&b);
    switch (direction) {
    case snake_up:
        head.moveTo(x,y-20+(y==20)*400);
        break;
    case snake_left:
        head.moveTo(x-20+(x==20)*700,y);
        break;
    case snake_right:
        head.moveTo(x+20-(x==700)*700,y);
        break;
    case snake_down:
        head.moveTo(x,y+20-(y==400)*400);
        break;
    default:
        break;
    }
    if(!iseat)snake_inf.pop_back();
    snake_inf.prepend(head);
    return 0;
}

void Snake::Reset(){
    QRect rect(80,60,20,20);
    snake_inf.clear();
    this->snake_inf.append(rect);
    direction=snake_right;
}


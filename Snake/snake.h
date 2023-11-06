#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include<QRect>

typedef enum directon{snake_up,snake_down,snake_left,snake_right} snake_direction;

class Snake
{
public:
    snake_direction direction;

    Snake(QRect rect);//构造函数
    void Reset();
    QList<QRect>snake_inf;//存储蛇
    bool move(snake_direction direction ,bool iseat);
private:

};

#endif // SNAKE_H

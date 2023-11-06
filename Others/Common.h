#include<QRect>
#include<QVector>
#include<vector>
#include<time.h>
#ifndef COMMON_H
#define COMMON_H
typedef enum t{empty,barry,food,body} Things;
class My_map{
public:
    bool is_eated=1;
    QVector<QVector<Things>> inf;
    My_map(){
        inf=QVector<QVector<Things>>(120,QVector<Things>(135));
        srand(time(NULL));
    }
    QPoint now_food;
    void make_food();
    void reset_food();
    void make_barry(int nums);
};




#endif // COMMON_H

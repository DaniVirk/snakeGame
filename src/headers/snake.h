#ifndef SNAKE_H
#define SNAKE_H

class Snake {
    int score = 0;
    int position_x = 0;
    int position_y = 0;

public:
    int getScore();
    void setScore(int score);

    int getPositionX();
    void setPositionX(int pos_x);

    int getPositionY();
    void setPositionY(int pos_y);
};



#endif //SNAKE_H

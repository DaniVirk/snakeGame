#include "../headers/snake.h"

int Snake::getScore() {
    return score;
}

void Snake::setScore(const int score) {
    this->score = score;
}

int Snake::getPositionX() {
    return position_x;
}

void Snake::setPositionX(const int pos_x) {
    this->position_x = pos_x;
}

int Snake::getPositionY() {
    return position_y;
}

void Snake::setPositionY(const int pos_y) {
    this->position_y = pos_y;
}
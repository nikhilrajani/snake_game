#include "Snake.h"

Snake::Snake(COORD pos, int v){
    this->pos=pos;
    this->v=v;
    l=1;
    d='n';

    body.push_back(pos);
}

void Snake::grow(){
    l++;
}

void Snake::move_snake(){
    switch(d){
        case 'u': pos.Y-=v;break;
        case 'd': pos.Y+=v;break;
        case 'l': pos.X-=v;break;
        case 'r': pos.X+=v;break;
    }
    body.push_back(pos);
    if(body.size()>l) body.erase(body.begin());
}


void Snake::changeDir(char dir){
    d=dir;
}

vector<COORD> Snake::get_body(){
    return body;
}

bool Snake::collided(){
    if(pos.X<1 || pos.X>WIDTH-2 || pos.Y<1 || pos.Y>HEIGHT-2){
        return true;
    }

    for(int i=0;i<l-1;i++){
        if(pos.X==body[i].X && pos.Y==body[i].Y) return true;
    }
    return false;
}

bool Snake::eaten(COORD food){
    if(pos.X==food.X && pos.Y==food.Y) return true;
    return false;
}

COORD Snake::get_pos(){
    return pos;
}




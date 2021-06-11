#include "Player.h"
void Player::MovementLeft(){
    Position.x -= 10;
}
void Player::MovementRight(){
    Position.x += 10;
}

bool Player::CollidesWith(Enemy& e){
    //std::cout << "x= " << Position.x << "y= " << Position.y << "EnemyX= " << e.Position.x << "EnemyY= " << e.Position.y;
    //if(e.Position.x-75 >= Position.x-50 && e.Position.x-75 <= Position.x ||e.Position.x+75 >= Position.x-50 && e.Position.x+75 <= Position.x){
        //if(e.Position.y-75 >= Position.y-50 && e.Position.y-75 <= Position.y || e.Position.y+75 >= Position.y-50 && e.Position.y+75 <= Position.y){
        if(e.Position.x <= Position.x+50 && e.Position.y <= Position.y){
            if(e.Position.x >= Position.x && e.Position.y <= Position.y+50){
                printf("IK STERF");
            }
        }
            return true;
       //}
   //}
    return false;
}
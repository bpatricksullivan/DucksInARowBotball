#include <kipr/wombat.h>

//MOTORS:
//CHANGE DELTA FOR MRP
//speed ranges from 0 to 1000
//mrp -> controlled movement (need bmd)
//mav / motor -> uncontrolled. use msleep & ao to stop
//rm lm + + -> left turn
//rm lm - - -> right turn
//rm lm + - -> forwards
//rm lm - + -> backwards

//Servos:
//enable_servos();
//movement ranges from 0 to 2047
//base servo -> 0 is towards bot, 2047 is away
//claw servo -> 0 is open, 2047 is closed, 1300~1700 (mostly closed)

int rm = 1;
int lm = 3;
int bserv = 0;
int cserv = 1;

void lturn(int speed, int delta) {
    mrp(rm, speed, delta);
    mrp(lm, speed, delta);
    bmd(rm);
    bmd(lm);
}

void rturn(int speed, int delta) {
    mrp(rm, speed, -delta);
    mrp(lm, speed, -delta);
    bmd(rm);
    bmd(lm);
}

void fwd(int speed, int delta) {
    mrp(rm, speed, delta);
    mrp(lm, speed, -delta);
    bmd(rm);
    bmd(lm);
}

void bwd(int speed, int delta) {
    mrp(rm, speed, -delta);
    mrp(lm, speed, delta);
    bmd(rm);
    bmd(lm);
}

int main()
{
    enable_servos();
    
    set_servo_position(bserv, 1800);
    set_servo_position(cserv, 1000);
    
    lturn(500, 240);
    fwd(800, 1900);
    
    set_servo_position(cserv, 1300);
    
    msleep(750);
    
    bwd(800, 1500);
    lturn(750, 1800);
    set_servo_position(bserv, 2000);
    fwd(500, 400);
    msleep(200);
    set_servo_position(cserv, 700);
    
    msleep(1500);
    
    disable_servos();
    
    return 0;
}

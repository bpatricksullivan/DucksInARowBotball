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
    
    set_servo_position(bserv, 1500);
    set_servo_position(cserv, 1100);
    
    fwd(1000, 2400);
    rturn(1000, 750);
    set_servo_position(bserv, 2047);
    fwd(1000, 4800);
    bwd(1000, 800);
    rturn(1000, 750);
    lturn(1000, 350);
    set_servo_position(bserv, 1000);
    fwd(1000, 1000);
    rturn(1000, 2200);
    set_servo_position(bserv, 2047);
    bwd(500, 600);
    fwd(1000, 500);
    rturn(1000, 20);
    fwd(2000, 4000);
    set_servo_position(cserv, 1700);
    rturn(1000, 400);
    set_servo_position(bserv, 1500);
    
    /*rturn(1000, 1100); //1100 is 90 deg. approx
    fwd(2000, 4600);
    lturn(1000, 1100);
    bwd(200, 250);
    set_servo_position(bserv, 2047);
    msleep(150);
    fwd(1500, 2800);
    bwd(1500, 100);
    set_servo_position(bserv, 1500);
    lturn(1000, 1100);
    msleep(150);
    set_servo_position(bserv, 2047);
    msleep(150);
    lturn(1000, 1100);
    rturn(1000, 1100);
    bwd(200, 250);
    fwd(2000, 7500);
    lturn(1000, 300);
    fwd(1000, 500);
    rturn(1000, 300);
    set_servo_position(cserv, 1400);*/
    
    return 0;
}

#include <kipr/wombat.h>

//FL + FR - BL + BR - -> backward
//FL - FR + BL - BR + -> forward
//All positive -> left turn
//All negative -> right turn
  
//mrp() -> low speed means accurate turns, speed(0, 1000) * delta(# ticks, + or -) = angle

//Servo:
//bserv: 0 is towards, 2047 is away (1400 is flat to ground)
//cserv: 0 is open, 2047 is closed (1600 is closed)
//DO NOT USE 2047

int br = 0;
int bl = 1;
int fr = 2;
int fl = 3;

int bserv = 0;
int cserv = 1;

void lturn(int speed, int delta){
    mrp(fl, speed, delta);
    mrp(fr, speed, delta);
    mrp(bl, speed, delta);
    mrp(br, speed, delta);
    bmd(fl);
    bmd(fr);
    bmd(bl);
    bmd(br);
}

void rturn(int speed, int delta){
    mrp(fl, speed, -delta);
    mrp(fr, speed, -delta);
    mrp(bl, speed, -delta);
    mrp(br, speed, -delta);
    bmd(fl);
    bmd(fr);
    bmd(bl);
    bmd(br);
}

void fwd(int speed, int delta){
    mrp(fl, speed, -delta);
    mrp(fr, speed, delta);
    mrp(bl, speed, -delta);
    mrp(br, speed, delta);
    bmd(fl);
    bmd(fr);
    bmd(bl);
    bmd(br);
}

void bwd(int speed, int delta){
    mrp(fl, speed, delta);
    mrp(fr, speed, -delta);
    mrp(bl, speed, delta);
    mrp(br, speed, -delta);
    bmd(fl);
    bmd(fr);
    bmd(bl);
    bmd(br);
}

int main()
{
    enable_servos();
    
    set_servo_position(bserv, 700);
    set_servo_position(cserv, 700);
    
    msleep(1500);
    
    set_servo_position(bserv, 1400);
    set_servo_position(cserv, 1600);
    
    msleep(750);
    
    disable_servos();
    
    return 0;
}

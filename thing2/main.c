#include <kipr/wombat.h>

//FL + FR - BL + BR - -> backward
//FL - FR + BL - BR + -> forward
//All positive -> left turn
//All negative -> right turn
  
//mrp() -> low speed means accurate turns, speed(0, 1000) * delta(# ticks, + or -) = angle

//Servo:
//bserv: 0 is towards, 2047 is away (1400 is flat to ground)
//cserv: 0 is open, 2047 is closed (1200 is closed)
//DO NOT USE 2047

int br = 0;
int bl = 1;
int fr = 2;
int fl = 3;

int bserv = 0;
int rserv = 1;
int cserv = 2;

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
    set_servo_position(bserv, 1000);
    set_servo_position(cserv, 600);
    set_servo_position(rserv, 0);
    
    fwd(1000, 1500);
    rturn(1000, 1385);
    fwd(1000, 2200);
    set_servo_position(bserv, 1350);
    fwd(1000, 300);
    set_servo_position(cserv, 1180);
    msleep(300);
    set_servo_position(bserv, 700);
    rturn(1000, 1700);
    bwd(1000, 150);
    set_servo_position(bserv, 1350);
    msleep(300);
    set_servo_position(cserv, 500);
    msleep(500);
    bwd(1000, 50);
    set_servo_position(bserv, 1500);
    fwd(1000, 150);
    set_servo_position(cserv, 1180);
    msleep(1000);
    set_servo_position(rserv, 2047);
    msleep(500);
    set_servo_position(bserv, 1300);
    msleep(500);
    set_servo_position(bserv, 1400);
    msleep(500);
    set_servo_position(cserv, 700);
    msleep(1000);
    
    disable_servos();
    /*enable_servos();
    
    set_servo_position(bserv, 700);
    set_servo_position(cserv, 700);
    
    msleep(1500);
    
    set_servo_position(bserv, 1400);
    set_servo_position(cserv, 1600);
    
    msleep(750);
    
    disable_servos();*/
    
    return 0;
}

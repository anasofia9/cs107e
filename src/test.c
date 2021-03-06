#include "printf.h"
#include "uart.h" 
#include "mcp3008.h"
#include "gpio.h"
#include "gl.h"
#include "timer.h"
#include "glove.h"
#include "display.h"
#include "i2c.h"
#include "servo.h"
#include "hand.h"


void test_glove(void) {
    uart_init();
    gpio_init();
    init_glove();
    int loop = 100;
    while (1) {
        timer_delay_ms(200);
        update_glove();
        for (int i = 0; i < 5; ++i) {
            printf("\b\b\b\b\b");
        }
        for (int i = 0; i < 5; ++i) {
            printf("%4d ", angle(i));
        }
    }
}

#define servoMin 4


void raw_variable_resistance(void) {
    uart_init();
    gpio_init();
    mcp3008_init();
    int loop = 100;
    while (1) {
        int sum[7] = {0, 0, 0, 0, 0, 0, 0};
        for (int i = 0; i < loop; ++i) {
            for (int n = 0; n < 7; n++) {
                sum[n] += mcp3008_read(n);
            }
        }
        for (int i = 0; i < 7; ++i) {
            printf("\b\b\b\b\b");
        }
        for (int i = 0; i < 7; ++i) {
            sum[i] /= loop;
            printf("%4d ", sum[i]);
        }
    }
}

// IMPORTANT NOTE FROM SEAN: Only put simple function calls in here.
// Put all the test functions in 
static void test_display(void)
{
//    gl_init(640, 512, GL_SINGLEBUFFER);
//    gl_clear(GL_BLACK);
//    draw_palm(100, 370, 160, 120);
//    draw_thumb(100, 370, 160, 120);
//    draw_index(100, 370, 160, 120);
//    draw_middle(100, 370, 160, 120);
//    draw_ring(100, 370, 160, 120);
//    draw_pinky(100, 370, 160, 120);
//    draw_side_view(450, 370, 160, 13);
    init_display();
    update_hand();

    
}

static void test_one_servo(){
  uart_init();
  // i2c_init();
  //timer_init();
  servo_init();
  //servo_set_position(0, 15);
  /*  while(1){
    servo_set_pwm(1, 20);
    timer_delay_ms(1000);
    servo_set_pwm(1, 100);
    timer_delay_ms(1000);
    }*/
  while(1){
    servo_set_position(0, 15);
    timer_delay_ms(1000);
    servo_set_position(0, 4);
    servo_set_position(1, 15);
    timer_delay_ms(1000);
    servo_set_position(1, 4);
    servo_set_position(2, 15);
    timer_delay_ms(1000);
    servo_set_position(2, 4); 
    servo_set_position(3, 15);
    timer_delay_ms(1000);
    servo_set_position(3, 4);
    servo_set_position(4, 15);
    timer_delay_ms(1000);
    servo_set_position(4, 4);
    timer_delay_ms(1000);
    }
  //  for(int i = 0; i < 100; i++){
  //servo_set_pwm(0, i);
  //timer_delay_ms(10);
  //}
}

void test_hand_pose(){
  servo_init();
  
  go_to_pose(PEACE);
  timer_delay_ms(10000);
  go_to_pose(SHAKA);
  timer_delay_ms(10000);
  go_to_pose(BIRD);
  timer_delay_ms(10000);
  go_to_pose(ROCK);
  timer_delay_ms(10000);
  go_to_pose(OPEN);
}

void main(void) 
{ 
  //   test_glove();
  //raw_variable_resistance();
  //  test_display();
  //test_one_servo();
  test_hand_pose();
}

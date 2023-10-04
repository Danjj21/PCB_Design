/*
 * kitchen_timer.c
 *
 *  Created on: Jun 18, 2021
 *      Author: <Your Name>
 */

#include "kitchen_timer.h"

volatile  uint8_t hours_count=0;
volatile  uint8_t hours_count_add=0;

volatile  uint8_t mins_count=0;
volatile  uint8_t mins_count_add=0;

volatile bool setting_chose;

/******************************************************************************
 * Make sure you examine the functions that are made available to you in
 * the provided_code directory.  There are already functions provided that
 * configure timers for 1 second and 2mS.  The ISRs for these timers are
 * also provided.
 *
 * You should also make use of the functions you completed in display.c and
 * cap_sense.c
 *
 * You can add as many helper functions are you like to this file.
 *
 * DO NOT try to code all of this at once.  Break this into smaller steps.
 *
 *      -> Write  a small amount of code to accomplish a simple requirement.
 *      -> Verify your new code works.
 *      -> Verify that you did not break any of your earlier code.
 *      -> Continue to the next requirement.
 *
 * Use the debugger to verify your code!
 *
 * Suggested Development Strategy
 *
 * 1. Detect when the user presses one of the Cap Sense Buttons
 * 2. Determine which button has been pressed
 * 3. Print out a number to a single seven segment digit
 * 4. Print out a 4-digit number to the display (see video on POV)
 * 5. Blink the 4-digit number on/off at a rate of 1 second
 * 6. Modify the 4-digit number displayed using the Cap Sense Buttons
 * 6. Count down to 00:00
 * 7. Toggle the eyes/buzzer
 * 8. Complete remaining requirements.
 *****************************************************************************/

/*****************************************************
 * Allows the user to set the duration of the timer
 *****************************************************/
void kitchen_timer_mode_init(void)
{

    display_all_dig_off();
    display_digit(0,1);
    display_digit(1,0);
    display_digit(2,0);
    display_digit(3,0);

    if((cap_sense_get_buttons() | (0xFE)) && BIT0){

        //minutes
        setting_chose=true;
    }
    if((cap_sense_get_buttons() | (0xFD)) && BIT1){

        //Hour touched
        setting_chose=false;
    }
    if((cap_sense_get_buttons() | (0xFB)) && BIT2){

        //Down touchsense
        if(setting_chose){
            mins_count--;
            mins_count_add--;
            if(mins_count<=9 && mins_count>=0){
                display_digit(0, mins_count);
            }
            else if(mins_count_add<=5 && mins_count_add >=0) {
                display_digit(1, mins_count_add);
            }
            else{
                display_digit(0,0);
                display_digit(1,0);
            }
            if(mins_count<=0){
                display_digit(0,9);
                display_digit(1,5);
            }
        }
        if(!setting_chose){
            hours_count--;

            if(hours_count<=9 && hours_count>=0){
                display_digit(2, hours_count);
            }
            else if(hours_count_add<=5 && hours_count_add >=0) {
                hours_count_add--;

                display_digit(3, hours_count_add);
            }
            else{
                display_digit(2,0);
                display_digit(3,0);
            }
            if(mins_count<=0){
                display_digit(2,9);
                display_digit(3,9);
            }
        }
    }
    if((cap_sense_get_buttons() | (0xF7)) && BIT3){

        //UP touchsense
        if(setting_chose){
            mins_count++;

            if(mins_count<=9){
                display_digit(0, mins_count);
            }
            else if(mins_count_add<=5) {
                mins_count_add++;
                mins_count=0;
                display_digit(1, mins_count_add);
            }
            else{
                mins_count_add++;
                display_digit(0,0);
                display_digit(1,0);
            }
        }
        if(!setting_chose){
            hours_count++;

            if(hours_count<=9){
                display_digit(2, mins_count);
            }
            else if(hours_count_add<=5) {
                hours_count_add++;
                hours_count=0;
                display_digit(3,hours_count_add);
            }
            else{
                display_digit(2,0);
                display_digit(3,0);
            }
        }
    }
    if((cap_sense_get_buttons() | (0xFC)) && (BIT1 && BIT0)){

        //both minutes and hours on
        kitchen_timer_mode_count_down();
    }
}

/*****************************************************
 * Starts the timer
 *****************************************************/
void kitchen_timer_mode_count_down(void)
{


   // kitchen_timer_initialize();

    //display_digit(location,number);

}



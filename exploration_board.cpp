#include <Arduino.h>

#include "src/timer/Timer.h"

#include "src/data_type.h"
#include "src/inputs/push_button.h"
#include "src/inputs/coded_rotary_switch.h"
#include "src/inputs/connect_wire.h"
#include "src/inputs/usb_connection.h"
#include "src/inputs/on_off_switch.h"
#include "src/inputs/toggle_switch.h"

#include "src/outputs/seven_segment_display.h"
#include "src/outputs/servo_leaver.h"
#include "src/outputs/hdd_spinner.h"
#include "src/outputs/status_led.h"
#include "src/outputs/motor.h"

Configuration config;
Timer timer;

/* **** Outputs ***** */
SevenSegmentDisplay * display;
ServoLeaver * servo;
HddSpinner * hdd;
StatusLed * connected_wire_red_led;
StatusLed * connected_wire_black_led;
Motor * motor;

/* **** Inputs ***** */
CodedRotarySwitch * rotary_switch;
PushButton * push_button;
ToggleSwitch * toggle_switch;
UsbConnection * usb_connection;
OnOffSwitch * on_off_switch;
ConnectWire * connect_wire_black;
ConnectWire * connect_wire_red;

/* **** Variables ***** */
bool was_spinning = false;


/* **** Logging ***** */
// uncomment define to enable logging to serial console
// #define LOG_ENABLED

void log(const char str[]) {
#ifdef LOG_ENABLED
    Serial.print(str);
    Serial.print("\n");
#endif
}

/** Simple intro to drive all actors to demonstrate functionallity after setup.
 * (except hdd which does not spin at startup) */
void intro() {
    log("Play intro...");
    connected_wire_red_led->play_intro();
    connected_wire_black_led->play_intro();
    servo->play_intro();
    display->play_intro();
    motor->play_intro();

}

/** Arduino setup function */
void setup() {
    #ifdef LOG_ENABLED
    Serial.begin(9600);
    #endif

    log("Start initializing inputs...");
    rotary_switch = new CodedRotarySwitch(config.coded_rotary_switch);
    push_button = new PushButton(config.push_button);
    toggle_switch = new ToggleSwitch(config.toggle_switch);
    on_off_switch = new OnOffSwitch(config.on_off_switch);
    usb_connection = new UsbConnection(config.usb_connection);
    connect_wire_red = new ConnectWire(config.connect_wire_red);
    connect_wire_black = new ConnectWire(config.connect_wire_black);



    log("Start initializing outputs...");
    display = new SevenSegmentDisplay(config.seven_segment);
    servo = new ServoLeaver(config.servo_pwm);
    hdd = new HddSpinner(config.hdd_spinner, &timer);
    connected_wire_red_led = new StatusLed(config.connect_wire_red_led, &timer);
    connected_wire_black_led = new StatusLed(config.connect_wire_black_led, &timer);
    motor = new Motor(config.motor);

    intro();
}


/** Simply control one actor with one input
 * - Read rotary switch and print number to display
 * - Fast blink leds till one and all wires are connected
 * - button to rotate the motor
 * - toggle switch to position the servo
 * - usb cable and switch to turn on hdd
 */
void easy_game() {
    /* ************* Rotary Switch & Display ************** */
    uint8_t rotary_switch_value = rotary_switch->get_value();
    display->set_value(rotary_switch_value);


    /* ************* Red wire ************** */
    ConnectedWire red_wire_value = connect_wire_red->get_connected_wires();
    if (red_wire_value == One) {
        connected_wire_red_led->blink_slow();
    } else if (red_wire_value == None) {
        connected_wire_red_led->blink_fast();
    } else {
        connected_wire_red_led->on();
    }


    /* ************* black wire ************** */
    ConnectedWire black_wire_value = connect_wire_black->get_connected_wires();
    if (black_wire_value == One) {
        connected_wire_black_led->blink_slow();
    } else if (black_wire_value == None) {
        connected_wire_black_led->blink_fast();
    } else {
        connected_wire_black_led->on();
    }


    /* ************* Toggle Switch & Servo ************** */
    Switch toggle_switch_value = toggle_switch->get_position();
    ServoPosition position = center;
    if (toggle_switch_value == LEFT) {
        position = left;
    } else if (toggle_switch_value == RIGHT) {
        position = right;
    }
    servo->set_position(position);


    /* ************* Push Button & Motor ************** */
    bool pushed = push_button->is_pushed();
    motor->turn(static_cast<OnOff>(pushed));


    /* ************* USB & Switch & hdd ************** */
    bool sw = on_off_switch->is_on();
    bool usb = usb_connection->is_connected();

    if (sw && usb && !was_spinning) {
        hdd->start_spinning();
        was_spinning = true;
    } else if (!sw && ! usb) {
        was_spinning = false;
    }


    char buffer[80];
    sprintf(buffer, "push %d, toggle %d, switch %d, red %d, black %d, rotary %d, cable %d",
            pushed, toggle_switch_value, sw, red_wire_value, black_wire_value, rotary_switch_value, usb);
    log(buffer);
}


/** Arduino loop function */
void loop() {
    timer.update();

    easy_game();
}
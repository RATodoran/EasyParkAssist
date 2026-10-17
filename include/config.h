#ifndef CONFIG_H
#define CONFIG_H

// define pentru senzori
#define XSHUT_FRONT_LEFT   2
#define XSHUT_FRONT_RIGHT  4
#define XSHUT_REAR_LEFT    6
#define XSHUT_REAR_RIGHT   7

// adresare pentru twi
#define ADDR_FRONT_LEFT    0x30
#define ADDR_FRONT_RIGHT   0x31
#define ADDR_REAR_LEFT     0x32
#define ADDR_REAR_RIGHT    0x33

// variabile motor tractiune
#define MOTOR_DRIVE_PWM  3
#define MOTOR_DRIVE_IN1  8
#define MOTOR_DRIVE_IN2  9

// variabile motor directie
#define MOTOR_STEER_PWM  5
#define MOTOR_STEER_IN1  10
#define MOTOR_STEER_IN2  11

// definire pentru modul bt
#define BT_RX_PIN  12
#define BT_TX_PIN  13

// ===== I2C =====
// Arduino UNO: SDA = A4, SCL = A5

#endif
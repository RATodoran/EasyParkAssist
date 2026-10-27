
#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// Senzori VL53L0X - XSHUT
#define XSHUT_FRONT_LEFT   A0
#define XSHUT_FRONT_RIGHT  A1
#define XSHUT_REAR_LEFT    A2
#define XSHUT_REAR_RIGHT   A3

// Adrese I2C senzori
#define ADDR_FRONT_LEFT    0x30
#define ADDR_FRONT_RIGHT   0x31
#define ADDR_REAR_LEFT     0x32
#define ADDR_REAR_RIGHT    0x33

// Driver motoare HW-627
#define MOTOR_ENABLE       5

// Motor tractiune
#define MOTOR_DRIVE_IN1    6
#define MOTOR_DRIVE_IN2    7

// Motor directie
#define MOTOR_STEER_IN1    8
#define MOTOR_STEER_IN2    9

// Bluetooth HC-05
// SoftwareSerial(RX, TX)
#define BT_RX_PIN          10
#define BT_TX_PIN          11

// LCD I2C
#define LCD_ADDRESS        0x27
#define LCD_COLUMNS        16
#define LCD_ROWS           2

// Configuratie generala
#define SERIAL_BAUD        9600
#define SENSOR_INTERVAL    300

#endif

#include "GoPlus2.h"

#define WIRE Wire1

GoPlus2::GoPlus2(){

}

void GoPlus2::begin(){
  WIRE.begin();
}

void GoPlus2::Servo_write_angle(uint8_t number, uint8_t angle) {
    WIRE.beginTransmission(GOPLUS_ADDR);
    WIRE.write(SERVO_ADDR | number);
    WIRE.write(angle);
    WIRE.endTransmission();
}

void GoPlus2::Servo_write_plusewidth(uint8_t number,  uint16_t width) {
    WIRE.beginTransmission(GOPLUS_ADDR);
    WIRE.write(PLUSE_ADDR | number);
    uint8_t buff_out[2];
    buff_out[0] = width >> 8;
    buff_out[1] = width & 0xff;
    WIRE.write(buff_out[0]);
    WIRE.write(buff_out[1]);
    WIRE.endTransmission();
}

void GoPlus2::Motor_write_speed(uint8_t number, int motor_speed) {
    WIRE.beginTransmission(GOPLUS_ADDR);
    WIRE.write(MOTOR_ADDR | number);
    WIRE.write(motor_speed);
    WIRE.endTransmission();
}

uint16_t GoPlus2::hub1_d_read_value(uint8_t reg){
  
  WIRE.beginTransmission(GOPLUS_ADDR);
  WIRE.write(HUB_READ_DIGITAL | reg);
  WIRE.endTransmission();
  
  uint8_t RegValue_L;

  WIRE.requestFrom(GOPLUS_ADDR,1);
  while(WIRE.available()){
    RegValue_L = WIRE.read();
  }
  return RegValue_L;   
} 


uint16_t GoPlus2::hub1_a_read_value(uint8_t reg){
  
  WIRE.beginTransmission(GOPLUS_ADDR);
  WIRE.write(HUB_READ_ANALOG | reg);
  WIRE.endTransmission();
  
  uint8_t RegValue_L,RegValue_H;

  WIRE.requestFrom(GOPLUS_ADDR,2);
  while(WIRE.available()){
    RegValue_H = WIRE.read();
    RegValue_L = WIRE.read();
  }
  
  return (RegValue_H<<8) | RegValue_L;   
} 

uint16_t GoPlus2::hub2_a_read_value(uint8_t reg){
  
  WIRE.beginTransmission(GOPLUS_ADDR);
  WIRE.write(HUB_READ_ANALOG | reg);
  WIRE.endTransmission();
  
  uint8_t RegValue_L,RegValue_H;

  WIRE.requestFrom(GOPLUS_ADDR,2);
  while(WIRE.available()){
    RegValue_H = WIRE.read();
    RegValue_L = WIRE.read();
  }
  
  return (RegValue_H<<8) | RegValue_L;   
} 

uint16_t GoPlus2::hub2_d_read_value(uint8_t reg){
  
  WIRE.beginTransmission(GOPLUS_ADDR);
  WIRE.write(HUB_READ_DIGITAL | reg);
  WIRE.endTransmission();
  
  uint8_t RegValue_L;

  WIRE.requestFrom(GOPLUS_ADDR,1);
  while(WIRE.available()){
    RegValue_L = WIRE.read();
  }
  
  return RegValue_L;   
} 

uint16_t GoPlus2::hub3_a_read_value(uint8_t reg){
  
  WIRE.beginTransmission(GOPLUS_ADDR);
  WIRE.write(HUB_READ_ANALOG | reg);
  WIRE.endTransmission();
  
  uint8_t RegValue_L,RegValue_H;

  WIRE.requestFrom(GOPLUS_ADDR,2);
  while(WIRE.available()){
    RegValue_H = WIRE.read();
    RegValue_L = WIRE.read();
  }
  
  return (RegValue_H<<8) | RegValue_L;   
} 



uint16_t GoPlus2::hub3_d_read_value(uint8_t reg){
  
  WIRE.beginTransmission(GOPLUS_ADDR);
  WIRE.write(HUB_READ_DIGITAL | reg);
  WIRE.endTransmission();
  
  uint8_t RegValue_L;

  WIRE.requestFrom(GOPLUS_ADDR,1);
  while(WIRE.available()){ 
    RegValue_L = WIRE.read();
  }
  
  return RegValue_L;   
} 


void GoPlus2::hub1_wire_value(uint8_t reg,uint8_t value){
  
  WIRE.beginTransmission(GOPLUS_ADDR);
  WIRE.write(HUB_WIRE | reg);
  WIRE.write(value & 0xff);
  WIRE.endTransmission(); 
} 

void GoPlus2::hub2_wire_value(uint8_t reg,uint8_t value){
  
  WIRE.beginTransmission(GOPLUS_ADDR);
  WIRE.write(HUB_WIRE | reg);
  WIRE.write(value & 0xff);
  WIRE.endTransmission(); 
} 

void GoPlus2::hub3_wire_value(uint8_t reg,uint8_t value){
  
  WIRE.beginTransmission(GOPLUS_ADDR);
  WIRE.write(HUB_WIRE | reg);
  WIRE.write(value & 0xff);
  WIRE.endTransmission(); 
} 


void GoPlus2::hub1_set_io(uint8_t reg, uint8_t value){
  WIRE.beginTransmission(GOPLUS_ADDR);
  WIRE.write(HUB_IO_SET | reg);
  WIRE.write(value & 0xff);
  WIRE.endTransmission(); 
}

void GoPlus2::hub2_set_io(uint8_t reg, uint8_t value){
  WIRE.beginTransmission(GOPLUS_ADDR);
  WIRE.write(HUB_IO_SET | reg);
  WIRE.write(value & 0xff);
  WIRE.endTransmission(); 
}

void GoPlus2::hub3_set_io(uint8_t reg, uint8_t value){
  WIRE.beginTransmission(GOPLUS_ADDR);
  WIRE.write(HUB_IO_SET | reg);
  WIRE.write(value & 0xff);
  WIRE.endTransmission(); 
}



uint8_t GoPlus2::hub1_d_o_read_value(uint8_t reg){
  
  WIRE.beginTransmission(GOPLUS_ADDR);
  WIRE.write(HUB_READ_O_DIGITAL | reg);
  WIRE.endTransmission();
  
  uint8_t RegValue;

  WIRE.requestFrom(GOPLUS_ADDR,1);
  while(WIRE.available()){ 
    RegValue = WIRE.read();
  }
  
  return RegValue;   
} 


uint8_t GoPlus2::hub2_d_o_read_value(uint8_t reg){
  
  WIRE.beginTransmission(GOPLUS_ADDR);
  WIRE.write(HUB_READ_O_DIGITAL | reg);
  WIRE.endTransmission();
  
  uint8_t RegValue;

  WIRE.requestFrom(GOPLUS_ADDR,1);
  while(WIRE.available()){ 
    RegValue = WIRE.read();
  }
  
  return RegValue;   
} 

uint8_t GoPlus2::hub3_d_o_read_value(uint8_t reg){
  
  WIRE.beginTransmission(GOPLUS_ADDR);
  WIRE.write(HUB_READ_O_DIGITAL | reg);
  WIRE.endTransmission();
  
  uint8_t RegValue;

  WIRE.requestFrom(GOPLUS_ADDR,1);
  while(WIRE.available()){ 
    RegValue = WIRE.read();
  }
  
  return RegValue;   
} 

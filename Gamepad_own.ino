
#include <Gamepad.h>

typedef struct {

  int gamepadButton;
  int IOPin;
  
} gpButton;

gpButton buttonA = {0,9};
gpButton buttonB = {1,8};

Gamepad gp;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  
  pinMode(buttonA.IOPin, INPUT_PULLUP);
  pinMode(buttonB.IOPin, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

  int lx,ly, rx, ry;

  lx = analogRead(A3);
  ly = analogRead(A2);
  rx = analogRead(A1);
  ry = analogRead(A0);

  rx = map(rx, 0,1023,-127,127);
  ry = map(ry,0,1023,-127,127);
  lx = map(lx, 0,1023,-127,127);
  ly = map(ly,0,1023,-127,127);

  gp.setLeftXaxis(lx);
  gp.setLeftYaxis(ly);

  gp.setRightXaxis(rx);
  gp.setRightYaxis(ry);

  pressButton(buttonA);
  pressButton(buttonB);
  

}


void pressButton(gpButton button){

  int buttonPressed = digitalRead(button.IOPin);

  if(buttonPressed == LOW)
    gp.setButtonState(button.gamepadButton, true);
  else 
    gp.setButtonState(button.gamepadButton, false);
    
  
}






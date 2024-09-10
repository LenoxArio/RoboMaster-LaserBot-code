#include <Arduino.h>
#include "servoMotor.h"
#include <Servo.h>

int RotateServoBase = 80; //Position du servo de la base au démarage
int RotateServoHead = 120; //Position du servo de la tête au démarage

const int servoHeadPin = 3; //Pin du servo de la tête
const int servoBasePin = 48; //Pin du servo de la base

Servo servoBase; //Déclaration du servo servoBase
Servo servoHead; //Déclaration du servo servoHead

void setupServo(){
    servoBase.attach(servoBasePin);
    servoHead.attach(servoHeadPin);
    servoBase.write(RotateServoBase);
    servoHead.write(RotateServoHead);
}

void posServoBase(int val1){
    //if(val1 >= 0 and val1 <= 180){ //Voir si val1 est entre 0 et 180 pour pas faire tourner trop le servo
        RotateServoBase = val1; //Modifier la valeur de RotateServoBase par celle de val1
        servoBase.attach(servoBasePin); //Définir la broche du servo avec la variable servoBasePin
        servoBase.write(RotateServoBase); //Définir la position du servo selon la valeur de la variable RotateServoBase
        delay(15); //Delay de 15 millisecond 
        servoBase.detach(); //Déconnecter le servo pour éviter les mouvements parasites
    //}
}

void posServoHead(int val2){
    //if(val2 >= 0 and val2 <= 180){ //Voir si val1 est entre 0 et 180 pour pas faire tourner trop le servo
        RotateServoHead = val2; //Modifier la valeur de RotateServoHead par celle de val2
        servoHead.attach(servoHeadPin); //Définir la broche du servo avec la variable servoHeadPin
        servoHead.write(RotateServoHead); //Définir la position du servo selon la valeur de la variable RotateServoHead
        delay(15); //Delay de 15 millisecond 
        servoHead.detach(); //Déconnecter le servo pour éviter les mouvements parasites
    //}
}

void servoBaseAdd(){
    RotateServoBase = RotateServoBase + 1;
    posServoBase(RotateServoBase);
}

void servoBaseRemoved(){
    RotateServoBase = RotateServoBase - 1;
    posServoBase(RotateServoBase);
}

void servoHeadAdd(){
    RotateServoHead = RotateServoHead + 1;
    posServoHead(RotateServoHead);
}

void servoHeadRemoved(){
    RotateServoHead = RotateServoHead - 1;
    posServoHead(RotateServoHead);
}
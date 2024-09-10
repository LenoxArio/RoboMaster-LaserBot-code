#include <Arduino.h>
#include "motor/motor.h"
#include "motor/servo/servoMotor.h"
#include "communication/uart/uart-communication.h"
#include "shield/led/ledShield.h"
#include "shield/capteur/capteur.h"


String msg = "";
int capteurVal = 0;

void powerOff();
void immobilized();

void setup() {
    setupUart();
    setupLedShield();
    setupMotor();
    ledRight(255);
    buzzerTone(500,100);
    delay(100);
    ledBack(255);
    ledBefore(255);
    buzzerTone(800,100);
    delay(100);
    ledLeft(255);
    buzzerTone(1000,100);
    setupServo();
    delay(1000);

    while(msg != "DC114"){
        msg = uartReceiveString();
        for (int brightness = 255; brightness >= 0; brightness-=5) {
            ledRight(brightness);
            ledBefore(brightness);
            ledBack(brightness);
            ledLeft(brightness);
            delay(10); // Attente pour voir la variation de luminosité
        }

        for (int brightness = 0; brightness <= 255; brightness+=5) {
            ledRight(brightness);
            ledBefore(brightness);
            ledBack(brightness);
            ledLeft(brightness);
            delay(10); // Attente pour voir la variation de luminosité
        }

        // Inverser la variation de luminosité
    }

    msg = "";

    ledRight(255);
    ledLeft(255);
    ledBack(255);
    ledBefore(255);

    buzzerTone(800,100);
    delay(100);
    buzzerTone(1000,100);
    delay(100);
}

void loop() {
    msg = uartReceiveString();
    if (msg != "") {
        if(msg == "avancer"){
            speedMotor(200,200,200,200);
            avancer();

        }else if(msg == "reculer"){
            speedMotor(200,200,200,200);
            reculer();

        }else if(msg == "droite"){
            speedMotor(200,200,200,200);
            droite();

        }else if(msg == "gauche"){
            speedMotor(200,200,200,200);
            gauche();

        }else if(msg == "bidroite"){
            speedMotor(200,200,200,200);
            BiDroite();

        }else if(msg == "bigauche"){
            speedMotor(200,200,200,200);
            BiGauche();
            
        }else if(msg == "TouGh"){ //base gauche
            servoBaseAdd();
        }else if(msg == "TouDr"){ //base droite
            servoBaseRemoved();
        }else if(msg == "blb"){ //tête bas
            servoHeadRemoved();
        }else if(msg == "blh"){ //tête haut
            servoHeadAdd();
        }else if(msg == "immobilized"){
            immobilized();
        }
        
        else if(msg == "stop"){
            stop();
        }else if(msg == "off"){
            powerOff();
        }

    }
    capteurVal = detectionShield(880);
    if(capteurVal == 1){
        uartSendString("capteur1");
        buzzerTone(800,100);
        ledLeft(255);
        delay(100);
        buzzerTone(800,100);
        ledLeft(0);
        delay(100);
        ledLeft(255);
   
    }else if(capteurVal == 2){
        uartSendString("capteur2");
        buzzerTone(800,100);
        ledRight(255);
        delay(100);
        buzzerTone(800,100);
        ledRight(0);
        delay(100);
        ledRight(255);

    }else if(capteurVal == 3){
        uartSendString("capteur3");
        buzzerTone(800,100);
        ledBefore(255);
        delay(100);
        buzzerTone(800,100);
        ledBefore(0);
        delay(100);
        ledBefore(255);

    }else if(capteurVal == 4){
        uartSendString("capteur4");
        buzzerTone(800,100);
        ledBack(255);
        delay(100);
        buzzerTone(800,100);
        ledBack(0);
        delay(100);
        ledBack(255);

    }

    msg = "";
}


void powerOff(){
    stop();
    ledRight(0);
    ledBack(0);
    ledBefore(0);
    ledLeft(255);
    buzzerTone(1000,100);
    delay(100);
    ledBack(255);
    ledBefore(255);
    buzzerTone(800,100);
    delay(100);
    ledRight(255);
    buzzerTone(500,100);
    posServoBase(80);
    posServoHead(120);
    delay(10000);
    buzzerTone(1000,100);
    ledRight(0);
    ledBack(0);
    ledBefore(0);
    ledLeft(0);
    while (true){delay(1000);}
}

void immobilized(){
    for(int tt = 0; tt <= 3; tt++){
        stop();
        ledBack(255);
        ledBefore(255);
        ledLeft(255);
        ledRight(255);
        buzzerTone(1000,100);
        delay(100);
        ledBack(0);
        ledBefore(0);
        ledLeft(0);
        ledRight(0);
        delay(50);
    }
    msg = "";
    while(msg != "unimmo"){
        msg = uartReceiveString();
        ledBack(255);
        ledBefore(255);
        ledLeft(255);
        ledRight(255);
        delay(100);
        ledBack(0);
        ledBefore(0);
        ledLeft(0);
        ledRight(0);
        delay(50);
    }
}


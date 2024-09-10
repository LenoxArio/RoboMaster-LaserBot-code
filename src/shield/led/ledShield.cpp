#include <Arduino.h>
#include "ledShield.h"

int ledG = 4; //gauche
int ledD = 5; //droite
int ledA = 9; //avant
int ledB = 13;//arrière
const int buzz = 32; //buzzer

void setupLedShield(){ //Fonction pour définir les broches de l'arduino en tant que sortie pour les led
  pinMode(ledG, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(buzz, OUTPUT);
}

void ledRight(byte intensity1){
    analogWrite(ledD, intensity1); //faire varier l'instansité de la led en PWM entre 0 et 255 avec byte

}


void ledLeft(byte intensity2){
    analogWrite(ledG, intensity2); //allumer la led
    
}


void ledBefore(byte intensity3){
    analogWrite(ledA, intensity3); //allumer la led
}


void ledBack(byte intensity4){
    analogWrite(ledB, intensity4); //allumer la led     
}

void buzzerTone(int hz, int timer){
    tone(buzz, hz, timer);
}
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "uart-communication.h"

SoftwareSerial RaspberryPI(10, 11); // RX, TX

const unsigned long timeoutDuration = 100;  // Durée d'attente en ms
String receivedMessage;
unsigned long lastReceivedTime = 0;  // Dernière fois que nous avons reçu un message

void setupUart() {
    RaspberryPI.begin(57600);
}

String uartReceiveString() {
    if (RaspberryPI.available()) {
        receivedMessage = RaspberryPI.readStringUntil('\n');  // Lire jusqu'à la fin de ligne
        receivedMessage.trim();  // Supprimer les espaces superflus

        lastReceivedTime = millis();  // Met à jour le temps de réception du message
        return receivedMessage;
    }

    // Vérifiez si le timeout est dépassé
    if (millis() - lastReceivedTime > timeoutDuration) {
        return "stop";  // Retourne une chaîne vide pour indiquer un timeout
    } else {
        return "";  // Retourne une chaîne vide si aucun message n'a encore été reçu
    }
}

void uartSendString(String message1){
    RaspberryPI.println(message1);
}
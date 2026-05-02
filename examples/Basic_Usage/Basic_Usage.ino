/**
 * @file Basic_Usage.ino
 * @brief Exemple d'utilisation de la librairie Capacitive_Sensor
 * @author Olivier FOURNET
 */

#include <Capacitive_Sensor.h>

// Pin analogique où le capteurs est connecté
const int SENSOR_PIN = A0;

// Choix de la tension de référence (5V pour Arduino, 3.3V pour ESP32/ESP8266)
const float VREF = 5.0;  // Modifier selon votre carte

void setup() {
  Serial.begin(9600);
  Serial.println("=== Exemple Capacitive_Sensor ===");
  Serial.println();
}

void loop() {
  // Lecture de la valeur brute du convertisseur analogique-numérique (0-1023)
  int rawValue = analogRead(SENSOR_PIN);
  
  // Conversion en tension (en Volts)
  float voltage = rawValue * (VREF / 1023.0);
  
  // Calcul du pourcentage d'humidité du sol
  float humidity = Calcule_HumiditeSol_CapteurCapacitif(voltage);
  
  // Affichage des résultats
  Serial.print("Valeur brute (ADC): ");
  Serial.print(rawValue);
  Serial.print(" | Tension: ");
  Serial.print(voltage);
  Serial.print(" V | Humidite: ");
  Serial.print(humidity);
  Serial.println(" %");
  
  delay(1000);
}
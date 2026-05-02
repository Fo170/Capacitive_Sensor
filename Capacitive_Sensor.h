/**
 * @file Capacitive_Sensor.h
 * @author FOURNET Olivier (olivier.fournet@free.fr)
 * @brief Librairie pour capteurs capacitifs d'humidité du sol
 * @version 1.0.0
 * @date 2025
 * 
 * @copyright Copyright (c) 2025
 * 
 * Librairie Arduino pour calculer le pourcentage d'humidité du sol
 * à partir d'un capteur capacitif de mesure de'humidité du sol.
 * 
 * BROCHAGE :
 * - VCC : 3.3V ou 5V
 * - GND : Masse
 * - AOUT : Sortie analogique (pin ADC)
 * 
 * CALIBRATION (par défaut) :
 * - Sol sec (hors terre) : ~1.696V → 0%
 * - Sol trempé : ~1.087V → 100%
 * 
 * Ces valeurs peuvent varier selon le capteurs et l'environnement.
 * Il est recommandé de calibrate votre propre capteurs.
 * 
 * UTILISATION :
 * \code{.cpp}
 * #include <Capacitive_Sensor.h>
 * 
 * const int SENSOR_PIN = A0;
 * 
 * void setup() {
 *   Serial.begin(9600);
 * }
 * 
 * void loop() {
 *   // Lecture de la tension du capteur (0-5V ou 0-3.3V selon board)
 *   int rawValue = analogRead(SENSOR_PIN);
 *   float voltage = rawValue * (5.0 / 1023.0);  // Pour Arduino 5V
 *   // float voltage = rawValue * (3.3 / 1023.0); // Pour ESP32/ESP8266
 *   
 *   // Calcul du pourcentage d'humidité
 *   float humidity = Calcule_HumiditeSol_CapteurCapacitif(voltage);
 *   
 *   Serial.print("Tension: ");
 *   Serial.print(voltage);
 *   Serial.print("V - Humidité: ");
 *   Serial.print(humidity);
 *   Serial.println("%");
 *   
 *   delay(1000);
 * }
 * \endcode
 * 
 * CALIBRATION PERSONNALISÉE :
 * \code{.cpp}
 * // Définir vos propres valeurs de calibration avant d'inclure la librairie
 * #define V_SEC     1.700    // Valeur pour sol sec
 * #define V_TREMPEE 1.050    // Valeur pour sol humide
 * #include <Capacitive_Sensor.h>
 * \endcode
 */

#ifndef _Capacitive_Sensor_
#define _Capacitive_Sensor_

// ============================================
// CALIBRATION PAR DÉFAUT
// ============================================

#ifndef V_SEC
  /** Tension mesurée pour un sol complètement sec (hors terre) */
  #define V_SEC     1.696
#endif

#ifndef V_TREMPEE
  /** Tension mesurée pour un sol complètement humide */
  #define V_TREMPEE 1.087
#endif

// ============================================
// FONCTION PRINCIPALE
// ============================================

/**
 * @brief Calcule le pourcentage d'humidité du sol
 * 
 * @param v Tension mesurée par le capteur (en Volts)
 * @return float Pourcentage d'humidité (0-100%)
 *         - 0% = sol complètement sec
 *         - 100% = sol complètement humide
 */
float Calcule_HumiditeSol_CapteurCapacitif(float v)
{
  float h;

  h = 100.0 - 100.0 * (v - V_TREMPEE)/(V_SEC - V_TREMPEE);

  if(h > 100.0) h = 100.0;
  if(h < 0.0) h = 0.0;

  return h;
}

#endif // _Capacitive_Sensor_
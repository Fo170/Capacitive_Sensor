# Capacitive_Sensor

![Arduino](https://img.shields.io/badge/Arduino-IDE-00979C?style=flat&logo=arduino)
![PlatformIO](https://img.shields.io/badge/PlatformIO-EE6C4D?style=flat&logo=platformio)
![License](https://img.shields.io/badge/License-MIT-green)

Arduino library for capacitive soil moisture sensors - calculates soil humidity percentage from sensor voltage.

## Capteur

Cette librairie est conçue pour les capteurs capacitifs d'humidité du sol (non résistifs).

![Capteur capacitif](https://raw.githubusercontent.com/Fo170/Capacitive_Sensor/main/capteur%20capacitif.png)

### Achat

- [Capacitive Soil Moisture Sensor - Elecbee](https://www.elecbee.com/fr/product-detail/capacitive-soil-moisture-sensor-not-easy-to-corrode-wide-voltage-monitor-module_25415)

## Installation

### Arduino IDE (Library Manager)

1. Ouvrez Arduino IDE
2. Allez dans **Sketch > Include Library > Manage Libraries**
2. Recherchez "Capacitive_Sensor"
3. Cliquez sur **Install**

### PlatformIO

```ini
lib_deps =
  Fo170/Capacitive_Sensor@^1.0.0
```

Ou ajoutez la librairie via la commande :
```bash
pio lib install "Fo170/Capacitive_Sensor"
```

### Installation manuelle

1. Téléchargez le dossier `Capacitive_Sensor`
2. Copiez-le dans votre dossier de librairies Arduino (`Documents/Arduino/libraries/`)
3. Redémarrez Arduino IDE

## Branchement

| Pin Capteur | Pin Arduino/ESP |
|-------------|----------------|
| VCC         | 3.3V ou 5V     |
| GND         | GND            |
| AOUT        | A0 (ou pin ADC)|

![Schéma](https://raw.githubusercontent.com/Fo170/Capacitive_Sensor/main/capteur%20capacitif%20-%20sch%C3%A9ma.png)

## Calibration

Les valeurs par défaut sont :
- **Sol sec** (hors de terre) : ~1.696V → 0%
- **Sol trempé** : ~1.087V → 100%

> ⚠️ **Important** : Ces valeurs peuvent varier selon le capteurs et l'environnement. Il est recommandé de calibrate votre propre capteurs.

## Utilisation

### Exemple de base

```cpp
#include <Capacitive_Sensor.h>

const int SENSOR_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Lecture de la tension du capteurs (0-5V)
  int rawValue = analogRead(SENSOR_PIN);
  float voltage = rawValue * (5.0 / 1023.0);  // Pour Arduino 5V
  
  // Pour ESP32/ESP8266 :
  // float voltage = rawValue * (3.3 / 1023.0);
  
  // Calcul du pourcentage d'humidité
  float humidity = Calcule_HumiditeSol_CapteurCapacitif(voltage);
  
  Serial.print("Tension: ");
  Serial.print(voltage);
  Serial.print("V - Humidite: ");
  Serial.print(humidity);
  Serial.println("%");
  
  delay(1000);
}
```

### Calibration personnalisée

Pour utiliser vos propres valeurs de calibration :

```cpp
// Définir vos propres valeurs AVANT d'inclure la librairie
#define V_SEC     1.700    // Valeur pour sol sec
#define V_TREMPEE 1.050    // Valeur pour sol humide

#include <Capacitive_Sensor.h>
```

## API

### `Calcule_HumiditeSol_CapteurCapacitif(float tension)`

Convertit la tension du capteurs en pourcentage d'humidité.

**Paramètres :**
- `tension` : Tension mesurée par le capteurs (en Volts, 0-5V)

**Retourne :**
- `float` : Pourcentage d'humidité (0-100%)
  - 0% = sol complètement sec
  - 100% = sol complètement humide

## Exemples

Voir le dossier [examples/](examples/) pour plus d'exemples.

## Compatibilité

- Arduino Uno, Nano, Mega
- Arduino Leonardo, Due
- ESP32
- ESP8266
- Teensy
- Autres cartes compatibles Arduino

## Licence

MIT License - voir [LICENSE](LICENSE)

## Auteur

Olivier FOURNET - [@Fo170](https://github.com/Fo170)
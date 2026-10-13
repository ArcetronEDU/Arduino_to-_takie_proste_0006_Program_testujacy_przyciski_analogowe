const int analogInputPin = A3; // Pin wejściowy analogowy
const int threshold = 50;      // Próg wykrycia wciśnięcia (odcina szumy w spoczynku)
const int tolerance = 5;       // Dokładna tolerancja do rozróżnienia bliskich napięć

// Tablica do zapamiętywania wykrytych przycisków (maksymalnie 6 sztuk)
int learnedValues[6] = {0, 0, 0, 0, 0, 0}; 
int buttonCount = 0;                       

bool wasPressed = false; 

void setup() {
  Serial.begin(9600);
  // Brak tekstu powitalnego – port szeregowy jest od razu czysty
}

void loop() {
  int sensorValue = analogRead(analogInputPin);

  // Sprawdzamy, czy wciśnięto coś powyżej progu szumów
  if (sensorValue > threshold) {
    if (!wasPressed) { 
      wasPressed = true;

      // 1. Sprawdzamy, czy ten przycisk jest już znany (używamy ścisłej tolerancji = 5)
      int foundButtonIndex = -1;
      for (int i = 0; i < buttonCount; i++) {
        if (abs(sensorValue - learnedValues[i]) <= tolerance) {
          foundButtonIndex = i + 1; // Numery od 1 do 6
          break;
        }
      }

      String statusText = "";

      // 2. Obsługa nowego przycisku (tylko dopóki nie mamy jeszcze 6)
      if (foundButtonIndex == -1 && buttonCount < 6) {
        buttonCount++;
        learnedValues[buttonCount - 1] = sensorValue; 
        foundButtonIndex = buttonCount;               
        statusText = "[NOWY]";
      } 
      // 3. Jeśli przycisk jest znany
      else if (foundButtonIndex != -1) {
        statusText = "[ZNANY]";
      }

      // Jeśli przycisk został poprawnie zidentyfikowany lub dodany
      if (foundButtonIndex != -1) {
        float voltage = sensorValue * (5.0 / 1023.0);
        Serial.print(statusText);
        Serial.print(" Przycisk nr: ");
        Serial.print(foundButtonIndex);
        Serial.print("  |  Napiecie: ");
        Serial.print(voltage, 3);
        Serial.print(" V  |  ADC: ");
        Serial.println(sensorValue);
      }
      
      delay(50); // Opóźnienie antydrganiowe
    }
  } else {
    wasPressed = false;
  }
}

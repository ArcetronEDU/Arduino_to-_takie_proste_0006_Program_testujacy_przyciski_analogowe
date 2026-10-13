const int analogInputPin = A3; // Pin wejściowy analogowy
int lastSensorValue = 0;       // Zmienna do zapamiętania poprzedniego stanu
const int threshold = 50;      // Próg wykrycia naciśnięcia (odcina szumy w stanie spoczynku)

void setup() {
  Serial.begin(9600); // Inicjalizacja portu szeregowego
}

void loop() {
  int sensorValue = analogRead(analogInputPin); // Odczyt wartości z pinu analogowego

  // Sprawdzamy czy naciśnięto przycisk (wartość powyżej progu)
  if (sensorValue > threshold) {
    // Reagujemy tylko wtedy, gdy wartość się zmieniła (nowe naciśnięcie lub inny przycisk)
    // Dodano małą tolerancję (np. 15), aby drgania styków nie powodowały wielokrotnego wypisu
    if (abs(sensorValue - lastSensorValue) > 15) {
      float voltage = sensorValue * (5.0 / 1023.0); // Konwersja na napięcie

      // Wyświetlenie obu informacji w jednej linijce
      Serial.print("Napiecie: ");
      Serial.print(voltage, 3);
      Serial.print(" V  |  Wartosc ADC: ");
      Serial.println(sensorValue);

      lastSensorValue = sensorValue; // Zapisujemy obecny stan
      delay(50); // Krótkie opóźnienie antydrganiowe (debouncing)
    }
  } else {
    // Gdy żaden przycisk nie jest wciśnięty, resetujemy zapamiętaną wartość,
    // co pozwala ponowne naciśnięcie tego samego przycisku.
    lastSensorValue = 0;
  }
}

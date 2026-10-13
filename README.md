# Arduino_to_takie_proste_0006_Program_testujacy_przyciski_analogowe
Materiały dodatkowe do filmów "Arduino to takie proste" do filmu nr:#0007

Dwa programy dla Arduino Uno R3 do testowania przycisków tact switch podłączonych pod wejście analogowe A3
Pierwszy odczytuje napięcie i wartość ADC w monitorze szeregowym, drugi dodatkowo nadaje numer (pozycje) kolejno naciśniętych przycisków:

OPIS OGÓLNY PROGRAMU (ZAŁOŻENIA):
Program służy do automatycznej obsługi i nauki do 6 przycisków analogowych 
podłączonych do jednego pinu (A3). Główne założenia to:

1. Autolearning (Tryb nauki): Program nie wymaga wpisów na sztywno – sam 
   zapamiętuje pierwszy odczyt dla każdego nowo wciśniętego przycisku.
2. Wysoka precyzja: Używa wąskiej tolerancji (5 jednostek ADC), co pozwala 
   rozróżnić przyciski generujące bardzo bliskie sobie napięcia.
3. Brak blokowania (Non-blocking): Nie używa długich opóźnień (delay), 
   dzięki czemu natychmiast reaguje na naciśnięcie i wypisuje dane w jednej linii.
4. Instrukcia: aby odczyt był prawidłowy w drugim programie z pozycjonowaniem należny po uruchomieniu okna monitora szeregowego,
    kolejno nacisnąć wszystkie przyciski tylko raz, po czym program zapamięta kolejność i pozycje, na czas otwartego okna monitora szeregowego



© 2026 ARCETRON https://creativecommons.org/licenses/by-nc/4.0/legalcode.pl
Licencja: Creative Commons BY‑NC 4.0

Oznacza to, że:
- możesz kopiować, udostępniać i używać tej pracy za darmo,
- możesz ją modyfikować i tworzyć na jej podstawie własne materiały,
- musisz podać autora w sposób wskazany przez twórcę,
- nie wolno używać tej pracy w celach komercyjnych,
- nie wolno sprzedawać tej pracy ani wykorzystywać jej w płatnych projektach,
- jeśli publikujesz zmodyfikowaną wersję, również musisz podać autora oryginału,
- licencja nie ogranicza praw autora do komercyjnego wykorzystania własnej pracy. 

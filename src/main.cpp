#include <Arduino.h>

#define LED_PIN 12

// --- Aturan Waktu Sandi Morse (dalam milidetik) ---
// 1 Unit waktu = 200ms (Bisa diubah jika ingin lebih cepat/lambat)
const int dotDelay = 200;                  // Titik (.) = 1 Unit
const int dashDelay = dotDelay * 3;        // Garis (-) = 3 Unit
const int elementPause = dotDelay;         // Jeda antar simbol dalam 1 huruf = 1 Unit
const int letterPause = dotDelay * 3;      // Jeda antar huruf = 3 Unit
const int wordPause = dotDelay * 7;        // Jeda antar kata (atau pengulangan SOS) = 7 Unit

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

// Fungsi pembantu untuk menyalakan LED sesuai durasi
void blinkLED(int duration) {
  digitalWrite(LED_PIN, HIGH);   
  delay(duration);               // Tunggu sesuai durasi (titik atau garis)
  digitalWrite(LED_PIN, LOW);    
  delay(elementPause);           // Jeda wajib setelah setiap simbol
}

void loop() {

  // Huruf S: Tiga Titik (...)
  blinkLED(dotDelay);
  blinkLED(dotDelay);
  blinkLED(dotDelay);

  // Jeda antar huruf (dikurangi elementPause karena sudah dipanggil di dalam blinkLED)
  delay(letterPause - elementPause);

  // Huruf O: Tiga Garis (---)
  blinkLED(dashDelay);
  blinkLED(dashDelay);
  blinkLED(dashDelay);

  // Jeda antar huruf
  delay(letterPause - elementPause);

  // Huruf S: Tiga Titik (...)
  blinkLED(dotDelay);
  blinkLED(dotDelay);
  blinkLED(dotDelay);

  // Jeda panjang sebelum mengulang dari awal
  delay(wordPause - elementPause);
}
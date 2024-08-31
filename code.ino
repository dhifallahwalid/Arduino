#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal.h>

// Définition des broches
#define DHTPIN 2     // Broche connectée au signal du capteur DHT11
#define DHTTYPE DHT11 // Type de capteur DHT 11 
#define lcd_rs 3  // signaux de contrôle de l'écran LCD
#define lcd_en  4
#define lcd_d4  5
#define lcd_d5  6
#define lcd_d6  7
#define lcd_d7  8

// Initialisation des objets
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(lcd_rs,lcd_en,lcd_d4,lcd_d5,lcd_d6,lcd_d7);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2); // Initialisation de l'écran LCD 16x2
}

void loop() {
  // Lecture des données du capteur DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  // Vérification si les données sont valides
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Affichage sur l'écran LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidite: ");
  lcd.print(h);
  lcd.print("%  ");
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("C");

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temp: ");
  Serial.print(t);
  Serial.println(" *C ");

  delay(2000);
}

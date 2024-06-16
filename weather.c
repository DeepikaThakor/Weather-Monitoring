#include <DHT.h>
#include <LiquidCrystal.h>
#define DHTPIN 7 // Define the pin where the DHT sensor is connected
#define DHTTYPE DHT11 // Use DHT11 sensor, change to DHT22 if you're using DHT22
DHT dht(DHTPIN, DHTTYPE);
// Initialize the LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
lcd.begin(16, 2); // Initialize the LCD with 16 columns, 2 rows
dht.begin(); // Initialize the DHT sensor
}
void loop() {
// Read temperature and humidity from the DHT sensor
float temperature = dht.readTemperature();
float humidity = dht.readHumidity();
// Check if the readings are valid
if (!isnan(temperature) && !isnan(humidity)) {
// Display temperature and humidity on the LCD
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Temp: ");
lcd.print(temperature);
lcd.print("C");
lcd.setCursor(0, 1);
lcd.print("Humidity: ");
lcd.print(humidity);
lcd.print("%");
} else {
// Display an error message if the readings are not valid
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Error reading sensor");
}
delay(2000); // Wait for 2 seconds before reading again
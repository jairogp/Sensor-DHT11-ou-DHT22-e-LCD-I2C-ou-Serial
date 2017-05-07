    /*
    Pinagem do LCD
    
    GND => (-)
    VCC => 5V
    SDA => A4
    SCL => A5 
    
  
    Pinagem do DHT11 Olhando de frente

    Pin 1 => VCC
    Pin 2 => Pin 8 do Arduino
    Pin 3 => Sem Uso
    Pin 4 => GND
    */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
#include <DHT.h> 

LiquidCrystal_I2C lcd(39,16,2);  // 0x27 ou 39

//Define a ligação ao pino de dados do sensor
#define DHTPIN 8
 
//Define o tipo de sensor DHT utilizado
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);
 
 
//Array simbolo grau
byte grau[8] ={ B00001100,
                B00010010,
                B00010010,
                B00001100,
                B00000000,
                B00000000,
                B00000000,
                B00000000,};
 
void setup()
{
lcd.init();                // initialize the lcd 
lcd.backlight();           // acende a luz de fundo no lcd
lcd.createChar(0, grau);   //Cria o caractere customizado com o simbolo do grau
}
 
void loop()
{
float h = dht.readHumidity(); //Le o valor da umidade
float t = dht.readTemperature(); //Le o valor da temperatura
lcd.setCursor(0,0);
lcd.print("Temp : ");
lcd.print(" ");
lcd.setCursor(7,0);
lcd.print(t,1);
lcd.setCursor(12,0);
 
//Mostra o simbolo do grau formado pelo array
lcd.write((byte)0);
 
//Mostra o simbolo do grau quadrado
//lcd.print((char)223);
 
lcd.setCursor(0,1);
lcd.print("Umid : ");
lcd.print(" ");
lcd.setCursor(7,1);
lcd.print(h,1);
lcd.setCursor(12,1);
lcd.print("%");
 
//Intervalo recomendado para leitura do sensor
delay(2000);
}

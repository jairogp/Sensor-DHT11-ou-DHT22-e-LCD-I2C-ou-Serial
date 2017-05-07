  /*
  Pinagem do DHT11 Olhando de frente
  Pin 1 => VCC
  Pin 2 => Pin 7 do Arduino
  Pin 3 => Sem Uso
  Pin 4 => GND
  */
  #include <DHT.h>

  // Pino conectado ao pino de dados do sensor
  #define DHTPIN 7

  // Utilize a linha abaixo de acordo com o modelo do sensor
  //#define DHTTYPE DHT11   // Sensor DHT11
  #define DHTTYPE DHT22   // Sensor DHT 22  (AM2302)
  //#define DHTTYPE DHT21   // Sensor DHT 21 (AM2301)

  // Definicoes do sensor : pino, tipo
  DHT dht(DHTPIN, DHTTYPE);

  void setup() 
  {
  Serial.begin(9600); 
  Serial.println("Aguardando dados...");
  // Iniclaiza o sensor DHT
  dht.begin();
  }

  void loop() 
  {
  // Aguarda 5 segundos entre as medicoes
  delay(5000);
  
  // Leitura da umidade
  float h = dht.readHumidity();
  // Leitura da temperatura (Celsius)
  float t = dht.readTemperature();
  
  // Verifica se o sensor esta respondendo
  if (isnan(h) || isnan(t))
  {
    Serial.println("Falha ao ler dados do sensor DHT !!!");
    return;
  }

  // Mostra a temperatura no serial monitor e no display
  Serial.print("Temperatura: "); 
  Serial.print(t);
  Serial.print(" graus  ");
  // Mostra a umidade no serial monitor e no display
  Serial.print("Umidade: "); 
  Serial.print(h);
  Serial.println(" %");
  }

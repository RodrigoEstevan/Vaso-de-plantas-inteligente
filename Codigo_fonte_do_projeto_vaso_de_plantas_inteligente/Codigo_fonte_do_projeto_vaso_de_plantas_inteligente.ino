//Vaso de plantas inteligente, Auto irrigável e Sustentável.
//Por: Rodrigo Estevan Nyari Vergara T.I.A: 31623913 Turma: 5J
//Data: 22/06/2020

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define DEBUG

//pinos
const int SensorUmidade = A0;
const int MiniBomba = D6;
const int SensorNivel = D1;

//variaveis
int agua;
int umidade;
int umidade2;

//informações da rede WIFI
const char* ssid = "VIVO-9480";         //SSID da rede WIFI
const char* password =  "3DD90B9480";   //senha da rede wifi
 
//informações do broker MQTT, informações geradas pelo CloudMQTT
const char* mqttServer = "postman.cloudmqtt.com";   //server
const char* mqttUser = "swpzpujm";                  //user
const char* mqttPassword = "7QJMMG77vznv";          //password
const int mqttPort = 17510;                         //port
const char* mqttTopicSub ="Vaso/Status";            //tópico

int ultimoEnvioMQTT = 0;
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
 
  Serial.begin(115200);
   
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    #ifdef DEBUG
    Serial.println("Conectando ao WiFi..");
    #endif
  }
  #ifdef DEBUG
  Serial.println("Conectado na rede WiFi");
  #endif
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    #ifdef DEBUG
    Serial.println("Conectando ao Broker MQTT...");
    #endif
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
      #ifdef DEBUG
      Serial.println("Conectado");  
      #endif
 
    } else {
      #ifdef DEBUG 
      Serial.print("falha estado  ");
      Serial.print(client.state());
      #endif
      delay(2000);
 
    }
  }

  //subscreve no tópico
  client.subscribe(mqttTopicSub);

 //Definição dos pinos;
 pinMode(MiniBomba, OUTPUT);
 pinMode(SensorUmidade, INPUT);
 pinMode(SensorNivel, INPUT);
}
 
void callback(char* topic, byte* payload, unsigned int length) {

  //armazena msg recebida em uma sring
  payload[length] = '\0';
  String strMSG = String((char*)payload);
 
}

void loop() {
agua = digitalRead(SensorNivel);
Serial.print("agua:");
Serial.println(agua);
delay(1000);

if (agua == LOW){

//faz leitura do sensor de umidade
umidade = analogRead(SensorUmidade);
Serial.print("umidade:");
Serial.println(umidade);
//informa que há água
Serial.print("Recipiente abastecido.");
client.publish("mqttTopicSub", "Recipiente abastecido.");
delay(2000);

if (umidade >= 1024){
  digitalWrite(MiniBomba, LOW);
  Serial.print("Solo seco, regando...");
  client.publish("mqttTopicSub", "Solo seco, regando.");
  delay(2000);
  }else{
    digitalWrite(MiniBomba, HIGH);
    Serial.print("Solo umido...");
    client.publish("mqttTopicSub", "Solo umido.");
    delay(2000);
    }
}

if (agua == HIGH){
  
umidade2 = analogRead(SensorUmidade);
Serial.print("umidade2:");
Serial.println(umidade2);

if (umidade2 >= 1024){
  digitalWrite(MiniBomba, HIGH);
  Serial.print("Sem água, necessário abastecer.");
  client.publish("mqttTopicSub", "Sem água, necessário abastecer.");
  delay(2000);
  }
if (umidade2 < 1024){
    digitalWrite(MiniBomba, HIGH);
    Serial.print("Sem água, necessário abastecer.");
    client.publish("mqttTopicSub", "Sem água, necessário abastecer.");
    delay(2000);
    }
}

}

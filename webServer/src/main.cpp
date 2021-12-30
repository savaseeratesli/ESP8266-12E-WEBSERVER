#include <Arduino.h>
#include <ESP8266WiFi.h>

//Wifi Adı,Şifresi
//const değişmesini istemediğim değişkenlerde kullanılır.
const char* ssid="Eratesli";
const char* password="2663.bond";

//80.portuaçtık
WiFiServer server(80);

void setup() 
{
  //Kurulum Ayarları
  Serial.begin(115200);
  delay(10);

  Serial.println(ssid);//Wifi adı
  WiFi.begin(ssid,password);

  //Wifi yoksa ... koy
  while (WiFi.status()!=WL_CONNECTED)
  {
    delay(100);
    Serial.println("...");
  }

  Serial.println();

  Serial.println("Baglandi.");

  server.begin();//Server başladı

  Serial.println("Server Aktif.");

  //Cihaz arayüzü arama motorunda açılsın
  Serial.print("URL= ");

  Serial.print("http://");

  //ESP IP
  Serial.print(WiFi.localIP());

  Serial.println("/");
  
}

void loop() 
{
  //client adında bağlantı oluştu
  //server buna atandı
  //WEBten biristek olduğunda client aktifleşecek
  WiFiClient client=server.available();

  if(!client)//İstek yoksa
  {
    return;//İstek var mı?
  }

  client.println("Server...");
}


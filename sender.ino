/*
 * Este é o sketch do arduino que vai
 * enviar os dados da tag rfid pela porta serial
 * para o outro arduino (arduino mega)
 * 
 * neste arduino (uno), temos os pinos 0 e 1 que são RX e TX
 * cada um deles, vai no pino contrário no outro aruino, RX -> TX, e TX -> RX
 * sendo que no outro arduíno (mega), os pinos usados são o 18 e 19
 * sobre o rfid, usei este link como referência
 * http://blog.filipeflop.com/wireless/controle-acesso-leitor-rfid-arduino.html
 * sendo que, se usar outro arduino, como o mega, os pinos mudam, então 
 * procurar usar o arduino uno como o device que vai enviar os dados da tag
 * rfid
 */
#include <SPI.h>
#include <MFRC522.h>

char tag[9];

#define tempo 500
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.print("iniciando");
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

}

void loop() {

  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Mostra UID na serial
//  Serial.print("\nUID da tag :");
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++){
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println(conteudo);
  envia(conteudo);
  delay(tempo);
  
}
void envia(String value){
  value.toCharArray(tag, 9);
  Serial.write(tag, 9);
}


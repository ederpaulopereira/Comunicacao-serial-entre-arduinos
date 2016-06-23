/*
 * Este sketch recebe os dados pela serial 1 (portas 18 e 19, tx e rx respectivamente)
 * e fará o envio dos dados via rede para um banco mysql (falta implementar)
 * o arduino mega tem várias (3) seriais, então esolhi a serial 1, que pertence aos
 * pinos citados ali em cima.
 * 
 * Para comunicar com o mysql, tem uma lib pronta com exemplos, só 
 * ir em sketch/incluir biblioteca/gerenciar bibliotecas
 * e pesquisar por mysql, instala
 * vai em arquivo/exemplos/mysql connector arduino, 
 * e dá uma olhada nos exemplos :)
 */
char tag[9];

#define tempo 500

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600); // serial do arduino mega para comunicação com arduino uno
}

void loop() {
  int i = 0;

  if (Serial1.available()){
    delay(tempo);
    while (Serial1.available() && i < 9){
      tag[i++] = Serial1.read();
    }
    tag[i++] = '\0';
  }
  if(i>0){
    Serial.println(tag);
  }
}

#include <RFsendDUO.h>

const uint16_t ativa_tx = 32;
const uint16_t envia_tx = 14;

RFsendDUO RFsendDUO(ativa_tx, envia_tx);

uint16_t rawSobe[] = {2050,4900,592,528,271,232,568,528,267,236,568,235,564,240,564,532,268,527,276,227,569,235,568,532,272,527,272,227,569,531,276,524,268,239,568,232,568,523,276,524,276,227,568,240,564,235,568,232,568,527,276,232,564,527,272,240,568,524,275,228,576,524,271,528,272,528,271,236,560,235,572,236,560,248,555,236,568,235,565,235,572,520,276,235,564,232,568,235,568,236,564,235,572,236,560,235,564,236,564,239,564,236,568,235,568,232,568,528,267,236,572,524,271,536,268,524,280,523,272,536,268,527,272,528,272,227,572,528,271,236,540,531};
uint16_t rawPara[] = {2050,4900,588,536,260,243,564,528,272,235,560,240,560,239,568,528,264,535,268,240,560,239,568,528,272,527,272,232,572,519,284,524,276,223,572,232,572,524,275,528,268,235,568,240,560,235,564,236,568,532,263,244,564,532,268,235,564,528,268,239,572,528,276,519,276,528,268,231,576,232,564,239,560,240,560,239,560,240,564,239,564,532,272,231,564,236,564,239,568,232,564,235,564,244,560,239,560,240,564,239,565,235,564,532,263,240,568,236,560,239,564,532,276,523,276,232,564,231,572,232,564,535,272,232,568,235,564,532,264,239,548,528};
uint16_t rawDesce[] = {2050,4900,588,536,264,244,564,527,272,232,559,244,560,240,564,535,268,528,268,239,564,236,564,531,272,524,276,231,572,524,272,531,264,244,560,235,568,524,280,523,272,232,568,239,560,236,568,239,564,528,268,243,564,520,272,243,568,524,272,231,568,532,272,528,267,528,272,239,560,240,564,235,560,240,564,240,559,240,564,231,573,527,272,236,564,239,564,228,572,235,560,240,564,239,556,244,564,231,572,232,564,531,272,232,568,231,564,240,564,239,568,528,276,520,271,236,560,239,568,532,272,524,275,232,564,239,560,536,268,239,540,528};

#define ledR 4
#define ledB 5
#define ledG 12

void setup() {

  Serial.begin(115200);
  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledG, OUTPUT);
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledG, HIGH);

  RFsendDUO.begin();
}

void loop() {

  //Liga o ledB, envia o comando para subir, espera 100ms, desliga o ledB, espera 5s
  digitalWrite(ledB, LOW);
  RFsendDUO.send(rawSobe, sizeof(rawSobe)/sizeof(rawSobe[0]));
  delay(100);
  digitalWrite(ledB, HIGH);
  delay(5000);
  
  //Liga o ledB, envia o comando para parar, espera 100ms, desliga o ledB, espera 5s
  digitalWrite(ledB, LOW);
  RFsendDUO.send(rawPara, sizeof(rawPara)/sizeof(rawPara[0]));
  delay(100);
  digitalWrite(ledB, HIGH);
  delay(5000);
  
  //Liga o ledB, envia o comando para descer, espera 100ms, desliga o ledB, espera 5s
  digitalWrite(ledB, LOW);
  RFsendDUO.send(rawDesce, sizeof(rawDesce)/sizeof(rawDesce[0]));
  delay(100);
  digitalWrite(ledB, HIGH);
  delay(5000);

  //Liga o ledB, envia o comando para parar, espera 100ms, desliga o ledB, espera 5s
  digitalWrite(ledB, LOW);
  RFsendDUO.send(rawPara, sizeof(rawPara)/sizeof(rawPara[0]));
  delay(100);
  digitalWrite(ledB, HIGH);
  delay(5000);
  
}

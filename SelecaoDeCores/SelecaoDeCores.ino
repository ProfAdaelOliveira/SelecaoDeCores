#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int botaoMais = 2;
const int botaoMenos = 3;

const int ledAzul = 8;
const int ledVermelho = 9;
const int ledAmarelo = 10; 

int selecao = 0;

void setup() {
  lcd.begin(16,2);
  lcd.backlight();
  lcd.init();

  pinMode(botaoMais, INPUT_PULLUP);
  pinMode(botaoMenos, INPUT_PULLUP);

  pinMode(ledAzul, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);

  atualizarMenu();
}

void loop() {
  if(digitalRead(botaoMais) == LOW){
    selecao++;
    if(selecao > 2) selecao = 0;
    atualizarMenu();
    delay(300);
  }

  if(digitalRead(botaoMenos) == LOW){
    selecao--;
    if(selecao < 0) selecao = 2;
    atualizarMenu();
    delay(300);
  }
}

void atualizarMenu(){
  lcd.clear();
  switch(selecao){
    case 0:
      lcd.print("LED Azul");
      acenderLed(ledAzul);
      break;
    
    case 1:
      lcd.print("LED Vermelho");
      acenderLed(ledVermelho);
      break;

    case 2:
      lcd.print("LCD Amarelo");
      acenderLed(ledAmarelo);
      break;
  }
}

void acenderLed(int ledSelecionado){
  digitalWrite(ledAzul, ledSelecionado == ledAzul ? HIGH : LOW);
  digitalWrite(ledVermelho, ledSelecionado == ledVermelho ? HIGH : LOW);
  digitalWrite(ledAmarelo, ledSelecionado == ledAmarelo ? HIGH : LOW);
}
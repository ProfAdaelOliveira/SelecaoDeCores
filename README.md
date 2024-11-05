# SelecaoDeCores
Este projeto em Arduino usa um display LCD 16x2 com I2C e dois botões para navegar por um menu, permitindo selecionar e acender LEDs coloridos (azul, vermelho e amarelo). Os botões "Mais" e "Menos" ajustam a seleção exibida no LCD, e o LED correspondente acende, criando uma interação simples e prática com o usuário.

Ambinete de Desenvolvimento(IDE) usada é o IDE Arduino, podendo encontrar o download no seguinte site: https://www.arduino.cc/en/software

Caso não tenha a placa de desenvolvimento você poderá acessar o seguinte link: https://www.tinkercad.com/things/bQqE2YR7uhS-selecaodecores 
Nesse link você acessará o projeto no Simulador TinkerCad já em funcinamento!

Vamos nos conectar ? Segue meu perfil: https://github.com/ProfAdaelOliveira/SobreMim_Portifolio

Segue projeto em Wiring/C++ e logo abaixo o esquema elétrico: 

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

SEGUE ESQUEMA ELÉTRICO:
![EsquemaElétrico](https://github.com/user-attachments/assets/734ca4d5-09b1-4c54-a942-a0b0d7645959)

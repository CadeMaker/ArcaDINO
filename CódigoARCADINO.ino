#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 2,1,0,4,5,6,7,3, POSITIVE);

#define BotA 2
#define BotB 3
#define BotC 4
#define BotD 5

int i;

int nQuestao = 10;
int array[10];

byte Entrada[8] = {
  B00000,
  B00001,
  B00001,
  B00001,
  B01111,
  B11111,
  B00111,
  B00111,
};

byte Entrada2[8] = {
  B00000,
  B00010,
  B10111,
  B11111,
  B11111,
  B11111,
  B11011,
  B11111,
};

byte Entrada3[8] = {
  B00000,
  B00000,
  B00000,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111,
};

byte Entrada4[8] = {
  B00000,
  B00000,
  B00001,
  B00000,
  B00000,
  B00000,
  B00110,
  B01110,
};

byte Entrada5[8] = {
  B00111,
  B11111,
  B11111,
  B11111,
  B01111,
  B01111,
  B01111,
  B11111,
};

byte Entrada6[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

byte Entrada7[8] = {
  B11111,
  B11111,
  B11110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte Entrada8[8] = {
  B11110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B01111,
  B00011,
};

byte Entrada9[8] = {
  B00000,
  B11110,
  B11111,
  B11111,
  B11111,
  B11110,
  B00000,
  B00000,
};


void setup(){
  pinMode(BotA, INPUT_PULLUP);
  pinMode(BotB, INPUT_PULLUP);
  pinMode(BotC, INPUT_PULLUP);
  pinMode(BotD, INPUT_PULLUP);

  lcd.begin(20, 4);
  
  lcd.createChar(1, Entrada);
  lcd.createChar(2, Entrada2);
  lcd.createChar(3, Entrada3);
  lcd.createChar(4, Entrada4);
  lcd.createChar(5, Entrada5);
  lcd.createChar(6, Entrada6);
  lcd.createChar(7, Entrada7);
  lcd.createChar(8, Entrada8);
  lcd.createChar(9, Entrada9);

  lcd.setCursor(1,1);
  lcd.write(byte(1));
  lcd.setCursor(2,1);
  lcd.write(byte(2));
  lcd.setCursor(3,1);
  lcd.write(byte(3));
  lcd.setCursor(0,2);
  lcd.write(byte(4));
  lcd.setCursor(1,2);
  lcd.write(byte(5));
  lcd.setCursor(2,2);
  lcd.write(byte(6));
  lcd.setCursor(3,2);
  lcd.write(byte(7));
  lcd.setCursor(0,4);
  lcd.write(byte(8));
  lcd.setCursor(1,4);
  lcd.write(byte(6));
  lcd.setCursor(2,4);
  lcd.write(byte(6));
  lcd.setCursor(3,4);
  lcd.write(byte(9));
for (i =0; i <16; i++){     
lcd.scrollDisplayRight();     
delay(300);  
}   
delay (200);
lcd.clear();
lcd.setCursor(7,0);
lcd.print ("-==+==-");
lcd.setCursor(5,1);
lcd.print ("Welcome to");
lcd.setCursor(2,2);
lcd.print("A r c a D I N O");
lcd.setCursor(7,4);
lcd.print ("-==+==-");

Serial.begin(9600);
delay(3000);
lcd.clear();
geraSequencia();
}

void correto(){
          lcd.clear();
          lcd.setCursor(4,0);
          lcd.print("Correto!");
          delay (1000);
}
  
void errado(){
          lcd.clear();
           lcd.setCursor(5,0);
          lcd.print("Errado!");
          delay (1000);
} 

 void loop(){
  for (int i = 0; i < nQuestao; i++){
      SelecionaQuestao(array[i]);
  }
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Fim de Jogo!");
  
  delay(2000);
}

void SelecionaQuestao(int nQuestao){
  
     //INGLÊS
  switch(nQuestao){
    case 0:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 1");
          lcd.clear();
          lcd.setCursor(3,1);
          lcd.print ("Fill the gap:");
          lcd.setCursor(1,2);
          lcd.print("[I have many ----]");
    
          delay (3000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("A-Books"); //certa
          delay (1000);
          lcd.setCursor(0,1);
          lcd.print ("B-Money");
          delay (1000);
          lcd.setCursor(0,2);
          lcd.print ("C-Energy");
          delay (1000);
          lcd.setCursor(0,4);
          lcd.print ("D-Time");
          delay (1000);
          
        if(AnalisaBotao()=='A'){
          correto();
        }else{
         errado();
        }
    break;
    
    case 1:
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 2");
          lcd.clear();
          lcd.setCursor(3,1);
          lcd.print ("Fill the gap:");
          lcd.setCursor(1,2);
          lcd.print("[My parentes ----]");
    
          delay (3000);lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("A-Has Arrived");
          delay (1000);
          lcd.setCursor(0,1);
          lcd.print ("B-Have arrived"); //certa
          delay (1000);
          lcd.setCursor(0,2);
          lcd.print ("C-Has arrive");
          delay (1000);
          lcd.setCursor(0,4);
          lcd.print ("D-Have arrive");
          delay (1000);
          
        if(AnalisaBotao()=='B'){
          correto();
        }else{
         errado();
        }
    break;
    
    case 2:
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 3");
          lcd.clear();
          lcd.setCursor(0,1);
          lcd.print ("Whats the meaning of");
          lcd.setCursor(0,2);
          lcd.print("the word “parents”?");
    
          delay (3000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("A-Pares");
          delay (1000);
          lcd.setCursor(0,1);
          lcd.print ("B-Parentes");
          delay (1000);
          lcd.setCursor(0,2);
          lcd.print ("C-Pais"); //certa
          delay (1000);
          lcd.setCursor(0,4);
          lcd.print ("D-Parecidos");
          delay (1000);
          
        if(AnalisaBotao()=='C'){
          correto();
        }else{
         errado();
        }
    break;
    
     case 3:
         lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 4");
          lcd.clear();
          lcd.setCursor(5,1);
          lcd.print ("Choose the");
          lcd.setCursor(2,2);
          lcd.print ("INCORRECT option");
    
          delay (3000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("A-It is");
          delay (1000);
          lcd.setCursor(0,1);
          lcd.print ("B-They are");
          delay (1000);
          lcd.setCursor(0,2);
          lcd.print ("C-I am");
          delay (1000);
          lcd.setCursor(0,4);
          lcd.print ("D-She are"); //certa
          delay (1000);
          
        if(AnalisaBotao()=='D'){
          correto();
        }else{
         errado();
        }
    break;
    
    //-----------PERGUNTA DE INGLÊS QUE FALTA----------------------------------
    case 4:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 5");
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("(3X14+154-161)X0");
          lcd.setCursor(3,1);
          lcd.print("e igual a:");
    
          delay (3000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("A-0"); //certa
          delay(1000);
          lcd.setCursor(0,1);
          lcd.print ("B-505");
          delay(1000);
          lcd.setCursor(0,2);
          lcd.print ("C-245");
          delay(1000);
          lcd.setCursor(0,4);
          lcd.print ("D-34");
          delay (1000);
          
        if(AnalisaBotao()=='A'){
          correto();
        }else{
         errado();
        } 
         break;
    //-----------------------------------------------------------------------

      //CONHECIMENTO GERAIS
    case 5:
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 6");
          lcd.clear();
          lcd.setCursor(4,1);
          lcd.print ("When was fire");
          lcd.setCursor(5,2);
          lcd.print ("discovered?");
    
          lcd.clear();
          delay (3000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("A-30");
          delay(1000);
          lcd.setCursor(0,1);
          lcd.print ("B-45");
          delay(1000);
          lcd.setCursor(0,2);
          lcd.print ("C-60");
          delay(1000);
          lcd.setCursor(0,4);
          lcd.print ("D-75");
          delay (1000);
          
          if(AnalisaBotao()=='D'){
          correto();
          }else{
          lcd.clear();
          errado();
        }
    break;
    
    //Geografia
    case 6:
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 7");
          lcd.clear();
          lcd.setCursor(2,0);         
          lcd.print("Qual o menor");
          lcd.setCursor(1,1); 
          lcd.print("pais do mundo?");
    
          delay (3000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("A-India");
          delay(1000);
          lcd.setCursor(0,1);
          lcd.print ("B-Brasil");
          delay(1000);
          lcd.setCursor(0,2);
          lcd.print ("C-Vaticano");
          delay(1000);
          lcd.setCursor(0,4);
          lcd.print ("D-Escocia");
          delay (1000);
          
        if(AnalisaBotao()=='C'){
          correto();
        }else{
          errado();
        }
    break;
    
     case 7:
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 8");
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("Manaus e capital");
          lcd.setCursor(1,1);
          lcd.print ("de que estado?");
    
          delay (3000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("A-SP");
          delay  (1000);
          lcd.setCursor(0,1);
          lcd.print ("B-AM");
          delay  (1000);
          lcd.setCursor(0,2);
          lcd.print ("C-RJ");
          delay  (1000);
          lcd.setCursor(0,3);
          lcd.print ("D-RS");
          delay (1000);
    
        if(AnalisaBotao()=='B'){
         correto();
        }else{
          lcd.clear();
         errado();
        }
    break;
    
    //História
    case 8:
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Questao 9");
        delay (2000);
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print ("Quando o fogo");
        lcd.setCursor(1,1);
        lcd.print("foi descoberto?");
    
        delay (3000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print ("A-Neolitico");
        delay  (1000);
        lcd.setCursor(0,1);
        lcd.print ("B-Paleolitico");
        delay  (1000);
        lcd.setCursor(0,2);
        lcd.print ("C-Idade media");
        delay  (1000);
        lcd.setCursor(0,3);
        lcd.print ("D-Idade da pedra");
        delay (1000);
    
        if(AnalisaBotao()=='B'){
        correto();
        }else{
         errado();
        }
    break;
    
    case 9:
          lcd.clear();
          lcd.setCursor(5,1);
          lcd.print("Questao 10");
          delay (2000);
          lcd.clear();
          lcd.setCursor(1,1);
          lcd.print ("Qual artista pintou");
          lcd.setCursor(1,2);
          lcd.print ("o quadro [Abapuru]?");
    
          delay (3000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("A-Romero Britto");
          delay (1000);
          lcd.setCursor(0,1);
          lcd.print ("B-Tarsila do Amaral");
          delay (1000);
          lcd.setCursor(0,2);
          lcd.print ("C-Picasso");
          delay (1000);
          lcd.setCursor(0,4);
          lcd.print ("D-Di Cavalcante");
          delay (1000);
    
        if(AnalisaBotao()=='B'){
          correto();
        }else{
         errado();
        }
    break;
  }
    
char AnalisaBotao(){
  bool BotaoPressionado = true;
  
  while(BotaoPressionado){
    if(!digitalRead(BotA)){
      BotaoPressionado = false;
      return 'A';
    }else if(!digitalRead(BotB)){
      BotaoPressionado = false;
      return 'B';
    }else if(!digitalRead(BotC)){
      BotaoPressionado = false;
      return 'C';
    }else if(!digitalRead(BotD)){
      BotaoPressionado = false;
      return 'D';
    }
  }
}


void geraSequencia(){
  randomSeed(random(0, 1000));
  for (int i = 0; i < nQuestao; i++){     
    array[i] = i;
  }
  for (int i = 0; i < nQuestao; i++) {    
    int temp = array[i];
    int novoIndice = random(nQuestao);
    array[i] = array[novoIndice];
    array[novoIndice] = temp;
  }
}
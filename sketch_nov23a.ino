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
          lcd.setCursor(7,0);
          lcd.print ("-==+==-");
          lcd.setCursor(6,2);
          lcd.print("Correto!");
          lcd.setCursor(7,4);
          lcd.print ("-==+==-");
          delay (1000);
}
  
void errado(){
          lcd.clear();
          lcd.setCursor(7,0);
          lcd.print ("-==+==-");
          lcd.setCursor(7,2);
          lcd.print("Errado!");
          lcd.setCursor(7,4);
          lcd.print ("-==+==-");
          delay (1000);
} 

 void loop(){
  for (int i = 0; i < nQuestao; i++){
      SelecionaQuestao(array[i]);
  }
  
  lcd.clear();
  lcd.setCursor(7,0);
  lcd.print ("-==+==-");
  lcd.setCursor(2,1);
  lcd.print("This is the end!");
  lcd.setCursor(1,2);
  lcd.print("Thanks for playing!");
  lcd.setCursor(7,4);
  lcd.print ("-==+==-");
  delay(4000);
}

void SelecionaQuestao(int nQuestao){
  
     //INGLÊS
  switch(nQuestao){
    case 0:
        lcd.clear();
          lcd.setCursor(5,1);
          lcd.print("Questao 7");
          delay (2000);
          lcd.clear();
          lcd.setCursor(7,0);
          lcd.print ("-==+==-");
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
          lcd.setCursor(5,1);
          lcd.print("Questao 2");
          delay (2000);
          lcd.clear();
          lcd.setCursor(7,0);
          lcd.print ("-==+==-");
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
          lcd.setCursor(5,1);
          lcd.print("Questao 10");
          delay (2000);
          lcd.clear();
          lcd.setCursor(7,0);
          lcd.print ("-==+==-");
          lcd.setCursor(0,1);
          lcd.print ("Whats the meaning of");
          lcd.setCursor(1,2);
          lcd.print("the word [parents]?");
    
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
          lcd.setCursor(5,1);
          lcd.print("Questao 6");
          delay (2000);
          lcd.clear();
          lcd.setCursor(7,0);
          lcd.print ("-==+==-");
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
    
    case 4:
        lcd.clear();
          lcd.setCursor(5,1);
          lcd.print("Questao 8");
          delay (2000);
          lcd.clear();
          lcd.setCursor(7,0);
          lcd.print ("-==+==-");
          lcd.setCursor(0,1);
          lcd.print ("Whats the meaning of");
          lcd.setCursor(2,2);
          lcd.print("the word [fate]?");
    
          delay (3000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("A-Destino"); //certa
          delay(1000);
          lcd.setCursor(0,1);
          lcd.print ("B-Fato");
          delay(1000);
          lcd.setCursor(0,2);
          lcd.print ("C-Factual");
          delay(1000);
          lcd.setCursor(0,4);
          lcd.print ("D-Fatiar");
          delay (1000);
          
        if(AnalisaBotao()=='A'){
          correto();
        }else{
         errado();
        } 
         break;
  
      //CONHECIMENTO GERAIS
    case 5:
          lcd.clear();
          lcd.setCursor(5,1);
          lcd.print("Questao 3");
          delay (2000);
          lcd.clear();
          lcd.setCursor(7,0);
          lcd.print ("-==+==-");
          lcd.setCursor(4,1);
          lcd.print ("When was fire");
          lcd.setCursor(5,2);
          lcd.print ("discovered?");
    
          delay (3000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("A-Neolithic");
          delay(1000);
          lcd.setCursor(0,1);
          lcd.print ("B-Paleolithic"); //certa
          delay(1000);
          lcd.setCursor(0,2);
          lcd.print ("C-Middle Age");
          delay(1000);
          lcd.setCursor(0,4);
          lcd.print ("D-Stone Age");
          delay (1000);
          
          if(AnalisaBotao()=='B'){
          correto();
          }else{
          lcd.clear();
          errado();
        }
    break;
    
  
    case 6:
          lcd.clear();
          lcd.setCursor(5,1);
          lcd.print("Questao 4");
          delay (2000);
          lcd.clear();
          lcd.setCursor(7,0);
          lcd.print ("-==+==-");
          lcd.setCursor(0,1);         
          lcd.print("The smallest country");
          lcd.setCursor(2,2); 
          lcd.print("in the world is:");
    
          delay (3000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("A-India");
          delay(1000);
          lcd.setCursor(0,1);
          lcd.print ("B-Scotland");
          delay(1000);
          lcd.setCursor(0,2);
          lcd.print ("C-Vatican");//certa
          delay(1000);
          lcd.setCursor(0,4);
          lcd.print ("D-Bhutan");
          delay (1000);
          
        if(AnalisaBotao()=='C'){
          correto();
        }else{
          errado();
        }
    break;
    
     case 7:
          lcd.clear();
          lcd.setCursor(5,1);
          lcd.print("Questao 5");
          delay (2000); 
          lcd.clear();
          lcd.setCursor(7,0);
          lcd.print ("-==+==-");
          lcd.setCursor(2,1);
          lcd.print ("How many elements");
          lcd.setCursor(2,2);
          lcd.print ("are there on the");
          lcd.setCursor(3,4);
          lcd.print ("periodic table?");
    
          delay (3000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("A-112");
          delay  (1000);
          lcd.setCursor(0,1);
          lcd.print ("B-114");
          delay  (1000);
          lcd.setCursor(0,2);
          lcd.print ("C-116");
          delay  (1000);
          lcd.setCursor(0,3);
          lcd.print ("D-118"); //certa
          delay (1000);
    
        if(AnalisaBotao()=='D'){
         correto();
        }else{
          lcd.clear();
         errado();
        }
    break;
    
    case 8:
        
        lcd.clear();
        lcd.setCursor(5,1);
        lcd.print("Questao 9");
        delay (2000);
        lcd.clear();
        lcd.setCursor(7,0);
        lcd.print ("-==+==-");
        lcd.setCursor(1,1);
        lcd.print ("The biggest country");
        lcd.setCursor(2,2);
        lcd.print("in the world is:");
    
        delay (3000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print ("A-Russia"); //certa
        delay  (1000);
        lcd.setCursor(0,1);
        lcd.print ("B-Canada");
        delay  (1000);
        lcd.setCursor(0,2);
        lcd.print ("C-United States");
        delay  (1000);
        lcd.setCursor(0,3);
        lcd.print ("D-China");
        delay (1000);
    
        if(AnalisaBotao()=='A'){
        correto();
        }else{
         errado();
        }
    break;
    
    case 9:
          lcd.clear();
          lcd.setCursor(5,1);
          lcd.print("Questao 1");
          delay (2000);
          lcd.clear();
          lcd.setCursor(7,0);
          lcd.print ("-==+==-");
          lcd.setCursor(0,1);
          lcd.print ("Which artist painted");
          lcd.setCursor(1,2);
          lcd.print ("the work [Abapuru]?");
    
          delay (3000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print ("A-Romero Britto");
          delay (1000);
          lcd.setCursor(0,1);
          lcd.print ("B-Tarsila do Amaral"); //certa
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

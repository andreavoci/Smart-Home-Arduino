#define led1 9
#define led2 10
#define led3 11
#define led4 12
#define B1 2
#define B2 3
#define B3 4
#define B4 5
#define B5 6
#define B6 7

// Variabili Pulsante1

int val1 = 0;
int stato1 = 0;
int val2 = 0;
int stato2 = 0;
int val3 = 0;
int stato3 = 0;
int val4 = 0;
int stato4 = 0;
int val5 = 0;
int stato5 = 0;
int val6 = 0;
int stato6 = 0;
bool stopVar;

void setup() {
  Serial.begin(9600); // serial monitor/bluetooth
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  void Comandi ();
}//setup

void loop() {
  if (Serial.available()>0) {
    String c=Serial.readString();
    char comando=c[0];
    Serial.write(comando);
    switch (comando) {
      case '1':
      Serial.println("");
      Serial.println("Luce bagno accesa");
      stopVar = false;// ***** // Le istruzioni verranno eseguiti fino a quando non sarà inviato un nuovo comando
      while (!stopVar) { //
        digitalWrite(9,HIGH);
        if (Serial.available()>0) { // *****
          stopVar = true; // *****
        }// **********
      }
      break;
      case '2':
      Serial.println("");
      stopVar = false;// ***** // Le istruzioni verranno eseguiti fino a quando non sarà inviato un nuovo comando
      while (!stopVar) {
        Serial.println("Luce cucina accesa");
        digitalWrite(10,HIGH);
        if (Serial.available()>0) { // *****
          stopVar = true; // *****
        }// **********
      }
      break;
      case '3':
      Serial.println("");
      stopVar = false;// ***** // Le istruzioni verranno eseguiti fino a quando non sarà inviato un nuovo comando
      while (!stopVar) {
        Serial.println("Luce salone accesa");
        digitalWrite(11,HIGH);
        if (Serial.available()>0) { // *****
          stopVar = true; // *****
        }// **********
      }
      break;
      case '4':
      Serial.println("");
      stopVar = false;// ***** // Le istruzioni verranno eseguiti fino a quando non sarà inviato un nuovo comando
      while (!stopVar) {
        Serial.println("Luce camera da letto accesa");
        digitalWrite(12,HIGH);
        if (Serial.available()>0) { // *****
          stopVar = true; // *****
        }// **********
      }
      break;
      case '5':
      Serial.println("");
      stopVar = false;// ***** // Le istruzioni verranno eseguiti fino a quando non sarà inviato un nuovo comando
      while (!stopVar) {
        Serial.println("Luce bagno spenta");
        digitalWrite(9,LOW);
        if (Serial.available()>0) { // *****
          stopVar = true; // *****
        }// **********
      }
      break;
      case '6':
      Serial.println("");
      stopVar = false;// ***** // Le istruzioni verranno eseguiti fino a quando non sarà inviato un nuovo comando
      while (!stopVar) {
        Serial.println("Luce cucina spenta");
        digitalWrite(10,LOW);
        if (Serial.available()>0) { // *****
          stopVar = true; // *****
        }// **********
      }
      break;
      case '7':
      Serial.println("");
      stopVar = false;// ***** // Le istruzioni verranno eseguiti fino a quando non sarà inviato un nuovo comando
      while (!stopVar) {
        Serial.println("Luce salone spenta");
        digitalWrite(11,LOW);
        if (Serial.available()>0) { // *****
          stopVar = true; // *****
        }// **********
      }
      break;
      case '8':
      Serial.println("");
      stopVar = false;// ***** // Le istruzioni verranno eseguiti fino a quando non sarà inviato un nuovo comando
      while (!stopVar) {
        Serial.println("Luce camera da letto spenta");
        digitalWrite(12,LOW);
        if (Serial.available()>0) { // *****
          stopVar = true; // *****
        }// **********
      }
      break;
      case '9':
      Serial.println("");
      Serial.println("Spegni tutte le luci");
      stopVar = false;// ***** // Le istruzioni verranno eseguiti fino a quando non sarà inviato un nuovo comando
      while (!stopVar) {
        digitalWrite(12,LOW);
        digitalWrite(11,LOW);
        digitalWrite(10,LOW);
        digitalWrite(9,LOW);
        if (Serial.available()>0) { // *****
          stopVar = true; // *****
        }// **********
      }
      break;
      case '0':
      Serial.println("");
      Serial.println("Accendi tutte le luci");
      stopVar = false;// ***** // Le istruzioni verranno eseguiti fino a quando non sarà inviato un nuovo comando
      while (!stopVar) {
        digitalWrite(12,HIGH);
        digitalWrite(11,HIGH);
        digitalWrite(10,HIGH);
        digitalWrite(9,HIGH);
        if (Serial.available()>0) { // *****
          stopVar = true; // *****
        }// **********
      }
      break;
      case 'c': {
        Serial.println("");
        Serial.println("Lista Comandi");
        Comandi();
        break;
      }
      default:
      Serial.print("-");
      break;
    }
  }
  
  val1 = digitalRead(B1);
  if (val1 == HIGH){
    stato1 = 1 - stato1;
  }
  if(stato1==1){
    digitalWrite(9,HIGH);
  } else{
    digitalWrite(9,LOW);
  }

  val2 = digitalRead(B2);
  if (stato2 == HIGH){
    stato2 = 1 - stato2;
  }
  if(stato2==1){
    digitalWrite(10,HIGH);
  } else{
    digitalWrite(10,LOW);
  }

  val3 = digitalRead(B3);
  if (stato3 == HIGH){
    stato3 = 1 - stato3;
  }
  if(stato3==1){
    digitalWrite(11,HIGH);
  } else{
    digitalWrite(11,LOW);
  }

  val4 = digitalRead(B4);
  if (stato4 == HIGH){
    stato4 = 1 - stato4;
  }
  if(stato4==1){
    digitalWrite(12,HIGH);
  } else{
    digitalWrite(12,LOW);
  }

  val5 = digitalRead(B5);
  if (stato5 == HIGH){
    stato5 = 1 - stato5;
  }
  if(stato5==1){
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
  }

  val6 = digitalRead(B6);
  if (stato6 == HIGH){
    stato6 = 1 - stato6;
  }
  if(stato6==1){
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
  }
}//loop

void Comandi(){
  Serial.println("1 = Accendi luce bagno");
  Serial.println("2 = Accendi luce cucina");
  Serial.println("3 = Accendi luce salone");
  Serial.println("4 = Accendi luce camera da letto");
  Serial.println("5 = Spegni luce bagno");
  Serial.println("6 = Spegni luce cucina");
  Serial.println("7 = Spegni luce salone");
  Serial.println("8 = Spegni luce camera da letto");
  Serial.println("9 = Spegni tutte le luci");
  Serial.println("0 = Accendi tutte le luci");
}//comandi

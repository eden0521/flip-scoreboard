#include <MyoController.h>
#define FIST_PIN 4
#define WAVEIN_PIN 5
#define waveOut_PIN 6
#define FINGERSSPREAD_PIN 7
#define DOUBLETAP_PIN 8
     
#include <SPI.h>
#include <WiFi.h>
char ssid[] = "NTU_5G";          //  your network SSID (name) 
char pass[] = "40588888";   // your network password
int status = WL_IDLE_STATUS;
WiFiClient client;
char server[] = "obo.myds.me";

String data;

long previousMillis = 0;
unsigned long currentMillis = 0;
long interval = 5000; // READING INTERVAL

String stringVal = ""; 
// Variable Setup
long lastConnectionTime = 0; 
boolean lastConnected = false;
int failedCounter = 0;
////////////////
const int PinY1 = A0;
const int PinY2 = A1;
const int PinG1 = A2;
const int PinG2 = A3;
const int PinG3 = A4;
const int PinR1 = A5;
const int PinR2 = 13;
MyoController myo = MyoController();
int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7, dp = 8; //Display pins
int d1 = 9, d2 = 10, d3 = 11, d4 = 12; //Common pins
int gr1=0, gr2=0, gr3=0, r1=0, r2=0, k1=0, k2=0, cg=0, cy=0;
int cL=0, cR=0, L=0, R=0;
int strike=0, ball=0, outt=0;
int rr=1;
String roud = "1UP";

void setup() {
  pinMode(PinY1, OUTPUT);
  pinMode(PinY2, OUTPUT);
  pinMode(PinR1, OUTPUT);
  pinMode(PinR2, OUTPUT);
  pinMode(PinG1, OUTPUT);
  pinMode(PinG2, OUTPUT);
  pinMode(PinG3, OUTPUT);
  Serial.begin(115200);

  data = "";
  
  int i = 1;
  for(i=1 ; i<13; i++)
    pinMode(i, OUTPUT);
  myo.initMyo();
}
void loop()
{
  currentMillis = millis();
   offd(d1);
   offd(d2);
   offd(d3);
   offd(d4);
   
      ond(d3);
      num(L%10);
      delay(3);
      offd(d3);
      ond(d4);
      num(L/10 - 10*(L/100));
      delay(3);
      offd(d4);
      ond(d1);
      num(R%10);
      delay(3);
      offd(d1);
      ond(d2);
      num(R/10 - 10*(R/100));
      delay(3);
      offd(d2); 
  
   //Serial.println("HI");
   myo.updatePose();
   switch ( myo.getCurrentPose() ) {
//////////////////////////////////////
    
    case rest:
      cL=0;
      cR=0;
      cg=0; 
      cy=0;
      ond(d3);
      num(L%10);
      delay(3);
      offd(d3);
      ond(d4);
      num(L/10 - 10*(L/100));
      delay(3);
      offd(d4);
      ond(d1);
      num(R%10);
      delay(3);
      offd(d1);
      ond(d2);
      num(R/10 - 10*(R/100));
      delay(3);
      offd(d2); 
      break;
/////////////////////////////////////////////
      
    case fist:
      cL=0;
      cR=0;
      cg=0; 
      //digitalWrite(FIST_PIN,HIGH);
      if (k1==0 && cy==0){
        digitalWrite(PinY1, HIGH);
        k1=1;
        cy=1;
        strike = 1;
      }
      else if(k2==0 && cy==0){
        digitalWrite(PinY2, HIGH);
        k2=1;
        cy=1;
        strike = 2;
      }
      else if (cy==0){
        k1=0;
        k2=0;
        cy=1;
        gr1=0;
        gr2=0;
        gr3=0;
        digitalWrite(PinY1, LOW);
        digitalWrite(PinY2, LOW);
        digitalWrite(PinG1, LOW);
        digitalWrite(PinG2, LOW);
        digitalWrite(PinG3, LOW);
        strike=0;
        ball=0;
        if (r1==0){
          digitalWrite(PinR1, HIGH);
          r1=1;
          outt=1;
        }
        else if(r2==0){
          digitalWrite(PinR2, HIGH);
          r2=1;
          outt=2;
        }
        else {
          digitalWrite(PinR1, LOW);
          digitalWrite(PinR2, LOW);
          rr++;
          outt=0;
          r1=0;
          r2=0;
          if (rr%2==0)
            roud = (String)((rr/2)) + "DOWN";
          else
            roud = (String)((rr+1)/2) + "UP";
          
        }
      }
      ond(d3);
      num(L%10);
      delay(3);
      offd(d3);
      ond(d4);
      num(L/10 - 10*(L/100));
      delay(3);
      offd(d4);
      ond(d1);
      num(R%10);
      delay(3);
      offd(d1);
      ond(d2);
      num(R/10 - 10*(R/100));
      delay(3);
      offd(d2); 
      
      break;
///////////////////////////////////////////////
      
    case waveIn:
      cR=0;
      //digitalWrite(WAVEIN_PIN,HIGH);
      cg=0; 
      cy=0;
      ond(d3);
      num(L%10);
      delay(3);
      offd(d3);
      ond(d4);
      num(L/10 - 10*(L/100));
      delay(3);
      offd(d4);
      ond(d1);
      num(R%10);
      delay(3);
      offd(d1);
      ond(d2);
      num(R/10 - 10*(R/100));
      delay(3);
      offd(d2); 
      
    if(cL==0){
      L++;
      cL=1;
      //offd(d3);
      ond(d3);
      num(L%10);
      delay(3);
      offd(d3);
      //offd(d4);  
      ond(d4);
      num(L/10 - 10*(L/100));
      delay(3);
      offd(d4); 
      ond(d1);
      num(R%10);
      delay(3);
      offd(d1);
      ond(d2);
      num(R/10 - 10*(R/100));
      delay(3);
      offd(d2); 
       
    }
      break;
////////////////////////////////
    case waveOut:
      cL=0;
      cg=0; 
      cy=0;
      ond(d3);
      num(L%10);
      delay(3);
      offd(d3);
      ond(d4);
      num(L/10 - 10*(L/100));
      delay(3);
      offd(d4);
      ond(d1);
      num(R%10);
      delay(3);
      offd(d1);
      ond(d2);
      num(R/10 - 10*(R/100));
      delay(3);
      offd(d2); 
    
    //digitalWrite(waveOut_PIN,HIGH);
    if(cR==0){
      R++;
      cR=1;      
      //offd(d1);
      ond(d1);
      num(R%10);
      delay(3);
      offd(d1);
      //offd(d2);
      ond(d2);
      num(R/10 - 10*(R/100));
      delay(3);
      offd(d2); 
      ond(d3);
      num(L%10);
      delay(3);
      offd(d3);
      ond(d4);
      num(L/10 - 10*(L/100));
      delay(3);
      offd(d4);
      
    }
      
      break;
//////////////////////////////////////
      
    case fingersSpread:
      cL=0;
      cR=0;
      //digitalWrite(FINGERSSPREAD_PIN,HIGH);
      cy=0;
      if (gr1==0 && cg==0){
        digitalWrite(PinG1, HIGH);
        gr1=1;
        cg=1;
        ball=1;
      }
      else if(gr2==0 && cg==0){
        digitalWrite(PinG2, HIGH);
        gr2=1;
        cg=1;
        ball=2;
      }
      else if(gr3==0 && cg==0){
        digitalWrite(PinG3, HIGH);
        gr3=1;
        cg=1;
        ball=3;
      }
      else if (cg==0){
        gr1=0;
        gr2=0;
        gr3=0;
        k1=0;
        k2=0;
        cg=1;
        strike=0;
        ball=0;
        digitalWrite(PinY1, LOW);
        digitalWrite(PinY2, LOW);
        digitalWrite(PinG1, LOW);
        digitalWrite(PinG2, LOW);
        digitalWrite(PinG3, LOW);
      }
      
      ond(d3);
      num(L%10);
      delay(3);
      offd(d3);
      ond(d4);
      num(L/10 - 10*(L/100));
      delay(3);
      offd(d4);
      ond(d1);
      num(R%10);
      delay(3);
      offd(d1);
      ond(d2);
      num(R/10 - 10*(R/100));
      delay(3);
      offd(d2); 
      
      break;
//////////////////////////////////////
    case doubleTap:
      cL=0;
      cR=0;
      cg=0; 
      cy=0;
     // digitalWrite(DOUBLETAP_PIN,HIGH);
      ond(d3);
      num(L%10);
      delay(3);
      offd(d3);
      ond(d4);
      num(L/10 - 10*(L/100));
      delay(3);
      offd(d4);
      ond(d1);
      num(R%10);
      delay(3);
      offd(d1);
      ond(d2);
      num(R/10 - 10*(R/100));
      delay(3);
      offd(d2); 
      break;
      
   } 

client.stop();
  if(currentMillis - previousMillis > interval) { // READ ONLY ONCE PER INTERVAL
    previousMillis = currentMillis;
    //data = "leftt=" + (String) L + "&rightt=" + (String) R + "&strike=" + (String) strike + "&ball=" + (String) ball + "&outt=" + (String) outt;
    if (client.connect(server, 80)) {
  
    Serial.println("connecting...");
   client.print("GET /add.php?le=");
   client.print(L);
   client.print("&ri=");
   client.print(R);
   client.print("&st=");
   client.print(strike);
   client.print("&ba=");
   client.print(ball);
   client.print("&ou=");
   client.print(outt);
   client.print("&r=");
   client.print(roud);

    client.println(" HTTP/1.1");
   
    client.println("Host: obo.myds.me");
    //client.println("Connection: close");
    client.println();
    //client.println("Content-Type: application/x-www-form-urlencoded");
    //client.print("Content-Length: ");
    //client.println(data.length());
    //client.println();
    //client.println(data); 
    //client.stop();  // DISCONNECT FROM THE SERVER
  }
    
  }
  
  delay(3);
}


void on(int i) {
  digitalWrite(i, HIGH);
}
void off(int i){
 digitalWrite(i, LOW); 
}
void ond(int i) {
  digitalWrite(i, LOW);
}
void offd(int i){
 digitalWrite(i, HIGH); 
}
void num(int n) {
 
 if(n < 0)
  n = 0; 
  
 switch(n) {
 
   case 0:
     on(a);
     on(b);
     on(c);
     on(d);
     on(e);
     on(f);
     off(g);
     break;
   case 1:
     off(a);
     on(b);
     on(c);
     off(d);
     off(e);
     off(f);
     off(g);
     break;
   case 2:
     on(a);
     on(b);
     off(c);
     on(d);
     on(e);
     off(f);
     on(g);
     break;
   case 3:
     on(a);
     on(b);
     on(c);
     on(d);
     off(e);
     off(f);
     on(g);
     break;
   case 4:
     off(a);
     on(b);
     on(c);
     off(d);
     off(e);
     on(f);
     on(g);
     break;
   case 5:
     on(a);
     off(b);
     on(c);
     on(d);
     off(e);
     on(f);
     on(g);
     break;
   case 6:
     on(a);
     off(b);
     on(c);
     on(d);
     on(e);
     on(f);
     on(g);
     break;
   case 7:
     on(a);
     on(b);
     on(c);
     off(d);
     off(e);
     off(f);
     off(g);
     break;
   case 8:
     on(a);
     on(b);
     on(c);
     on(d);
     on(e);
     on(f);
     on(g);
     break;
   case 9:
     on(a);
     on(b);
     on(c);
     on(d);
     off(e);
     on(f);
     on(g);
     break;
 
   
 }
 
  
}

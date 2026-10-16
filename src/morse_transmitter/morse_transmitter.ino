unsigned long start=0;
unsigned long timpA=0;
unsigned long timpB=0;
unsigned long timpC=0;
unsigned long LEDpauza=0;
unsigned long pauza=0;
int afostpus=HIGH;
int contor=HIGH;
int stareAnterioara=HIGH;
int butonListening=HIGH;
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int stareCurenta;
  
 if(digitalRead(6)==1)
 {
   butonListening=LOW;
   Serial.print("Listening");
 }
  else
  {
    butonListening=HIGH;
    Serial.print("Not listening");
  }
  
  if(digitalRead(3)==0)
  {
    stareCurenta=LOW;
    digitalWrite(2,HIGH);
  }
  else
  {
    stareCurenta=HIGH;
   digitalWrite(2,LOW); 
     digitalWrite(4,LOW); 
  }
  
  
  
  
    
  
  if(stareAnterioara != stareCurenta && stareCurenta==0)
  {
   start=millis();
    
    
  }

  if(stareAnterioara == stareCurenta && stareCurenta==0)
  {
  
    timpB=millis()-start;
    
    if(timpB>350)
        digitalWrite(4,HIGH); 
   
  
  }
  
    if(contor==LOW)
    {
      LEDpauza=millis()-pauza;
      if(LEDpauza>3000)
        digitalWrite(5,HIGH);
        
      
    }
  
  
  
  if(stareAnterioara != stareCurenta && stareCurenta==1)
  {
    
  
    timpA=millis()-start;
    
    if(contor==HIGH)
    {
    pauza=millis();
    }
  
    if(contor==LOW)
    {
     timpC=millis() - pauza;
      contor=HIGH;
      
      if(timpC>5000)
      {
       Serial.print("/"); 
        digitalWrite(5,LOW);
      }
      else if(timpC>3000)
      {
       Serial.print(" ");
        digitalWrite(5,LOW);
      }
      
    }
    
    
    if(timpA<65)
    {

    }
     else if(timpA>350)
    {
       Serial.print("-");
    
      
    }
    else
    {
       Serial.print("."); 
    }
    
    
    if(contor==HIGH)
     pauza=millis();
    
    contor=LOW;
    
    
    
  }
  
  
  
  
   stareAnterioara=stareCurenta;
  
  
}

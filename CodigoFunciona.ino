// pHRead.ino

// Constantes:-
const byte pHpin = A0;// entrada A0
float termometro1= A1;// entrada A1
float t1=0;
// Variables:-
float Po=7.3;
int cont=0;
int RELE=7;
int estanque=1;//1 para dismuir ph , 2 para aumentar ph ,0 no tiene ningun liquido

void setup()
{
Serial.begin(9600);
pinMode(RELE,OUTPUT);
pinMode(13,OUTPUT);
analogReference(INTERNAL);// pone como referencia iterna 1.1V
}

void loop()
{
  //Rele
  if(estanque==1){//baja ph
    if(Po>7.6){
    digitalWrite(RELE,HIGH);
    delay(1000);
    }
  }
  if(estanque==2){//sube ph
    if(Po<7.2){
    digitalWrite(RELE,HIGH);
    delay(1000);
    }
  }
  if(estanque==0){//imprime que es necesario bajar o subir ph 
    if(Po>7.6){
    Serial.print("Es necesario bajar el ph de la piscina.....El agua en muy alcalina!");
    }
    if(Po<7.2){
    Serial.print("Es necesario subir el ph de la piscina.....El agua es muy acida!");
    }
  }
cont=cont+1;
//PH
Serial.println(cont);
delay(1000);// Take 1 reading per second.

Serial.print("    pH:");  
  Serial.print(Po,2);
  Serial.println(" ");
//Temperatura

 t1 = map(analogRead(A1),492,658,1023,0); // a 0°C la lectrura de analgRead es 140 y a 100°C es 99
 termometro1= t1/10;
  Serial.print (" Term 1= ");   
  Serial.println (termometro1,1);       
    delay(1000);
}

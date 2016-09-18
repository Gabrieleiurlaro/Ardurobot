const int triggerPort = 10;//imposto la porta del Trigger al pin 10
const int echoPort = 11;//imposto la porta dell'echo al pin 11
long t,distanza;
void setup() {
  Serial.begin(9600);
  pinMode(triggerPort, OUTPUT);
  pinMode(echoPort, INPUT);
  Serial.print( "Sensore Ultrasuoni: ");
}
 
void loop() {
  misuradistanza();
  Serial.print("distanza: ");
  Serial.println(distanza);
}

void misuradistanza(){
  //porta bassa l'uscita del trigger
  digitalWrite( triggerPort, LOW );
  //invia un impulso di 10microsec su trigger
  digitalWrite( triggerPort, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( triggerPort, LOW );
 
   t = pulseIn( echoPort, HIGH );
   distanza = t/58;
}


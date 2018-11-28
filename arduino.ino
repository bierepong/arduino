
int led = 13;
int sensorValue[6] = {0, 0, 0, 0, 0, 0};
String pre = "sensor(";
String post = ");";
int freq = 1000;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);   
   //Initialize serial and wait for port to open:
  Serial.begin(115200); 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }  
}

// the loop routine runs over and over again forever:
void loop() {
  
  // Turn on the led while we are collecting and sending data
  digitalWrite(led, HIGH);

  sensorValue[0] = analogRead(A0);
  sensorValue[1] = analogRead(A1);
  sensorValue[2] = analogRead(A2);
  sensorValue[3] = analogRead(A3);
  sensorValue[4] = analogRead(A4);
  sensorValue[5] = analogRead(A5);

  // Build RPC string to send over Serial link
  String rpc = pre;
  for(int i=0; i<6; i++) {
    rpc += sensorValue[i];
    if (i<5) rpc += ","; 
  }
  rpc += post;

  // Send value
  Serial.println(rpc);
  
  // We are done, turn off led
  digitalWrite(led, LOW);
  
  // Wait a bit before next loop
  delay(freq);
}

byte incomingByte = 0;
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);  
}

void forward(int dist) {
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(dist);
}
void backward(int dist) {
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  delay(dist);
}
void block() {
 digitalWrite(8, LOW);
 digitalWrite(9, LOW); 
}
//21 backward  = 2step/1mm
//dépend du poids
//TODO: autocalibrage
void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("I got: ");
    Serial.println(incomingByte);
    switch (incomingByte) {
      case 49:
        forward(21);
        break;
      case 50:
        backward(21);
        break;
    }
    block();
    delay(50);
  } 
}

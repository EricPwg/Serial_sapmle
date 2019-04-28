void setup() {
  Serial.begin(9600);

}

void loop() {
  if(Serial.available()){
      int a = Serial.read();
      Serial.println(a);
  }
}

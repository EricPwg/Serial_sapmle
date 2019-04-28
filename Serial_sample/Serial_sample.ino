int get_t;
bool flag;

void get_serial(int get_t){
  Serial.println(get_t);
}

void setup() {
  Serial.begin(9600);
  get_t = 0;
  flag = false;
}

void loop() {
  if (Serial.available()){
    char get_char = Serial.read();
    if (get_char == ' ' || get_char == '\n' || get_char == '\r'){
      if (flag){
        flag = false;
        get_serial(get_t);
        get_t = 0;
      }
   }
   else{
        flag = true;
        get_t = get_t*10+((int)get_char-48);
   }
  }
}
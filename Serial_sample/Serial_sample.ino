# define command_len 2

int get_t;
bool flag;
int state;
int command[command_len];

void get_serial(int get_t){
  Serial.println(get_t);
}

void print_command(int len){
  for (int i=0; i<command_len; i++){
    Serial.print(command[i]);
    Serial.print(' ');
  }
  Serial.print('\n');
}

void action(int len){
  int act_pin = command[0];
  int onoff = command[1];
  onoff = (onoff < 0) ? -onoff : onoff;
  onoff %= 2;
  if (act_pin >=2 && act_pin <=13){
    digitalWrite(act_pin, onoff);
  }
}

void setup() {
  Serial.begin(9600);
  get_t = 0;
  flag = false;
  state = 0;
  for (int i=0; i<command_len; i++)
    command[i] = 0;
  for (int i=2; i<=13; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  if (Serial.available()){
    char get_char = Serial.read();
    if (get_char == ' ' || get_char == '\n' || get_char == '\r'){
      if (flag){
        flag = false;
        if (state < command_len){
          command[state] = get_t;
          state++;
        }
        get_t = 0;
        if (get_char == '\n' || get_char == '\r'){
          action(command_len);
          state = 0;
        }
      }
   }
   else{
        flag = true;
        get_t = get_t*10+((int)get_char-48);
   }
  }
}
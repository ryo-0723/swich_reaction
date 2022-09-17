bool sw_state;
bool before_state, send_sw;

void setup() {
  Serial.begin(115200);
  pinMode(4, INPUT_PULLUP);
}


void loop() {
  sw_state = !digitalRead(4);
  if (sw_state == HIGH && before_state == LOW) { //clickの反応
    send_sw = 1;
  }
  else {
    send_sw = 0;
  }
  before_state = sw_state;

  Serial.print(sw_state);
  Serial.print("\t");
  Serial.println(send_sw);
}

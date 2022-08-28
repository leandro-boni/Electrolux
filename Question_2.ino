
#define button 2
unsigned long init_time = 0, unsigned long button_time = 0, bool state_button = 0;
bool previous_state_button, bool int_state_button;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  state_button = !digitalRead(button);
  // button pressed
  if (state_button && !previous_state_button && !int_state_button){
    if (init_time == 0){
      init_time = millis();
    }
  }
  // button released
  if (init_time > 200){//debounce filter
    if (!state_button && previous_state_button && !int_state_button){
      button_time = millis() – init_time;
      if (button_time < 10000){
        int_state_button = !int
      init_time = 0;

}

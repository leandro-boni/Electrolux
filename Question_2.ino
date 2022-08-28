
#define button 2
unsigned long init_time = 0;
unsigned long button_time = 0;
int state_button = 0;
int previous_state_button = 0;
int int_state_button = 0;

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
    Serial.println("State ON");
    if (init_time == 0){
      init_time = millis();
    }
  }
  // button released
  if (init_time > 200){//debounce filter
    if (!state_button && previous_state_button && !int_state_button){
      button_time = millis() – init_time;
      Serial.println("button's time pressed:");
      Serial.println(button_time);
      int_state_button = 1;
      init_time = millis();
      button_time = 0;
    }
  }
  if (!state_button && !previous_state_button && int_state_button){ 
     button_time = millis() – init_time;
     if(button_time <= 10000)
        Serial.println("State PROTECTED");
     else{
        Serial.println("State OFF");   
        init_time = 0;
     } 
  }
}

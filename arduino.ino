//Libraries included

#include <Keypad.h>
#include <EEPROM.h>

//Declaration of variables

int BASE_LED = 0;
int FIRST_LED = 1;
int SECOND_LED = 2;
int SENSOR = 3;
int BUZZER = 12;

int status;
int sensor_state;
int second_index;

unsigned long previous_time = 0;
unsigned long current_time = 0;

int led_validation = 0;
int buzzer_validation = 0;

bool access = false;
bool password_validation = true;
bool update_password_validation = false;

byte index = 0;

char key;
char key_pulsed;
char PASSWORD[4];
char STORED_PASSWORD[4];
char captured_value;

//Keypad logic

const byte numColumns = 4;
const byte numRows = 4;

char keymap[numRows][numColumns]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {11,10,9,8};
byte colPins[numColumns] = {7,6,5,4};

Keypad keyboard = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numColumns);

//Practical functions

void sensor_validation(){

  sensor_state = digitalRead(SENSOR);

  if (sensor_state == 1 && status != 255 && access == false){

    alarm();

  }

}

void capture_keys(){
  
  while (index != 4){

    key = keyboard.getKey();

    if (key){
      
      if (key != '#' && key != '*' && key != 'A' && key != 'B' && key != 'C' && key != 'D'){

        key_pulsed_notification_sound();
        PASSWORD[index] = key;
        index++;

      }

    }

    else{

      sensor_validation();

    }

  }

  index = 0;

  if (status == 255){

    verify_password();

  }

  else{

    get_stored_password();
    verify_password();

  }

}

void verify_password(){

  if (status != 255){

    if (update_password_validation == false){

      for (int j; j<4; j++){

        if (PASSWORD[j] != STORED_PASSWORD[j]){

          second_error_notification();
          password_validation = false;
          break;

        }

        password_validation = true;

      }

    }

  }

}

void get_memory_status(){ 

  status = EEPROM.read(0);

}

void save_new_password(){

  if (status == 255){

    while (second_index < 4){

      EEPROM.write(second_index,PASSWORD[second_index]);
      second_index++;

    }

    second_index = 0;

  }

  else {

    if (update_password_validation == true)

      while (second_index < 4){

        EEPROM.update(second_index,PASSWORD[second_index]);
        second_index++;

      }

      second_index = 0;

  }

}

void get_stored_password(){

  while (second_index < 4){

      EEPROM.get(second_index,captured_value);
      STORED_PASSWORD[second_index] = captured_value;
      second_index++;

    }

    second_index = 0;
}

void restore_memory(){

  while (second_index < 4){

      EEPROM.write(second_index,255);
      second_index++;

    }

    second_index = 0;

}

//Visual functions

void change_indication(){

    while (true){

      current_time = millis();

      if (current_time - previous_time >= 400 && led_validation == 0){

        digitalWrite(BASE_LED, LOW);
        previous_time = current_time;
        led_validation += 1;

      }

      else if (current_time - previous_time >= 400 && led_validation == 1){

        change_notification_sound();
        digitalWrite(BASE_LED, HIGH);
        previous_time = current_time;
        led_validation = 0;
        break;

      }

    }

}

void first_action_notification(){

    while (true){

      current_time = millis();

      if (current_time - previous_time >= 50 && led_validation == 0){

        digitalWrite(BASE_LED, LOW);
        previous_time = current_time;
        led_validation += 1;

      }

      else if (current_time - previous_time >= 400 && led_validation == 1){

        digitalWrite(FIRST_LED, HIGH);
        first_notification_sound_correct_action();
        previous_time = current_time;
        led_validation += 1;

      }

      else if (current_time - previous_time >= 400 && led_validation == 2){

        digitalWrite(FIRST_LED, LOW);
        previous_time = current_time;
        led_validation += 1;

      }

      else if (current_time - previous_time >= 400 && led_validation == 3){

        digitalWrite(BASE_LED, HIGH);
        previous_time = current_time;
        led_validation = 0;
        break;

      }

    }
}

void second_action_notification(){

    while (true){

      current_time = millis();

      if (current_time - previous_time >= 400 && led_validation == 0){

        digitalWrite(FIRST_LED, HIGH);
        second_notification_sound_correct_action();
        previous_time = current_time;
        led_validation += 1;

      }

      else if (current_time - previous_time >= 400 && led_validation == 1){

        digitalWrite(FIRST_LED, LOW);
        previous_time = current_time;
        led_validation += 1;

      }

      else if (current_time - previous_time >= 400 && led_validation == 2){

        digitalWrite(FIRST_LED, HIGH);
        second_notification_sound_correct_action();
        previous_time = current_time;
        led_validation += 1;

      }

      else if (current_time - previous_time >= 400 && led_validation == 3){

        digitalWrite(FIRST_LED, LOW);
        previous_time = current_time;
        led_validation = 0;
        break;

      }

    }
}

void third_action_notification(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 400 && led_validation == 0){

        digitalWrite(FIRST_LED, HIGH);
        third_notification_sound_correct_action();
        previous_time = current_time;
        led_validation += 1;

      }

      else if (current_time - previous_time >= 400 && led_validation == 1){

        digitalWrite(FIRST_LED, LOW);
        previous_time = current_time;
        led_validation = 0;
        break;

      }

    }

}

void fourth_action_notification(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 400 && led_validation == 0){

        digitalWrite(FIRST_LED, HIGH);
        fourth_notification_sound_correct_action();
        previous_time = current_time;
        led_validation += 1;

      }

      else if (current_time - previous_time >= 400 && led_validation == 1){

        digitalWrite(FIRST_LED, LOW);
        previous_time = current_time;
        led_validation = 0;
        break;

      }

    }

}

void fifth_action_notification(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 400 && led_validation == 0){

        digitalWrite(FIRST_LED, HIGH);
        fifth_notification_sound_correct_action();
        previous_time = current_time;
        led_validation += 1;

      }

      else if (current_time - previous_time >= 400 && led_validation == 1){

        digitalWrite(FIRST_LED, LOW);
        previous_time = current_time;
        led_validation = 0;
        break;

      }

    }

}

void first_error_notification(){

    while (true){

      current_time = millis();

      if (current_time - previous_time >= 50 && led_validation == 0){

        digitalWrite(BASE_LED, LOW);
        previous_time = current_time;
        led_validation += 1;

      }

      else if (current_time - previous_time >= 400 && led_validation == 1){

        digitalWrite(SECOND_LED, HIGH);
        digitalWrite(BASE_LED, HIGH);
        first_notification_sound_incorrect_action();
        previous_time = current_time;
        led_validation += 1;

      }

      else if (current_time - previous_time >= 400 && led_validation == 2){

        digitalWrite(SECOND_LED, LOW);
        previous_time = current_time;
        led_validation = 0;
        break;

      }

    }
}

void second_error_notification(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 50 && led_validation == 0){

        digitalWrite(SECOND_LED, HIGH);
        second_notification_sound_incorrect_action();
        previous_time = current_time;
        led_validation += 1;

      }

      else if (current_time - previous_time >= 400 && led_validation == 1){

        digitalWrite(SECOND_LED, LOW);
        previous_time = current_time;
        led_validation = 0;
        break;

      }

    }

}

void third_error_notification(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 50 && led_validation == 0){

        digitalWrite(SECOND_LED, HIGH);
        third_notification_sound_incorrect_action();
        previous_time = current_time;
        led_validation += 1;

      }

      else if (current_time - previous_time >= 400 && led_validation == 1){

        digitalWrite(SECOND_LED, LOW);
        previous_time = current_time;
        led_validation = 0;
        break;

      }

    }

}

//Sound functions

void key_pulsed_notification_sound(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 200 && buzzer_validation == 0){

        tone(BUZZER, 800);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 200 && buzzer_validation == 1){

        noTone(BUZZER);

        previous_time = current_time;
        buzzer_validation = 0;
        break;

      }

    }
}

void access_attempt_notification_sound(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 200 && buzzer_validation == 0){

        tone(BUZZER, 1000);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 200 && buzzer_validation == 1){

        noTone(BUZZER);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 200 && buzzer_validation == 2){

        tone(BUZZER, 1000);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 200 && buzzer_validation == 3){

        noTone(BUZZER);

        previous_time = current_time;
        buzzer_validation = 0;
        break;

      }

    }

}

void change_notification_sound(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 50 && buzzer_validation == 0){

        tone(BUZZER, 900);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 1){

        tone(BUZZER, 600);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 2){

        noTone(BUZZER);

        previous_time = current_time;
        buzzer_validation = 0;
        break;

      }

    }

}

void first_notification_sound_correct_action(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 50 && buzzer_validation == 0){

        tone(BUZZER, 200);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 1){

        tone(BUZZER, 600);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 2){

        noTone(BUZZER);

        previous_time = current_time;
        buzzer_validation = 0;
        break;

      }

    }

}

void second_notification_sound_correct_action(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 50 && buzzer_validation == 0){

        tone(BUZZER, 350);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 1){

        tone(BUZZER, 750);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 2){

        noTone(BUZZER);

        previous_time = current_time;
        buzzer_validation = 0;
        break;

      }

    }

}

void third_notification_sound_correct_action(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 50 && buzzer_validation == 0){

        tone(BUZZER, 400);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 1){

        tone(BUZZER, 800);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 2){

        noTone(BUZZER);

        previous_time = current_time;
        buzzer_validation = 0;
        break;

      }

    }

}

void fourth_notification_sound_correct_action(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 50 && buzzer_validation == 0){

        tone(BUZZER, 550);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 1){

        tone(BUZZER, 950);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 2){

        noTone(BUZZER);

        previous_time = current_time;
        buzzer_validation = 0;
        break;

      }

    }

}

void fifth_notification_sound_correct_action(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 50 && buzzer_validation == 0){

        tone(BUZZER, 450);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 1){

        tone(BUZZER, 850);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 2){

        tone(BUZZER, 600);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 3){

        noTone(BUZZER);

        previous_time = current_time;
        buzzer_validation = 0;
        break;

      }

    }

}

void first_notification_sound_incorrect_action(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 50 && buzzer_validation == 0){

        tone(BUZZER, 600);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 1){

        tone(BUZZER, 400);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 2){

        noTone(BUZZER);

        previous_time = current_time;
        buzzer_validation = 0;
        break;

      }

    }


}

void second_notification_sound_incorrect_action(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 50 && buzzer_validation == 0){

        tone(BUZZER, 750);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 1){

        tone(BUZZER, 550);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 2){

        noTone(BUZZER);

        previous_time = current_time;
        buzzer_validation = 0;
        break;

      }

    }

}

void third_notification_sound_incorrect_action(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 50 && buzzer_validation == 0){

        tone(BUZZER, 850);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 1){

        tone(BUZZER, 650);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 400 && buzzer_validation == 2){

        noTone(BUZZER);

        previous_time = current_time;
        buzzer_validation = 0;
        break;

      }

    }

}

void alarm(){

  while (true){

      current_time = millis();

      if (current_time - previous_time >= 200 && buzzer_validation == 0){

        tone(BUZZER, 4000);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 200 && buzzer_validation == 1){

        noTone(BUZZER);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 200 && buzzer_validation == 2){

        tone(BUZZER, 4000);

        previous_time = current_time;
        buzzer_validation += 1;

      }

      else if (current_time - previous_time >= 200 && buzzer_validation == 3){

        noTone(BUZZER);

        previous_time = current_time;
        buzzer_validation = 0;
        break;

      }

    }

}

//Execution

void setup() {

  pinMode(BASE_LED, OUTPUT);
  pinMode(FIRST_LED, OUTPUT);
  pinMode(SECOND_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(SENSOR, INPUT_PULLUP);

}

void loop() {

  digitalWrite(BASE_LED, HIGH);

  get_memory_status();

  sensor_validation();

  key = keyboard.getKey();

  if (key){
 
    if (key=='A'){

      if (status == 255){

        first_error_notification();

      }

      else{

        access_attempt_notification_sound();

        capture_keys();

        while (password_validation == false){

          capture_keys();

        } 
        
        third_action_notification();

        access = true;
        
      }

    }

    else if(key=='B'){

      if (status == 255){
        
        change_indication();
        capture_keys();
        save_new_password();
        first_action_notification();

      }

      else {
        
        change_indication();
        capture_keys();

        while (password_validation == false){

          change_indication();
          capture_keys();

        }

        second_action_notification();

        update_password_validation = true;

        capture_keys();
        save_new_password();
        first_action_notification();

        update_password_validation = false;
        password_validation = false;

      }

    }

    else if(key=='C'){

      if (status == 255){

        first_error_notification();

      }

      else {

        if (access == true){

          access = false;
          fourth_action_notification();

        }

        else {

          third_error_notification();

        }

      }

    }

    else if(key=='D'){

      if (status == 255){

        first_error_notification();

      }
      
      else {

        change_indication();
        capture_keys();

        while (password_validation == false){

          change_indication();
          capture_keys();

        }

        restore_memory();
        fifth_action_notification();

        password_validation = false;

      }

    }

  }

}
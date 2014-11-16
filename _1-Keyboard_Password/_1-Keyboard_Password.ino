/* 
 Keyboard test
 
 */
// Initialize the sequence that is to be detected and the length of the sequence
char Str[] = "NaMo";
int len = 4;

int state = 0;

void setup() {
  // Initialize pin connected to LED as Output pin
  pinMode(3,OUTPUT);
  // Start Serial communication with baud rate 9600
  Serial.begin(9600);
}

void loop() {
  // Check for incoming serial data:
  if (Serial.available() > 0) {
    // read incoming serial data:
    char inChar = Serial.read();
    if (inChar == Str[state]){
      state++;
    }
    else{
      // Reset the state variable if a mismatch occurs anywhere before the end of the sequence
      state = 0;
      // Check if the character is equal to the first character of the sequence
      if (inChar == Str[0])
        state++;
    }
    // If all the characters of the sequence are received, then the state will be 4
    if (state == len){
      // Blink LED
      for (int i=0;i<5; i++){
        digitalWrite(3,HIGH);
        delay(1000);
        digitalWrite(3,LOW);
        delay(1000);
      }
      // Reset the State Variable
      state = 0;
    }
  }  
}


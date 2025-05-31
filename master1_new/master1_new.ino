const int SSPin = 10;
const int MOSIPin = 11;
const int SCKPin = 13;

#define DELAY 250

#define BUTTON_UP 2
#define BUTTON_RIGHT 3
#define BUTTON_DOWN 4
#define BUTTON_LEFT 5


void setup() {
  digitalWrite(SSPin, LOW);
  digitalWrite(MOSIPin, LOW);
  digitalWrite(SCKPin, LOW);
  pinMode(MOSIPin, INPUT);
  
// tasteri setup
 pinMode(BUTTON_UP, INPUT);
 digitalWrite(BUTTON_UP, HIGH);

 pinMode(BUTTON_RIGHT, INPUT);
 digitalWrite(BUTTON_RIGHT, HIGH);
 
 pinMode(BUTTON_DOWN, INPUT);
 digitalWrite(BUTTON_DOWN, HIGH);
  
 pinMode(BUTTON_LEFT, INPUT);
 digitalWrite(BUTTON_LEFT, HIGH);

}

void loop() {
  byte bang = B0;
  
  if(digitalRead(BUTTON_UP) == LOW) {
    //Button A is pressed
    bang = B00000001;    	//A = 1
 }
 else if(digitalRead(BUTTON_DOWN) == LOW) {
  //Button B is pressed
    bang =  B00000010; 		//B = 2
 }
 else if(digitalRead(BUTTON_LEFT) == LOW) {
    //Button C is pressed
    bang =  B00000100; 		//C = 4
 }
 else if(digitalRead(BUTTON_RIGHT) == LOW) {
    //Button D is pressed
    bang =  B00001000; 		//D = 8
 }
*/

  if(bang != 0){
  pinMode(SSPin, OUTPUT); // drive pin SS = 0

  bitBangData(bang);
  
  pinMode(SSPin, INPUT);  // hi-Z state SS = 1
  }
}

byte bitBangData(byte _send)  // This function transmit the data via bitbanging
{

  for(int i=7; i>=0; i--)  // 8 bits in a byte
  {
    pinMode(SCKPin, OUTPUT);                     // SCK high
    if (bitRead(_send, i))
  {
    pinMode(MOSIPin, INPUT); // MOSI high
  }
  else
  {
     pinMode(MOSIPin, OUTPUT); // MOSI low
  }
    delay(DELAY);
    pinMode(SCKPin, INPUT);                      // SCK low
    delay(DELAY);
  } 
  return 0;        // Return the received data
}

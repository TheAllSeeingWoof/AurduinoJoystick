const int SSPin = 10;
const int MOSIPin = 11;
const int SCKPin = 13;

#define DELAY 50

#define BUTTON_UP 2
#define BUTTON_RIGHT 3
#define BUTTON_DOWN 4
#define BUTTON_LEFT 5


void setup() {
  Serial.begin(115200);
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
  byte bang = 0;

  if(digitalRead(BUTTON_UP) == LOW) {
    //Button A is pressed
    bang = 0x01;		//A = 1
    pinMode(SSPin, OUTPUT);  // drive pin SS = 0

  bitBangData(bang);
  
  pinMode(SSPin, INPUT);  // hi-Z state SS = 1
 }
 else if(digitalRead(BUTTON_RIGHT) == LOW) {
	//Button B is pressed
    bang =  0x02;	//B = 2
    pinMode(SSPin, OUTPUT);  // drive pin SS = 0

  bitBangData(bang);
  
  pinMode(SSPin, INPUT);  // hi-Z state SS = 1
 }
 else if(digitalRead(BUTTON_DOWN) == LOW) {
    //Button C is pressed
    bang =  0x03;	//C = 4
    pinMode(SSPin, OUTPUT);  // drive pin SS = 0

  bitBangData(bang);
  
  pinMode(SSPin, INPUT);  // hi-Z state SS = 1
 }
 else if(digitalRead(BUTTON_LEFT) == LOW) {
    //Button D is pressed
    bang =  0x04;	//D = 8
    pinMode(SSPin, OUTPUT);  // drive pin SS = 0

  bitBangData(bang);
  
  pinMode(SSPin, INPUT);  // hi-Z state SS = 1
 }

 /* if(bang != 0){
  pinMode(SSPin, OUTPUT);	// drive pin SS = 0

  bitBangData(bang);
  
  pinMode(SSPin, INPUT);	// hi-Z state SS = 1
  }*/
}

byte bitBangData(byte _send)  // This function transmit the data via bitbanging
{

  for(int i=7; i>=0; i--)  // 8 bits in a byte
  {
    pinMode(SCKPin, OUTPUT);              	   	 // SCK high
    if (bitRead(_send, i))
	{
    pinMode(MOSIPin, INPUT); // MOSI high
	}
	else
	{
     pinMode(MOSIPin, OUTPUT); // MOSI low
	}
    delay(DELAY);
    pinMode(SCKPin, INPUT);                   	 // SCK low
    delay(DELAY);
  } 
  return 0;        // Return the received data
}

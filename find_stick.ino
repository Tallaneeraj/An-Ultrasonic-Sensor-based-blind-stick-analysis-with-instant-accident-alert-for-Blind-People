String voice;
int
led1 = 8;
void setup() 
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  
  
}
//-----------------------------------------------------------------------// 
void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
  if (voice.length() > 0) {
    Serial.println(voice);  
 
 
  //----------Turn On One-By-One----------//
  if(voice == "stick") 
  {
    digitalWrite(led1, HIGH);
    delay(200);
  }
  
  //----------Turn Off One-By-One----------//
  else if(voice == "stop") 
  {
    digitalWrite(led1, LOW);
    delay(200);
    }

    
//-----------------------------------------------------------------------// 
voice="";}} //Reset the variable after initiating

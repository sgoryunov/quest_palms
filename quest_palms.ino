
# define SEN_PIN A0
# define RELAY_PIN 12

const short triggerThreshold = 500;// Lower is more sensitive;

const short countNum = 5;
short countSum = 0;
short count = 0;
short currVal = 1000;

void setup() {
//  Serial.begin(9600);
  pinMode(SEN_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
  delay(1);
}

void loop() {
  short value = analogRead(SEN_PIN);
  short avrVal = GetAverage(value);
//  Serial.print("triggerThreshold is ");
//  Serial.print(value);
//  Serial.print("\t");
//  Serial.print("average triggerThreshold is ");
//  Serial.println(avrVal);
  digitalWrite(RELAY_PIN, (avrVal < triggerThreshold) ? LOW : HIGH);
}

short GetAverage(short val){
  if(count >= countNum){
    currVal = countSum/countNum;
    countSum = 0;
    count = 0; 
  }
  countSum += val;
  count++;
  return currVal;
}

// I release this code under the standard MIT licence;
// (in addition to whatever StackExchange implies);
# define INT_TIME 500

const short triggerThreshold = 800;// Lower is more sensitive;

const short countNum = 10;
short countSum = 0;
short count = 0;
short currVal = 1000;
short delayTime = INT_TIME/countNum;

void setup() {
//  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A5, OUTPUT);
  digitalWrite(A5, LOW);
  delay(1);
}

void loop() {
  short value = analogRead(A0);
  short avrVal = GetAverage(value);
//  Serial.print("triggerThreshold is ");
//  Serial.print(value);
//  Serial.print("\t");
//  Serial.print("average triggerThreshold is ");
//  Serial.println(avrVal);
  digitalWrite(A5, (avrVal < triggerThreshold) ? HIGH : LOW);
  delay(delayTime);// 10ms;
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

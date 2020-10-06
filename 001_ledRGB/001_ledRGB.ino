#define redPin 11
#define greenPin 10
#define bluePin 9
#define potPin A0
#define photoPin A1


void setup() {
    Serial.begin(9600);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(potPin, INPUT);
    pinMode(photoPin, INPUT);
}

void loop() {
    Serial.print("RGB");
    int potValue = analogRead(potPin);
    Serial.print("Pot Val = ");
    Serial.println(potValue, DEC);
    potValue = map(potValue, 0, 1023, 0, 255);
    rgb(potValue, potValue, potValue);

    int lightValue = analogRead(photoPin);
    Serial.print("Light Val = ");
    Serial.println(lightValue, DEC);

    Serial.println();
    
    delay(100);
}

void rgb(unsigned char r, unsigned char g, unsigned char b){
    analogWrite(redPin, r);
    analogWrite(greenPin, g);
    analogWrite(bluePin, b);  
}

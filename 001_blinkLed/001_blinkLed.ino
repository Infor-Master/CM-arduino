#define LEDPIN 13

void setup() {
    Serial.begin(9600);
    pinMode(LEDPIN, OUTPUT);
}

void loop() {
    Serial.print("Blink & Serial Debug!");
    digitalWrite(LEDPIN, HIGH);
    Serial.print("PIN ");
    Serial.print(LEDPIN, DEC);
    Serial.println('1', DEC);
    delay(1000);
    digitalWrite(LEDPIN, LOW); // LED off
    Serial.print("PIN ");
    Serial.print(LEDPIN, DEC);
    Serial.println('0', DEC);
    delay(2000);
}

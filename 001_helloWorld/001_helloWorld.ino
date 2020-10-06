#define MSG "Count Seconds: "
int counter=0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.print(MSG);
    Serial.println(counter++, DEC);
    delay(1000);
}

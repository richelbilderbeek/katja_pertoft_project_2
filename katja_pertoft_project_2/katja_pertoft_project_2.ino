void setup() 
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(13, OUTPUT);
}

void loop() 
{
  digitalWrite(13, LOW);
  if (digitalRead(A0)) {
    if (digitalRead(A1)) {
      digitalWrite(13, HIGH);
    }
  }
}

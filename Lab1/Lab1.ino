int RGB[] = {8, 9, 10};
int SW[] = {2, 3, 4};
void setup()
{
  pinMode(SW[0], INPUT);
  pinMode(SW[1], INPUT);
  pinMode(SW[2], INPUT);
  pinMode(RGB[0], OUTPUT); // red
  pinMode(RGB[1], OUTPUT); // blue
  pinMode(RGB[2], OUTPUT); // green
}
void Color(int r, int b, int g)
{
  analogWrite(RGB[0], r); // red
  analogWrite(RGB[1], b); // blue
  analogWrite(RGB[2], g); // green
}

void loop()
{
  if(digitalRead(SW[0]) == LOW){
    Color(1023, 0, 0); //red
  }
  else if(digitalRead(SW[1]) == LOW){
    Color(0, 1023, 0); //blue
  }
  else if(digitalRead(SW[2]) == LOW){
    Color(0, 0, 1023); // green
  }
}

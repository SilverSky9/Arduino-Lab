int seg[] = {2,3,4,5,8,9,10};
void setup()
{
  pinMode(seg[0], OUTPUT);
  pinMode(seg[1], OUTPUT);
  pinMode(seg[2], OUTPUT);
  pinMode(seg[3], OUTPUT);
  pinMode(seg[4], OUTPUT);
  pinMode(seg[5], OUTPUT);
  pinMode(seg[6], OUTPUT);
}
void display(int G, int F, int A, int B, int E, int D, int C){
  digitalWrite(seg[0], G);
    digitalWrite(seg[1], F);
    digitalWrite(seg[2], A);
    digitalWrite(seg[3], B);
    digitalWrite(seg[4], E);
    digitalWrite(seg[5], D);
    digitalWrite(seg[6], C);
    
}

void loop()
{
  display(LOW,LOW,LOW,HIGH,LOW,LOW,HIGH); // 1
  delay(1000); // Wait for 1000 millisecond(s)
  display(HIGH,LOW,HIGH,HIGH,HIGH,HIGH,LOW); // 2
  delay(1000); // Wait for 1000 millisecond(s)
  display(HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH); // 3
  delay(1000); // Wait for 1000 millisecond(s)
  display(HIGH,HIGH,LOW,HIGH,LOW,LOW,HIGH); // 4
  delay(1000); // Wait for 1000 millisecond(s)
  display(HIGH,HIGH,HIGH,LOW,LOW,HIGH,HIGH); // 5
  delay(1000); // Wait for 1000 millisecond(s)
  display(HIGH,HIGH,HIGH,LOW,HIGH,HIGH,HIGH); // 6
  delay(1000); // Wait for 1000 millisecond(s)
  display(LOW,HIGH,HIGH,HIGH,LOW,LOW,HIGH); // 7
  delay(1000); // Wait for 1000 millisecond(s)
  display(HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH); // 8
  delay(1000); // Wait for 1000 millisecond(s)
  display(HIGH,HIGH,HIGH,HIGH,LOW,HIGH,HIGH); // 9
  delay(1000); // Wait for 1000 millisecond(s)
}

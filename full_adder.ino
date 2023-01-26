int input0 = 3;
int input1 = 4;
int input2 = 5;
int output0 = 11;
int output1 = 12;

void setup() {
  pinMode(input0, INPUT);
  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  pinMode(output0, OUTPUT);
  pinMode(output1, OUTPUT);
  digitalWrite(output0, LOW);
  digitalWrite(output1, LOW);
}

bool XOR(bool a, bool b){
  return (a + b) % 2;
}

bool AND(bool a, bool b){
  return a && b;
}

bool OR(bool a, bool b){
  return a || b;
}

void loop() {
  bool x = digitalRead(input0);
  bool y = digitalRead(input1);
  bool z = digitalRead(input2);

  bool s = XOR(XOR(x, y), z);
  bool c = OR(AND(z, XOR(x, y)), AND(x, y));

  digitalWrite(output0, s);
  digitalWrite(output1, c);
}

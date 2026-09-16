//SECURITY ALARM BOX - alert system 


#define TRIG    6    // 6 سلك إرسال الموجات
#define ECHO    7   // 7 سلك استقبال الموجات
#define BUZZER  9   // 9 مكان الجرس
#define LED     10   // مكان الضوء الأحمر      8

// متغيرات حساب المسافة
long duration;
int distance;

void setup() {
  pinMode(TRIG, OUTPUT); 
  pinMode(ECHO, INPUT);  
  pinMode(BUZZER, OUTPUT);  
  pinMode(LED, OUTPUT);  
  
  Serial.begin(9600); 
}

void loop() {

  // تنظيف الحساس وإرسال النبضة
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;



  //print distance 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");  
  if (distance > 0 && distance <=20) {
    digitalWrite(LED, HIGH);    // شغل الضوء

    
    // إنشاء صوت إنذار متناوب (Siren)
    tone(BUZZER, 1000);         // نغمة بتردد 1000 هرتز
    delay(150);
    tone(BUZZER, 1500);         // نغمة بتردد 1500 هرتز
    delay(150);
  } 
  else {
    noTone(BUZZER);             // أوقف الصوت تماماً
    digitalWrite(LED, LOW);     // أطفئ الضوء
    
    delay(100);                 // تأخير بسيط لاستقرار القراءة
  }
}

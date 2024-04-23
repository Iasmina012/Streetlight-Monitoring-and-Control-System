int led = 13; //pinul la care este atasat LED-ul
int sensor_pir = 2; //pinul la care este atasat senzorul de miscare (pir)
int value_pir = LOW; //valoarea senzorului de miscare
int state_pir = LOW; //starea curenta a senzorului de miscare
int sensor_light = 8; //pinul la care este atasat senzorul de lumina
int state_light = LOW; //starea senzorului de lumina
char next_value = 0; //valoarea transmisa ca parametru de pe aplicatia proiectate pe android

void setup() {
  // put your setup code here, to run once:

  pinMode(led, OUTPUT); //initalizam LED-ul ca output
  pinMode(sensor_pir, INPUT); //initializam senzorul miscare ca input
  pinMode(sensor_light, INPUT); //initializam senzorul lumina ca input
  Serial.begin(9600); //initializam serial monitor

}

void loop() {
  // put your main code here, to run repeatedly:

  command(); //apelam functia de comanda

}

void command() {

  if(Serial.available() > 0) //verificam daca modulul este conectat
  {

    next_value = Serial.read(); //citim valoarea transmisa de catre modul

    //afisare text
    Serial.print(next_value);
    Serial.print("\n");

    if(next_value == '0') //stingere LED
    {
      digitalWrite(led, LOW);
    }

    else if(next_value == '1') //aprindere LED
    {
      digitalWrite(led, HIGH);
    }

    else if(next_value == '2') //aprindere sau stingere in functie de senzorul de miscare
    {
      PIR();
    }

    else if(next_value == '3') //aprindere sau stingere in functie de senzorul de lumina
    {
      LIGHT();
    }

    else if(next_value == '4') //aprindere sau stingere in functie de ambii senzori
    {
      SMART();
    }

  }

}

void LIGHT() {	//functia senzorului de lumina

  while(1)	//bucla infinita pana la primirea unei noi valori
  {

    if(next_value != '3')
      break;

    state_light = digitalRead(sensor_light); //atribuim variabilei state_light valoarea transmisa de senzorul de lumina

    //afisare text
    Serial.print("Intensity: ");
    Serial.println(state_light);

    delay(50);	//setam delay

    if(state_light == HIGH) //verificam valoarea state_light - HIGH inseamna ca este nu este detectata lumina
    {

      digitalWrite(led, HIGH);	//aprindere LED
      Serial.println("LIGHT OFF & LED ON"); //afisare text
      command(); //apelam functia de comanda

    }
    else
    {

      digitalWrite(led, LOW); //stingere LED
      Serial.println("LIGHT ON & LED OFF");	//afisare text
      command(); //apelam functia de comanda

    }

  }

}

void PIR() {

  while(1) //bucla infinita pana la primirea unei noi valori
  {

    if(next_value != '2')
      break;

    value_pir = digitalRead(sensor_pir);	//citim valoarea senzorului de miscare

    if (value_pir == HIGH) //testam valoarea value_pir
    {

      digitalWrite(led, HIGH); //aprindere LED
      delay(100);	//setare delay

      if (state_pir == LOW)
      {

        Serial.println("Motion detected!");	//afisare text
        state_pir = HIGH;	//actualizam variabila state_pir
        command(); //apelam functia de comanda

      }
    }
    else
      {

        digitalWrite(led, LOW);	//stingere LED
        delay(100);	//setare delay

        if (state_pir == HIGH)
        {

          Serial.println("Motion stopped!");
          state_pir = LOW; //actualizam variabila state_pir
          command(); //apelam functia de comanda

        }

      }

    }

  }


void SMART() {

  while(1)	//bucla infinita pana la primirea unei noi valori
  {

    if(next_value != '4')
      break;
    
    state_light = digitalRead(sensor_light); //atribuim variabilei state_light valoarea transmisa de senzorul de lumina
    value_pir = digitalRead(sensor_pir); //atribuim variabilei value_pir valoarea transmisa de senzorul de miscare

    if(state_light == HIGH && value_pir == HIGH)	//testam valorile
    {

      digitalWrite(led, HIGH);	//aprindere LED
      command(); //apelam functia de comanda

    }
    else
    {

      digitalWrite(led, LOW);	//stingere LED
      command(); //apelam functia de comanda

    }

  }

}
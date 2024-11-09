#define echoPin 7 // Broche d'entrée d'écho
#define triggerPin 8 // Broche de sortie de déclenchement
#define buzzer 13 // Broche de sortie pour le buzzer
#define led_red 10 // Pin pour le rouge
#define led_green 11 // Pin pour le vert
#define led_blue 12 // Pin pour le bleu
 
// Les variables nécessaires sont définies
int maximumRange = 300; 
int minimumRange = 2; 
int firstThreshold = 50;
int secondThreshold = 15;
int lastThreshold = 5;
int isBuzzLedOn = 0;
long distance;
long duration;
 
void setup() {
  // On initialise les entrées sorties des différents pins
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_blue, OUTPUT);
  Serial.begin(9600);
  Serial.println("KY-050 Mesure de la distance");
}
 
void loop() {
  // La mesure de la distance est lancée à l'aide du signal de déclenchement d'une longueur de 10us
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(triggerPin, LOW);

  // On attend maintenant à l'entrée Echo que le signal soit activé
  // puis on mesure le temps pendant lequel il reste activé 
  duration = pulseIn(echoPin, HIGH);

  // La distance est maintenant calculée à l'aide du temps enregistré
  distance = duration/58.2;

  // Vérification si la valeur mesurée se situe dans la distance autorisée
  if (distance >= maximumRange) {
    // Si ce n'est pas le cas, un message d'erreur est affiché.
    Serial.println("Distance hors de la plage de mesure");
    Serial.println("-----------------------------------");
    // On éteint tout les composants de signalisation, puisqu'aucun obstacle n'est en vue.
    digitalWrite(buzzer, LOW);
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_blue, LOW);
  }
  else if (distance <= maximumRange) {
    Serial.println("Tout va bien pour l'instant.");
    Serial.print("La distance est de: ");
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("-----------------------------------");
    // On active la LED en vert et on éteint le buzzer
    digitalWrite(buzzer, LOW);
    digitalWrite(led_green, HIGH);
    digitalWrite(led_blue, LOW);
    digitalWrite(led_red, LOW);
  }
  else if (distance <= firstThreshold) {
    // La distance calculée est affichée dans la sortie sérielle
    Serial.println("On approche d'un obstacle!");
    Serial.print("La distance est de: ");
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("-----------------------------------");
    // On active la LED en jaune et on éteint le buzzer
    digitalWrite(buzzer, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_blue, HIGH);
    digitalWrite(led_red, HIGH);

  }
  else if (distance <= secondThreshold){
    Serial.println("Attention!");
    Serial.print("La distance est de: ");
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("-----------------------------------");
    // On veut faire clignoter la LED en jaune, ainsi que faire alterner le buzzer
    if (isBuzzLedOn){
      digitalWrite(buzzer, LOW);
      digitalWrite(led_red, LOW);
      digitalWrite(led_green, LOW);
      digitalWrite(led_blue, LOW);
      isBuzzLedOn = 0;
    } else {
      digitalWrite(buzzer, HIGH);
      digitalWrite(led_red, HIGH);
      digitalWrite(led_green, LOW);
      digitalWrite(led_blue, HIGH);
      isBuzzLedOn = 1;
    }
    
  }
  else if (distance <= lastThreshold){
    Serial.println("Contact imminent!");
    Serial.print("La distance est de: ");
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println("-----------------------------------");
    // On allume la LED en rouge et on allume le buzzer en continu
    digitalWrite(buzzer, HIGH);
    digitalWrite(led_green, LOW);
    digitalWrite(led_blue, LOW);
    digitalWrite(led_red, HIGH);
  }
  // Pause entre les différentes mesures
  delay(500);
}


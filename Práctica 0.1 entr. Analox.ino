// C++ code
/*
 * Programa que mapea a entrada dun potenciómetroa cinco cores.
 * Unha entrada analóxica, conectada a un potenciómetro
 * determinará cal das 5 LEDS se encenden (activando unha de cinco
 * saídas dixitais, segundo o nivel detectado.
 * 
 * Autor: Fer
 * Data: 10 de xaneiro de 2024
 * Actualización: 15 de xaneiro de 2024
 */

// Definicións da entrada analóxoca
#define POTENCIOMETRO A0
#define LED_VERMELLO 6
#define LED_VERDE 3
#define LED_AZUL 4
// Declaración de variables
int tempo = 200;
int valor_potenciometro;
int nivel;
int numero_niveis = 15; // Número de valores que toma a variable nivel.


void setup ()
{
  // Non hai que declarar as entradas e saìdas analóxicas
  Serial.begin(9600);
}

void loop ()
{
  valor_potenciometro = analogRead(POTENCIOMETRO);
  nivel = map(valor_potenciometro, 0, 1023, 0, 4);
  switch (nivel)
  {
    case 0:
    	setColor(255, 0, 0);
    break;
    case 1:
    	setColor(192, 64, 0);
    break;
    case 2:
    	setColor(127, 127, 0);
    break;
    case 3:
    	setColor(0, 255, 0);
    break;
    case 4:
    	setColor(0, 64, 192);
    break;
    default:
    apagarLed();
  }
}
/*
void loop()
{
  // Detectar o valor obtido do potenciómetro
  valor_potenciometro = analogRead(POTENCIOMETRO);
  // Seleccionar 1 de 5 niveis en función do valor detectado
  // Escribir no LED RGB
  if (valor_potenciometro <= 0)
  {
    apagarLed();
  }
  else if(valor_potenciometro < 205)
  {
    // Encender en vermello
    setColor(255, 0 ,127);
  }
  else if (valor_potenciometro < 410)
  {
    // Encender en laranxa
    setColor(255, 32, 0);
  }
  else if (valor_potenciometro < 615)
  {
    // Encender en amarelo
    setColor(255, 255, 0);
  }
  else if (valor_potenciometro < 820)
  {
    // Encender en verde
    setColor(0, 255, 127);
  }
  else
  {
    // Encender en azul
    setColor(0, 0, 255);
  }
  Serial.print("Valor obtido: ");
  Serial.println(valor_potenciometro);
  Serial.print("Valor de tension: ");
  Serial.println(valor_potenciometro * 4.887585);
  delay(tempo);
}
*/
// Funciones auxiliares
void setColor (int vermello, int verde, int azul)
{
  analogWrite(LED_VERMELLO, vermello);
  analogWrite(LED_VERDE, verde);
  analogWrite(LED_AZUL, azul);
}

void apagarLed (){
  setColor(0, 0, 0);
}


#include <SoftwareSerial.h>

SoftwareSerial myGsm(7, 8);
String reading = "{\"bus_name\":\"HU-02\",  \"lat\" : 12.983027,  \"lng\" : 80.2594 }";
void setup()
{
  myGsm.begin(9600);
  Serial.begin(9600);
  delay(500);
  myGsm.println("AT+SAPBR=3,1,\"Contype\",\"GPRS\"");
  delay(1000);
  printSerialData();

  myGsm.println("AT+SAPBR=3,1,\"APN\",\"ufone.pinternet \"");//APN
  delay(1000);
  printSerialData();

  myGsm.println("AT+SAPBR=1,1");
  delay(1000);
  printSerialData();

  myGsm.println("AT+SAPBR=2,1");
  delay(1000);
  printSerialData();
  //  myGsm.println("AT+CIPSHUT");
  //  delay(1000);
  //  printSerialData();
  //
  //  myGsm.println("AT+CIPMUX=0");
  //  delay(2000);
  //  printSerialData();
  //
  //  myGsm.println("AT+CGATT=1");
  //  delay(1000);
  //  printSerialData();
  //
  //
  //  myGsm.println("AT+CSTT=\"Ufone.internet\",\"\",\"\"");//setting the APN,2nd parameter empty works for all networks
  //  delay(5000);
  //  printSerialData();
  //
  //  myGsm.println();
  //  myGsm.println("AT+CIICR");
  //  delay(6000);
  //  printSerialData();

}

void loop()
{
  myGsm.println("AT+HTTPINIT");
  //  myGsm.println("AT+CIFSR"); //init the HTTP request
  delay(2000);
  printSerialData();

  myGsm.println("AT+HTTPSSL=1");
  delay(2000);
  printSerialData();

  myGsm.println("AT+HTTPPARA=\"CID\",1");
  // myGsm.println("AT+CIPSTART=\"TCP\",\"122.178.80.228\",\"350\"");
  delay(5000);
  printSerialData();
  delay(5000);
  myGsm.println("AT+HTTPPARA=\"URL\",\"shielded-hollows-81695.herokuapp.com/live\"");
  // myGsm.println("AT+CIPSEND");
  delay(2000);
  printSerialData();

  myGsm.println("AT+HTTPPARA=\"CONTENT\",\"application/json\"");
  //sendtemp();
  delay(3000);
  //myGsm.println("AT+CIPCLOSE");
  printSerialData();

  myGsm.println("AT+HTTPDATA=" + String(reading.length()) + ",100000");
  //myGsm.println("AT+CIPSHUT");
  delay(1000);
  printSerialData();


  myGsm.println(reading);
  delay(1000);
  printSerialData();

  myGsm.println("AT+HTTPACTION=1");
  delay(1000);
  printSerialData();

  myGsm.println("AT+HTTPREAD");
  delay(1000);
  printSerialData();

//  myGsm.println("AT+HTTPTERM");
//  delay(1000);
//  printSerialData();

Serial.println("one request completed now waiting for 10 seconds");

delay(10000);

}


void printSerialData()
{
  while (myGsm.available() != 0)
    Serial.write(myGsm.read());
}

void sendtemp()
{
  //  temp = analogRead(tempPin);
  //  temp = temp * 0.48828125;
  //  Serial.print("TEMPERATURE = ");
  //  Serial.print(temp);
  //  Serial.print("*C");
  //  Serial.println();
  //  delay(5000);
  // myGsm.println(temp);
  // delay(3000);
  // printSerialData();
  // myGsm.write(0x1A);
  // delay(3000);
  //   printSerialData();


}

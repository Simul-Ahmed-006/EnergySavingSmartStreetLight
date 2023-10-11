#define ir0 2
#define ir1 3
#define ir2 4
#define ldr 5
#define led0_1 10
#define led1_2 11

int IR[3];
int STATE[3] ={0,0,0};
int TOGGLE[3] ={0,0,0};
int LIGHT[2]={0,0};

void setup() {

  pinMode(ir0,INPUT); // object 0  free 1
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ldr,INPUT); //night 1  day 0

  pinMode(A7,OUTPUT);
  pinMode(A6,OUTPUT);  
  Serial.begin(9600);

}

void loop() {
int Day0_Night_1 = digitalRead(ldr);  

if(Day0_Night_1 ==0 )
 {
   analogWrite(led0_1,0);
   analogWrite(led1_2,0);
 }
  else if(Day0_Night_1 ==1 ) 
  {
    Lightcontrol();
  }

//   Serial.println("Day_Night_1");
//   Serial.print(Day0_Night_1);
  // Serial.println("IR 0 :");
  // Serial.println(IR[0]);
  // Serial.println("IR 1 :");
  // Serial.println(IR[1]);
  // Serial.println("IR 2 :");
  // Serial.println(IR[2]);
// Serial.println();
// Serial.println();
// Serial.println();
//   Serial.println("TOGGLE0 :");
//   Serial.print(TOGGLE[0]);
//   Serial.println("TOGGLE 1 :");
//   Serial.print(TOGGLE[1]);
//   Serial.println("TOGGLE2 :");
//   Serial.print(TOGGLE[2]);

  // Serial.println("LIGHT 0 :");
  // Serial.print(LIGHT[0]);
  // Serial.println("LIGHT 1 :");
  // Serial.print(LIGHT[1]);


//   Serial.println();
//   Serial.println();
  
// delay(1000);



}


void Lightcontrol()
{
  IRstate();

  if(LIGHT[0]>0){ analogWrite(led0_1,250); }
  if(LIGHT[0]==0){ analogWrite(led0_1,50); }
  if(LIGHT[1]>0){ analogWrite(led1_2,250); }
  if(LIGHT[1]==0){ analogWrite(led1_2,50); }
  
}
void IRstate()
{

  IR[0]= digitalRead(ir0);
  IR[1]= digitalRead(ir1);
  IR[2]= digitalRead(ir2);





  for( int i =0; i <3; i ++)
  {
    if(STATE[i]==1 && IR[i] == 1)
    {
      TOGGLE[i]++;
      STATE[i]=0;
    }
    else if(STATE[i]==0 && IR[i] == 0)
    {
      STATE[i]=1;
    }


    Serial.println("STATE[i] :");
  Serial.print(STATE[i]);

  }


  LIGHT[0] = TOGGLE[1] - TOGGLE[0];
  LIGHT[1] = TOGGLE[2] - TOGGLE[1];

  if( LIGHT[0]<0 ){  LIGHT[0] =0; }
  if( LIGHT[1]<0 ){  LIGHT[1] =0; }


}





#include <ros.h>
#include <Wire.h>
#include <std_msgs/String.h>


ros::NodeHandle  nh;
int turn_value;
void messageCb(const std_msgs::String & dir_msg){
    if (dir_msg.data == "forward"){
      turn_value += 1000;
    }
    else if (dir_msg.data == "backward"){
      turn_value -= 1000;
    }   
}

ros::Subscriber<std_msgs::String> sub("direction", messageCb );


void setup() {
  pinMode(9,OUTPUT);
  
}

void loop() {
  if(turn_value>2000)
  turn_value ==2000;
  if(turn_value<-2000)
  turn_value == -2000;
  
  if(turn_value>0){
   digitalWrite(9,HIGH);
   turn_value--;
  }else if (turn_value <0){
   digitalWrite(8,HIGH);
   turn_value++;
  }else{
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
  }
  nh.spinOnce();
  delay(1);
  
  
  // put your main code here, to run repeatedly:

}

/**
   测试样例：用遥控器控制继电器
   说    明：如果继电器采用常通的接法，遥控器按下时继电器断开
             如果继电器采用常断的接法，遥控器按下时继电器接通
   版 本 号：1.0
   作    者：田辛
   日    期：2017年12月30日
*/

/* 引用库 */
#include <IRremote.h>

/* 接脚定义 */
#define RECV_PIN  11        // 红外接收端口
#define RELAY_PIN  7        // 继电器信号端口

/* 全局声明 */
IRrecv irrecv(RECV_PIN);
decode_results results;

/*  初期化  */
void setup()
{
  /* 设定串口通信波特率 */
  Serial.begin(9600);
  
  /* 开启红外接收 */
  irrecv.enableIRIn();
  Serial.println("IRin Enabled");

  /* 初始化端口输入输出 */
  pinMode(RELAY_PIN, OUTPUT);
}

/* 循环部分 */
void loop() {
  /* 判断接收到了遥控器的输入 */
  if (irrecv.decode(&results)) {
    /* 过滤遥控器杂讯（FFFFFFF）*/
    if(results.value != 4294967295){
      /* 输出每一个按键的代码 */
      Serial.print("红外线接收的代码：");
      Serial.println(results.value);
      
      /* 过滤后匹配指定按钮   */
      if(results.value == 16761405){
        /* 收到既定红外接收码后，控制继电器端口 */
        digitalWrite(RELAY_PIN,digitalRead(RELAY_PIN));
      }
    }

    /* 重置红外接收器，并准备下一次接收操作 */
    irrecv.resume();
  }

}

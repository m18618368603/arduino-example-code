/**
   测试样例：用开关控制LED小灯通断
   说    明：开关按下时灯亮，开关放开时灯灭
   版 本 号：1.0
   作    者：田辛
   日    期：2017年12月29日
*/

/* 引用库 */

/* 接脚定义 */
#define LED_PIN    12        // LED使用端口
#define SWITCH_PIN  7        // 开关所使用的端口

/* 全局设定 */

/*  初期化  */
void setup() {
  /* 初始化端口输入输出 */
  pinMode(LED_PIN,   OUTPUT);
  pinMode(SWITCH_PIN, INPUT);

  /* 用内置上拉电阻过滤杂讯 */
  digitalWrite(SWITCH_PIN, HIGH);
}

/* 循环部分 */
void loop() {
  /* 读取开关的状态，当开关闭合时（H），灯亮；反之，灯暗 */
  digitalWrite(LED_PIN, digitalRead(SWITCH_PIN));
}


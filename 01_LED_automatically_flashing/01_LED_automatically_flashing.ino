/**
   测试样例：让LED小灯明暗闪烁
   说    明：一明一暗，每秒变换一次明暗状态
   版 本 号：1.0
   作    者：田辛
   日    期：2017年12月28日
*/

/* 接脚定义 */
#define LED_PIN 12          // LED小灯所使用的接口

/* 全局设定 */
#define FLASHING_DELAY 1000 // 延迟设定（单位：毫秒）

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  /* 设置LED状态是当前状态的非 */
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));

  /* 延迟 */
  delay(FLASHING_DELAY);
}


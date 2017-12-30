/**
   测试样例：LCD1602+IIC 芯片显示测试程序
   说    明：IIC芯片控制LCD1602显示器，非Arduino直接控制
   版 本 号：1.0
   作    者：田辛
   日    期：2017年12月30日
*/

/* 引用库 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

/* 接脚定义 */

/* 全局设定 */
/* 声明LCD的初始化端口及行列 */
LiquidCrystal_I2C lcd(0x3F,16,2);

/*  初期化  */
void setup()
{
  /* 初期化LCD */
  lcd.init();
  /* 设置背光常亮 */
  lcd.backlight();

  /* 开始开机画面 */
  lcd.setCursor(0,0);
  lcd.print("Tianxin's       ");
  lcd.setCursor(0,1);
  lcd.print("         Arduino");
  delay(2000);
}

/* 循环部分 */
void loop()
{
  int i;        // 循环变量

  /* 半小时倒计时 */
  for(i=1800;i>=0;i--){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(i+);
    delay(1000);
  }
}

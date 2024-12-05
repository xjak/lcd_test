##### 一、初始化相关API
  ###### 1.初始化屏幕
    函数：`tft.init();`
    _ 说明：初始化TFT屏幕。 _
    _填充全屏幕_
    函数：tft.fillScreen(uint32_t color);
    * 说明：使用指定的颜色值填充全屏幕。 *

  ###### 2.设置屏幕方向
    函数：``tft.setRotation(uint8_t r);``
    说明：设置屏幕方向。参数r为旋转角度，0为0°，1为90°，2为180°，3为270°。
    颜色反转
    函数：tft.invertDisplay(bool i);
    说明：反转显示颜色。当i为1时反转，为0时正常显示。

#### 二、文字相关API
  ###### 1.设置文本显示坐标和字体
    函数：tft.setCursor(int16_t x, int16_t y, uint8_t font);
    函数：tft.setCursor(int16_t x, int16_t y);（不带字体参数）
    说明：设置文本显示的坐标和字体。默认以文本左上角为参考点。

  ###### 2.设置字体颜色
    函数：tft.setTextColor(uint16_t color);
    函数：tft.setTextColor(uint16_t fgcolor, uint16_t bgcolor);
    说明：设置文本颜色。前者仅设置字体颜色，后者同时设置字体颜色和背景色。

  ###### 3.设置字体大小
    函数：tft.setTextSize(uint8_t size);
    说明：设置字体大小。文本大小范围为1~7的整数。
    显示字符串
    函数：tft.print("Hello World!");
    函数：tft.println("Hello World!");
    说明：在屏幕上显示字符串。println函数会在字符串后添加换行符。

  ###### 4.绘制字符串
    函数：tft.drawString(const String &string, int32_t x, int32_t y, uint8_t font);
    函数：tft.drawString(const char *string, int32_t x, int32_t y, uint8_t font);
    函数：tft.drawCentreString(const String &string, int32_t x, int32_t y, uint8_t font);
    函数：tft.drawCentreString(const char *string, int32_t x, int32_t y, uint8_t font);
    函数：tft.drawRightString(const String &string, int32_t x, int32_t y, uint8_t font);
    函数：tft.drawRightString(const char *string, int32_t x, int32_t y, uint8_t font);
    说明：drawString函数用于绘制居左对齐的字符串，drawCentreString函数用于绘制居中对齐的字符串，drawRightString函数用于绘制居右对齐的字符串。

  ###### 5.绘制字符
    函数：tft.drawChar(uint16_t uniCode, int32_t x, int32_t y, uint8_t font);
    函数：tft.drawChar(int32_t x, int32_t y, uint16_t c, uint32_t color, uint32_t bg, uint8_t size);
    说明：绘制单个字符。前者使用Unicode编码和字体大小，后者还可以设置字符颜色和背景色。

  ###### 6.绘制数字
    函数：tft.drawNumber(long intNumber, int32_t x, int32_t y, uint8_t font);
    函数：tft.drawNumber(long intNumber, int32_t x, int32_t y);
    说明：在指定位置绘制数字。前者可以指定字体大小，后者使用当前字体。

  ###### 7.绘制浮点数
    函数：tft.drawFloat(float floatNumber, uint8_t decimal, int32_t x, int32_t y, uint8_t font);
    函数：tft.drawFloat(float floatNumber, uint8_t decimal, int32_t x, int32_t y);
    说明：在指定位置绘制浮点数。前者可以指定小数位数和字体大小，后者使用当前字体。

#### 三、绘制几何图形API
  ###### 1.绘制点
    函数：tft.drawPixel(int32_t x, int32_t y, uint32_t color);
    说明：在指定位置绘制一个点，并设置颜色。

  ###### 1.绘制线段
    函数：tft.drawLine(int32_t xs, int32_t ys, int32_t xe, int32_t ye, uint32_t color);
    说明：在指定起点和终点之间绘制一条线段，并设置颜色。

  ###### 2.绘制快速横线和竖线
    函数：tft.drawFastHLine(int32_t x, int32_t y, int32_t w, uint32_t color);
    函数：tft.drawFastVLine(int32_t x, int32_t y, int32_t h, uint32_t color);
    说明：分别绘制快速横线和竖线。w和h分别表示线段的宽度和高度。

  ###### 3.绘制圆
    函数：tft.drawCircle(int32_t x, int32_t y, int32_t r, uint32_t color);
    函数：tft.fillCircle(int32_t x, int32_t y, int32_t r, uint32_t color);
    说明：drawCircle函数绘制空心圆，fillCircle函数绘制实心圆。x和y表示圆心坐标，r表示半径。

  ###### 4.绘制椭圆
    函数：tft.drawEllipse(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color);
    函数：tft.fillEllipse(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color);
    说明：drawEllipse函数绘制空心椭圆，fillEllipse函数绘制实心椭圆。w和h分别表示椭圆的宽度和高度。

  ###### 5.绘制矩形
    函数：tft.drawRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color);
    函数：tft.fillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color);
    说明：drawRect函数绘制空心矩形，fillRect函数绘制实心矩形。w和h分别表示矩形的宽度和高度
##### 一、初始化相关API
  ##### 1.初始化屏幕
  `tft.init();`
  *说明：初始化TFT屏幕。*
  ##### 2.填充全屏幕
  `tft.fillScreen(uint32_t color);`
  *说明：使用指定的颜色值填充全屏幕。*
  ##### 3.设置屏幕方向
  `tft.setRotation(uint8_t r);`
  *说明：设置屏幕方向。参数r为旋转角度，0为0°，1为90°，2为180°，3为270°。*
  ##### 4.颜色反转`
  `tft.invertDisplay(bool i);`
  *说明：反转显示颜色。当i为1时反转，为0时正常显示。*

#### 二、文字相关API
  ##### 1.设置文本显示坐标和字体
  ```cpp
    tft.setCursor(int16_t x, int16_t y, uint8_t font);
    tft.setCursor(int16_t x, int16_t y);（不带字体参数）
  ```
  *说明：设置文本显示的坐标和字体。默认以文本左上角为参考点。*

  ##### 2.设置字体颜色
  ```cpp
  tft.setTextColor(uint16_t color);
  tft.setTextColor(uint16_t fgcolor, uint16_t bgcolor);
  ```
  *说明：设置文本颜色。前者仅设置字体颜色，后者同时设置字体颜色和背景色。*

  ##### 3.设置字体大小
  `tft.setTextSize(uint8_t size);`
  *说明：设置字体大小。文本大小范围为1~7的整数。*
  ##### 3.显示字符串
  ```cpp
    tft.print("Hello World!");
    tft.println("Hello World!");
  ```
  *说明：在屏幕上显示字符串。println函数会在字符串后添加换行符。*

  ##### 4.绘制字符串
  ```cpp
    tft.drawString(const String &string, int32_t x, int32_t y, uint8_t font);
    tft.drawString(const char *string, int32_t x, int32_t y, uint8_t font);
    tft.drawCentreString(const String &string, int32_t x, int32_t y, uint8_t font);
    tft.drawCentreString(const char *string, int32_t x, int32_t y, uint8_t font);
    tft.drawRightString(const String &string, int32_t x, int32_t y, uint8_t font);
    tft.drawRightString(const char *string, int32_t x, int32_t y, uint8_t font);
  ```
  *说明：drawString函数用于绘制居左对齐的字符串，drawCentreString函数用于绘制居中对齐的字符串，drawRightString函数用于绘制居右对齐的字符串。*

  ##### 5.绘制字符
  ```cpp
    tft.drawChar(uint16_t uniCode, int32_t x, int32_t y, uint8_t font);
    tft.drawChar(int32_t x, int32_t y, uint16_t c, uint32_t color, uint32_t bg, uint8_t size);
  ```
  *说明：绘制单个字符。前者使用Unicode编码和字体大小，后者还可以设置字符颜色和背景色。*

  ##### 6.绘制数字
  ```cpp
    tft.drawNumber(long intNumber, int32_t x, int32_t y, uint8_t font);
    tft.drawNumber(long intNumber, int32_t x, int32_t y);
  ```
  *说明：在指定位置绘制数字。前者可以指定字体大小，后者使用当前字体。*

  ##### 7.绘制浮点数
  ```cpp
    tft.drawFloat(float floatNumber, uint8_t decimal, int32_t x, int32_t y, uint8_t font);
    tft.drawFloat(float floatNumber, uint8_t decimal, int32_t x, int32_t y);
  ```
  *说明：在指定位置绘制浮点数。前者可以指定小数位数和字体大小，后者使用当前字体。*

#### 三、绘制几何图形API
  ##### 1.绘制点
  `tft.drawPixel(int32_t x, int32_t y, uint32_t color);`
  *说明：在指定位置绘制一个点，并设置颜色。*

  ##### 1.绘制线段
  tft.drawLine(int32_t xs, int32_t ys, int32_t xe, int32_t ye, uint32_t color);
  *说明：在指定起点和终点之间绘制一条线段，并设置颜色。*

  ##### 2.绘制快速横线和竖线
  ```cpp
    tft.drawFastHLine(int32_t x, int32_t y, int32_t w, uint32_t color);
    tft.drawFastVLine(int32_t x, int32_t y, int32_t h, uint32_t color);
  ```
  *说明：分别绘制快速横线和竖线。w和h分别表示线段的宽度和高度。*

  ##### 3.绘制圆
  ```cpp
    tft.drawCircle(int32_t x, int32_t y, int32_t r, uint32_t color);
    tft.fillCircle(int32_t x, int32_t y, int32_t r, uint32_t color);
  ```
  *说明：drawCircle函数绘制空心圆，fillCircle函数绘制实心圆。x和y表示圆心坐标，r表示半径。*

  ##### 4.绘制椭圆
  ```cpp
    tft.drawEllipse(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color);
    tft.fillEllipse(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color);
  ```
  *说明：drawEllipse函数绘制空心椭圆，fillEllipse函数绘制实心椭圆。w和h分别表示椭圆的宽度和高度。*

  ##### 5.绘制矩形
  ```cpp
    tft.drawRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color);
    tft.fillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color);
  ```
  *说明：drawRect函数绘制空心矩形，fillRect函数绘制实心矩形。w和h分别表示矩形的宽度和高度*

#### 三、TFT_eSprite
  ##### 1、构造函数
    TFT_eSprite(TFT_eSPI *tft): 创建一个 TFT_eSprite 对象，并将其与 TFT_eSPI 对象关联起来。TFT_eSPI 对象负责底层的屏幕显示操作。
  ##### 2、初始化与设置
  ```cpp
    createSprite(int16_t w, int16_t h): 创建一个指定宽度和高度的精灵。在调用此函数之前，精灵对象是一个空对象，无法绘制。
    deleteSprite(): 删除精灵对象，释放其占用的资源。
    setColorDepth(uint8_t depth): 设置精灵的颜色深度。颜色深度决定了精灵可以显示的颜色数量。
    loadFont(const GFXfont *f): 加载字体到精灵对象中，以便在精灵上绘制文本。
    unloadFont(): 卸载当前加载的字体。
  ```
  ##### 3、绘制与显示
  ```cpp
    pushSprite(int16_t x, int16_t y): 将精灵绘制到屏幕上指定的位置。x 和 y 参数指定了精灵左上角的屏幕坐标。
    fillSprite(uint16_t color): 用指定的颜色填充精灵的整个区域。
    drawPixel(int16_t x, int16_t y, uint16_t color): 在精灵上绘制一个像素点。x 和 y 参数指定了像素点的位置，color 参数指定了像素点的颜色。
    drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color): 在精灵上绘制一条直线。x0、y0 是直线的起点坐标，x1、y1 是直线的终点坐标，color 是直线的颜色。
    drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color): 在精灵上绘制一个矩形。x、y 是矩形左上角的坐标，w、h 是矩形的宽度和高度，color 是矩形的颜色。
    fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color): 用指定的颜色填充精灵上的一个矩形区域。
    drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color): 在精灵上绘制一个圆。x0、y0 是圆心的坐标，r 是圆的半径，color 是圆的颜色。
    fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color): 用指定的颜色填充精灵上的一个圆形区域。
    drawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color): 在精灵上绘制一个圆角矩形。x、y 是矩形左上角的坐标，w、h 是矩形的宽度和高度，r 是圆角的半径，color 是矩形的颜色。
    fillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color): 用指定的颜色填充精灵上的一个圆角矩形区域。
    drawString(const char *str, int16_t x, int16_t y, uint16_t color = TFT_WHITE): 在精灵上绘制字符串。str 是要绘制的字符串，x、y 是字符串左下角的坐标，color 是字符串的颜色。
  ```
  ##### 3、其他
  ```cpp
    setCursor(int16_t x, int16_t y): 设置绘制文本时的光标位置。x、y 是光标的位置坐标。
    setTextColor(uint16_t fg, uint16_t bg = TFT_BLACK): 设置绘制文本时的前景色和背景色。fg 是前景色，bg 是背景色。
    setTextDatum(uint8_t datum): 设置绘制文本时的对齐方式。datum 参数决定了文本的对齐方式，如左对齐、右对齐、居中对齐等。
  ```
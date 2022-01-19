<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />

</head>

<body>
<p>DD 虚拟鼠标 &amp; 虚拟键盘<br />
  DD Virtual Mouse &amp; Virtual Keyboard<br />
</p>
<p>QQ群: 984539184 <br />
<img src="http://www.ddxoft.com/pic/1458056700q.jpg" alt="2" width="280" height="280" /></p>
<p>&nbsp;</p>
<p>6个DD通用函数说明：</p>
<p>1. DD_btn(int btn)<br />
  功能： 鼠标点击<br />
  参数： <br />
  1 =左键按下 ，2 =左键放开<br />
  4 =右键按下 ，8 =右键放开<br />
  16 =中键按下 ，32 =中键放开<br />
  64 =4键按下 ，128 =4键放开<br />
  256 =5键按下 ，512 =5键放开 <br />
例子：<br />
模拟鼠标右键 只需要连写(中间可添加延迟) <br />
dd_btn(4); dd_btn(8);</p>
<p>2. DD_mov(int x, int y)<br />
  功能： 鼠标绝对移动<br />
  参数：<br />
x , y 以屏幕左上角为原点。<br />
  例子： <br />
  把鼠标移动到分辨率1920*1080 的屏幕正中间，<br />
  int x = 1920/2 ; int y = 1080/2;<br />
DD_mov(x,y) ;</p>
<p>3. DD_movR(int dx,int dy)<br />
  功能： 模拟鼠标相对移动<br />
  参数： <br />
  dx , dy 以当前坐标为原点。<br />
  例子：<br />
把鼠标向左移动10像素<br />
DD_movR(-10,0) ;</p>
<p>4. DD_whl(int whl)<br />
  功能: 模拟鼠标滚轮<br />
  参数:<br />
1=前 , 2 = 后<br />
  例子: <br />
  向前滚一格, <br />
  DD_whl(1)</p>
<p>5. DD_key(int ddcode，int flag)<br />
  功能： 键盘按键<br />
  参数： <br />
  ddcode参考[DD虚拟键盘码表]。<br />
  flag，1=按下，2=放开<br />
  例子： <br />
  单键WIN，<br />
  DD_key(601, 1);<br />
  DD_key(601, 2);<br />
  组合键：ctrl+alt+del<br />
  DD_key(600,1); <br />
  DD_key(602,1); <br />
  DD_key(706,1); <br />
  DD_key(706,2);<br />
  DD_key(602,2);<br />
  DD_key(600,2);</p>
<p>6. DD_str(char *str)<br />
  功能： 直接输入键盘上可见字符和空格<br />
  参数： 单字节字符串<br />
  例子：<br />
DD_str(&quot;MyEmail@aa.bb.cc !@#$&quot;)</p>
<p>&nbsp;</p>
</body>
</html>

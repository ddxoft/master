<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>无标题文档</title>
</head>

<body>
<p>DD 虚拟键盘 &amp; 虚拟鼠标<br />
  DD Virtual Mouse &amp; Virtual Keyboard<br />
  QQ : 2827362732   QQ群: 984539184
</p>
<p>&nbsp;</p>
<p>1. DD_btn(参数)<br />
  功能： 模拟鼠标点击<br />
  参数： 1 =左键按下 ，2 =左键放开<br />
  4 =右键按下 ，8 =右键放开<br />
  16 =中键按下 ，32 =中键放开<br />
  64 =4键按下 ，128 =4键放开<br />
  256 =5键按下 ，512 =5键放开 <br />
例子：模拟鼠标右键 只需要连写(中间可添加延迟) dd_btn(4); dd_btn(8);</p>
<p>2. DD_mov(参数x,参数y)<br />
  功能： 模拟鼠标结对移动<br />
  参数： 参数x , 参数y 以屏幕左上角为原点。<br />
  例子： 把鼠标移动到分辨率1920*1080 的屏幕正中间，<br />
  int x = 1920/2 ; int y = 1080/2;<br />
DD_mov(x,y) ;</p>
<p>3. DD_movR(参数dx,参数dy)<br />
  功能： 模拟鼠标相对移动<br />
  参数： 参数dx , 参数dy 以当前坐标为原点。<br />
  例子： 把鼠标向左移动10像素<br />
DD_movR(-10,0) ;</p>
<p>4. DD_whl(参数)<br />
  功能: 模拟鼠标滚轮<br />
  参数: 1=前 , 2 = 后<br />
  例子: 向前滚一格, DD_whl(1)</p>
<p>5. DD_key(参数1，参数2)<br />
  功能： 模拟键盘按键<br />
  参数： 参数1 ，请查看[DD虚拟键盘码表]。<br />
  参数2，1=按下，2=放开<br />
  例子： 模拟单键WIN，<br />
  DD_key(601, 1);DD_key(601, 2);<br />
  组合键：ctrl+alt+del<br />
  DD_key(600,1); <br />
  DD_key(602,1); <br />
  DD_key(706,1); <br />
  DD_key(706,2);<br />
  DD_key(602,2);<br />
  DD_key(600,2);</p>
<p>6. DD_str(参数)<br />
  功能： 直接输入键盘上可见字符和空格<br />
  参数： 字符串, (注意，这个参数不是int32 类型)<br />
  例子： DD_str(&quot;MyEmail@aa.bb.cc !@#$&quot;)</p>
<p>&nbsp;</p>
</body>
</html>

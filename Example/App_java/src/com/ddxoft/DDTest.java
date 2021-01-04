package com.ddxoft;
import com.sun.jna.Library;
import com.sun.jna.Native;

public class DDTest {
	 public static void main(String[] args) {
		 System.out.println("²âÊÔ¿ªÊ¼");
		 
		 //DD.INSTANCE.DD_mov(500, 500);   
		 //DD.INSTANCE.DD_movR(100, 100);  
		 //DD.INSTANCE.DD_btn(4);DD.INSTANCE.DD_btn(8); //
		 
		 DD.INSTANCE.DD_key(601, 1); // 1==down, 601=Left.Win (dd key code)
		 DD.INSTANCE.DD_key(601, 2); // 2=up
		 DD.INSTANCE.DD_str("123@AbC");    
	 }
	 
	 public interface DD extends Library {
		   DD INSTANCE = (DD)Native.loadLibrary("DD94687.64", DD.class);
		  
		   public int DD_mov(int x, int y);//mouse move abs.
		   public int DD_movR(int dx, int dy);//mouse move rel.
		   public int DD_btn(int btn);//1==L.down, 2==L.up, 4==R.down, 8==R.up, 16==M.down, 32==M.up
		   public int DD_whl(int whl);//Mouse Wheel. 1==down, 2==up
		   public int DD_key(int ddcode, int flag);//keyboard,
		   public int DD_str(String s);////Input visible char  
	 }
}

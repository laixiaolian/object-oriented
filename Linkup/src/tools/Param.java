package tools;

import java.awt.Image;

import javax.swing.ImageIcon;

public class Param {

	// 游戏总行数与总列数
	public static int rows = 8;
	public static int cols = 10;

	// 棋子图标 宽与高
	public static int chessWidth = 55;
	public static int chessHeight = 55;

	// 棋盘到边界的距离
	public static int marginWidth = 200 - chessWidth;
	public static int marginHeight = 100 - chessHeight;

	// 游戏的背景图片
	public static Image imageBackground = new ImageIcon(
			"Images/Back/Background3.jpg").getImage();

	public static Image[] chessImage = new Image[20];
	static {
		for (int i = 0; i < chessImage.length; i++) {
			chessImage[i] = new ImageIcon("Images/build/" + (i + 1) + ".png")
					.getImage();
		}
	}
	public static int gameStatus = 0;

}

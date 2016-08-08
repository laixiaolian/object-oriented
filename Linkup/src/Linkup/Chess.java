package Linkup;

/**
 * 棋子封装类
 * 
 * @author laixl
 * 
 */

public class Chess {

	// 图片的 状态 //1.....20
	// 0表示消掉

	private int status;

	public Chess(int status) {
		this.status = status;
	}

	public int getStatus() {
		return status;
	}

	public void setStatus(int status) {
		this.status = status;
	}

}

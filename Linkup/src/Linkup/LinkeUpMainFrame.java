package Linkup;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Label;
import java.awt.Point;
import java.awt.event.InputEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.List;
import java.util.Random;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

import tools.Core;
import tools.Param;

public class LinkeUpMainFrame extends JFrame {
	MapPanel mapPanel = new MapPanel(this);

	int countRemark = 3, countRefresh = 3;
	JLabel labelStart = new LinkedJLable("开始");
	JLabel labelRemark = new LinkedJLable("提示(" + countRemark + ")");
	JLabel labelRefresh = new LinkedJLable("洗牌(" + countRefresh + ")");
	JLabel labelScore = new LinkedJLable("当前成绩：");
	
	
	public LinkeUpMainFrame() {
		init();
		//
		this.setTitle("连连看");// 设置 标题

		this.setSize(1000, 650);// 设置宽高

		this.setLocationRelativeTo(null);// 自动适配到屏幕中间

		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);// 设置关闭模式
		this.setResizable(false);

		this.setVisible(true);// 设置可见

//		ImageIcon imageIcon = new ImageIcon("Images/Photos/serverstop.gif");
//		Image image = imageIcon.getImage();
//		this.setIconImage(image);// 设置连连看窗体图标
	}

	private void init() {
		this.setLayout(null);
		labelStart.setFont(new Font("宋体",Font.BOLD,16));
		labelRemark.setFont(new Font("宋体",Font.BOLD,16));
		labelRefresh.setFont(new Font("宋体",Font.BOLD,16));
		labelScore.setFont(new Font("宋体",Font.BOLD,16));
		labelStart.setBounds(20, 20, 80, 25);
		labelRemark.setBounds(110, 20, 80, 25);
		labelRefresh.setBounds(200, 20, 80, 25);
		labelScore.setBounds(300, 20, 100, 25);
		this.add(labelStart);
		this.add(labelRemark);
		this.add(labelRefresh);
		this.add(labelScore);
		mapPanel.setBounds(0, 0, 1000, 650);

		this.add(mapPanel);

		labelStart.addMouseListener(new MouseAdapter() {

			@Override
			public void mousePressed(MouseEvent e) {
				String text = labelStart.getText();
				if ("开始".equals(text)) {
					Param.gameStatus = 1;
					labelStart.setText("暂停");

					repaint();
				} else if ("暂停".equals(text)) {
					Param.gameStatus = 2;
					labelStart.setText("继续");

					repaint();
				} else if ("继续".equals(text)) {
					Param.gameStatus = 1;
					labelStart.setText("暂停");

					repaint();
				}
			}

		});

		// 洗牌

		labelRefresh.addMouseListener(new MouseAdapter() {
			int count = 0;

			@Override
			public void mousePressed(MouseEvent e) {

				if (Param.gameStatus != 1) {
					JOptionPane.showMessageDialog(LinkeUpMainFrame.this,
							"游戏还未开始，请先开始游戏！");
					return;
				}

				if (e.getModifiers() != InputEvent.BUTTON1_MASK) {
					return;
				}

				if (count < 3) {
					Core.refreshArr(mapPanel.arr);
					repaint();
					count++;
					countRefresh--;
					labelRefresh.setText("洗牌(" + countRefresh + ")");
				}

			}

		});

		// 提示 监听

		labelRemark.addMouseListener(new MouseAdapter() {
			int count = 0;

			@Override
			public void mousePressed(MouseEvent e) {
				if (Param.gameStatus != 1) {
					JOptionPane.showMessageDialog(LinkeUpMainFrame.this,
							"游戏还未开始，请先开始游戏！");
					return;
				}

				if (e.getModifiers() != InputEvent.BUTTON1_MASK) {
					return;
				}
				if (count < 3) {
					List<Point> list = Core.remarkArr(mapPanel.arr);
					if (list != null) {
						remarkDeal(list);

					}
					count++;
					countRemark--;
					labelRemark.setText("提示(" + countRemark + ")");
				}

			}

		});
	}

	public static void main(String[] args) {
		try {
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		new LinkeUpMainFrame();

	}

	public void remarkDeal(final List<Point> list) {
		//
		new Thread() {
			public void run() {
				int count = 0;
				while (count < 3) {
					mapPanel.drawMyRect(list.get(0), Color.orange);
					mapPanel.drawMyRect(list.get(1), Color.orange);
					count++;
					try {
						Thread.sleep(500);
					} catch (InterruptedException e1) {
						e1.printStackTrace();
					}
					repaint();
					try {
						Thread.sleep(500);
					} catch (InterruptedException e1) {
						e1.printStackTrace();
					}
				}
			}
		}.start();
	}
}

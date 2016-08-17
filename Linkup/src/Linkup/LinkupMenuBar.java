package Linkup;

import java.awt.Paint;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.TreeSet;

import javax.swing.AbstractButton;
import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.plaf.OptionPaneUI;

import Dialog.AboutJDialog;
import Dialog.ExitJDialog;
import Dialog.ParamJDialog;
import Dialog.RuleJDialog;
import Dialog.ScoreJDialog;
import tools.Param;
import tools.Student;

public class LinkupMenuBar extends JMenuBar {
	JMenuItem menuItemParam = new JMenuItem("游戏参数");
	JMenu menuItemBackground = new JMenu("设置背景");
	JMenu menuItemChessIcon = new JMenu("设置棋子");
	JMenuItem menuItemScore = new JMenuItem("查看成绩");
	JMenuItem menuItemExit = new JMenuItem("退出游戏");
	JMenuItem menuItemRule = new JMenuItem("游戏规则");
	
	JMenuItem menuItemAbout = new JMenuItem("游戏版权");

	LinkeUpMainFrame mainFrame;
	public LinkupMenuBar(LinkeUpMainFrame mainFrame) {
		this.mainFrame=mainFrame;
		
		this.init();
	}
	private void init() {
		
		JMenu menuSet = new JMenu("设置");
		menuSet.add(menuItemParam);
		menuSet.addSeparator();
		menuSet.add(menuItemBackground);
		menuSet.addSeparator();
		menuSet.add(menuItemChessIcon);
		menuSet.addSeparator();
		menuSet.add(menuItemScore);
		menuSet.addSeparator();
		menuSet.add(menuItemExit);
		String[] arrIcon=new String[]{"水果","图标","可爱","friends"};
		for (int i = 0; i < arrIcon.length; i++) {
			final JCheckBoxMenuItem jCheckBoxMenuItem = new JCheckBoxMenuItem(arrIcon[i]);
			menuItemChessIcon.add(jCheckBoxMenuItem);
			menuItemChessIcon.addSeparator();
			jCheckBoxMenuItem.addActionListener(new ActionListener() {
				
				@Override
				public void actionPerformed(ActionEvent e) {
					String text = jCheckBoxMenuItem.getText();
					if("水果".equals(text)){
						Param.chessImageIcon=Param.chessImage[0];
					}else if("图标".equals(text)){
						Param.chessImageIcon=Param.chessImage[1];
					}else if("可爱".equals(text)){
						Param.chessImageIcon=Param.chessImage[2];
					}else if("friends".equals(text)){
						Param.chessImageIcon=Param.chessImage[3];
					}
					mainFrame.repaint();
				}
			});
		}
		
		String[] arr = new String[]{"蓝色天空","海洋之星","绿草青青","水墨青花","五彩缤纷","蓝色之恋"};
		ButtonGroup buttonGroup = new ButtonGroup();
		for (int i = 0; i < arr.length; i++) {
			final JCheckBoxMenuItem jCheckBoxMenuItem = new JCheckBoxMenuItem(arr[i]);
			
			menuItemBackground.add(jCheckBoxMenuItem);
			menuItemBackground.addSeparator();
			buttonGroup.add(jCheckBoxMenuItem);
			jCheckBoxMenuItem.addActionListener(new ActionListener() {
				
				@Override
				public void actionPerformed(ActionEvent e) {
					String text = jCheckBoxMenuItem.getText();
					if("蓝色天空".equals(text)){
						Param.imageBackground=Param.imageBackgroundLSTK;
					}else if("海洋之星".equals(text)){
						Param.imageBackground=Param.imageBackgroundHYZX;
					}else if("绿草青青".equals(text)){
						Param.imageBackground=Param.imageBackgroundLCQQ;
					}else if("水墨青花".equals(text)){
						Param.imageBackground=Param.imageBackgroundSMQH;
					}else if("五彩缤纷".equals(text)){
						Param.imageBackground=Param.imageBackgroundWCBF;
					}else if("蓝色之恋".equals(text)){
						Param.imageBackground=Param.imageBackgroundLSZL;
					}
					mainFrame.repaint();
					
					
					
				}
			});
		}
		
		JMenu menuHelp = new JMenu("帮助");
		
		menuHelp.add(menuItemRule);
		menuHelp.addSeparator();
		menuHelp.add(menuItemAbout);
		this.add(menuSet);
		this.add(menuHelp);
		
		menuItemParam.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				new ParamJDialog(mainFrame);
				
			}
		});
		
		menuItemExit.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				new ExitJDialog(mainFrame);
				
			
			}
			
		});
		
		menuItemScore.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {

				new ScoreJDialog(mainFrame);
				
			}
		});
		
		menuItemRule.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				new RuleJDialog(mainFrame);			}
		
		
			
		});
	
		
		menuItemAbout.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				new AboutJDialog(mainFrame);
				
			}
		});
	}
	
	
	
}

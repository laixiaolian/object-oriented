package Dialog;

import java.awt.Dimension;
import java.awt.Graphics;

import javax.swing.JDialog;

import tools.Param;
import Linkup.LinkeUpMainFrame;

public class RuleJDialog extends JDialog {
	LinkeUpMainFrame frame;
	public RuleJDialog(LinkeUpMainFrame frame) {
		super(frame);
		this.frame=frame;
		setTitle("”Œœ∑πÊ‘Ú");
		this.setSize(new Dimension(600,400));
		this.setLocationRelativeTo(frame);
		
		this.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
		this.setResizable(false);
		this.setModal(true);
		this.setVisible(true);
		
	}
	@Override
	public void paint(Graphics g) {
		// TODO Auto-generated method stub
		super.paint(g);
		g.drawImage(Param.Rule, 0, 0, this);
	}
	
}

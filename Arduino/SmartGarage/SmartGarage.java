package prova_ser;


import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.TextArea;
import java.awt.TextField;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class SmartGarage extends JFrame {
	
	
	private JPanel PPC;
	private JPanel PGarage;

	private JPanel contentaPane;
	private JLabel labGarage;
	
	private JPanel panPC;
	private JPanel panGAR;
	
	
	
	public SmartGarage () {
		this.setTitle("Smart garage");
		this.contentaPane = new JPanel();
		
		this.PPC = new JPanel();
		this.PPC.setLayout(new BoxLayout(PPC, 3));
		this.PGarage = new JPanel();
		this.panGAR = new JPanel();
		this.panPC = new JPanel();
		this.PGarage.setLayout(new BoxLayout(PGarage, 3));
		
		

		
		
				
		this.contentaPane.setLayout(new BoxLayout(contentaPane, 3));
		this.contentaPane.setBackground(Color.GRAY);
		
		this.PGarage.setBackground(Color.GRAY);
	
		JTextArea gtext = new JTextArea("                  ");
		JPanel jp2 = new JPanel();
		jp2.setBackground(Color.GRAY);
		jp2.add(gtext);
		gtext.setEditable(false);
		this.PGarage.add(gtext);
	



	
	  
	    JPanel jp = new JPanel();
	    jp.setBackground(Color.GRAY);
	    JButton openButton = new JButton("OPEN");
	    openButton.setBackground(new Color(0,137,123));
	    
	    JButton closeButton = new JButton("CLOSE");
	    closeButton.setBackground(new Color(0,137,123));
	   	jp.add(openButton);
	   	jp.add(closeButton);
		this.PPC.add(jp);
		this.PPC.setBackground(Color.gray);
	
	
		this.contentaPane.add(PPC, BorderLayout.WEST);
		this.contentaPane.add(PGarage, BorderLayout.EAST);
		
		this.add(contentaPane);
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(500, 500);
		
		this.setMinimumSize(new Dimension(200, 200));

		
	}

	public static void main (String[] args) {
		SmartGarage sm = new SmartGarage();
		sm.setVisible(true);
		
		}
	
	
}

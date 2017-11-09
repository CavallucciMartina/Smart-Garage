package main;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.io.IOException;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;

public class GarageGui extends JFrame implements Garage{
	
	private static final long serialVersionUID = 1L;
	private JPanel PCPanel;
	private JPanel GaragePanel;
	private JPanel contentaPane;
	private JPanel tmpPanel;
	private JButton openButton;
	private JButton closeButton;
	private JTextArea GarageText;
	private SerialMonitor serial;
	private static final short BOX = 3;
	private static final short GREEN = 137;
	private static final short BLUE = 123;
	private static final short DIM = 300;
	private static final short DIM_MIN = 200;
	/*
	 * The GUI constructor.
	 */
	public GarageGui() {
		this.setTitle("Smart garage");
		
		this.contentaPane = new JPanel();
		this.PCPanel = new JPanel();
		this.PCPanel.setLayout(new BoxLayout(PCPanel, BOX));
		this.GaragePanel = new JPanel();
		
		this.GaragePanel.setLayout(new BoxLayout(GaragePanel, BOX));
		this.contentaPane.setLayout(new BoxLayout(contentaPane, BOX));
		this.contentaPane.setBackground(Color.GRAY);
		this.GaragePanel.setBackground(Color.GRAY);
		
		this.GarageText = new JTextArea(" ");
		this.GaragePanel.add(this.GarageText);
		this.tmpPanel = new JPanel();
		this.tmpPanel.setBackground(Color.GRAY);
		this.openButton = new JButton("OPEN");

		this.openButton.setBackground(new Color(0, GREEN, BLUE));
		this.openButton.addActionListener(e -> {
			try {
				serial.sendData("OPEN");
			} catch (IOException e1) {
				e1.printStackTrace();
			}
		});
		this.closeButton = new JButton("CLOSE");
		this.closeButton.setBackground(new Color(0, GREEN, BLUE));
		this.closeButton.addActionListener(e -> {
			try {
				serial.sendData("CLOSE");
			} catch (IOException e1) {
				e1.printStackTrace();
			}
		});
		this.tmpPanel.add(this.openButton);
		this.tmpPanel.add(this.closeButton);
		this.PCPanel.add(this.tmpPanel);
		this.PCPanel.setBackground(Color.gray);
		this.contentaPane.add(this.PCPanel, BorderLayout.WEST);
		this.contentaPane.add(this.GaragePanel, BorderLayout.EAST);
		
		this.add(contentaPane);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(DIM, DIM);
		this.setMinimumSize(new Dimension(DIM_MIN, DIM_MIN));
		this.setVisible(true);

	}

	public static void main(String[] args) {

		GarageGui monitor = new GarageGui();
		monitor.serial = new SerialMonitor(monitor);
		monitor.serial.start(args[0], Integer.parseInt(args[1])); 
		
	}
	/**
	 * Set the text area that show the garage message.
	 */
	public void addData(final String data) {

		this.GarageText.setText(data + '\n');

	}
}

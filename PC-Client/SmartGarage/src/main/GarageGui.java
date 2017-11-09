package main;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.io.IOException;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;

public class GarageGui extends JFrame {
	private static final long serialVersionUID = 1L;
	private JPanel PPC;
	private JPanel PGarage;
	private JPanel contentaPane;
	//private JLabel labGarage;
	//private JPanel panPC;
	//private JPanel panGAR;
	public JButton openButton;
	public JTextArea gtext;

	public SerialMonitor serial;

	public GarageGui() {
		this.setTitle("Smart garage");
		this.contentaPane = new JPanel();
		this.PPC = new JPanel();
		this.PPC.setLayout(new BoxLayout(PPC, 3));
		this.PGarage = new JPanel();
		//this.panGAR = new JPanel();
		//this.panPC = new JPanel();
		this.PGarage.setLayout(new BoxLayout(PGarage, 3));

		this.contentaPane.setLayout(new BoxLayout(contentaPane, 3));
		this.contentaPane.setBackground(Color.GRAY);

		this.PGarage.setBackground(Color.GRAY);

		gtext = new JTextArea("                  ");

		JPanel jp2 = new JPanel();
		jp2.setBackground(Color.GRAY);
		jp2.add(gtext);

		this.PGarage.add(gtext);

		JPanel jp = new JPanel();
		jp.setBackground(Color.GRAY);
		openButton = new JButton("OPEN");

		openButton.setBackground(new Color(0, 137, 123));
		openButton.addActionListener(e -> {

			try {
				serial.sendData("OPEN");

			} catch (IOException e1) {

				e1.printStackTrace();
			}
		});
		JButton closeButton = new JButton("CLOSE");
		closeButton.setBackground(new Color(0, 137, 123));
		closeButton.addActionListener(e -> {
			try {
				serial.sendData("CLOSE");
			} catch (IOException e1) {

				e1.printStackTrace();
			}
		});
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

		this.setVisible(true);

	}

	public static void main(String[] args) {

		GarageGui monitor = new GarageGui();
		monitor.serial = new SerialMonitor(monitor);
		monitor.serial.start(args[0], Integer.parseInt(args[1])); /* QUI DA LINEA DI COMANDO LA COMM4 E LA 9600 */
		
	}

	public void addData(String data) {

		gtext.setText(data + '\n');

	}
}

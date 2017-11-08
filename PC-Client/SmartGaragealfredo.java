package seiot.modulo_lab_2_2;

import gnu.io.NoSuchPortException;
import gnu.io.SerialPortEvent;

public class SmartGarage {

	public static void main(String[] args) throws NoSuchPortException {
		Buffer buf = new Buffer();
		buf.initialize();
		Thread t = new Thread() {
			public void run() {
				try {
					Thread.sleep(5000);
				} catch (InterruptedException ie) {
				}
			}
		};

		t.start();
		GarageGui sm = new GarageGui(buf);
		sm.setVisible(true);
		

		
	}
}

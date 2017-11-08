package seiot.modulo_lab_2_2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import gnu.io.CommPortIdentifier;
import gnu.io.NoSuchPortException;
import gnu.io.SerialPort;
import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;

public class Buffer implements SerialPortEventListener {

	static SerialPort serialPort;

	/** The port we're normally going to use. */

	/**
	 * A BufferedReader which will be fed by a InputStreamReader converting the
	 * bytes into characters making the displayed results codepage independent
	 */
	private BufferedReader input;
	/** The output stream to the port */
	private static OutputStream output;
	/** Milliseconds to block while waiting for port open */
	private static final int TIME_OUT = 2000;
	/** Default bits per second for COM port. */
	private static final int DATA_RATE = 9600;

	public void initialize() throws NoSuchPortException {
		// porta con la quale comunicare (a cui è attaccato arduino)
		CommPortIdentifier portId = CommPortIdentifier.getPortIdentifier("COM5");

		if (portId == null) {
			System.out.println("Could not find COM port.");
			return;
		}

		try {
			// apre la porta di comunicazione con arduino
			serialPort = (SerialPort) portId.open(this.getClass().getName(), TIME_OUT);

			// setta i parametri di comunicazione
			serialPort.setSerialPortParams(DATA_RATE, SerialPort.DATABITS_8, SerialPort.STOPBITS_1,
					SerialPort.PARITY_NONE);

			// apre gli stream di input e di output
			input = new BufferedReader(new InputStreamReader(serialPort.getInputStream()));
			output = serialPort.getOutputStream();
			// aggancio gli event listener per sapere quando sono disponibili dei dati da
			// leggere
			serialPort.addEventListener(this);
			serialPort.notifyOnDataAvailable(true);// notifica quando sono disponibili dei dati
		} catch (Exception e) {
			System.err.println(e.toString());
			System.out.println("NON APRE LA PORTA");
		}
	}

	/**
	 * ATTENZIONE! Da richiarare quando si chiude la connessione con la porta
	 */
	public synchronized static void close() {
		if (serialPort != null) {
			serialPort.removeEventListener();
			serialPort.close();
		}
	}

	/**
	 * Cattura un evento sulla porta seriale, poi legge i dati e li stampa.
	 */
	public synchronized void serialEvent(SerialPortEvent oEvent) {
		try {
			if (oEvent.getEventType() == SerialPortEvent.DATA_AVAILABLE && input.ready()) {
				try {

					String inputLine = input.readLine();
					// gtext.append(inputLine);
					// System.out.println(inputLine);
				} catch (Exception e) {
					System.err.println(e.toString());
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		// ignora tutti gli altri tipi di evento, si attiva solo quando sono disponibili
		// dei dati da leggere
	}
	
	public void sendMessage(String s) {
		output.write(s.getBytes());
	}

}

package ramirezag;

import org.junit.Test;

import java.io.IOException;
import java.io.OutputStream;

public class BufferedOutputStream {

    private OutputStream out;
    private byte[] buf;
    private int bufCount = 0;
    private int bitCount = 0;
    private static final int BUF_SIZE = 32;

    /**
     * This constructor sets a buffer of size 32
     * @param out Output stream
     */
    public BufferedOutputStream(OutputStream out){
        this.out = out;
        buf = new byte[BUF_SIZE];
    }

    /**
     * This method sets a buffer of a user defined size
     * @param out Output stream
     * @param size buffer size
     */
    public BufferedOutputStream(OutputStream out, int size){
        this.out = out;
        buf = new byte[size];
    }

    /**
     * This method writes a single byte
     * @param b The indicator of the byte to be written
     * @throws IllegalStateException Thrown when attempting to write a partial byte
     */
    public void write(int b) throws IllegalStateException{
        if(bitCount % 8 != 0) {
            throw new IllegalStateException("Cannot write to a partial bit");
        }
            try{
                out.write(b);
            } catch (IOException e){
                System.out.println("There was an error writing the byte");
            }
    }

    /**
     * This method writes multiple bytes to a user given byte array
     * @param list The given byte array
     * @param off The offset
     * @param len The array length
     */
    public void write(byte[] list, int off, int len){
        if(bitCount % 8 != 0) {
            throw new IllegalStateException("Cannot read a partial bit");
        }
        try{
            out.write(list, off, len);
        } catch (IOException e){
            System.out.println("There was an error reading the byte");
        }
    }

    /**
     * This method writes a single bit
     * @param num The bit
     */
    public void writeBit(int num){
        int bit = bitCount;
        if(bit == 0){
            buf[bufCount] = (byte) (num << 7);
        } else {
            buf[bufCount] = (byte)((bit << 7 - bitCount) | buf[bufCount]);
        }
    }

    /**
     * This method writes the rest of the buffer, and then clears the buffer
     */
    public void flush(){
        try{
            while(bufCount < buf.length){
                out.write(bufCount);
                bufCount++;
            }
        } catch(IOException e){

        }
    }

}

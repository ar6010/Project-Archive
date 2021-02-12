package ramirezag;

import org.junit.Test;

import java.io.IOException;
import java.io.InputStream;


public class BufferedInputStream {

    private InputStream in;
    private byte[] buf;
    private int bufCount = 0;
    private int bitCount = 8;
    private static final int BUF_SIZE = 32;
    private byte storageByte;
    private byte finalByte;
    private boolean initialized = false;

    /**
     * This constructor sets a buffer of size 32
     * @param in Input stream
     */
    public BufferedInputStream(InputStream in){
        this.in = in;
        buf = new byte[BUF_SIZE];
    }

    /**
     * This constructor sets a buffer of a user defined size
     * @param in Input Stream
     * @param size Size of the buffer
     */
    public BufferedInputStream(InputStream in, int size){
        this.in = in;
        buf = new byte[size];
    }

    /**
     * This method reads the next byte in the buffer
     * @return the next byte
     * @throws IllegalStateException Thrown if the user is attemting to read a partial bit
     */
    public int read() throws IllegalStateException{
        if(bitCount % 8 != 0) {
            throw new IllegalStateException("Cannot read a partial bit");
        }
        int temp = -1;
        if(buf.length == bufCount || !initialized){
            try{
                in.read(buf);
                temp = buf[0];
                bufCount++;
                initialized = true;
            } catch (IOException e){
                System.out.println("There was an error reading the byte");
            }
        } else {
            temp = buf[bufCount];
            bufCount++;
        }
        return temp;
    }

    /**
     * This method reads bytes into a user given byte
     * @param list The user's given buffer
     * @param off The offset
     * @param len The length of the buffer
     * @return
     * @throws IllegalStateException
     */
    public int read(byte[] list, int off, int len) throws IllegalStateException{
        if(bitCount % 8 != 0) {
            throw new IllegalStateException("Cannot read a partial bit");
        }
        int temp = -1;
        try{
            temp = in.read(list, off, list.length);
        } catch (IOException e){
            System.out.println("There was an error reading the byte");
        }
        if(temp == 0){
            temp = -1;
        }
        return temp;
    }

    /**
     * This method reads a single bit from the buffer
     * @return The single bit
     */
    public int readBit(){
        int bit = -1;
        storageByte = buf[bufCount];
        if(bitCount == 8){
            bit = storageByte & 0b00000001;
            bitCount--;
        } else {
            bit = (storageByte >> bitCount) & 0b00000001;
            bitCount--;
            if(bitCount == 0){
                bitCount = 8;
            }
        }
        return bit;
    }
}

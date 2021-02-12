package ramirezag;

import org.junit.Test;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Random;

import static org.junit.Assert.*;

public class Lab5Tests {

    /**
     * This method tests the read(byte[]) method
     */
    @Test
    public void readByteArray() {
        byte[] buf = new byte[10];
        byte[] store = new byte[10];
        for(int i = 0; i < buf.length; i++){
            buf[i] = 1;
        }
        InputStream is = new ByteArrayInputStream(buf);
        BufferedInputStream bi = new BufferedInputStream(is);
        bi.read(store, 0, buf.length);
        assert((store.length == 10) && store[5] == 1);
    }

    /**
     * This method tests the read() method
     */
    @Test
    public void read(){
        byte[] buf = new byte[10];
        for(int i = 0; i < buf.length; i++){
            buf[i] = 1;
        }
        InputStream is = new ByteArrayInputStream(buf);
        BufferedInputStream bi = new BufferedInputStream(is);
        int temp = bi.read();
        System.out.println(temp);
        assert(temp == 1);
    }

    /**
     * This method tests the readBit method
     */
    @Test
    public void readBit(){
        byte[] buf = new byte[10];
        for(int i = 0; i < buf.length; i++){
            buf[i] = 1;
        }
        InputStream is = new ByteArrayInputStream(buf);
        BufferedInputStream bi = new BufferedInputStream(is);
        int temp = bi.readBit();
        System.out.println(temp);
        assert(temp == 0);
    }

    /**
     * This method tests the write() method
     */
    @Test
    public void write(){
        byte[] buf = new byte[10];
        for(int i = 0; i < buf.length; i++){
            buf[i] = 1;
        }
        ByteArrayOutputStream os = new ByteArrayOutputStream(buf.length);
        BufferedOutputStream bo = new BufferedOutputStream(os);
        for(byte temp : buf){
            bo.write(temp);
        }
        byte[] bytes = os.toByteArray();
        assert(Arrays.equals(bytes, buf));

    }

}
import java.util.*;




class Limited_LinkedHashMap extends LinkedHashMap{
    protected boolean removeEldestEntry(Map.Entry eldest){
	//一番古いエントリを消す時はtrue->10よりサイズ大でtrue
	return size()>6;
    }
}



public class Fifo{


    static void map_make(Map m){
	System.out.println(m.getClass().toString());
	m.put(1,1);
	System.out.println(m);
	m.put(20,5);
	System.out.println(m);
	m.put(100,50);
	System.out.println(m);
	m.put(2,90);
	System.out.println(m);
	m.put(5,5);
	System.out.println(m);
	m.put(15,51);
	System.out.println(m);
	m.put(17,19);
	System.out.println(m);


    }

    public static void main(String[] args){
	map_make(new LinkedHashMap());//普通の
	map_make(new Limited_LinkedHashMap()); //6制限
    }

}

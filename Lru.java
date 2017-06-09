import java.util.*;

//ハッシュでの格納とリスト作成を同時にやる。お互いにどこにあるかわかるようにしておく。(ハッシュにはリストのどのあたりにあるかのポインタ、リストにはハッシュのキーなど)
//ハッシュの方に既存のデータがアクセスされたら、既存のポインタをはずして最後尾に並び替える
//新しいデータが入ってきたら後ろへ、もし規定よりリストが長くなってしまったら、先頭をリストからはずして新しいデータをリストの後ろにつける

//これ自体はとりあえず目的を果たすものですが、上の文はCのイメージです。



class Limited_LinkedHashMap extends LinkedHashMap{
    protected boolean removeEldestEntry(Map.Entry eldest){
	//一番古いエントリを消す時はtrue->10よりサイズ大でtrue
	return size()>6;
    }

    public Limited_LinkedHashMap(int i,float f, boolean b){

	super(i,f,b);//第三引数がtrueの時はアクセス順

}
	
}

public class Lru{


    static void map_make(Map m){//最新でアクセスされたものがリストのしりにくる
	System.out.println(m.getClass().toString());
	m.put(1,1);
	m.put(20,5);
	m.put(100,50);
	m.put(2,90);
	m.put(5,5);
	m.put(15,51);
	m.put(17,19);
	System.out.println(m);

	m.get(20);//アクセス
	m.get(2);
	System.out.println(m);
	m.put(14,19);
	System.out.println(m);
		
		
	


    }

    public static void main(String[] args){
	map_make(new LinkedHashMap());//普通の
	map_make(new Limited_LinkedHashMap(16,0.75f,true)); //6制限
    }

}

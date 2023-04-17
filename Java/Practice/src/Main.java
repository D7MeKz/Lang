import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        int[] odds = { 1, 2, 3};
        // Array는 크기가 고정되어 있다.
        String[] weeks = new String[7];
        weeks[0] = "Monday";
        for(int i = 0 ; i <weeks.length;i++){
            System.out.println(weeks[i]);
        }

        // 그에 비하면 List의 경우 배열의 크기가 정해져있지 않다.
        // 실행하고자 하는 자료형을 명시하는 것을 권고하고 있다.
        // ArrayList 안에 담을 수 있는 것은 String 뿐이다를 명시
        // 제네릭을 사용하지 않으면 Objecct로 명시되므로, 일리릴 String으로 캐스팅해야한다.
        ArrayList<String> pitches = new ArrayList<>(); // 제네릭스
        pitches.add("138");
        pitches.add(1,"1234"); // 특정 위치에 삽입 가능
        System.out.println(pitches.get(1)); // 출력하고 싶다면
        System.out.println(pitches.size());// size
        System.out.println(pitches.contains("144")); // 항목에 있는지 여부를 boolean으로 표현

        String[] data = {"!", "?"};
        ArrayList<String> pictches2 = new ArrayList<>(Arrays.asList(data));
        String result;
        result = String.join(",",pictches2);
        // 리스트 정렬
        pictches2.sort(Comparator.naturalOrder()); // 오름차순으로 정렬

        // Map도 List와 마찬가지로 인터페이스이다.
        HashMap<String,String> map = new HashMap<>();
        map.put("people","사람");
        map.getOrDefault("java","지바"); // 특정 key에 대한 default를 지정할 수 있다.
        System.out.println(map.containsKey("people")); // key가 있는지 확인
        // Map에 입력된 순서대로 데이터를 가져오고 싶다면 LinkedHashMap이나 TreeMap을 활용하자.
    }
}
import java.util.Scanner;

public class Main{
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int[] arr = new int[T];
        for (int i = 0; i<T; i++){
            arr[i] = sc.nextInt();
        }
        int max = 0;
        for (int i : arr){
            if (max < i){
                max = i;
            }
        }
        System.out.println(max);
        sc.close();
    }
}
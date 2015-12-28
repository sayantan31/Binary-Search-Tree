package bubble_sort;

public class BubbleSort {

	public static void main(String args[]) {
		
		int [] arr = {2,7,4,1,5,3};
		
		doBubbleSort(arr);
		
		for(int i=0; i<arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}
	
	public static void doBubbleSort(int[] a) {
		
		for(int i=0; i<a.length; i++) {		
			for(int j=0; j<a.length-1; j++) {
				if(a[j] > a[j+1]) {
					int temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
				
			}
		}
	}
}

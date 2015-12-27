package insertion_sort;

public class InsertionSort {

	public static void main(String args[]) {
		
		int[] arr = {3,7,9,5};
		
		doInsertionSort(arr);
		
		for(int i : arr) {
			System.out.print(i + " ");
		}
		
		System.out.println();
	}
	
	public static void doInsertionSort(int [] arr) {
		
		for(int i=1; i<arr.length; i++) {
			int key = arr[i];
			int index = i;
			
			while(index > 0 && arr[index-1] > key) {
				arr[index] = arr[index-1];
				index -= 1;
			}
			
			arr[index] = key;
		}
	}
}
